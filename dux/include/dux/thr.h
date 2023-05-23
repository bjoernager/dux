/*
	Copyright 2019-2023 Gabriel Jensen.

	This file is part of dux.
	dux is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
	dux is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
	You should have received a copy of the GNU Lesser General Public License along with dux. If not, see <https://www.gnu.org/licenses>.
*/

#if !defined(dux_hdr_thr)
#define dux_hdr_thr

#include <dux/dux.h>

dux_prv_cdec

struct dux_prv_thr;
typedef struct dux_prv_thr dux_thr;

zp_noret dux_err dux_exi(void * res);

dux_err dux_slp(zp_f04 sec);

dux_err dux_crtthr(dux_thr * * thr);
dux_err dux_srtthr(dux_thr *   thr,void * (* srt)(dux_thr *,void *),void *);
dux_err dux_joithr(dux_thr *   thr,void * *  res);

dux_prv_cdecend

#endif
