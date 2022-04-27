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

/* TO-DO: Implement our own memory allocation routines (independent of C stdlib). */

dux_priv_begincdecls

dux_attr_useret void * dux_priv_alloc(dux_priv_uwrd sz, dux_priv_uwrd align);
                void   dux_priv_free( void *        ptr);

dux_priv_endcdecls
