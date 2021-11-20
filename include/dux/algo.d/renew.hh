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

template<typename T> constexpr auto ::dux::renew(T * const dux_restr _ptr,::dux::usz const _sz,::dux::usz const _newsz) -> T * {
	T * const dux_restr ptr = ::new T[_newsz]();
	::dux::cpyn(_ptr,::dux::min(_sz,_newsz),ptr);
	::delete[] _ptr;
	return ptr;
}
