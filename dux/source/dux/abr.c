/*
	Copyright 2019-2023 Gabriel Jensen.

	This file is part of dux.
	dux is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
	dux is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
	You should have received a copy of the GNU Lesser General Public License along with dux. If not, see <https://www.gnu.org/licenses>.
*/

#include <dux/prv/dux.h>

#include <linux/unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <zp/str.h>

void dux_abr(char const * const restrict msg) {
	zp_syscal(__NR_write,STDERR_FILENO,msg,zp_strlen(msg));

	zp_syscal(__NR_kill,(pid_t)zp_syscal(__NR_getpid),SIGABRT);
	zp_unrch();
}
