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

constexpr auto ::dux::cstrlen(char const * const dux_restr _str) noexcept -> ::dux::usz {
	auto sz = 0x0uz;
	for (::dux::usz n = 0x0uz;;n += 0x1uz) {
		if (_str[n] == '\u0000') [[unlikely]] {
			break;
		}
		sz += 0x1uz;
	}
	return sz;
}
