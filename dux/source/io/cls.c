/*
	Copyright 2019-2023 Gabriel Jensen.

	This file is part of dux.
	dux is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
	dux is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
	You should have received a copy of the GNU Lesser General Public License along with dux. If not, see <https://www.gnu.org/licenses>.
*/

#include <dux/prv/io.h>

#include <errno.h>
#include <linux/unistd.h>
#include <stdlib.h>

extern int * __errno_location(void);

dux_err dux_cls(dux_fil * const restrict fil) {
	cls:;

	int const cd = (int)zp_syscal(__NR_close,fil->fd);
	zp_unlik (cd == -0x1) {
		switch (*__errno_location()) {
		default:
			goto fre;
		case EINTR:
			goto cls;
		}
	}

fre:;
	free(fil);

	return dux_err_oky;
}
