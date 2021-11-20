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

#include <signal.h>
#if defined(dux_os_linux)
#include <sys/syscall.h>
#include <unistd.h>
#else
#include <pthread.h>
#endif

#include "priv.hh"

auto ::dux::raise(::dux::sig const _sig) noexcept -> void {
	::dux::dbgprint(U"dux :: Raising signal #$!\n",static_cast<int>(_sig));
#if !defined(dux_os_posix)
	if (_sig == ::dux::sig::kill) {
		::dux::abrt();
	}
	if (_sig == ::dux::sig::trap) {
		::dux::trap();
	}
#endif
	auto const sig = ::dux::_sigtocsig(_sig);
#if defined(dux_os_linux)
	::dux::dbgprint(U"dux :: Killing process via syscall!\n");
	::syscall(__NR_kill,::syscall(__NR_getpid),sig);
#elif defined(dux_os_posix)
::dux::dbgprint(U"dux :: Killing thread!\n");
	::pthread_kill(::pthread_self(),sig);
#else
	::dux::dbgprint(U"dux :: Raising signal!\n");
	::raise(sig);
#endif
}
