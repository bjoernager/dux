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

# include <dux/mem>
# include <dux/seq>

void * dux_priv_dup(void const * const restrict _in,dux_uwrd const _num,dux_uwrd const _sz) {
# if dux_dbg
	dux_unlikely (_in == dux_nullptr) {
		dux_seterr(dux_errcd_badaddr);
		return dux_nullptr;
	}
# endif
	dux_unlikely (_num == dux_uwrdl(0x0)) {return dux_nullptr;}
	dux_uwrd const numbyte = _num * _sz;
	void * newarr = dux_alloc(numbyte);
	dux_reseterr();
	dux_unlikely (dux_haserr()) {return dux_nullptr;}
	dux_cpy(_in,_num,newarr,_sz);
	return newarr;
}
