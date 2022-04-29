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

# include <sys/types.h>

auto ::dux::raise(::dux::sig const _sig) noexcept -> void {
	auto const syssig = static_cast<int>(_sig);
	::dux::dbglog("dux.raise       :: Raise #%i\n",syssig);
# if defined(dux_priv_nosigtrap)
	switch (_sig) {
	[[likely]] default:
		break;
	case ::dux::sig::term:
		::dux_priv_dbglog("dux.raise       :: Terminated!\n");
		::dux::exit(::dux::stat::err);
	case ::dux::sig::trap:
		::dux::trap();
	}
# endif
	::dux_priv_posix_kill(::dux_priv_posix_getpid(),syssig);
}

# pragma GCC diagnostic ignored "-Wmissing-declarations"

extern "C" auto dux_raise(dux_priv_sig const _sig) -> void {return ::dux::raise(static_cast<::dux::sig>(_sig));}
