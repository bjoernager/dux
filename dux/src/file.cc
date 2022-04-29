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

namespace dux::local {
	[[nodiscard]] constexpr static auto iotypstr(::dux::iotyp const _typ) noexcept -> ::dux::str {
		switch (_typ) {
		case ::dux::iotyp::r:
			return ::dux::priv::strlittoduxstr("R");
		case ::dux::iotyp::rw:
			return ::dux::priv::strlittoduxstr("R/W");
		case ::dux::iotyp::w:
			return ::dux::priv::strlittoduxstr("W");
		}
		::dux::unreach();
	}
}

::dux::file::file() noexcept : _isopen(false) {this->_sysdat = ::dux::alloc<::dux::priv::filesysdat>();}

::dux::file::~file() noexcept {	
	if (this->isopen()) [[unlikely]] {
		::dux::dbglog("dux.\x1B[91mfile\x1B[0m :: Pipe wasn't closed!\n");
		::dux::abrt();
	}
	auto const sysdat {static_cast<::dux::priv::filesysdat *>(this->_sysdat)};
	::dux::free(sysdat);
}

auto ::dux::file::close() noexcept -> void {
	if (!this->isopen()) [[unlikely]] {return;}
	::dux::dbglog("dux.file.close  :: Close \"%s\"\n",this->path().ptr);
	auto const sysdat {static_cast<::dux::priv::filesysdat *>(this->_sysdat)};
# if defined(dux_os_posix)
close:;
	auto const closeret {::dux_priv_posix_close(sysdat->fd)};
	if (closeret == -0x1) [[unlikely]] {
		switch (dux_priv_errno) {
		default:
			::dux::seterr(::dux::errcd::runerr);
			break;
		case EINTR:
			goto close;
		}
		::dux::dbglog("dux.file.open   :: Error!\n");
		return;
	}
# endif
	this->_isopen = false;
}

auto ::dux::file::isopen() noexcept -> bool {return this->_isopen;}

# if false /* Base for dux.pipe.mv (for future implementation): */
auto ::dux::file::mv(char const * const _newpath) noexcept -> ::dux::str {
	auto const oldpath {this->path()};
	auto const newpath {[&_newpath] {
		::dux::str newpath;
		newpath.ptr = _newpath;
		newpath.sz  = ::dux::strlen(_newpath);
		return newpath;
	}()};
	if (newpath.sz != oldpath.sz || !::dux::memeq(newpath.ptr,newpath.sz,oldpath.ptr)) [[unlikely]] {goto retold;}
retold:;
	return oldpath;
}
# endif

auto ::dux::file::open(char const * const _path,::dux::iotyp const _typ) noexcept -> void {
	dux_ass("",_path != nullptr);
	if (this->isopen()) [[unlikely]] {this->close();}
	::dux::dbglog("dux.file.open   :: Open %s:\"%s\"\n",::dux::local::iotypstr(_typ).ptr,_path);
	auto const sysdat {static_cast<::dux::priv::filesysdat *>(this->_sysdat)};
# if defined(dux_os_posix)
	auto const openatflags {[&_typ] {
		switch (_typ) {
		case ::dux::iotyp::r:
			return O_RDONLY;
		case ::dux::iotyp::rw:
			return O_RDWR;
		case ::dux::iotyp::w:
			return O_WRONLY;
		}
		::dux::unreach();
	}()};
open:;
	auto const openatret {::dux_priv_posix_openat(AT_FDCWD,_path,openatflags,static_cast<::mode_t>(0x0))};
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
		case ENOENT:
			::dux::seterr(::dux::errcd::nofile);
			break;
		case ENOTDIR:
			::dux::seterr(::dux::errcd::nodir);
			break;
		}
		::dux::dbglog("dux.file.\x1B[91mopen\x1B[0m   :: Error!\n");
		return;
	}
	sysdat->fd = openatret;
# endif
	this->_path.ptr = _path;
	this->_path.sz  = ::dux::strlen(_path);
	this->_typ      = _typ;
	this->_isopen   = true;
}

auto ::dux::file::path() const noexcept -> ::dux::str {return this->_path;}

auto ::dux::file::read(::dux::uwrd const _num) noexcept -> ::dux::arr<::dux::uint8> {
	if (!this->isopen()) [[unlikely]] {
		::dux::dbglog("dux.file.\x1B[91mread\x1B[0m   :: Pipe not open!\n");
		::dux::abrt();
	}
	if (this->typ() != ::dux::iotyp::r && this->typ() != ::dux::iotyp::rw) [[unlikely]] {
		::dux::dbglog("dux.file.\x1B[91mread\x1B[0m   :: I/O type (%s) does not support reading!\n",::dux::local::iotypstr(_typ).ptr);
		::dux::abrt();
	}
	::dux::dbglog("dux.file.read   :: Read %zu @ \"%s\"\n",_num,this->path());
	auto const sysdat {static_cast<::dux::priv::filesysdat *>(this->_sysdat)};
	::dux::arr<::dux::uint8> buf;
	buf.alloc(_num);
# if defined(dux_os_posix)
read:;
	auto const readret {::dux_priv_posix_read(sysdat->fd,buf.raw(),_num)};
	if (readret == dux_swrdl(-0x1)) [[unlikely]] {
		switch (dux_priv_errno) {
		case EINTR:
			goto read;
		}
		::dux::dbglog("dux.file.\x1B[91mread\x1B[0m   :: Unable to read file!\n");
		::dux::seterr(::dux::errcd::ioerr);
		buf.free();
		return buf;
	}
# endif
	return buf;
}

auto ::dux::file::typ() const noexcept -> ::dux::iotyp {return this->_typ;}

auto ::dux::file::write(void const * const _buf,::dux::uwrd const _sz) noexcept -> void {
	dux_ass("",_buf != nullptr);
	dux_ass("",_sz != dux_uwrdl(0x0));
	if (!this->isopen()) [[unlikely]] {
		::dux::dbglog("dux.file.\x1B[91mwrite\x1B[0m  :: Pipe not open!\n");
		::dux::abrt();
	}
	if (this->typ() != ::dux::iotyp::rw && this->typ() != ::dux::iotyp::w) [[unlikely]] {
		::dux::dbglog("dux.file.\x1B[91mwrite\x1B[0m  :: I/O type (%s) does not support writting!\n",::dux::local::iotypstr(_typ));
		::dux::abrt();
	}
	auto const sysdat {static_cast<::dux::priv::filesysdat *>(this->_sysdat)};
	::dux::dbglog("dux.file.write  :: Write %zu @ %p -> \"%s\"\n",_sz,_buf,this->path().ptr);
# if defined(dux_os_posix)
	::dux_priv_posix_write(sysdat->fd,_buf,_sz);
	::dux_priv_posix_fsync(sysdat->fd);
# endif
}
