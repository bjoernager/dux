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

constexpr auto ::dux::isdigit(char32_t const _chr) -> bool {
	if(_chr > ::dux::unimax) [[unlikely]] {
		throw ::dux::outofdomain("Unicode codepoint too big!");
	}
	switch(_chr) {
	[[likely]] default:
		return false;
	case U'\u0030':  /* DIGIT ZERO */
		[[fallthrough]];
	case U'\u0031':  /* DIGIT ONE */
		[[fallthrough]];
	case U'\u0032':  /* DIGIT TWO */
		[[fallthrough]];
	case U'\u0033':  /* DIGIT THREE */
		[[fallthrough]];
	case U'\u0034':  /* DIGIT FOUR */
		[[fallthrough]];
	case U'\u0035':  /* DIGIT FIVE */
		[[fallthrough]];
	case U'\u0036':  /* DIGIT SIX */
		[[fallthrough]];
	case U'\u0037':  /* DIGIT SEVEN */
		[[fallthrough]];
	case U'\u0038':  /* DIGIT EIGHT */
		[[fallthrough]];
	case U'\u0039':  /* DIGIT NINE */
		[[fallthrough]];
	case U'\u218A': /* TURNED DIGIT TWO */
		[[fallthrough]];
	case U'\u218B': /* TURNED DIGIT THREE */
		return true;
	}
}