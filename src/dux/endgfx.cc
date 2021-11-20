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

auto ::dux::endgfx() -> void {
	::dux::dbgprint(U"dux :: Ending the graphics module...\n");
	dux_ass(!::dux::_inst.numwin,"Ammount of windows is non-zero!");
	if (!::dux::_inst.gfxinit) [[unlikely]] {
		goto isend;
	}
#if defined(dux_gfxproto_wlgl) || defined(dux_gfxproto_wlvk)
#elif defined(dux_gfxproto_xgl) || defined(dux_gfxproto_xvk)
	::dux::print(U"dux :: Disconnecting from the X server!\n");
	::xcb_disconnect(::dux::_inst.xconn);
#endif
isend:;
	::dux::dbgprint(U"dux :: Ending successful!\n");
}
