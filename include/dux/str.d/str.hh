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

constexpr auto ::dux::str::begin() noexcept -> char32_t * {
	return this->_arr.begin();
}
constexpr auto ::dux::str::begin() const noexcept -> char32_t const * {
	return this->_arr.begin();
}
constexpr auto ::dux::str::cbegin() const noexcept -> char32_t const * {
	return this->_arr.cbegin();
}
constexpr auto ::dux::str::cend() const noexcept -> char32_t const * {
	return this->_arr.cbegin();
}
constexpr auto ::dux::str::del(::dux::usz const _pos) -> void {
	this->_arr.del(_pos);
}
constexpr auto ::dux::str::end() noexcept -> char32_t * {
	return this->_arr.end();
}
constexpr auto ::dux::str::end() const noexcept -> char32_t const * {
	return this->_arr.end();
}
constexpr auto ::dux::str::fnd(char32_t const _chr) const noexcept -> ::dux::usz {
	for (auto pos = 0x0uz;pos < this->len();pos += 0x1uz) {
		if (this->operator [] (pos) == _chr) [[unlikely]] {
			return pos;
		}
	}
	return ::dux::npos;
}
constexpr auto ::dux::str::ins(::dux::usz const _pos,::dux::str const & _oth) -> ::dux::str const & {
	this->_arr.ins(_oth._arr,_pos);
	return *this;
}
constexpr auto ::dux::str::len() const noexcept -> ::dux::usz {
	return this->_arr.sz();
}
constexpr auto ::dux::str::operator + (::dux::str const & _oth) const -> ::dux::str {
	auto str = *this;
	str._arr.app(_oth._arr);
	return str;
}
constexpr auto ::dux::str::operator = (::dux::str const & _oth) -> ::dux::str const & {
	this->_arr = _oth._arr;
	return *this;
}
constexpr auto ::dux::str::operator == (::dux::str const & _oth) const noexcept -> bool {
	if (this->len() != _oth.len()) {
		return false;
	}
	for (auto n = 0x0uz;n < this->len() && n < _oth.len();n += 0x1uz) {
		if ((*this)[n] != _oth[n]) {
			return false;
		}
	}
	return true;
}
constexpr auto ::dux::str::operator [] (::dux::usz const _pos) noexcept -> char32_t & {
	return this->_arr[_pos];
}
constexpr auto ::dux::str::operator [] (::dux::usz const _pos) const noexcept -> char32_t const & {
	return this->_arr[_pos];
}
constexpr ::dux::str::str(char32_t const _chr) {
	this->_arr.app(_chr);
}
constexpr ::dux::str::str(::dux::str const & _oth) {
	*this = _oth;
}
constexpr ::dux::str::str(::dux::str && _oth) {
	this->_arr.setraw(_oth._arr.begin(),_oth._arr.sz());
	_oth._arr.setraw(nullptr,0x0uz);
}
template<::dux::usz N> constexpr ::dux::str::str(char32_t const (& _strlit)[N]) noexcept {
	this->_arr = _strlit;
}
template<::dux::utf T> constexpr ::dux::str::str(T const _chr) {
	if constexpr (::dux::issame<T,char32_t>) {
		this->_arr.alloc(0x1uz);
		this->_arr[0x0uz] = _chr;
	}
}
template<::dux::utf T> constexpr ::dux::str::str(T const * const dux_restr _utf) {
	auto const sz = [&]() {
		for (auto n = 0x0uz;;n += 0x1uz) {
			if (_utf[n] == T{0x0}) {
				return n;
			}
		}
	}();
	this->_arr = ::dux::cnv<char32_t>(_utf,_utf + sz);
}
constexpr auto ::dux::str::sub(::dux::usz const _pos,::dux::usz const _len) const -> ::dux::str {
	::dux::str str;
	str._arr = this->_arr.sub(_pos,_len);
	return str;
}
constexpr auto ::dux::str::u8() const -> ::dux::arr<char8_t> {
	return ::dux::cnv<char8_t>(this->begin(),this->end());
}
