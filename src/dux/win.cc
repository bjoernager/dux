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

#include <cstdlib>
#include <dux/io>
#include <dux/media>
#if defined(dux_gfxproto_wlgl) || defined(dux_gfxproto_wlvk)
#include <wayland-client.h>
#elif defined(dux_gfxproto_xgl) || defined(dux_gfxproto_xvk)
#include <xcb/xcb.h>
#include <xcb/xcb_atom.h>
#endif

#include "priv.hh"

namespace dux {
	class windat {
	public:
		bool open{false};
#if defined(dux_gfxproto_wlgl) || defined(dux_gfxproto_wlvk)
		::wl_shell_surface * wlsurf{nullptr};
#elif defined(dux_gfxproto_xgl) || defined(dux_gfxproto_xvk)
		::xcb_window_t xwin{};
#endif
	};
}
auto ::dux::win::close() -> void {
	[[maybe_unused]] auto * const dux_restr dat = static_cast<::dux::windat *>(this->_dat);
	::dux::dbgprint(U"dux :: Closing window!\n");
#if defined(dux_gfxproto_wlgl) || defined(dux_gfxproto_wlvk)
#elif defined(dux_gfxproto_xgl) || defined(dux_gfxproto_xvk)
	::xcb_unmap_window(::dux::_inst.xconn,dat->xwin);
	::xcb_flush(::dux::_inst.xconn);
# endif
	this->_isopen = false;
	::dux::_inst.numwin -= ::dux::uint16v(0x1);
	::dux::dbgprint(U"dux :: Current number of windows: $\n",::dux::_inst.numwin);
	::dux::dbgprint(U"dux :: Unsetting the SIGINT signal handler!\n");
	if (!::dux::_inst.numwin) {
		::dux::sighandl(::dux::sig::int_,*::dux::_inst.prevsiginthandl);
		::dux::_inst.siginthandlset = false;
		return;
	}
	::dux::dbgprint(U"dux :: An open window exists!\n");
}
auto ::dux::win::crt(char const * const dux_restr _nm,::dux::uint16 const _w,::dux::uint16 const _h) -> ::dux::win {
	::dux::win win;
	[[maybe_unused]] auto * const dux_restr dat = static_cast<::dux::windat *>(win._dat);
#if defined(dux_gfxproto_wlgl)
#elif defined(dux_gfxproto_xgl) || defined(dux_gfxproto_xvk)
	dat->xwin = ::xcb_generate_id(::dux::_inst.xconn);
	::dux::uint32 valmask[] = {
		XCB_EVENT_MASK_EXPOSURE,
	};
	::xcb_create_window(::dux::_inst.xconn,XCB_COPY_FROM_PARENT,dat->xwin,::dux::_inst.xscrn->root,::dux::uint16v(0x0),::dux::uint16v(0x0),_w,_h,::dux::uint16v(0x0),XCB_WINDOW_CLASS_INPUT_OUTPUT,::dux::_inst.xscrn->root_visual,::dux::uint32v(0x0),valmask);
	::xcb_map_window(::dux::_inst.xconn,dat->xwin);
	::xcb_flush(::dux::_inst.xconn);
	win.renm(_nm);
#endif
	::dux::_inst.numwin += ::dux::uint16v(0x1);
	::dux::dbgprint(U"dux :: Current number of windows: $\n",::dux::_inst.numwin);
	::dux::_setsiginthandl();
	win._isopen = true;
	return win;
}
auto ::dux::win::destr() noexcept -> void {
	::dux::dbgprint(U"dux :: Destroying window!\n");
	this->close();
	::delete static_cast<::dux::windat *>(this->_dat);
}
auto ::dux::win::open() -> void {
	[[maybe_unused]] auto * const dux_restr dat = static_cast<::dux::windat *>(this->_dat);
	::dux::dbgprint(U"dux :: Opening window!\n");
#if defined(dux_gfxproto_wlgl) || defined(dux_gfxproto_wlvk)
#elif defined(dux_gfxproto_xgl) || defined(dux_gfxproto_xvk)
	::xcb_map_window(::dux::_inst.xconn,dat->xwin);
	::xcb_flush(::dux::_inst.xconn);
# endif
	::dux::_inst.numwin += ::dux::uint16v(0x1);
	::dux::dbgprint(U"dux :: Current number of windows: $\n",::dux::_inst.numwin);
	::dux::_setsiginthandl();
	this->_isopen = true;
}
auto ::dux::win::pollevt() noexcept -> ::dux::opt<::dux::evt> {
	::dux::evt evt;
	if (::dux::_inst.hassigint) [[unlikely]] {
		evt.typ = ::dux::evttyp::quit;
		::dux::_inst.hassigint = false;
		return evt;
	}
#if defined(dux_gfxproto_xgl) || defined(dux_gfxproto_xvk)
	while (auto const xevt = ::xcb_poll_for_event(::dux::_inst.xconn)) {
		switch (xevt->response_type & ~0x80) {
		case XCB_CLIENT_MESSAGE:
			evt.typ = ::dux::evttyp::quit;
			break;
		}
		::std::free(xevt);
		return evt;
	}
#endif
	return evt;
}
auto ::dux::win::renm(char const * const dux_restr _nm) -> void {
	[[maybe_unused]] auto * const dux_restr dat = static_cast<::dux::windat *>(this->_dat);
#if defined(dux_gfxproto_wlgl) || defined(dux_gfxproto_wlvk)
#elif defined(dux_gfxproto_xgl) || defined(dux_gfxproto_xvk)
	::xcb_change_property(::dux::_inst.xconn,XCB_PROP_MODE_REPLACE,dat->xwin,XCB_ATOM_WM_NAME,XCB_ATOM_STRING,::dux::ubytev(0x8),static_cast<::dux::uint32>(::dux::cstrlen(_nm)),_nm);
	::xcb_flush(::dux::_inst.xconn);
# endif
}
auto ::dux::win::resz(::dux::uint16 const _w,::dux::uint16 const _h) -> void {
	[[maybe_unused]] auto * const dux_restr dat = static_cast<::dux::windat *>(this->_dat);
#if defined(dux_gfxproto_wlgl) || defined(dux_gfxproto_wlvk)
#elif defined(dux_gfxproto_xgl) || defined(dux_gfxproto_xvk)
	::dux::uint32 const vals[] = {
		_w,
		_h,
	};
	::xcb_configure_window(::dux::_inst.xconn,dat->xwin,XCB_CONFIG_WINDOW_HEIGHT | XCB_CONFIG_WINDOW_WIDTH,vals);
	::xcb_flush(::dux::_inst.xconn);
#endif
}
::dux::win::win() : _dat(::new ::dux::windat) {
}
::dux::win::~win() noexcept {
	if (this->_isopen) [[unlikely]] {
		::dux::dbgprint(U"dux :: Window was not closed!\n");
		::dux::abrt();
	}
}
