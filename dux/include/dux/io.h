/*
	Copyright 2019-2023 Gabriel Jensen.

	This file is part of dux.
	dux is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
	dux is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
	You should have received a copy of the GNU Lesser General Public License along with dux. If not, see <https://www.gnu.org/licenses>.
*/

#if !defined(dux_hdr_io)
#define dux_hdr_io

#include <dux/fs.h>

dux_prv_cdec

struct dux_prv_fil;
typedef struct dux_prv_fil dux_fil;

extern dux_fil * dux_dfli;
extern dux_fil * dux_dflo;
extern dux_fil * dux_log;

dux_err dux_crt(  dux_fil * * fil,char const* pth,dux_prm prm);
dux_err dux_opn(  dux_fil * * fil,char const* pth);
dux_err dux_opnrw(dux_fil * * fil,char const* pth,struct dux_prv_dsc);

dux_err dux_cls(dux_fil * fil);

dux_err dux_wrt(   dux_fil * fil,void const* dat,zp_siz num);
dux_err dux_wrtstr(dux_fil * fil,char const* str);
dux_err dux_red(   void *    buf,dux_fil *   fil,zp_siz num,zp_siz * numred);

dux_prv_cdecend

#endif
