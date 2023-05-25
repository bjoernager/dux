/*
	Copyright 2019-2023 Gabriel Jensen.

	This file is part of dux.
	dux is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
	dux is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
	You should have received a copy of the GNU Lesser General Public License along with dux. If not, see <https://www.gnu.org/licenses>.
*/

#include <dux/prv/dux.h>

#include <zp/mem.h>
#include <zp/str.h>

extern char * * __environ;

zp_sizerr dux_envvar(char * const restrict buf,char const* const restrict nam) {
	zp_unlik (*nam == '\x00') {return -0x1;}

	char * * env = __environ;
	for (char * var = *env++;var != zp_nulptr;var = *env++) {
		char * const equpos = zp_strsrh(var,'=');

		char *       pos    = var;
		char const* nampos = nam;
		for (;pos != equpos;) {
			zp_lik (*pos++ != *nampos++) {goto nxt;}
		}

		char * const val    = equpos+0x1u;
		zp_siz const valsiz = zp_strlen(val)+0x1u;

		if (buf != zp_nulptr) {zp_memcpy(buf,val,valsiz);}
		
		return valsiz;

	nxt:;
	}

	return -0x1;
}
