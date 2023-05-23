/*
	Copyright 2019-2023 Gabriel Jensen.

	This file is part of dux.
	dux is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
	dux is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
	You should have received a copy of the GNU Lesser General Public License along with dux. If not, see <https://www.gnu.org/licenses>.
*/

#include <dux/prv/dux.h>

char const * dux_errmsg(dux_err const err) {
	switch (err) {
	case dux_err_oky:
		return "okay";
	case dux_err_err:
		return "error";
	case dux_err_badalc:
		return "bad memory allocation";
	case dux_err_badfil:
		return "bad file";
	case dux_err_badfmt:
		return "bad format specifier";
	case dux_err_badprv:
		return "bad privileges";
	case dux_err_badval:
		return "bad value";
	case dux_err_eof:
		return "end of file";
	case dux_err_exs:
		return "file already exists";
	case dux_err_isdir:
		return "is directory";
	case dux_err_nodir:
		return "no such directory";
	case dux_err_nofil:
		return "no such file or directory";
	case dux_err_redonl:
		return "file is read only";
	case dux_err_spclim:
		return "space limit reached";
	}
	zp_unrch();
}
