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
	[[nodiscard]] constexpr auto fndchr(char const * const restrict _str,char const _chr) noexcept -> ::dux::uwrd {
		for (::dux::uwrd n = dux_uwrdl(0x0);_str[n] != '\u0000';++n) {if (_str[n] == _chr) {return n;}}
		return dux_uwrdl(-0x1);
	}

	[[nodiscard]] constexpr auto strcmp(char const * const restrict _lstr,char const * const restrict _rstr) noexcept -> ::dux::sint8 {
		auto lptr {_lstr};
		auto rptr {_rstr};
		for (;;++lptr,++rptr) {
			auto const lchr = *lptr;
			auto const rchr = *rptr;
			if (lchr != rchr) [[unlikely]] {
				if (lchr > rchr) {return dux_sint8l(-0x1);}
				if (lchr < rchr) {return dux_sint8l(0x1);}
			}
		}
		return dux_sint8l(0x0);
	}

	[[nodiscard]] constexpr auto streq(char const * const restrict _lstr,char const * const restrict _rstr) noexcept -> bool {
		auto lptr {_lstr};
		auto rptr {_rstr};
		for (;;++lptr,++rptr) {
			if (*lptr != *rptr) {return false;}
			if (*lptr == '\u0000' || *rptr == '\u0000') {return true;}
		}
		::dux::unreach();
	}

	[[nodiscard]] constexpr auto strlen(char const * const restrict _str) noexcept -> ::dux::uwrd {
		auto sz = dux_uwrdl(0x0);
		for (::dux::uwrd n = dux_uwrdl(0x0);;++n) {
			if (_str[n] == '\u0000') [[unlikely]] {
				break;
			}
			++sz;
		}
		return sz;
	}

	constexpr auto strcpy(char const * const restrict _src,char * const restrict _dest) noexcept -> void {
		auto const sz = ::dux::strlen(_src);
		if (sz == dux_uwrdl(0x0)) [[unlikely]] {return;}
		::dux::cpy(_src,sz,_dest);
	}

	[[nodiscard]] constexpr auto strdup(char const * const restrict _str) noexcept -> ::dux::str {
		::dux::str str;
		           str.sz = ::dux::strlen(_str);
		auto const rawstr {::dux::alloc<char>(str.sz)};
		::dux::cpy(_str,str.sz,rawstr);
		str.ptr = rawstr;
		return str;
	}
}

namespace dux {
# include <dux/str.d/uniblk.ii>
# include <dux/str.d/uninm.ii>

# include <dux/str.d/isdigit.ii>
# include <dux/str.d/islower.ii>
# include <dux/str.d/ispunct.ii>
# include <dux/str.d/isspace.ii>
# include <dux/str.d/issurro.ii>
# include <dux/str.d/isupper.ii>
# include <dux/str.d/isxdigit.ii>

# include <dux/str.d/isalpha.ii>

# include <dux/str.d/isalnum.ii>
}
