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

#if defined(dux_os_linux)
#include <sys/syscall.h>
#include <unistd.h>
#elif defined(dux_os_posix)
#include <stdlib.h>
#else
#include <cstdlib>
#endif

auto ::dux::qexit(::dux::stat const _stat) noexcept -> void {
#if defined(dux_os_linux)
	auto const stat = _stat == ::dux::stat::ok ? 0x0 : 0x1;
	::syscall(__NR_exit_group,stat);
	::syscall(__NR_exit,stat);
	::dux::trap();
#else
	auto const stat = _stat == ::dux::stat::ok ? EXIT_SUCCESS : EXIT_FAILURE;
#if defined(dux_os_posix)
	::_exit(stat);
	::dux::trap();
#else
	::std::_Exit(stat);
#endif
#endif
}
