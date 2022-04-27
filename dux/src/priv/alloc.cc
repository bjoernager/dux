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

# include <cstddef>
# include <cstdlib>
# include <stdlib.h>

extern "C" auto dux_priv_alloc(::dux::uwrd const _sz,::dux::uwrd const _align) -> void * { /* Currently, we implement memory using the standard C++ functions. Implement our own runtime system. */
	if (_sz == dux_uwrdl(0x0)) [[unlikely]] {return nullptr;}
	auto const ptr {[&_align,&_sz] {
		if (_align == alignof (::std::max_align_t)) {return ::std::malloc(_sz);}
		return ::std::aligned_alloc(_align,_sz);
	}()};
	if (ptr == nullptr) [[unlikely]] {goto badalloc;}
	dux_ass("",reinterpret_cast<::dux::uwrd>(ptr) % _align == dux_uwrdl(0x0)); /* Make sure the pointer is aligned. */
	return ptr;
badalloc:;
	::dux::seterr(::dux::errcd::badalloc);
	return nullptr;
}
