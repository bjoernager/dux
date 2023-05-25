/*
	Copyright 2019-2023 Gabriel Jensen.

	This file is part of dux.
	dux is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
	dux is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
	You should have received a copy of the GNU Lesser General Public License along with dux. If not, see <https://www.gnu.org/licenses>.
*/

#include <dux/prv/io.h>

#include <fcntl.h>
#include <linux/errno.h>
#include <linux/unistd.h>
#include <stdlib.h>

extern int * __errno_location(void);

dux_err dux_setprm(char const* const pth,dux_prm const prm) {
set:;
	int const cod = (int)zp_syscal(__NR_chmod,pth,(mode_t)prm);
	zp_unlik (cod == -0x1) {
		int const err = *__errno_location();

		zp_lik (err == EINTR) {goto set;}

		switch (err) {
		default:
			return dux_err_err;
		}
	}

	return dux_err_oky;
}
