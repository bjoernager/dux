/*
	Copyright 2021 Gabriel Jensen

	This file is part of u8c.

	u8c is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

	u8c is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

	See the	GNU Affero General Public License for more details.

	You should have received a copy of the GNU Affero General Public License along with u8c.

	If not, see <https://www.gnu.org/licenses/>.
*/
# include "intern.h"
# include <assert.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <u8c/SIZE_C.h>
# include <u8c/err.h>
# include <u8c/fmt.h>
# include <u8c/u32.h>
# include <u8c/u8.h>
# include <uchar.h>
# if defined(u8c_bethrdsafe)
# include <threads.h>
# endif
bool u8c_vprint(FILE * _fp,char32_t const * const _msg,va_list _args) {
	assert(_msg != NULL);
	char32_t const * str0 = NULL;
	u8c_vfmt(NULL,&str0,_msg,_args);
	size_t                str1sz = SIZE_C(0x0);
	unsigned char const * str1   = NULL;
	u8c_u8enc(&str1sz,&str1,str0);
	assert(str1sz > SIZE_C(0x0));
# if defined(u8c_bethrdsafe)
	mtx_lock(&u8c_dat.outlock);
# endif
	{
		register size_t const val = fwrite(str1,sizeof(uint_least8_t),str1sz - SIZE_C(0x1),_fp);
# if defined(u8c_bethrdsafe)
		mtx_unlock(&u8c_dat.outlock);
# endif
		if(val < str1sz - SIZE_C(0x1)) {
			u8c_seterr(U"u8c_vprint: fwrite: Unable to write to stdout.",u8c_errtyp_badio);
			return true;
		}
	}
	u8c_u32free(&str0);
	u8c_u8free(&str1);
	return false;
}
