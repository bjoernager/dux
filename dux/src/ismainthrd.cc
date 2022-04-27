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

# include <dux/thrd>

auto ::dux::ismainthrd() noexcept -> bool {
# if defined(dux_os_linux)
	if (::dux_priv_posix_getpid() != static_cast<::pid_t>(::dux::syscall(__NR_gettid))) {return true;} /* Check if calling thread is also the main thread. Only thread exit and quick exit are allowed outside the main thread. */
# endif
	return false; /* I don't know how to check for this on other platforms. */
}

# pragma GCC diagnostic ignored "-Wmissing-declarations"

extern "C" auto dux_ismainthrd() -> bool {return ::dux::ismainthrd();}
