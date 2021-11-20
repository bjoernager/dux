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

template<::dux::arith T> constexpr auto ::dux::isprime(T const _val) noexcept -> bool {
	if (_val <= T{0x1}) [[unlikely]] {
		return false;
	}
	for (T iter = T{0x2};iter < _val / T{0x2} + T{0x1};iter += T{0x1}) {
		if (_val % iter == T{0x0}) [[unlikely]] {
			return false;
		}
	}
	return true;
}
