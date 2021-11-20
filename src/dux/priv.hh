/*
	Copyright 2021 Gabriel Jensen

	This file is part of dux.

	dux is free software:
	you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

	dux is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
	without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
	See the GNU Affero General Public License for more details.

	You should have received a copy of the GNU Affero General Public License along with dux.
	If not, see <https://www.gnu.org/licenses/>.
*/

#if !defined(dux_hdr_priv)
#define dux_hdr_priv

#include <dux/sys>
#if defined(dux_os_posix)
#include <pthread.h>
#endif
#if defined(dux_winsproto_wl)
#include <wayland-client.h>
#elif defined(dux_gfxproto_xgl) || defined(dux_gfxproto_xvk)
#include <xcb/xcb.h>
#endif

namespace dux {
	class _insttyp {
	public:
		bool          gfxinit                     {false};
		bool          hassigint                   {false};
		::dux::uint16 numwin                      {::dux::uint16v(0x0)};
		void (*       prevsiginthandl)(::dux::sig){::dux::dflsighandl}; /* Used for setting the previous signal handler in case there aren't any open windows to handle the signal. */
		bool          siginthandlset              {false};
#if defined(dux_gfxproto_wlgl) || defined(dux_gfxproto_wlvk)
		::wl_display * wldisp{nullptr};
#elif defined(dux_gfxproto_xgl) || defined(dux_gfxproto_xvk)
		::xcb_connection_t * xconn{nullptr};
		::xcb_screen_t *     xscrn{nullptr};
#endif
	} inline _inst;

#if defined(dux_os_posix)
	class _pthrddat {
	public:
		pthread_t pthrd;
	};
#endif

	auto _setsiginthandl()                        -> void;
	auto _siginthandl(   ::dux::sig)     noexcept -> void;
	auto _sigtocsig(     ::dux::sig sig) noexcept -> int;
}

#endif
