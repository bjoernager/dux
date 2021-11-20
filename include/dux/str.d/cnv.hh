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

template<::dux::utf T,::dux::utf T0> constexpr auto ::dux::cnv(T0 const * const dux_restr _begin,T0 const * const dux_restr _end) -> ::dux::arr<T> {
	if (_begin == nullptr || _end == nullptr) [[unlikely]] {
		throw ::dux::invalarg("Null pointer provided as parameter.");
	}
	::dux::arr<T0> in(_begin,_end);
	::dux::arr<T> out;
	if constexpr (::dux::issame<T0,T>) {
		out.alloc(static_cast<::dux::usz>(_end - _begin));
		::dux::cpy(_begin,_end,out.begin());
		return out;
	}
	else {
		if constexpr (::dux::issame<T0,char16_t>) {
		}
		else if constexpr (::dux::issame<T0,char32_t>) {
			for (auto const tmp : in) {
				if constexpr (::dux::issame<T,char16_t>) {
					if (tmp >= ::dux::uint32v(0x10000)) { /* Two hextets. */
						char16_t const tmp0 = tmp - ::dux::uint16v(0x10000);
						out.app((tmp0 / ::dux::uint16v(0x400) + ::dux::uint16v(0xD800)));
						out.app((tmp0 % ::dux::uint16v(0x400) + ::dux::uint16v(0xDC00)));
					}
					else [[likely]] {
						/* One hextet. */
						out.app((static_cast<char16_t>(tmp)));
					}
				}
				else {
					if (tmp >= ::dux::uint32v(0x10000)) { /* Four octets. */
						out.app((::dux::ubytev(0b11110000) + static_cast<char8_t>(tmp >> ::dux::uint32v(0x12) & ::dux::uint32v(0b00000111))));
						out.app((::dux::ubytev(0b10000000) + static_cast<char8_t>(tmp >> ::dux::uint32v(0xC) & ::dux::uint32v(0b00111111))));
						out.app((::dux::ubytev(0b10000000) + static_cast<char8_t>(tmp >> ::dux::uint32v(0x6) & ::dux::uint32v(0b00111111))));
						out.app((::dux::ubytev(0b10000000) + static_cast<char8_t>(tmp & ::dux::uint32v(0b00111111))));
					}
					else if (tmp >= U'\u0800') { /* Three octets. */
						out.app((::dux::ubytev(0xE0) + static_cast<char8_t>(tmp >> ::dux::uint32v(0xC) & ::dux::uint32v(0b00001111))));
						out.app((::dux::ubytev(0x80) + static_cast<char8_t>(tmp >> ::dux::uint32v(0x6) & ::dux::uint32v(0b00111111))));
						out.app((::dux::ubytev(0x80) + static_cast<char8_t>(tmp & ::dux::uint32v(0b00111111))));
					}
					else if (tmp >= U'\u0080') { /* Two octets. */
						out.app((::dux::ubytev(0xC0) + static_cast<char8_t>(tmp >> ::dux::uint32v(0x6) & ::dux::uint32v(0b00111111))));
						out.app((::dux::ubytev(0x80) + static_cast<char8_t>(tmp & ::dux::uint32v(0b00111111))));
					}
					else [[likely]] {
						/* One octet. */
						out.app(static_cast<char8_t>(tmp));
					}
				}
			}
		}
		else {
			if constexpr (::dux::issame<T,char16_t>) {
			}
			else {
				for (::dux::usz n = 0x0uz;n < in.sz();n += 0x1uz) {
					auto const tmp = in[n];
					auto chr = U'\u0000';
					if (tmp >= ::dux::ubytev(0b11110000)) { /* Four octets. */
						chr =  (tmp ^ ::dux::uint32v(0b11110000)) << ::dux::uint32v(0x12);
						chr += (in[n + 0x1uz] ^ ::dux::uint32v(0b10000000)) << ::dux::uint32v(0xC);
						chr += (in[n + 0x2uz] ^ ::dux::uint32v(0b10000000)) << ::dux::uint32v(0x6);
						chr += in[n + 0x3uz] ^ ::dux::uint32v(0b10000000);
						n   += 0x3uz;
					}
					else if (tmp >= ::dux::ubytev(0b11100000)) { /* Three octets. */
						chr =  (tmp ^ ::dux::uint32v(0b11100000)) << ::dux::uint32v(0xC);
						chr += (in[n + 0x1uz] ^ ::dux::uint32v(0b10000000)) << ::dux::uint32v(0x6);
						chr += in[n + 0x2uz] ^ ::dux::uint32v(0b10000000);
						n   += 0x2uz;
					}
					else if (tmp >= ::dux::ubytev(0b11000000)) { /* Two octets. */
						chr =  (tmp ^ ::dux::uint32v(0b11000000)) << ::dux::uint32v(0x6);
						chr += in[n + 0x1uz] ^ ::dux::uint32v(0b10000000);
						n   += 0x1uz;
					}
					else [[likely]] {
						/* One octet. */
						chr = tmp;
					}
					out.app(chr);
				}
			}
		}
	}
	return out;
}
