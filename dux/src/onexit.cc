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

# include <atomic>

auto ::dux::onexit(::dux::priv::onexitfn const _fn) noexcept -> void {
	if (::dux::priv::exitlock.load()) [[unlikely]] {
		::dux::dbglog("dux :: \x1B[91monexit\x1B[0m :: Invoked after exit!\n");
		::dux::seterr(::dux::errcd::illcallseq);
		return;
	}
	using ::dux::priv::onexitlock;
	{
		while (onexitlock.load()) {} /* Wait for other threads to register onexit functions. */
		onexitlock.store(true);
		using ::dux::priv::onexitfns;
		using ::dux::priv::numonexitfns;
		for (auto n {dux_uwrdl(0x0)};n < numonexitfns;++n) {if (onexitfns[n] == _fn) [[unlikely]] {
			::dux::dbglog("dux :: onexit :: Function at %p has already been registered!\n",reinterpret_cast<void *>(_fn));
			goto ret;
		}}
		if (numonexitfns == ::dux::priv::maxnumonexitfns) [[unlikely]] {
			::dux::dbglog("dux :: \x1B[91monexit\x1B[0m :: Function at %p cannot be registered as limit (%zu) has been reached!\n",reinterpret_cast<void *>(_fn),::dux::priv::maxnumonexitfns);
			::dux::seterr(::dux::errcd::nospc);
			goto ret;
		}
		::dux::dbglog("dux :: onexit :: Registering function at %p!\n",reinterpret_cast<void *>(_fn));
		++numonexitfns;
		onexitfns[numonexitfns - 0x1] = _fn;
	}
ret:;
	onexitlock.store(false);
}

# pragma GCC diagnostic ignored "-Wmissing-declarations"

extern "C" dux_attr_cold auto dux_onexit(::dux::priv::onexitfn const _fn) -> void {::dux::onexit(_fn);}
