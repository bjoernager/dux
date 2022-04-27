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

void dux_priv_assfail(char const * const restrict _filenm,unsigned long const _ln,char const * const restrict _fn,char const * const restrict _msg,char const * const restrict _exprstr) {
	/* We will call dux_priv_dbglog directly, as we must print, even if debug mode is enabled. */
	dux_priv_dbglog("\n");
	dux_priv_dbglog("Assertion \x1B[38;2;225;61;61mfailed\x1B[0m");
	if (dux_streq(_msg,"")) {dux_priv_dbglog("!");}
	else {dux_priv_dbglog(": \x1B[3m%s\x1B[0m",_msg);}
	dux_priv_dbglog("\n");
	dux_priv_dbglog("  Expression (\x1B[38;2;61;225;169m%s\x1B[0m) does not evaluate to true!\n",_exprstr);
	dux_priv_dbglog("    ... at \x1B[38;2;225;169;61m\"%s\"\x1B[0m:\x1B[38;2;255;169;61m%li\x1B[0m\n",_filenm,_ln);
	dux_priv_dbglog("    ... in \x1B[38;2;169;225;61m%s\x1B[0m\n",_fn);
	dux_priv_dbglog("\n");
	dux_abrt();
}
