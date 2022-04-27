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

# include <dux/priv>

# include <dux/str>

void dux_priv_dbgunreach(char const * const restrict _file,long const _line) {
	dux_dbglog("dux :: Unreachable point reached");
	if (!dux_streq(_file,"") && _line != 0x0l) {
		dux_dbglog(" at \"%s\":%li",_file,_line);
	}
	dux_dbglog("!\n");
	dux_trap();
}
