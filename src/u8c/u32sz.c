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
# include <stddef.h>
# include <stdint.h>
# include <u8c/seterr.h>
# include <u8c/SIZE_C.h>
# include <u8c/u32sz.h>
uint_least8_t u8c_u32sz(size_t * const _sz,uint_least32_t * const _u32) {
	assert(_sz != NULL);
	assert(_u32 != NULL);
	for(register size_t n = SIZE_C(0x0);n <= SIZE_MAX;n += SIZE_C(0x1)) {
		if(_u32[n] == UINT32_C(0x0)) {
			*_sz = n + SIZE_C(0x1);
			return UINT8_C(0x0);
		}
	}
	u8c_seterr((uint_least32_t[]){UINT32_C(0x75),UINT32_C(0x38),UINT32_C(0x63),UINT32_C(0x5F),UINT32_C(0x75),UINT32_C(0x33),UINT32_C(0x32),UINT32_C(0x73),UINT32_C(0x7A),UINT32_C(0x3A),UINT32_C(0x20),UINT32_C(0x55),UINT32_C(0x6E),UINT32_C(0x74),UINT32_C(0x65),UINT32_C(0x72),UINT32_C(0x6D),UINT32_C(0x69),UINT32_C(0x6E),UINT32_C(0x61),UINT32_C(0x74),UINT32_C(0x65),UINT32_C(0x64),UINT32_C(0x20),UINT32_C(0x69),UINT32_C(0x6E),UINT32_C(0x70),UINT32_C(0x75),UINT32_C(0x74),UINT32_C(0x2E),UINT32_C(0x0),}); /* u8c_u32sz: Unterminated input. */
	return UINT8_C(0x1);
}
