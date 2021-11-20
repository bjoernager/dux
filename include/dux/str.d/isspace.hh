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

constexpr auto ::dux::isspace(char32_t const _chr) -> bool {
	if(_chr > ::dux::unimax) [[unlikely]] {
		throw ::dux::outofdomain("Unicode codepoint too big!");
	}
	switch(_chr) {
	[[likely]] default:
		return false;
	case U'\u0009': /* HORIZONTAL TABULATION */
		[[fallthrough]];
	case U'\u000A': /* NEW LINE */
		[[fallthrough]];
	case U'\u000B': /* VERTICAL TABULATION */
		[[fallthrough]];
	case U'\u000C': /* FORM FEED */
		[[fallthrough]];
	case U'\u000D': /* CARRIAGE RETURN */
		[[fallthrough]];
	case U'\u0020': /* SPACE */
		return true;
	}
}
