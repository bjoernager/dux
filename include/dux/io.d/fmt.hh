/*
	Copyright 2021 Gabriel Jensen

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

constexpr auto ::dux::fmt(::dux::str const & _str) -> ::dux::str {
	if (auto const pos = _str.fnd(::dux::fmtchr);pos != ::dux::npos) {
		throw ::dux::fmterr("Format-specifier '$' was found, but no object to be formatted was provided.");
	}
	return _str;
}
template<typename T> constexpr auto ::dux::fmt(::dux::str const & _str,T const _fmt) -> ::dux::str {
	auto const pos = _str.fnd(::dux::fmtchr);
	if (pos == ::dux::npos) {
		throw ::dux::fmterr("Object to be formatted provided, but an equivalent format-specifier '$' was not found!");
	}
	auto str = _str;
	str.del(pos);
	str.ins(pos,::dux::fmter(_fmt));
	return str;
}
template<typename T,typename... Ts> constexpr auto ::dux::fmt(::dux::str const & _str,T const _fmt,Ts... args) -> ::dux::str {
	auto const pos = _str.fnd(::dux::fmtchr);
	if (pos == ::dux::npos) {
		throw ::dux::fmterr("Object to be formatted provided, but an equivalent format-specifier '$' was not found!");
	}
	auto       str = _str;
	str.del(pos);
	str.ins(pos,::dux::fmter(_fmt));
	return str + ::dux::fmt(_str.sub(pos + 0x1uz,0x0uz),args...);
}
