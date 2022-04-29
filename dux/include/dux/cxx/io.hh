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

namespace dux::ioacs {
	constexpr static auto uid  {static_cast<::dux::uint16>(dux_priv_ioacs_uid)};
	constexpr static auto gid  {static_cast<::dux::uint16>(dux_priv_ioacs_gid)};
	constexpr static auto stck {static_cast<::dux::uint16>(dux_priv_ioacs_stck)};
	constexpr static auto usrr {static_cast<::dux::uint16>(dux_priv_ioacs_usrr)};
	constexpr static auto usrw {static_cast<::dux::uint16>(dux_priv_ioacs_usrw)};
	constexpr static auto usrx {static_cast<::dux::uint16>(dux_priv_ioacs_usrx)};
	constexpr static auto grpr {static_cast<::dux::uint16>(dux_priv_ioacs_grpr)};
	constexpr static auto grpw {static_cast<::dux::uint16>(dux_priv_ioacs_grpr)};
	constexpr static auto grpx {static_cast<::dux::uint16>(dux_priv_ioacs_grpr)};
	constexpr static auto othr {static_cast<::dux::uint16>(dux_priv_ioacs_othr)};
	constexpr static auto othw {static_cast<::dux::uint16>(dux_priv_ioacs_othr)};
	constexpr static auto othx {static_cast<::dux::uint16>(dux_priv_ioacs_othr)};
}

namespace dux {
	enum class iotyp : ::dux::uint8 {
		r  = static_cast<::dux::uint8>(::dux_priv_iotyp_r),
		rw = static_cast<::dux::uint8>(::dux_priv_iotyp_rw),
		w  = static_cast<::dux::uint8>(::dux_priv_iotyp_w),
	};
}

namespace dux {
	class file;
}

namespace dux {
	[[nodiscard]] auto crtfile(char const * path,::dux::uint16 acs = ::dux::ioacs::usrr | ::dux::ioacs::usrw | ::dux::ioacs::grpr | ::dux::ioacs::othr /* -rw-r--r-- */) noexcept -> ::dux::file;
}

namespace dux {
	class file {
	public:
		[[nodiscard]] file()  noexcept;
		              ~file() noexcept;

		              auto close()                                                               noexcept -> void;
		              auto del()                                                                 noexcept -> void                     = delete;
		[[nodiscard]] auto isopen()                                                              noexcept -> bool;
		              auto open(  char const * path,                     ::dux::iotyp typ)       noexcept -> void;
		[[nodiscard]] auto path()                                                          const noexcept -> ::dux::str;
		[[nodiscard]] auto read(  ::dux::uwrd  num     = dux_uwrdl(-0x1))                        noexcept -> ::dux::arr<::dux::uint8>;
		              auto mv(    char const * newpath)                                          noexcept -> ::dux::str               = delete;
		              auto reopen()                                                              noexcept -> void;
		[[nodiscard]] auto typ()                                                           const noexcept -> ::dux::iotyp;
		              auto write( void const * buf,                      ::dux::uwrd  sz)        noexcept -> void;

		template<::dux::uwrd N> auto write(char const (&         _buf)[N]) noexcept -> void {this->write(_buf,N - dux_uwrdl(0x1));}
		template<typename    T> auto write(T const &             _val)     noexcept -> void {this->write(&_val,sizeof (T));}
		template<typename    T> auto write(::dux::arr<T> const & _buf)     noexcept -> void {
			dux_ass("",_buf.isalloc());
			this->write(_buf.raw(),_buf.sz() * sizeof (T));
		}

		friend auto ::dux::crtfile(char const * path,::dux::uint16 acs) noexcept -> ::dux::file;
	private:
		bool         _isopen;
		::dux::str   _path;
		void *       _sysdat;
		::dux::iotyp _typ;
	};
}
