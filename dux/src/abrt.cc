/*
	Copyright 2021, 2022 Gabriel Jensen.

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

# include <dux/priv>

# include <atomic>
# include <dux/sig>
# include <dux/thrd>

auto ::dux::abrt() noexcept -> void {
	static ::std::atomic_flag lock {ATOMIC_FLAG_INIT};
	while (lock.test_and_set()) {} /* We make sure we don't abort from multiple threads. */
	::dux::dbglog("dux :: abrt :: Aborting!\n");
	if (::dux::haserr()) {::dux::dbglog("dux :: abrt :: Last error: %s\n",::dux::errcdnm(::dux::geterr()));}
	::dux::setsighandl(::dux::sig::abrt,::dux::sighandl::dfl());
	::dux::raise(::dux::sig::abrt); /* Raise SIGABRT to call the default signal handler. */
	::dux::trap(); /* The default signal handler returned, so we will trap as we can't return. */
}

# pragma GCC diagnostic ignored "-Wmissing-declarations"

extern "C" dux_attr_cold auto dux_abrt() -> void {::dux::abrt();}
