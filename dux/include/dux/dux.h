/*
	Copyright 2019-2023 Gabriel Jensen.

	This file is part of dux.
	dux is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
	dux is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
	You should have received a copy of the GNU Lesser General Public License along with dux. If not, see <https://www.gnu.org/licenses>.
*/

#if !defined(dux_hdr_dux)
#define dux_hdr_dux

#include <zp/zp.h> // We always guarantee this header.

#if zp_std_cxx
#define dux_prv_cdec    extern "C" {
#define dux_prv_cdecend }
#else
#define dux_prv_cdec
#define dux_prv_cdecend
#endif

dux_prv_cdec

#define dux_api ((zp_i04)+0x0u)
#define dux_ext ((zp_i04)+0x0u)

typedef enum {
	dux_err_oky    = 0x0u,
	dux_err_err    = 0x1u,
	dux_err_badalc,
	dux_err_badfil,
	dux_err_badfmt,
	dux_err_badprm,
	dux_err_badval,
	dux_err_eof,
	dux_err_exs,
	dux_err_isdir,
	dux_err_nodir,
	dux_err_nofil,
	dux_err_redonl,
	dux_err_spclim,
} dux_err;

zp_noret void dux_prv_abr(char const * fil,long lin,char const * fun,char const * msg,...);
#define dux_abr(msg) (dux_prv_abr(__FILE__,__LINE__,__func__,(msg)))

zp_unseq char const * dux_errmsg(dux_err err);

dux_prv_cdecend

#endif
