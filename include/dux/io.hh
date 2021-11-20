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

/*
	to-do:
		Implement a prettier (and larger) API for I/O operations!
*/

namespace dux {
	class fmterr : public ::dux::except {
	public:
		using ::dux::except::except;
	};

	template<typename... Ts>               constexpr auto dbgprint(::dux::str const & str,Ts... args)              -> void;
	                                       constexpr auto fmt(     ::dux::str const & str)                         -> ::dux::str;
	template<typename    T>                constexpr auto fmt(     ::dux::str const & str,T       fmt)             -> ::dux::str;
	template<typename    T,typename... Ts> constexpr auto fmt(     ::dux::str const & str,T       fmt, Ts... args) -> ::dux::str;
	template<typename    T>                constexpr auto fmter(   T                  fmt)                         -> ::dux::str;
	template<typename... Ts>               constexpr auto print(   ::dux::str const & str,Ts... args)              -> void;
	inline auto    base  {::dux::ubytev(0xC)};
	constexpr auto fmtchr{U'\u0024'};
}

#include <dux/io.d/dbgprint.hh>
#include <dux/io.d/fmt.hh>
#include <dux/io.d/fmter.hh>
#include <dux/io.d/print.hh>
