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

#if defined(dux_os_posix)
#include <dlfcn.h>
#endif

namespace dux {
	class _dobjdat {
	public:
#if defined(dux_os_posix)
		void * dlhandl{nullptr};
#endif
	};
}

template<typename T,typename... Ts> auto ::dux::dobj::call(char const * const dux_restr _fn,Ts const &... _args) -> T {
	[[maybe_unused]] auto const dat = static_cast<::dux::_dobjdat *>(this->_dat);
	dux_ass(_fn != nullptr,"Input C-string points to null!");
#if defined(dux_os_posix)
	dux_ass(dat->dlhandl != nullptr,"Dynamic object has not been linked!");
	auto const sym = reinterpret_cast<T (*)(Ts...)>(::dlsym(dat->dlhandl,_fn));
	if (sym == nullptr) [[unlikely]] {
		throw ::dux::runerr("Unable to load function!");
	}
	return sym(_args...);
#endif
}
::dux::dobj::dobj() : _dat(::new ::dux::_dobjdat) {
}
auto ::dux::dobj::link(char const * const dux_restr _lib) -> void {
	[[maybe_unused]] auto const dat = static_cast<::dux::_dobjdat *>(this->_dat);
	dux_ass(_lib != nullptr,"Input C-string points to null!");
#if defined(dux_os_posix)
	dat->dlhandl = ::dlopen(_lib,RTLD_LOCAL | RTLD_NOW);
	if (dat->dlhandl == nullptr) [[unlikely]] {
		throw ::dux::runerr("Unable to open library!");
	}
#endif
}
auto ::dux::dobj::unlink() noexcept -> void {
	[[maybe_unused]] auto const dat = static_cast<::dux::_dobjdat *>(this->_dat);
#if defined(dux_os_posix)
	if (dat->dlhandl != nullptr) {
		::dlclose(dat->dlhandl);
		dat->dlhandl = nullptr;
	}
#endif
}
::dux::dobj::~dobj() noexcept {
	::delete static_cast<::dux::_dobjdat *>(this->_dat);
}
