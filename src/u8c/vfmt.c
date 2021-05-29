/*
	Copyright 2021 Gabriel Jensen

	This file is part of u8c.

	u8c is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

	u8c is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

	See the	GNU Affero General Public License for more details.

	You should have received a copy of the GNU Affero General Public License along with u8c.

	If not, see <https://www.gnu.org/licenses/>.
*/
# include <stdarg.h>
# include <stdint.h>
# include <u8c/u32cp.h>
# include <u8c/vfmt.h>
uint_least8_t u8c_vfmt(size_t * const restrict _sz,uint_least32_t * restrict * const restrict _out,uint_least32_t * const restrict _in,va_list _args) {
	/* To be added. */
	return u8c_u32cp(_sz,_out,_in);
}
