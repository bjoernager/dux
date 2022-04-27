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

void dux_priv_cpy(void const * const restrict _in,dux_uwrd const _num,void * const restrict _out,dux_uwrd const _sz) {
# if dux_dbg
	dux_unlikely (_in == dux_nullptr || _out == dux_nullptr) {
		dux_seterr(dux_errcd_badaddr);
		return;
	}
# endif
	dux_uwrd const numbyte = _num * _sz;
# if dux_hasbuiltin(__builtin_memcpy) /* We would like to use this builtin, if available, as it may be optimised in a way which would be UB if we did it. */
	dux_ppmsg("Using __builtin_memcpy for dux_cpy.")
	__builtin_memcpy((void *)_out,(void *)_in,numbyte);
# else
	unsigned char const * const restrict in  = (unsigned char const *)_in;
	unsigned char * const restrict       out = (unsigned char *)_out;
	for (dux_uwrd n = dux_uwrdl(0x0);n < numbyte;++n) {
		*(unsigned char *)&out[n] = *(unsigned char const *)&in[n];
	}
# endif
}
