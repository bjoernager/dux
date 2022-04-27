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

# include <dux/str>

::dux::mainparams::mainparams() noexcept {this->_alloc = false;}

::dux::mainparams::~mainparams() noexcept {if (this->_alloc) {::dux::free(this->_params);}}

auto ::dux::mainparams::fromstd(int const argc,char const * const * const argv) noexcept -> void {
	this->~mainparams();
	if (argc == 0x0) [[unlikely]] {
		this->_params = nullptr;
		this->_num    = dux_uwrdl(0x0);
		return;
	}
	this->_num    = {static_cast<::dux::uwrd>(argc)};
	this->_params = ::dux::alloc<::dux::str>(this->_num);
	if (::dux::geterr() != ::dux::errcd::noerr) [[unlikely]] {return;}
	this->_alloc = true;
	for (auto n {dux_uwrdl(0x0)};n < this->_num;++n) {
		auto & param     {this->_params[n]};
		       param.ptr = argv[n];
		       param.sz  = ::dux::strlen(param.ptr);
	}
}

auto ::dux::mainparams::num() const noexcept -> ::dux::uwrd {return this->_num;}

auto ::dux::mainparams::param(::dux::uwrd const _n) const noexcept -> ::dux::str {
	if (_n >= _num) [[unlikely]] {
		::dux::str str;
		           str.ptr = nullptr;
		           str.sz  = dux_uwrdl(0x0);
		::dux::seterr(::dux::errcd::outofrange);
		return str;
	}
	return this->_params[_n];
}
