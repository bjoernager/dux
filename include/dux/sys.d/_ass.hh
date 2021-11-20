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

#include <iostream>

constexpr auto ::dux::_ass(char const * const dux_restr _fl,unsigned long const _ln,char const * const dux_restr _fn,bool const _expr,char const * const dux_restr _exprstr,char const * const dux_restr _msg) noexcept -> bool {
	if (!_expr) [[unlikely]] {
		::std::cerr << "\n";
		::std::cerr << "Assertion \u001B[38;2;225;61;61mfailed\u001B[0m";
		if (!::dux::cstrcmp(_msg,"")) {
			::std::cerr << "!";
		}
		else {
			::std::cerr << ": \u001B[3m" << _msg << "\u001B[0m";
		}
		::std::cerr << "\n";
		::std::cerr << "... at \u001B[38;2;225;169;61m\"" << _fl << "\"\u001B[0m:\u001B[38;2;255;169;61m" << _ln << "\u001B[0m\n";
		::std::cerr << "... in \u001B[38;2;169;225;61m" << _fn << "\u001B[0m\n";
		::std::cerr << "    Expression (\u001B[38;2;61;169;225m" << _exprstr << "\u001B[0m) does not evaluate to true!\n";
		::std::cerr << "\n";
		::dux::abrt();
	}
	return _expr;
}
