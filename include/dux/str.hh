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
	class str {
	public:
		                                      constexpr auto app(         ::dux::str const & oth)                                              -> ::dux::str const &;
		                        [[nodiscard]] constexpr auto begin()                                                                  noexcept -> char32_t *;
		                        [[nodiscard]] constexpr auto begin()                                                            const noexcept -> char32_t const *;
		                        [[nodiscard]] constexpr auto cbegin()                                                           const noexcept -> char32_t const *;
		                        [[nodiscard]] constexpr auto cend()                                                             const noexcept -> char32_t const *;
		                                      constexpr auto del(         ::dux::usz         pos)                                              -> void;
		                        [[nodiscard]] constexpr auto end()                                                                    noexcept -> char32_t *;
		                        [[nodiscard]] constexpr auto end()                                                              const noexcept -> char32_t const *;
		                        [[nodiscard]] constexpr auto fnd(         char32_t           chr)                               const noexcept -> ::dux::usz;
		                                      constexpr auto ins(         ::dux::usz         pos,       ::dux::str const & oth)                -> ::dux::str const &;
		                                      constexpr auto len()                                                              const noexcept -> ::dux::usz;
		                                      constexpr auto operator + ( ::dux::str const & oth)                               const          -> ::dux::str;
		                                      constexpr auto operator = ( ::dux::str const & oth)                                              -> ::dux::str const &;
		                                      constexpr auto operator == (::dux::str const & oth)                               const noexcept -> bool;
		                                      constexpr auto operator [] (::dux::usz         pos)                                     noexcept -> char32_t &;
		                                      constexpr auto operator [] (::dux::usz         pos)                               const noexcept -> char32_t const &;
		                        [[nodiscard]] constexpr      str()                                                                    noexcept                       = default;
		                        [[nodiscard]] constexpr      str(         char32_t           chr);
		                        [[nodiscard]] constexpr      str(         ::dux::str const & oth);
		                        [[nodiscard]] constexpr      str(         ::dux::str &&      oth);
		template<::dux::usz  N> [[nodiscard]] constexpr      str(         char const (&      strlit)[N])                              noexcept                       = delete;
		template<::dux::usz  N> [[nodiscard]] constexpr      str(         char32_t const (&  strlit)[N])                              noexcept;
		template<::dux::utf  T> [[nodiscard]] constexpr      str(         T                  chr);
		template<::dux::utf  T> [[nodiscard]] constexpr      str(         T        const *   utf);
		                        [[nodiscard]] constexpr auto sub(         ::dux::usz         pos,       ::dux::usz         len) const          -> ::dux::str;
		                        [[nodiscard]] constexpr auto u8()                                                               const          -> ::dux::arr<char8_t>;
	private:
		::dux::arr<char32_t> _arr;
	};

	template<::dux::utf T,::dux::utf T0> [[nodiscard]]                constexpr auto cnv(     T0 const * begin,T0 const * end) -> ::dux::arr<T>;
	                                     [[nodiscard,dux_attr_const]] constexpr auto isalnum( char32_t   chr)                  -> bool;
	                                     [[nodiscard,dux_attr_const]] constexpr auto isalpha( char32_t   chr)                  -> bool;
	                                     [[nodiscard,dux_attr_const]] constexpr auto iscntrl( char32_t   chr)                  -> bool;
	                                     [[nodiscard,dux_attr_const]] constexpr auto isdigit( char32_t   chr)                  -> bool;
	                                     [[nodiscard,dux_attr_const]] constexpr auto islower( char32_t   chr)                  -> bool;
	                                     [[nodiscard,dux_attr_const]] constexpr auto ispunct( char32_t   chr)                  -> bool;
	                                     [[nodiscard,dux_attr_const]] constexpr auto isspace( char32_t   chr)                  -> bool;
	                                     [[nodiscard,dux_attr_const]] constexpr auto issurro( char32_t   chr)                  -> bool;
	                                     [[nodiscard,dux_attr_const]] constexpr auto isupper( char32_t   chr)                  -> bool;
	                                     [[nodiscard,dux_attr_const]] constexpr auto isxdigit(char32_t   chr)                  -> bool;
	                                     [[nodiscard]]                constexpr auto uniblk(  char32_t   chr)                  -> ::dux::str;
	                                     [[nodiscard]]                constexpr auto uninm(   char32_t   chr)                  -> ::dux::str;
}

#include <dux/str.d/cnv.hh>
#include <dux/str.d/isalnum.hh>
#include <dux/str.d/isalpha.hh>
#include <dux/str.d/iscntrl.hh>
#include <dux/str.d/isdigit.hh>
#include <dux/str.d/islower.hh>
#include <dux/str.d/ispunct.hh>
#include <dux/str.d/isspace.hh>
#include <dux/str.d/issurro.hh>
#include <dux/str.d/isupper.hh>
#include <dux/str.d/isxdigit.hh>
#include <dux/str.d/str.hh>
#include <dux/str.d/uniblk.hh>
#include <dux/str.d/uninm.hh>
