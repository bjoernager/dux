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

#include <dux/sys>
#if defined(dux_os_posix)
#include <unistd.h>
#if defined(dux_os_linux)
#include <sys/syscall.h>
#else
#include <time.h>
#endif
#endif

auto ::dux::sleep(::dux::uint64 const _sec,::dux::uint64 const _nsecx,::dux::uint64 const _nsecy) noexcept -> void {
#if defined(dux_os_posix)
#if defined(dux_os_linux)
	class {
	public:
		::dux::uint64 tv_sec;
		long        tv_nsec;
	} timespec;
#else
	::timespec timespec;
#endif
	timespec.tv_sec  = _sec;
	timespec.tv_nsec = static_cast<long>(static_cast<float>(_nsecx) / static_cast<float>(_nsecy) * 0x3B9ACA00p0);
#if defined(dux_os_linux)
	::syscall(__NR_nanosleep,&timespec,&timespec);
#else
	::nanosleep(&timespec,&timespec);
#endif
#endif
}
