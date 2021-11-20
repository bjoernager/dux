/*
	Copyright 2021 Gabriel Jensen

	This file is part of dux.

	dux is free software:
	you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

	dux is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
	without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
	See the GNU Affero General Public License for more details.

	You should have received a copy of the GNU Affero General Public License along with dux.
	If not, see <https://www.gnu.org/licenses/>.
*/

#include <dux/io>

#include "priv.hh"

auto ::dux::_setsiginthandl() -> void {
	::dux::dbgprint(U"dux :: Setting the SIGINT signal handler!\n");
	if (!::dux::_inst.siginthandlset) {
		::dux::_inst.prevsiginthandl = ::dux::sighandl(::dux::sig::int_,::dux::_siginthandl);
		::dux::_inst.siginthandlset = true;
		return;
	}
	::dux::dbgprint(U"dux :: The SIGINT signal handler is already set!\n");
};
