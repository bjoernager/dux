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

# include <atomic>
# include <csetjmp>

namespace dux::priv {
	class filesysdat {
	public:
# if defined(dux_os_posix)
		int fd;
# endif
	};
}

namespace dux::priv {
	inline ::std::jmp_buf       exitjmp;
	inline ::dux::stat volatile exitstat;

	constexpr auto                  maxnumonexitfns                         {dux_uwrdl(0x100)};
	inline    ::std::atomic<bool>   exitlock;
	inline    ::dux::priv::onexitfn onexitfns[::dux::priv::maxnumonexitfns];
	inline    ::std::atomic<bool>   onexitlock;
	inline    auto                  numonexitfns                            {dux_uwrdl(0x0)};
}
