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
	template<::dux::arith T>             [[dux_attr_const,       nodiscard]]                                                    constexpr auto abs(    T         val)                                    noexcept -> T;
	template<typename     T>             [[dux_attr_hot]]                                                                       constexpr auto cpy(    T const * begin,T const *  end, T *       out)    noexcept -> void;
	template<typename     T>             [[dux_attr_hot]]                                                                       constexpr auto cpyn(   T const * in,   ::dux::usz num, T *       out)    noexcept -> void;
	template<typename     T,typename T0> [[dux_attr_hot]]                                                                       constexpr auto fill(   T *       begin,T *        end, T0        val)    noexcept -> void;
	template<typename     T,typename T0> [[dux_attr_hot]]                                                                       constexpr auto filln(  T *       in,   ::dux::usz num, T0        val)    noexcept -> void;
	template<::dux::arith T>             [[dux_attr_const,       nodiscard]]                                                    constexpr auto fma(    T         x,    T          y,   T         z)      noexcept -> T;
	template<typename     T>             [[dux_attr_hot]]                                                                       constexpr auto ins(    T const * begin,T const *  end, T *       out)    noexcept -> void;
	template<typename     T>             [[dux_attr_hot]]                                                                       constexpr auto insn(   T const * om,   ::dux::usz num, T *       out)    noexcept -> void;
	//template<::dux::arith T>             [[dux_attr_const]]                                                                     constexpr auto isinf(  T         val)                                    noexcept -> bool;
	template<::dux::arith T>             [[dux_attr_const]]                                                                     constexpr auto isnan(  T         val)                                    noexcept -> bool;
	template<::dux::arith T>             [[dux_attr_const]]                                                                     constexpr auto isprime(T         val)                                    noexcept -> bool;
	template<typename     T>             [[dux_attr_const,       nodiscard]]                                                    constexpr auto max(    T const & lval, T const &  rval)                  noexcept -> T const &;
	template<typename     T>             [[dux_attr_const,       nodiscard]]                                                    constexpr auto min(    T const & lval, T const &  rval)                  noexcept -> T const &;
	template<typename     T>             [[dux_attr_hot]]                                                                       constexpr auto mv(     T *       begin,T *        end, T *        out)   noexcept -> void;
	template<typename     T>             [[dux_attr_hot]]                                                                       constexpr auto mvn(    T *       in,   ::dux::usz num, T *        out)   noexcept -> void;
	template<::dux::arith T>             [[dux_attr_const]]                                                                     constexpr auto pow(    T         base, T          exp)                   noexcept -> T;
	template<typename     T>             [[dux_attr_allocsz(0x3),dux_attr_hot,dux_attr_malloc,dux_attr_nonnull(0x1),nodiscard]] constexpr auto renew(  T *       ptr,  ::dux::usz sz,  ::dux::usz newsz)          -> T *;
	template<::dux::arith T>             [[dux_attr_const]]                                                                     constexpr auto sqrt(   T         val)                                    noexcept -> T;

	/* Consteval alternatives for mathematical functions: */
	template<::dux::arith T> [[nodiscard]] consteval auto cabs(    T         _val)                        noexcept -> T         {return ::dux::abs(_val);}
	template<::dux::arith T> [[nodiscard]] consteval auto cfma(    T         _x,    T         _y,   T _z) noexcept -> T         {return ::dux::fma(_x,_y,_z);}
	//template<::dux::arith T>               consteval auto cisinf(  T         _val)                        noexcept -> bool      {return ::dux::isinf(_val);}
	template<::dux::arith T>               consteval auto cisnan(  T         _val)                        noexcept -> bool      {return ::dux::isnan(_val);}
	template<::dux::arith T>               consteval auto cisprime(T         _val)                        noexcept -> bool      {return ::dux::isprime(_val);}
	template<typename     T> [[nodiscard]] consteval auto cmax(    T const & _lval, T const & _rval)      noexcept -> T const & {return ::dux::max(_lval,_rval);}
	template<typename     T> [[nodiscard]] consteval auto cmin(    T const & _lval, T const & _rval)      noexcept -> T const & {return ::dux::min(_lval,_rval);}
	template<::dux::arith T> [[nodiscard]] consteval auto cpow(    T         _base, T         _exp)       noexcept -> T         {return ::dux::pow(_base,_exp);}
	template<::dux::arith T> [[nodiscard]] consteval auto csqrt(   T         _val)                        noexcept -> T         {return ::dux::sqrt(_val);}
}

#include <dux/algo.d/abs.hh>
#include <dux/algo.d/cpy.hh>
#include <dux/algo.d/cpyn.hh>
#include <dux/algo.d/fill.hh>
#include <dux/algo.d/filln.hh>
#include <dux/algo.d/fma.hh>
#include <dux/algo.d/ins.hh>
#include <dux/algo.d/insn.hh>
//#include <dux/algo.d/isinf.hh>
#include <dux/algo.d/isnan.hh>
#include <dux/algo.d/isprime.hh>
#include <dux/algo.d/min.hh>
#include <dux/algo.d/mv.hh>
#include <dux/algo.d/mvn.hh>
#include <dux/algo.d/pow.hh>
#include <dux/algo.d/renew.hh>
#include <dux/algo.d/sqrt.hh>
