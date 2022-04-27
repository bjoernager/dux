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

dux_priv_begincdecls

void   dux_priv_cpy( void const * in, dux_priv_uwrd num,void *         out,dux_priv_uwrd sz);
void * dux_priv_dup( void const * in, dux_priv_uwrd num,dux_priv_uwrd  sz);
void   dux_priv_fill(void *       ptr,dux_priv_uwrd num,dux_priv_uint8 val,dux_priv_uwrd sz);
void   dux_priv_plot(void const * ptr,dux_priv_uwrd num,dux_priv_uwrd  sz,void (*        fn)(void const * ptr));

dux_priv_endcdecls

