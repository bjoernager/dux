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
#include <sys/sendfile.h>
#include <sys/types.h>

extern int * __errno_location(void);

dux_err dux_cpy(char const* const newpth,char const* const pth,dux_prm const prm) {
	dux_pthinf inf;
	dux_err const err = dux_sttpth(&inf,pth);
	zp_unlik (err != dux_err_oky) {return err;}

	int const fd = (int)zp_syscal(__NR_openat,AT_FDCWD,pth,O_RDONLY,(mode_t)0x0);

	int const newfd = (int)zp_syscal(__NR_openat,AT_FDCWD,newpth,O_CREAT|O_TRUNC|O_WRONLY,(mode_t)prm);

	ssize_t const numcpy = (ssize_t)zp_syscal(__NR_sendfile,newfd,fd,(off_t *)zp_nulptr,inf.siz);
	zp_unlik (numcpy == -0x1) {
		switch (*__errno_location()) {
		default:
			return dux_err_err;
		case EIO:
			return dux_err_io;
		case ENOMEM:
			return dux_err_memlim;
		}
	}

	return dux_err_oky;
}
