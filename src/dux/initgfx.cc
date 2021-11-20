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

#include <dux/io>
#include <dux/media>
#if defined(dux_gfxproto_gl)
#include <GL/gl.h>
#endif
#if defined(dux_gfxproto_wlgl) || defined(dux_gfxproto_wlvk)
#include <wayland-client.h>
#elif defined(dux_gfxproto_xgl) || defined(dux_gfxproto_xvk)
#include <xcb/xcb.h>
#if defined(dux_gfxproto_gl)
#include <GL/glx.h>
#include <X11/Xlib-xcb.h>
#endif
#endif

#include "priv.hh"

auto ::dux::initgfx() -> void {
	::dux::dbgprint(U"dux :: Initialising the graphics module...\n");
	if (::dux::_inst.gfxinit) [[unlikely]] {
		goto isinit;
	}
#if defined(dux_gfxproto_wlgl) || defined(dux_gfxproto_wlvk)
	try {
		auto const * const dux_restr envval = ::dux::getenv("XDG_SESSION_TYPE");
		if (!!::dux::cstrcmp(envval,"wayland")) [[unlikely]] {
			::dux::print(U"dux :: Environment variable \"XDG_SESSION_TYPE\" is not set to \"wayland\", but dux is targeting Wayland!\n");
		}
	}
	catch (::dux::except const & e) {
	}
	::dux::dbgprint(U"dux :: Wayland support is experimental!\n");
	::dux::_inst.wldisp = ::wl_display_connect(nullptr);
	if (::dux::_inst.wldisp == nullptr) [[unlikely]] {
		throw ::dux::runerr("Unable to open Wayland display!");
	}
#else
	if (::dux::_inst.xconn = ::xcb_connect(nullptr,nullptr);::dux::_inst.xconn == nullptr) [[unlikely]] {
		throw ::dux::runerr("Unable to open connection to X server.");
	}
	::dux::dbgprint(U"dux :: Made a connection to an X server!\n");
	::dux::_inst.xscrn = ::xcb_setup_roots_iterator(xcb_get_setup(::dux::_inst.xconn)).data;
	::dux::dbgprint(U"dux :: Set up roots iterator!\n");
#endif
	::dux::_inst.gfxinit = true;
isinit:;
	::dux::dbgprint(U"dux :: Initialisation successful!\n");
}
