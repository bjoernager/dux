/*
	Copyright 2019-2023 Gabriel Jensen.

	This file is part of dux.
	dux is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
	dux is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
	You should have received a copy of the GNU Lesser General Public License along with dux. If not, see <https://www.gnu.org/licenses>.
*/

#include <dux/prv/dux.h>

#include <zp/mem.h>

#define set(_msg) (msg = (_msg),len = sizeof ((_msg))-0x1u)

zp_sizerr dux_errmsg(char * const restrict buf,dux_err const err) {
	char const* msg;
	zp_siz      len;

	switch (err) {
	case dux_err_oky:
		set("okay");
		break;
	case dux_err_err:
		set("generic error");
		break;
	case dux_err_badalc:
		set("bad memory allocation");
		break;
	case dux_err_badfil:
		set("bad file");
		break;
	case dux_err_badfmt:
		set("bad format specifier");
		break;
	case dux_err_badprv:
		set("bad privileges");
		break;
	case dux_err_badval:
		set("bad value");
		break;
	case dux_err_eof:
		set("end of file");
		break;
	case dux_err_exs:
		set("file already exists");
		break;
	case dux_err_io:
		set("input/output error");
		break;
	case dux_err_isdir:
		set("is directory");
		break;
	case dux_err_memlim:
		set("memory limit reached");
		break;
	case dux_err_nodir:
		set("no such directory");
		break;
	case dux_err_nofil:
		set("no such file or directory");
		break;
	case dux_err_redonl:
		set("file is read only");
		break;
	case dux_err_spclim:
		set("space limit reached");
		break;
	}

	if (buf != zp_nulptr) {zp_memcpy(buf,msg,len);}
	return len;
}
