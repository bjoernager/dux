/*
	Copyright 2021, 2022 Gabriel Jensen.

	This file is part of dux.

	dux is free software: you can redistribute it and/or modify it under the
	terms of the GNU Affero General Public License as published by the Free
	Software Foundation, either version 3 of the License, or (at your
	option) any later version.

	dux is distributed in the hope that it will be useful, but WITHOUT ANY
	WARRANTY; without even the implied warranty of MERCHANTABILITY or
	FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public
	License for more details.

	You should have received a copy of the GNU Affero General Public License
	along with dux. If not, see <https://www.gnu.org/licenses/>.
*/

dux_attr_const dux_attr_useret bool dux_isalnum( dux_chr32 chr);
dux_attr_const dux_attr_useret bool dux_isalpha( dux_chr32 chr);
dux_attr_const dux_attr_useret bool dux_iscntrl( dux_chr32 chr);
dux_attr_const dux_attr_useret bool dux_isdigit( dux_chr32 chr);
dux_attr_const dux_attr_useret bool dux_islower( dux_chr32 chr);
dux_attr_const dux_attr_useret bool dux_ispunct( dux_chr32 chr);
dux_attr_const dux_attr_useret bool dux_isspace( dux_chr32 chr);
dux_attr_const dux_attr_useret bool dux_issurro( dux_chr32 chr);
dux_attr_const dux_attr_useret bool dux_isupper( dux_chr32 chr);
dux_attr_const dux_attr_useret bool dux_isxdigit(dux_chr32 chr);

dux_attr_const dux_attr_useret char const * dux_uniblk(dux_chr32 chr);
dux_attr_const dux_attr_useret char const * dux_uninm( dux_chr32 chr);

dux_attr_useret dux_chr32 const * dux_u16tou32(dux_chr16 const * u16);
dux_attr_useret dux_chr8  const * dux_u16tou8( dux_chr16 const * u16);
dux_attr_useret dux_chr16 const * dux_u32tou16(dux_chr32 const * u32);
dux_attr_useret dux_chr8  const * dux_u32tou8( dux_chr32 const * u32);
dux_attr_useret dux_chr16 const * dux_u8tou16( dux_chr8  const * u8);
dux_attr_useret dux_chr32 const * dux_u8tou32( dux_chr8  const * u8);

dux_attr_useret dux_uwrd       dux_fndchr(char const * str, int          chr);
dux_attr_useret dux_uwrd       dux_fndstr(char const * str, char const * substr);
dux_attr_useret dux_sint8      dux_strcmp(char const * lstr,char const * rstr);
                void           dux_strcpy(char const * src, char *       dest);
dux_attr_useret struct dux_str dux_strdup(char const * str);
dux_attr_useret bool           dux_streq(char const * lstr,char const * rstr);
dux_attr_useret dux_uwrd       dux_strlen(char const * lstr);
