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

# include <dux/math>

# include <sys/random.h>
# if defined(dux_os_freebsd)
# include <errno.h>
# elif defined(dux_os_linux)
# include <linux/errno.h>
# endif

auto ::dux::priv::rnd(::dux::uint8 * const restrict _buf,::dux::uwrd const _sz) noexcept -> void {
getrnd:;
	auto const getrndret = ::dux_priv_posix_getrandom(_buf,_sz,GRND_NONBLOCK);
	if (getrndret == dux_swrdl(-0x1)) [[unlikely]] {
		if (dux_priv_errno == EAGAIN) [[likely]] {goto getrnd;} /* We specify this as likely to speed this loop up. */
		return;
	}
	dux_ass("",static_cast<::dux::uwrd>(getrndret) == _sz);
}
