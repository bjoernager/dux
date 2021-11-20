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

namespace dux {
	[[nodiscard]] constexpr auto cstrcmp(char const * lstr,char const *  rstr) noexcept -> ::dux::sbyte;
	[[nodiscard]] constexpr auto cstrcpy(char *       dest,char const *  src)  noexcept -> char *;
	[[nodiscard]] constexpr auto cstrdup(char const * str)                              -> char *;
	[[nodiscard]] constexpr auto cstrlen(char const * str)                     noexcept -> ::dux::usz;
}

#include <dux/cstr.d/cstrcmp.hh>
#include <dux/cstr.d/cstrcpy.hh>
#include <dux/cstr.d/cstrdup.hh>
#include <dux/cstr.d/cstrlen.hh>
