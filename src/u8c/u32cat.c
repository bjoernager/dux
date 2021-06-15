/*
	Copyright 2021 Gabriel Jensen

	This file is part of u8c.

	u8c is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

	u8c is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

	See the	GNU Affero General Public License for more details.

	You should have received a copy of the GNU Affero General Public License along with u8c.

	If not, see <https://www.gnu.org/licenses/>.
*/
# include <assert.h>
# include <stdbool.h>
# include <stdlib.h>
# include <u8c/SIZE_C.h>
# include <u8c/seterr.h>
# include <u8c/u32alloc.h>
# include <u8c/u32cat.h>
# include <u8c/u32cp.h>
# include <u8c/u32free.h>
# include <u8c/u32sz.h>
# include <uchar.h>
bool u8c_u32cat(size_t * const _sz,char32_t const * * const _out,char32_t const * const _lstr,char32_t const * const _rstr) {
	assert(_out != NULL);
	assert(_lstr != NULL);
	assert(_rstr != NULL);
	size_t sz  = SIZE_C(0x0);
	size_t lsz = SIZE_C(0x0);
	size_t rsz = SIZE_C(0x0);
	u8c_u32sz(&lsz,_lstr);
	u8c_u32sz(&rsz,_rstr);
	sz = lsz + rsz - SIZE_C(0x1);
	if(_sz != NULL) {
		*_sz = sz;
	}
	char32_t * out = NULL;
	if(u8c_u32alloc(&out,sz + SIZE_C(0x1))) {
		return false;
	}
	for(register size_t n = SIZE_C(0x0);n < lsz - SIZE_C(0x1);n += SIZE_C(0x1)) {
		out[n] = _lstr[n];
	}
	for(register size_t n = SIZE_C(0x0);n < rsz;n += SIZE_C(0x1)) {
		out[n + lsz - SIZE_C(0x1)] = _rstr[n];
	}
	u8c_u32free(_out);
	*_out = out;
	return false;
}