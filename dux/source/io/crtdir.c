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
#include <sys/stat.h>
#include <sys/types.h>

extern int * __errno_location(void);

dux_err dux_crtdir(char const * const pth,zp_i01 const prm) {
	int const cod = (int)zp_syscal(__NR_mkdir,pth,(mode_t)prm);
	if (cod == -0x1) {
		switch (*__errno_location()) {
		default:
			return dux_err_err;
		case EACCES:
			return dux_err_badprv;
		case EEXIST:
			break;
		case EROFS:
			return dux_err_redonl;
		}
	}
	
	return dux_err_oky;
}
