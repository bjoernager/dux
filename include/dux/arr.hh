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
	template<typename T> class arr {
	public:
		                                           constexpr auto alloc(       ::dux::usz             num)                                                  -> void;
		template<::dux::cnvto<T> T0>               constexpr auto alloc(       ::dux::usz             num,    T0         val)                               -> void;
		                                           constexpr auto app(         ::dux::arr<T> const &  oth)                                                  -> ::dux::arr<T> const &;
		template<::dux::cnvto<T> T0>               constexpr auto app(         T0                     val)                                                  -> ::dux::arr<T> const &;
		                             [[nodiscard]] constexpr      arr()                                                                            noexcept                          = default;
		                             [[nodiscard]] constexpr      arr(         T const *              begin,  T const *  end);
		                             [[nodiscard]] constexpr      arr(         ::dux::usz             num);
		                             [[nodiscard]] constexpr      arr(         ::dux::arr<T> const &  oth);
		                             [[nodiscard]] constexpr      arr(         ::dux::arr<T>  &&      oth);
		template<::dux::usz      N>  [[nodiscard]] constexpr      arr(         T const (&             arr)[N])                                     noexcept;
		template<::dux::cnvto<T> T0> [[nodiscard]] constexpr      arr(         ::dux::usz             num,    T0         val);
		                             [[nodiscard]] constexpr auto begin()                                                                          noexcept -> T *;
		                             [[nodiscard]] constexpr auto begin()                                                                    const noexcept -> T const *;
		                             [[nodiscard]] constexpr auto cbegin()                                                                   const noexcept -> T const *;
		                             [[nodiscard]] constexpr auto cend()                                                                     const noexcept -> T const *;
		                                           constexpr auto del(         ::dux::usz             pos)                                                  -> void;
		                             [[nodiscard]] constexpr auto end()                                                                            noexcept -> T *;
		                             [[nodiscard]] constexpr auto end()                                                                      const noexcept -> T const *;
		template<::dux::cnvto<T> T0>               constexpr auto fill(        T0                     val)                                                  -> void;
		template<::dux::cnvto<T> T0>               constexpr auto fill(        T *                    begin,  T *        end,T0         val)                -> void;
		                                           constexpr auto ins(         ::dux::arr<T> const &  oth,    ::dux::usz pos)                               -> ::dux::arr<T> const &;
		                                           constexpr auto ins(         T const *              begin,  T const *  end,::dux::usz pos)                -> ::dux::arr<T> const &;
		                             [[nodiscard]] constexpr auto isstatic()                                                                 const noexcept -> bool;
		                                           constexpr auto operator = ( ::dux::arr<T> const &  oth)                                                  -> ::dux::arr<T> const &;
		                             [[nodiscard]] constexpr auto operator [] (::dux::usz             pos)                                                  -> T &;
		                             [[nodiscard]] constexpr auto operator [] (::dux::usz             pos)                                   const          -> T const &;
		                                           constexpr auto realloc(     ::dux::usz             num)                                                  -> void;
		                                           constexpr auto setraw(      T const *              ptr,    ::dux::usz sz)                       noexcept -> void;
		                             [[nodiscard]] constexpr auto sub(         ::dux::usz             pos,    ::dux::usz sz)                 const          -> ::dux::arr<T>;
		                             [[nodiscard]] constexpr auto sz()                                                                       const noexcept -> ::dux::usz;
		                                           constexpr      ~arr()                                                                           noexcept;
	private:
		bool       _isstatic{false};
		T *        _ptr     {nullptr};
		::dux::usz _sz      {0x0uz};
	};
}

#include <dux/arr.d/arr.hh>
