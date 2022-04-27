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

auto ::dux::trap() noexcept -> void {
	for (;;) {
# if !defined(dux_priv_nosigtrap)
		::dux::raise(::dux::sig::trap); /* POSIX systems have a signal for trapping. Use it. */
# elif defined(dux_arch_x86)
		asm volatile ( /* x86 has an interrupt instruction. Use it. */
			"int3\n"
		);
# elif dux_hasbuiltin(__builtin_trap)
		::__builtin_trap();	
# endif
	}
}

# pragma GCC diagnostic ignored "-Wmissing-declarations"

extern "C" auto dux_trap() -> void {::dux::trap();}
