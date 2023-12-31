/*
	Copyright 2019-2023 Gabriel Jensen.

	This file is part of dux.
	dux is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
	dux is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
	You should have received a copy of the GNU Lesser General Public License along with dux. If not, see <https://www.gnu.org/licenses>.
*/

#if !defined(dux_hdr_prv_io)
#define dux_hdr_prv_io

#include <dux/io.h>

#if zp_std_cxx
#include <dux/io>
#endif

dux_prv_cdec

struct dux_det_fil {
	int fd;
};

dux_prv_cdecend

#endif
