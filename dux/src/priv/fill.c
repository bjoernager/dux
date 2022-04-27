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

# include <dux/seq>

void dux_priv_fill(void * const restrict _ptr,dux_uwrd const _num,dux_uint8 const _val,dux_uwrd const _sz) {
# if dux_dbg
	dux_unlikely (_ptr == dux_nullptr) {
		dux_seterr(dux_errcd_badaddr);
		return;
	}
	dux_unlikely (_sz == dux_uwrdl(0x0)) {
		dux_seterr(dux_errcd_illsz);
		return;
	}
# endif
	dux_unlikely (_num == dux_uwrdl(0x0)) {return;}
	dux_uwrd const numbyte = _num * _sz;
# if dux_hasbuiltin(__builtin_memset)
	dux_ppmsg("Using __builtin_memset for dux_fill.")
	__builtin_memset(_ptr,_val,numbyte);
# else
	dux_uint8 * const restrict ptr = (dux_uint8 *)_ptr;
	for (dux_uwrd n = dux_uwrdl(0x0);n < numbyte;++n) {
		ptr[n] = _val;
	}
# endif
}
