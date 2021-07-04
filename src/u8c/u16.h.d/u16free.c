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
# include <stdint.h>
# include <stdlib.h>
# include <u8c/u16.h>
struct u8c_u16free_tuple u8c_u16free(char16_t const * const restrict _u16) {
	struct u8c_u16free_tuple ret = {
		.stat = false,
	};
	free((char16_t *)_u16);
	return ret;
}