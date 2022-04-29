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

# include <dux/io>

# include <dux/str>

# include <fcntl.h>
# if defined(dux_os_freebsd)
# include <errno.h>
# elif defined(dux_os_linux)
# include <linux/errno.h>
# endif

auto ::dux::crtfile(char const * _path,::dux::uint16 const _acs) noexcept -> ::dux::file {
	dux_ass("",_path != nullptr);
	::dux::file file;
	::dux::dbglog("dux.crtfile     :: Create \"%s\"\n",_path);
	auto const sysdat {static_cast<::dux::priv::filesysdat *>(file._sysdat)};
# if defined(dux_os_posix)
open:;
	auto const openatret {::dux_priv_posix_openat(AT_FDCWD,_path,O_CREAT | O_TRUNC | O_WRONLY,static_cast<::mode_t>(_acs))};
	if (openatret == -0x1) [[unlikely]] {
		switch (dux_priv_errno) {
		default:
			::dux::seterr(::dux::errcd::runerr);
			break;
		case EACCES:
			[[fallthrough]];
		case EROFS:
			::dux::seterr(::dux::errcd::badacs);
			break;
		case EINTR:
			goto open;
		case ENOTDIR:
			::dux::seterr(::dux::errcd::nodir);
			break;
		}
		::dux::dbglog("dux.\x1B[91mcrtfile\x1B[0m     :: Error!\n");
		return file;
	}
	sysdat->fd = openatret;
# endif
	file._path.ptr = _path;
	file._path.sz  = ::dux::strlen(_path);
	file._typ      = ::dux::iotyp::w;
	file._isopen   = true;
	return file;
}
