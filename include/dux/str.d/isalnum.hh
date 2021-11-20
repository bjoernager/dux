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

constexpr auto ::dux::isalpha(char32_t const _chr) -> bool {
	if(_chr > ::dux::unimax) [[unlikely]] {
		throw ::dux::outofdomain("Unicode codepoint too big!");
	}
	if(::dux::islower(_chr) || ::dux::isupper(_chr)) [[unlikely]] {
		return true;
	}
	switch(_chr) {
	[[likely]] default:
		return false;
	case U'\u0297': /* LATIN LETTER GLOTTAL STOP */
		[[fallthrough]];
	case U'\u16A0': /* RUNIC LETTER FEHU FEOH FE F */
		[[fallthrough]];
	case U'\u16A1': /* RUNIC LETTER FEHU FEOH FE F */
		[[fallthrough]];
	case U'\u16A2': /* RUNIC LETTER FEHU FEOH FE F */
		[[fallthrough]];
	case U'\u16A3': /* RUNIC LETTER FEHU FEOH FE F */
		[[fallthrough]];
	case U'\u16A4': /* RUNIC LETTER FEHU FEOH FE F */
		[[fallthrough]];
	case U'\u16A5': /* RUNIC LETTER FEHU FEOH FE F */
		[[fallthrough]];
	case U'\u16A6': /* RUNIC LETTER FEHU FEOH FE F */
		[[fallthrough]];
	case U'\u16A7': /* RUNIC LETTER FEHU FEOH FE F */
		[[fallthrough]];
	case U'\u16A8': /* RUNIC LETTER FEHU FEOH FE F */
		[[fallthrough]];
	case U'\u16A9': /* RUNIC LETTER FEHU FEOH FE F */
		[[fallthrough]];
	case U'\u16AA': /* RUNIC LETTER FEHU FEOH FE F */
		[[fallthrough]];
	case U'\u16AB': /* RUNIC LETTER FEHU FEOH FE F */
		[[fallthrough]];
	case U'\u16AC': /* RUNIC LETTER FEHU FEOH FE F */
		[[fallthrough]];
	case U'\u16AD': /* RUNIC LETTER FEHU FEOH FE F */
		[[fallthrough]];
	case U'\u16AE': /* RUNIC LETTER FEHU FEOH FE F */
		[[fallthrough]];
	case U'\u16AF': /* RUNIC LETTER FEHU FEOH FE F */
		[[fallthrough]];
	case U'\u16B0': /* RUNIC LETTER FEHU FEOH FE F */
		[[fallthrough]];
	case U'\u16B1': /* RUNIC LETTER FEHU FEOH FE F */
		[[fallthrough]];
	case U'\u16B2': /* RUNIC LETTER FEHU FEOH FE F */
		[[fallthrough]];
	case U'\u16B3': /* RUNIC LETTER FEHU FEOH FE F */
		[[fallthrough]];
	case U'\u16B4': /* RUNIC LETTER FEHU FEOH FE F */
		[[fallthrough]];
	case U'\u16B5': /* RUNIC LETTER FEHU FEOH FE F */
		[[fallthrough]];
	case U'\u16B6': /* RUNIC LETTER FEHU FEOH FE F */
		[[fallthrough]];
	case U'\u16B7': /* RUNIC LETTER FEHU FEOH FE F */
		[[fallthrough]];
	case U'\u16B8': /* RUNIC LETTER FEHU FEOH FE F */
		[[fallthrough]];
	case U'\u16B9': /* RUNIC LETTER FEHU FEOH FE F */
		[[fallthrough]];
	case U'\u16BA': /* RUNIC LETTER FEHU FEOH FE F */
		[[fallthrough]];
	case U'\u16BB': /* RUNIC LETTER FEHU FEOH FE F */
		[[fallthrough]];
	case U'\u16BC': /* RUNIC LETTER FEHU FEOH FE F */
		[[fallthrough]];
	case U'\u16BD': /* RUNIC LETTER FEHU FEOH FE F */
		[[fallthrough]];
	case U'\u16BE': /* RUNIC LETTER FEHU FEOH FE F */
		[[fallthrough]];
	case U'\u16BF': /* RUNIC LETTER FEHU FEOH FE F */
		[[fallthrough]];
	case U'\u16C0': /* RUNIC LETTER FEHU FEOH FE F */
		[[fallthrough]];
	case U'\u16C1': /* RUNIC LETTER FEHU FEOH FE F */
		[[fallthrough]];
	case U'\u16C2': /* RUNIC LETTER FEHU FEOH FE F */
		[[fallthrough]];
	case U'\u16C3': /* RUNIC LETTER FEHU FEOH FE F */
		[[fallthrough]];
	case U'\u16C4': /* RUNIC LETTER FEHU FEOH FE F */
		[[fallthrough]];
	case U'\u16C5': /* RUNIC LETTER FEHU FEOH FE F */
		[[fallthrough]];
	case U'\u16C6': /* RUNIC LETTER FEHU FEOH FE F */
		[[fallthrough]];
	case U'\u16C7': /* RUNIC LETTER FEHU FEOH FE F */
		[[fallthrough]];
	case U'\u16C8': /* RUNIC LETTER FEHU FEOH FE F */
		[[fallthrough]];
	case U'\u16C9': /* RUNIC LETTER FEHU FEOH FE F */
		[[fallthrough]];
	case U'\u16CA': /* RUNIC LETTER FEHU FEOH FE F */
		[[fallthrough]];
	case U'\u16CB': /* RUNIC LETTER FEHU FEOH FE F */
		[[fallthrough]];
	case U'\u16CC': /* RUNIC LETTER FEHU FEOH FE F */
		[[fallthrough]];
	case U'\u16CD': /* RUNIC LETTER FEHU FEOH FE F */
		[[fallthrough]];
	case U'\u16CE': /* RUNIC LETTER FEHU FEOH FE F */
		[[fallthrough]];
	case U'\u16CF': /* RUNIC LETTER FEHU FEOH FE F */
		[[fallthrough]];
	case U'\u16D0': /* RUNIC LETTER FEHU FEOH FE F */
		[[fallthrough]];
	case U'\u16D1': /* RUNIC LETTER FEHU FEOH FE F */
		[[fallthrough]];
	case U'\u16D2': /* RUNIC LETTER FEHU FEOH FE F */
		[[fallthrough]];
	case U'\u16D3': /* RUNIC LETTER FEHU FEOH FE F */
		[[fallthrough]];
	case U'\u16D4': /* RUNIC LETTER FEHU FEOH FE F */
		[[fallthrough]];
	case U'\u16D5': /* RUNIC LETTER FEHU FEOH FE F */
		[[fallthrough]];
	case U'\u16D6': /* RUNIC LETTER FEHU FEOH FE F */
		[[fallthrough]];
	case U'\u16D7': /* RUNIC LETTER FEHU FEOH FE F */
		[[fallthrough]];
	case U'\u16D8': /* RUNIC LETTER FEHU FEOH FE F */
		[[fallthrough]];
	case U'\u16D9': /* RUNIC LETTER FEHU FEOH FE F */
		[[fallthrough]];
	case U'\u16DA': /* RUNIC LETTER FEHU FEOH FE F */
		[[fallthrough]];
	case U'\u16DB': /* RUNIC LETTER FEHU FEOH FE F */
		[[fallthrough]];
	case U'\u16DC': /* RUNIC LETTER FEHU FEOH FE F */
		[[fallthrough]];
	case U'\u16DD': /* RUNIC LETTER FEHU FEOH FE F */
		[[fallthrough]];
	case U'\u16DE': /* RUNIC LETTER FEHU FEOH FE F */
		[[fallthrough]];
	case U'\u16DF': /* RUNIC LETTER FEHU FEOH FE F */
		[[fallthrough]];
	case U'\u16E0': /* RUNIC LETTER FEHU FEOH FE F */
		[[fallthrough]];
	case U'\u16E1': /* RUNIC LETTER FEHU FEOH FE F */
		[[fallthrough]];
	case U'\u16E2': /* RUNIC LETTER FEHU FEOH FE F */
		[[fallthrough]];
	case U'\u16E3': /* RUNIC LETTER FEHU FEOH FE F */
		[[fallthrough]];
	case U'\u16E4': /* RUNIC LETTER FEHU FEOH FE F */
		[[fallthrough]];
	case U'\u16E5': /* RUNIC LETTER FEHU FEOH FE F */
		[[fallthrough]];
	case U'\u16E6': /* RUNIC LETTER FEHU FEOH FE F */
		[[fallthrough]];
	case U'\u16E7': /* RUNIC LETTER FEHU FEOH FE F */
		[[fallthrough]];
	case U'\u16E8': /* RUNIC LETTER FEHU FEOH FE F */
		[[fallthrough]];
	case U'\u16E9': /* RUNIC LETTER FEHU FEOH FE F */
		[[fallthrough]];
	case U'\u16EA': /* RUNIC LETTER FEHU FEOH FE F */
		return true;
	}
}
