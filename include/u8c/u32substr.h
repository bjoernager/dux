/*
	Copyright 2021 Gabriel Jensen

	This file is part of u8c.

	u8c is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

	u8c is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

	See the	GNU Affero General Public License for more details.

	You should have received a copy of the GNU Affero General Public License along with u8c.

	If not, see <https://www.gnu.org/licenses/>.
*/
/* UTF-32 sub-string */
# if !defined(luma_sym_u32substr)
# define luma_sym_u32substr
# include <stdbool.h>
# include <stddef.h>
# include <uchar.h>
extern bool u8c_u32substr(char32_t const * * const out,size_t const start,size_t const len,char32_t const * const in);
# endif
