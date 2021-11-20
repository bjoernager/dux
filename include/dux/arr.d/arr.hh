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

template<typename T> constexpr auto ::dux::arr<T>::alloc(::dux::usz const _num) -> void {
	if (this->isstatic()) [[unlikely]] {
		this->_isstatic = false;
	}
	else {
		::delete[] this->_ptr;
	}
	if (_num > 0x0uz) [[likely]] {
		this->_ptr = ::new T[_num]();
	}
	this->_sz  = _num;
}
template<typename T> template<::dux::cnvto<T> T0> constexpr auto ::dux::arr<T>::alloc(::dux::usz const _num,T0 const _val) -> void {
	this->alloc(_num);
	this->fill(this->begin(),this->end(),_val);
}
template<typename T> constexpr auto ::dux::arr<T>::app(::dux::arr<T> const & _oth) -> ::dux::arr<T> const & {
	this->realloc(this->sz() + _oth.sz());
	::dux::cpy(_oth.begin(),_oth.end(),this->begin() + this->sz() - _oth.sz());
	return *this;
}
template<typename T> template<::dux::cnvto<T> T0> constexpr auto ::dux::arr<T>::app(T0 const _val) -> ::dux::arr<T> const & {
	this->realloc(this->sz() + 0x1uz);
	(*this)[this->sz() - 0x1uz] = static_cast<T>(_val);
	return *this;
}
template<typename T> constexpr ::dux::arr<T>::arr(T const * const _begin,T const * const _end) {
	if constexpr (::dux::dbg) {
		if (_begin == nullptr || _end == nullptr) [[unlikely]] {
			throw ::dux::invalarg("Provided parameter has value of nullptr.");
		}
	}
	this->alloc(static_cast<::dux::usz>(_end - _begin) + 0x1uz);
	::dux::cpy(_begin,_end,this->begin());
}
template<typename T> constexpr ::dux::arr<T>::arr(::dux::usz const _num) {
	this->alloc(_num);
}
template<typename T> constexpr ::dux::arr<T>::arr(::dux::arr<T> const & _oth) {
	if (_oth.isstatic()) [[unlikely]] {
		this->_isstatic = true;
		this->_ptr      = _oth.begin();
		this->_sz       = _oth.sz();
		return;
	}
	this->alloc(_oth.sz());
	this->ins(_oth.begin(),_oth.end(),0x0uz);
}
template<typename T> constexpr ::dux::arr<T>::arr(::dux::arr<T> && _oth) {
	this->_isstatic = _oth.isstatic();
	this->_ptr      = _oth.begin();
	this->_sz       = _oth.sz();
	_oth._ptr       = nullptr;
	_oth._sz        = 0x0uz;
}
template<typename T> template<::dux::usz N> constexpr ::dux::arr<T>::arr(T const (&_arr)[N]) noexcept {
	this->_isstatic = true;
	this->_ptr      = _arr;
	this->_sz       = N;
}
template<typename T> template<::dux::cnvto<T> T0> constexpr ::dux::arr<T>::arr(::dux::usz const _num,T0 const _val) {
	this->alloc(_num,_val);
}
template<typename T> constexpr auto ::dux::arr<T>::begin() noexcept -> T * {
	return this->_ptr;
}
template<typename T> constexpr auto ::dux::arr<T>::begin() const noexcept -> T const * {
	return this->_ptr;
}
template<typename T> constexpr auto ::dux::arr<T>::cbegin() const noexcept -> T const * {
	return this->begin();
}
template<typename T> constexpr auto ::dux::arr<T>::cend() const noexcept -> T const * {
	return this->begin() + this->sz;
}
template<typename T> constexpr auto ::dux::arr<T>::del(::dux::usz const _pos) -> void {
	if constexpr (::dux::dbg) {
		if (_pos >= this->sz()) [[unlikely]] {
			throw ::dux::outofdomain("Position out of bounds!");
		}
	}
	if (this->sz() <= 0x1uz) [[unlikely]] {
		if (this->sz() == 0x0uz) {
			this->alloc(0x0uz);
			return;
		}
		return;
	}
	::dux::cpy(this->begin() + _pos + 0x1uz,this->end(),this->begin() + _pos);
	this->realloc(this->sz() - 0x1uz);
}
template<typename T> constexpr auto ::dux::arr<T>::end() noexcept -> T * {
	return this->begin() + this->sz();
}
template<typename T> constexpr auto ::dux::arr<T>::end() const noexcept -> T const * {
	return this->begin() + this->sz();
}
template<typename T> template<::dux::cnvto<T> T0> constexpr auto ::dux::arr<T>::fill(T0 const _val) -> void {
	this->fill(this->begin(),this->end(),_val);
}
template<typename T> template<::dux::cnvto<T> T0> constexpr auto ::dux::arr<T>::fill(T * const dux_restr _begin,T * const dux_restr _end,T0 const _val) -> void {
	if (this->sz() == 0x0uz) [[unlikely]] {
		return; /* slime incident */
	}
	if constexpr (::dux::dbg) {
		if (_begin < this->begin() || _end > this->end()) [[unlikely]] {
			throw ::dux::outofdomain("Beginning or end are out of this array's range.");
		}
	}
	if (this->isstatic()) [[unlikely]] {
		this->alloc(static_cast<::dux::usz>(_end - _begin) + 0x1uz);
	}
	::dux::fill(this->begin(),this->end(),_val);
}
template<typename T> constexpr auto ::dux::arr<T>::ins(T const * const _begin,T const * const _end,::dux::usz const _pos) -> ::dux::arr<T> const & {
	this->realloc(this->sz() + static_cast<::dux::usz>(_end - _begin) + 0x1uz);
	::dux::ins(_begin,_end,this->begin() + _pos);
	return *this;
}
template<typename T> constexpr auto ::dux::arr<T>::ins(::dux::arr<T> const & _oth,::dux::usz const _pos) -> ::dux::arr<T> const & {
	return this->ins(_oth.begin(),_oth.end(),_pos);
}
template<typename T> constexpr auto ::dux::arr<T>::isstatic() const noexcept -> bool {
	return this->_isstatic;
}
template<typename T> constexpr auto ::dux::arr<T>::operator = (::dux::arr<T> const & _oth) -> ::dux::arr<T> const & {
	this->~arr();
	if (_oth.isstatic()) [[unlikely]] {
		this->_isstatic = true;
		this->_ptr      = const_cast<T *>(_oth.begin());
		this->_sz       = _oth.sz();
	}
	else {
		this->alloc(_oth.sz());
		this->ins(_oth.begin(),_oth.end(),0x0uz);
	}
	return *this;
}
template<typename T> constexpr auto ::dux::arr<T>::operator [] (::dux::usz const _pos) -> T & {
	if constexpr (::dux::dbg) {
		if (_pos >= this->sz()) [[unlikely]] {
			throw ::dux::invalarg("Input parameter is out of range.");
		}
	}
	return this->begin()[_pos];
}
template<typename T> constexpr auto ::dux::arr<T>::operator [] (::dux::usz const _pos) const -> T const & {
	if constexpr (::dux::dbg) {
		if (_pos >= this->sz()) [[unlikely]] {
			throw ::dux::invalarg("Input parameter is out of range.");
		}
	}
	return this->begin()[_pos];
}
template<typename T> constexpr auto ::dux::arr<T>::realloc(::dux::usz const _num) -> void {
	if (this->sz() == 0x0uz) [[unlikely]] {
		return this->alloc(_num);
	}
	if (this->isstatic()) [[unlikely]] {
		this->_isstatic = false;
	}
	this->_ptr = ::dux::renew(this->begin(),this->sz(),_num);
	this->_sz  = _num;
}
template<typename T> constexpr auto ::dux::arr<T>::setraw(T const * const dux_restr _ptr,::dux::usz const _sz) noexcept -> void {
	if (!this->isstatic()) [[unlikely]] {
		::delete[] this->_ptr;
	}
	this->_ptr = const_cast<T *>(_ptr);
	this->_sz  = _sz;
}
template<typename T> constexpr auto ::dux::arr<T>::sub(::dux::usz const _pos,::dux::usz const _sz) const -> ::dux::arr<T> {
	auto const sz = [&]() {
		if (_sz == 0x0uz) {
			return this->sz() - _sz;
		}
		return _sz;
	}();
	::dux::arr<T> arr;
	if (this->isstatic()) [[unlikely]] {
		arr._sz  = sz;
		arr._ptr = const_cast<T *>(this->begin()) + _pos;
	}
	else {
		arr.alloc(sz);
		::dux::cpyn(this->begin(),sz,arr.begin());
	}
	return arr;
}
template<typename T> constexpr auto ::dux::arr<T>::sz() const noexcept -> ::dux::usz {
	return this->_sz;
}
template<typename T> constexpr ::dux::arr<T>::~arr<T>() noexcept {
	if (this->isstatic()) {
		return;
	}
	::delete[] this->_ptr;
}
