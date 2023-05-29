/*
	Copyright 2019-2023 Gabriel Jensen.

	This file is part of dux.
	dux is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
	dux is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
	You should have received a copy of the GNU Lesser General Public License along with dux. If not, see <https://www.gnu.org/licenses>.
*/

#include <dux/prv/io.h>

dux::fil::fil() noexcept {
	this->_cfil = nullptr;
}

dux::fil::fil(char const* pth) noexcept {this->opn(pth);}

dux::fil::~fil() noexcept {this->cls();}

auto dux::fil::opn(char const* pth) noexcept -> ::dux::err {this->_cfil = ::dux_opn(pth);}

auto dux::fil::cls() noexcept -> void {::dux_cls(this->_cls);}

auto dux::fil::wrt(void const) noexcept -> void {::dux_cls(this->_cls);}
