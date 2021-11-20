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

template<typename T> constexpr auto ::dux::opt<T>::operator * () const -> T const & {
	if (!*this) [[unlikely]] {
		throw ::dux::badoptacs();
	}
	return this->_val;
}
template<typename T> constexpr auto ::dux::opt<T>::operator -> () const -> T const * {
	if (!*this) [[unlikely]] {
		throw ::dux::badoptacs();
	}
	return &**this;
}
template<typename T> constexpr auto ::dux::opt<T>::operator = (::dux::opt<T> const & _oth) -> ::dux::opt<T> const & {
	if (!_oth) {
		this->reset();
		return *this;
	}
	this->_has = true;
	this->_val = *_oth;
	return *this;
}
template<typename T> constexpr ::dux::opt<T>::opt(T const & _val) noexcept {
	this->_has = true;
	this->_val = _val;
}
template<typename T> constexpr ::dux::opt<T>::opt(::dux::opt<T> const & _oth) noexcept {
	this->operator = (_oth);
}
template<typename T> constexpr auto ::dux::opt<T>::set(T const & _val) noexcept {
	this->_val = _val;
	this->_has = true;
}
template<typename T> constexpr auto ::dux::opt<T>::reset() noexcept -> void {
	this->_has = false;
	::new (&this->_val) T; /* Placement new: used for "uninitialising" a variable (I think). */
}
