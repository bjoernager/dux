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

namespace dux::priv {
	template<typename T> constexpr auto intfmter(T const _fmt) -> ::dux::str {
		auto const fmt = [&]() {
			if constexpr(::dux::isptr<T>) {
				return (::dux::uint64)_fmt;
			}
			else {
				return _fmt;
			}
		}();
		using T0 = decltype(fmt);
		if constexpr (::dux::issint<T>) {
			if (fmt < T0{0x0}) {
				return ::dux::str(U'−') + ::dux::fmter(::dux::abs(fmt));
			}
		}
		if (fmt < ::dux::base) {
			auto const nums = []() {
				if (::dux::base == ::dux::ubytev(0xC)) {
					return U"0123456789↊↋";
				}
				return U"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
			}();
			return nums[fmt];
		}
		return ::dux::fmter(fmt / T0{::dux::base}) + ::dux::fmter(fmt % T0{::dux::base});
	}
}
template<> constexpr auto ::dux::fmter(bool const _fmt) -> ::dux::str {
	if (_fmt) {
		return U"true";
	}
	return U"false";
}
/*template<> constexpr auto ::dux::fmter(char16_t const * const dux_restr _fmt) -> ::dux::str {
	return ::dux::str{_fmt};
}*/
template<> constexpr auto ::dux::fmter(char32_t const * const dux_restr _fmt) -> ::dux::str {
	return ::dux::str{_fmt};
}
template<> constexpr auto ::dux::fmter(char8_t const * const dux_restr _fmt) -> ::dux::str {
	return ::dux::str{_fmt};
}
template<> constexpr auto ::dux::fmter(int const _fmt) -> ::dux::str {
	return ::dux::priv::intfmter(_fmt);
}
template<> constexpr auto ::dux::fmter(long const _fmt) -> ::dux::str {
	return ::dux::priv::intfmter(_fmt);
}
template<> constexpr auto ::dux::fmter(long long const _fmt) -> ::dux::str {
	return ::dux::priv::intfmter(_fmt);
}
template<> constexpr auto ::dux::fmter(short const _fmt) -> ::dux::str {
	return ::dux::priv::intfmter(_fmt);
}
template<> constexpr auto ::dux::fmter(::dux::nullptrtyp) -> ::dux::str {
	return U"nullptr";
}
template<> constexpr auto ::dux::fmter(::dux::str const _fmt) -> ::dux::str {
	return _fmt;
}
template<> constexpr auto ::dux::fmter(unsigned const _fmt) -> ::dux::str {
	return ::dux::priv::intfmter(_fmt);
}
template<> constexpr auto ::dux::fmter(unsigned long const _fmt) -> ::dux::str {
	return ::dux::priv::intfmter(_fmt);
}
template<> constexpr auto ::dux::fmter(unsigned long long const _fmt) -> ::dux::str {
	return ::dux::priv::intfmter(_fmt);
}
template<> constexpr auto ::dux::fmter(unsigned short const _fmt) -> ::dux::str {
	return ::dux::priv::intfmter(_fmt);
}
template<> constexpr auto ::dux::fmter(void const * const dux_restr _fmt) -> ::dux::str {
	if (_fmt == nullptr) {
		return ::dux::fmter(nullptr);
	}
	return ::dux::priv::intfmter(_fmt);
}
