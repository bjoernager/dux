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

# if defined(dux_os_freebsd)
# include <sys/syscall.h>
# elif defined(dux_os_linux)
# include <linux/unistd.h>
# endif

dux_swrd dux_priv_posix_getrandom(void * const buf,dux_uwrd const buflen,unsigned int flags) {
# if defined(dux_os_freebsd)
	return (dux_swrd)dux_syscall(SYS_getrandom,buf,buflen,flags);
# elif defined(dux_os_linux)
	return (dux_swrd)dux_syscall(__NR_getrandom,buf,buflen,flags);
# endif
}
