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

#include <cstdio>

template<typename... Ts> constexpr auto ::dux::print(::dux::str const & _str,Ts... _args) -> void {
	auto const str = ::dux::fmt(_str,_args...);
	if (str.len() == 0x0uz) [[unlikely]] {
		throw ::dux::invalarg("Too many format options!");
	}
	if (::std::fwrite(str.u8().begin(),0x1uz,str.len(),stdout) < str.len()) {
		throw ::dux::runerr("Unable to write to stout!");
	}
}
