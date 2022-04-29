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

enum dux_priv_iotyp {
	dux_priv_iotyp_r,
	dux_priv_iotyp_rw,
	dux_priv_iotyp_w,
};

# define dux_priv_ioacs_uid  (dux_uint16l(04000))
# define dux_priv_ioacs_gid  (dux_uint16l(02000))
# define dux_priv_ioacs_stck (dux_uint16l(01000))
# define dux_priv_ioacs_usrr (dux_uint16l(0400))
# define dux_priv_ioacs_usrw (dux_uint16l(0200))
# define dux_priv_ioacs_usrx (dux_uint16l(0100))
# define dux_priv_ioacs_grpr (dux_uint16l(040))
# define dux_priv_ioacs_grpw (dux_uint16l(020))
# define dux_priv_ioacs_grpx (dux_uint16l(010))
# define dux_priv_ioacs_othr (dux_uint16l(04))
# define dux_priv_ioacs_othw (dux_uint16l(02))
# define dux_priv_ioacs_othx (dux_uint16l(01))
