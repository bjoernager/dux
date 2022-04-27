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

namespace dux {
	template<typename T> inline auto bytefill(T * const _in,::dux::uwrd const _num,::dux::uint8 const _val) noexcept -> void {
		static_assert(!::dux::issame<T,void>);
		dux_priv_ifconsteval {
			if (_num == dux_uwrdl(0x0)) [[unlikely]] {return;}
			auto const in      {reinterpret_cast<::dux::uint8 *>(_in)};
			auto const numbyte {_num * sizeof (T)};
			for (auto pos = dux_uwrdl(0x0);pos < numbyte;++pos) {in[pos] = _val;}
		}
		else {::dux_priv_fill(_in,_num,_val,sizeof (T));}
	}

	template<typename T> dux_attr_hot constexpr auto cpy(T const * const restrict _in,::dux::uwrd const _num,T * const restrict _out) noexcept -> void {
		static_assert(!::dux::issame<T,void>);
		dux_priv_ifconsteval {
			if (_num == dux_uwrdl(0x0)) [[unlikely]] {return;}
			for (::dux::uwrd pos = dux_uwrdl(0x0);pos != _num;++pos) {_out[pos] = _in[pos];}
		}
		else {::dux_priv_cpy(_in,_num,_out,sizeof (T));}
	}

	template<typename T,::dux::cnvto<T> T0> constexpr auto fill(T * const restrict _in,::dux::uwrd const _num,T0 const & _val) noexcept -> void {
		static_assert(!::dux::issame<T,void>);
		if (_num == dux_uwrdl(0x0)) [[unlikely]] {return;}
		auto const & val {static_cast<T const &>(_val)};
		for (auto pos = dux_uwrdl(0x0);pos < _num;++pos) {_in[pos] = val;}
	}
}
