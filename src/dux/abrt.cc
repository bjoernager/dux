/*
	Copyright 2021 Gabriel Jensen

	This file is part of dux.

	dux is free software: you can redistribute it and/or modify it under the
	terms of the GNU Affero General Public License as published by the Free
	Software Foundation, either version 3 of the License, or (at your
	option) any later version.

	dux is distributed in the hope that it will be useful, but WITHOUT ANY
	WARRANTY; without even the implied warranty of MERCHANTABILITY or
	FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public
	License for more details.

	You should have received a copy of the GNU Affero General Public License
	along with dux. If not, see <https://www.gnu.org/licenses/>.
*/

#include <dux/io>
#if defined(dux_os_posix)
#include <pthread.h>
#endif

namespace dux::_static {
#if defined(dux_os_posix)
	static ::pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
#endif
}

auto ::dux::abrt() noexcept -> void {
	::pthread_mutex_lock(&::dux::_static::lock); /* Lock this so we will not abort from multiple threads. */
	::dux::dbgprint(U"dux :: Aborting!\n");
	::dux::dbgprint(U"dux :: Raising SIGABRT!\n");
	::dux::raise(::dux::sig::abrt); /* We will now raise SIGABRT in an attempt to quit. */
	::dux::dbgprint(U"dux :: Signal handler returned! Reset it!\n");
	::dux::sighandl(::dux::sig::abrt,::dux::dflsighandl); /* The signal handler has returned, and so we will attempt to set the default handler. */
	::dux::dbgprint(U"dux :: Raising SIGABRT!\n");
	::dux::raise(::dux::sig::abrt); /* Raise SIGABRT again to call the default signal handler. */
	::dux::dbgprint(U"dux :: Default signal handler returned! Trapping!\n");
	::dux::trap(); /* The default signal handler returned, so we will trap or never return. */
}
auto ::dux::abrt(::dux::str const & _msg) noexcept -> void {
	::dux::print(U"dux :: Aborting due to \"$\"!\n",_msg);
	::dux::abrt();
}
