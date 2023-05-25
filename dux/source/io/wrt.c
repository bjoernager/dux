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
#include <sys/types.h>

extern int * __errno_location(void);

dux_err dux_wrt(dux_fil * const restrict fil,void const* const restrict voiddat,zp_siz const num) {
	zp_unlik (num == 0x0u) {return dux_err_oky;}
	
	unsigned char const* dat = voiddat;

	for (size_t rem = num;rem != 0x0u;) {
		ssize_t const cod = (ssize_t)zp_syscal(__NR_write,fil->fd,dat,rem);
		zp_unlik (cod == -0x1) {
			switch (*__errno_location()) {
			default:
				return dux_err_err;
			case EBADF:
				return dux_err_badfil;
			case EFBIG:
				return dux_err_spclim;
			case EINTR:
				continue;
			case ENOSPC:
				return dux_err_spclim;
			}
		}

		dat += (size_t)cod;
		rem -= (size_t)cod;
	}

	return dux_err_oky;
}
