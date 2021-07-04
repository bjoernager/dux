/*
	Copyright 2021 Gabriel Jensen

	This file is part of u8c.

	u8c is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

	u8c is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

	See the	GNU Affero General Public License for more details.

	You should have received a copy of the GNU Affero General Public License along with u8c.

	If not, see <https://www.gnu.org/licenses/>.
*/
# if !defined(__STDC_UTF_32__)
# error UTF-32 is required.
# endif
# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>
# include <u8c/SIZE_C.h>
# include <u8c/err.h>
# include <u8c/intern.h>
# include <u8c/main.h>
# include <u8c/str.h>
# if defined(u8c_bethrdsafe)
# include <threads.h>
# endif
struct u8c_init_tuple u8c_init() {
	struct u8c_init_tuple ret = {
		.stat = false,
	};
	/* Initialise mutexes: */
# if defined(u8c_bethrdsafe)
	if(mtx_init(&u8c_dat.errhandlslock,mtx_plain) == thrd_error) {
		ret.stat = true;
		return ret;
	}
	if(mtx_init(&u8c_dat.errlock,mtx_plain) == thrd_error) {
		ret.stat = true;
		return ret;
	}
	if(mtx_init(&u8c_dat.fmtlock,mtx_plain) == thrd_error) {
		ret.stat = true;
		return ret;
	}
	if(mtx_init(&u8c_dat.outlock,mtx_plain) == thrd_error) {
		ret.stat = true;
		return ret;
	}
# endif
	/* Set default error message: */
	u8c_dat.err = NULL;
	u8c_seterr(u8c_errtyp_deferr,U"");
	/* Initialise error handler array: */
	for(register size_t n = SIZE_C(0x0);n < u8c_errtyp_all;n += SIZE_C(0x1)) {
		u8c_dat.errhandls[n] = NULL;
	}
	/* Set status: */
	u8c_dat.stat = UINT8_C(0x1);
	return ret;
}
