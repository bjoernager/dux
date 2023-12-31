/*
	Copyright 2019-2023 Gabriel Jensen.

	This file is part of dux.
	dux is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
	dux is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
	You should have received a copy of the GNU Lesser General Public License along with dux. If not, see <https://www.gnu.org/licenses>.
*/

#if !defined(dux_hdr_fs)
#define dux_hdr_fs

#include <dux/dux.h>

dux_prv_cdec

typedef zp_i01 dux_prm;

struct dux_det_dsc {
	bool _dsc;
};

#if zp_std_cxx
#define dux_kep (::dux_det_dsc {false,})
#define dux_dsc (::dux_det_dsc {true,})
#else
#define dux_kep ((struct dux_det_dsc) {._dsc = false,})
#define dux_dsc ((struct dux_det_dsc) {._dsc = true,})
#endif

typedef struct {
	zp_siz  siz;
	dux_prm prm;
	bool    isdir : 0x1;
	bool    isreg : 0x1;
} dux_pthinf;

zp_sizerr dux_curdir(char * buf);
zp_sizerr dux_homdir(char * buf);

dux_err dux_chgdir(char const* pth);

dux_err dux_setprm(char const*  pth,dux_prm     prm);
dux_err dux_sttpth(dux_pthinf * inf,char const* pth);

dux_err dux_crtdir(char const* pth,dux_prm prm);

dux_err dux_cpy(char const* newpth,char const* pth,dux_prm prm);
dux_err dux_mov(char const* newpth,char const* pth);
dux_err dux_rem(char const* pth);

dux_prv_cdecend

#endif
