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

constexpr auto ::dux::cstrcmp(char const * const dux_restr _lstr,char const * const dux_restr _rstr) noexcept -> ::dux::sbyte {
	auto const maxn = ::dux::min(::dux::cstrlen(_lstr),::dux::cstrlen(_rstr));
	for (auto n = 0x0uz;n <= maxn;n += 0x1uz) {
		auto const lchr = _lstr[n];
		auto const rchr = _rstr[n];
		if (lchr != rchr) [[unlikely]] {
			if (lchr > rchr) {
				return ::dux::sbytev(-0x1);
			}
			if (lchr < rchr) {
				return ::dux::sbytev(0x1);
			}
		}
	}
	return ::dux::sbytev(0x0);
}
