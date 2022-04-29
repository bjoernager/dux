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

# include <dux/priv>

# include <dux/mem>

# include <dux/sig>

auto ::dux::memeq(void const * const restrict _lptr,::dux::uwrd const _num,void const * const restrict _rptr) noexcept -> bool {
	auto       lptr    {static_cast<::dux::uint8 const *>(_lptr)};
	auto       rptr    {static_cast<::dux::uint8 const *>(_rptr)};
	auto const maxlptr {lptr + _num - dux_uwrdl(0x1)};
	for (;lptr <= maxlptr;++lptr,++rptr) {if (*lptr != *rptr) [[unlikely]] {return false;}}
	return true;
}

# pragma GCC diagnostic ignored "-Wmissing-declarations"

extern "C" auto dux_memeq(void const * const restrict _lptr,::dux::uwrd const _num,void const * const restrict _rptr) noexcept -> bool {return ::dux::memeq(_lptr,_num,_rptr);}
