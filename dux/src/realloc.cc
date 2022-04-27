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

# include <dux/sig>
# include <dux/mem>

# include <cstddef>
# include <cstdlib>

auto ::dux::priv::realloc(void * const restrict _ptr,::dux::uwrd const _newsz) noexcept -> void * {
	if (reinterpret_cast<::dux::uwrd>(_ptr) % alignof (::std::max_align_t) != dux_uwrdl(0x0)) [[unlikely]] {
		::dux::dbglog("dux :: realloc :: Address %p is not default-aligned and cannot be reallocated in the current version of dux!\n",_ptr);
		::dux::raise(::dux::sig::segv);
	}
	auto const newptr {::std::realloc(const_cast<void *>(_ptr),_newsz)};
	if (::dux::haserr()) [[unlikely]] {return nullptr;}
	return newptr;
}
