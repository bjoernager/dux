/*
	Copyright 2021, 2022 Gabriel Jensen.

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

namespace dux::num {
	constexpr auto e   {dux_priv_num_e};
	constexpr auto phi {dux_priv_num_phi};
	constexpr auto pi  {dux_priv_num_pi};
}

namespace dux::priv {
	template<::dux::arithtyp T> constexpr auto inf              {::dux::maxval<T>};
	template<>                  constexpr auto inf<double>      {dux_priv_infd};
	template<>                  constexpr auto inf<float>       {dux_priv_inff};
	template<>                  constexpr auto inf<long double> {dux_priv_infld};
}
namespace dux {
	template<::dux::arithtyp T> constexpr auto inf {::dux::priv::inf<T>};
}

namespace dux::priv {
	template<::dux::arithtyp T> constexpr auto nan              {T {0x0}};
	template<>                  constexpr auto nan<double>      {dux_priv_nand};
	template<>                  constexpr auto nan<float>       {dux_priv_nanf};
	template<>                  constexpr auto nan<long double> {dux_priv_nanld};
}
namespace dux {
	template<::dux::arithtyp T> constexpr auto nan {::dux::priv::nan<T>};
}

namespace dux {
	template<::dux::arithtyp T> dux_attr_const [[nodiscard]] constexpr auto abs(  T const   _val)                             noexcept -> T         {return dux_priv_abs(_val);}
	template<::dux::uinttyp  T> dux_attr_const [[nodiscard]] constexpr auto abs(  T const   _val)                             noexcept -> T         {return _val;}
	template<::dux::arithtyp T> dux_attr_const [[nodiscard]] constexpr auto fma(  T const   _x,   T const   _y,   T const _z) noexcept -> T         {return dux_priv_fma(_x,_y,_z);}
	template<::dux::arithtyp T> dux_attr_const [[nodiscard]] constexpr auto isinf(T const   _val)                             noexcept -> bool      {return _val > ::dux::inf<T>;}
	template<::dux::arithtyp T> dux_attr_const [[nodiscard]] constexpr auto isnan(T const   _val)                             noexcept -> bool      {return dux_priv_isnan(_val);}
	template<typename        T> dux_attr_const [[nodiscard]] constexpr auto max(  T const & _lval,T const & _rval)            noexcept -> T const & {return dux_priv_max(_lval,_rval);}
	template<typename        T> dux_attr_const [[nodiscard]] constexpr auto min(  T const & _lval,T const & _rval)            noexcept -> T const & {return dux_priv_min(_lval,_rval);}

	template<::dux::inttyp T> dux_attr_const [[nodiscard]] constexpr auto fac(T const _val) noexcept -> auto {
		using T0 = ::dux::unsign<T>;
		if constexpr (::dux::issinttyp<T>) {if (_val < T {0x0}) [[unlikely]] {return T0 {0x0};}}
		auto const val {[&_val] {
			if constexpr (::dux::issinttyp<T>) {return static_cast<T0>(_val);}
			else                            {return _val;}
		}()};
		auto res {T0 {0x1}};
		for (auto n {T0 {0x1}};n <= _val;++n) {res *= n;}
		return res;
	}

	template<::dux::inttyp T> dux_attr_const [[nodiscard]] constexpr auto msb(T const _val) noexcept -> auto {
		using T0 = ::dux::unsign<T>;
		if constexpr (::dux::issinttyp<T>) {if (_val < T {0x0}) [[unlikely]] {return - T0 {0x1};}}
		if (_val == T {0x0}) [[unlikely]] {return T0 {0x0};}
		auto val {static_cast<T0>(_val)};
		auto bit {T0 {0x0}};
		while (val >>= T0 {0x1}) {++bit;}
		return static_cast<T0>(T0 {0x1} << bit);
	}

	template<typename T,typename Fn> constexpr auto plot(T * const restrict _list,::dux::uwrd const _sz,Fn const & _fn) noexcept -> void {
		using fntyp = auto (*)(::dux::uwrd n) -> T;
		static_assert(::dux::iscnvto<Fn,fntyp>,"Function must be of type (auto (*)(::dux::uwrd) -> T)!");
		auto const fn {static_cast<fntyp>(_fn)};
		for (auto n {dux_uwrdl(0x0)};n < _sz;++n) {_list[n] = fn(n);}
	}

	template<::dux::arithtyp T> dux_attr_const [[nodiscard]] constexpr auto pow(T const _base,T const _exp) noexcept -> T {
		if (::dux::abs(_base) <= T {0x1}) [[unlikely]] {return _base;}
		auto res = _base;
		for (auto iter = T {0x1};iter < _exp;iter += T {0x1}) {res *= _base;}
		return res;
	}

	template<::dux::arithtyp T> dux_attr_const [[nodiscard]] constexpr auto sqrt(T const _val) noexcept -> T {
		dux_priv_ifconsteval {return ::dux_priv_sqrtf(_val);}
		{
			if (_val < T {0x0}) [[unlikely]] {return ::dux::nan<T>;}
			if (_val == T {0x0}) [[unlikely]] {return T {0x0};}
			return _val;
		}
	}

	template<::dux::arithtyp T> constexpr auto swp(T & _lvar,T & _rvar) noexcept -> void {
		T const mvar  = _lvar;
		        _lvar = _rvar;
		        _rvar = mvar;
	}
}

namespace dux {
	template<::dux::arithtyp T> dux_attr_const [[nodiscard]] constexpr auto isprime(T const _val) noexcept -> bool {
		if (_val <  T {0x2})            [[unlikely]] {return false;}
		if (_val == T {0x2})            [[unlikely]] {return true;}
		if (_val %  T {0x2} == T {0x0})              {return false;}
		for (auto n {T {0x3}};n < _val / T {0x2};n += T {0x2}) {if (_val % n == T {0x0}) {return false;}}
		return true;
	}
}

namespace dux {
	template<::dux::arithtyp T> [[nodiscard]] consteval auto cabs( T const   _val)                             noexcept -> T         {return ::dux::abs(_val);}
	template<::dux::inttyp   T> [[nodiscard]] consteval auto cfac( T const   _val)                             noexcept -> T         {return ::dux::fac(_val);}
	template<::dux::arithtyp T> [[nodiscard]] consteval auto cfma( T const   _x,   T const   _y,   T const _z) noexcept -> T         {return ::dux::fma(_x,_y,_z);}
	template<typename        T> [[nodiscard]] consteval auto cmax( T const & _lval,T const & _rval)            noexcept -> T const & {return ::dux::max(_lval,_rval);}
	template<typename        T> [[nodiscard]] consteval auto cmin( T const & _lval,T const & _rval)            noexcept -> T const & {return ::dux::min(_lval,_rval);}
	template<::dux::arithtyp T> [[nodiscard]] consteval auto cpow( T const   _base,T         _exp)             noexcept -> T         {return ::dux::pow(_base,_exp);}
	template<::dux::arithtyp T> [[nodiscard]] consteval auto csqrt(T const   _val)                             noexcept -> T         {return ::dux::sqrt(_val);}
}

namespace dux::priv {
	auto freernd(::dux::uint8 * ptr)                noexcept -> void;
	auto rnd(    ::dux::uint8 * buf,::dux::uwrd sz) noexcept -> void;
}
namespace dux {
	template<::dux::arithtyp T> inline auto rnd() noexcept -> T { /* TO-DO: Implement a compile time (pseudo) random number generator. Use __TIME__? */
		if constexpr (::dux::isflttyp<T>) {return ::dux::nan<T>;} /* TO-DO: Implement a working random number generator for floating-point types. */
		else {
			constexpr auto sz {sizeof (T)};
			::dux::uint8 buf[sz];
			::dux::priv::rnd(buf,sz);
			return *reinterpret_cast<T *>(buf);
		}
	}
}
