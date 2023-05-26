/*
	Copyright 2019-2023 Gabriel Jensen.

	This file is part of dux.
	dux is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
	dux is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
	You should have received a copy of the GNU Lesser General Public License along with dux. If not, see <https://www.gnu.org/licenses>.
*/

#include <dux/prv/io.h>

#include <unistd.h>

static dux_fil dux_det_idfl = {
	.fd = STDIN_FILENO,
};

static dux_fil dux_det_odfl = {
	.fd = STDOUT_FILENO,
};

static dux_fil dux_det_log = {
	.fd = STDERR_FILENO,
};

dux_fil * dux_idfl = &dux_det_idfl;
dux_fil * dux_odfl = &dux_det_odfl;
dux_fil * dux_log  = &dux_det_log;
