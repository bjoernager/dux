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

# include <cstdlib>

extern "C" auto dux_priv_free(void * const restrict _ptr) -> void {
	if constexpr (::dux::dbg) {if (_ptr == nullptr) [[unlikely]] {::dux::free(nullptr);}}
	::std::free(static_cast<::dux::uint8 *>(_ptr));
}
