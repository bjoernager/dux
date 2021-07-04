/*
	Copyright 2021 Gabriel Jensen

	This file is part of u8c.

	u8c is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

	u8c is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

	See the	GNU Affero General Public License for more details.

	You should have received a copy of the GNU Affero General Public License along with u8c.

	If not, see <https://www.gnu.org/licenses/>.
*/
# include <stdbool.h>
# include <stdlib.h>
# include <u8c/err.h>
# include <u8c/u16.h>
# include <uchar.h>
struct u8c_u16alloc_tuple u8c_u16alloc(size_t const _sz) {
	struct u8c_u16alloc_tuple ret = {
		.stat = false,
	};
	char16_t * arr = NULL;
	if((arr = calloc(sizeof *arr,_sz)) == NULL) {
		u8c_seterr(u8c_errtyp_badalloc,U"u8c_u16alloc: Unable to allocate resources (not enough memory?).");
		ret.stat = true;
		return ret;
	}
	ret.u16 = arr;
	return ret;
}