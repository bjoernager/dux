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

# include <dux/time>

# include <time.h>
# if defined(dux_os_freebsd)
# include <sys/syscall.h>
# elif defined(dux_os_linux)
# include <linux/unistd.h>
# endif

static_assert(sizeof (::time_t) * dux_bytesz >= dux_uwrdl(0x40),"The size of the system type (time_t) must be eqaul to or larger than our replacement type's size.");

auto ::dux::gettime() noexcept -> ::dux::sint64 {
	struct timespec timespec {};
	::dux_priv_posix_clock_gettime(CLOCK_REALTIME,&timespec);
	return static_cast<::dux::sint64>(timespec.tv_sec);
}

# pragma GCC diagnostic ignored "-Wmissing-declarations"

extern "C" auto dux_gettime() -> ::dux::sint64 {return ::dux::gettime();}
