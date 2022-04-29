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

# include <dux/mem>
# include <dux/sig>

# include <csetjmp>

auto main(int const argc,char const * const * const argv) -> int {return ::dux_priv_start(argc,argv);}

extern "C" auto dux_main(::dux::mainparams const *) -> ::dux::stat;

extern "C" auto dux_priv_start(int const argc,char const * const * const argv) -> int {
	::dux::dbglog("dux.priv.start  :: Bootstrapping!\n");
	::dux::mainparams mainparams;
	mainparams.fromstd(argc,argv);
	::dux::stat volatile stat;
	if (setjmp(::dux::priv::exitjmp) == 0x0) {
		try {stat = ::dux_main(&mainparams);}
		catch (...) {
			::dux::dbglog("dux.\x1B[91mpriv.start\x1B[0m  :: Exception was not caught!\n");
			::dux::abrt();
		}
		::dux::priv::exitlock.store(true); /* Disable all future exits. */
		::dux::dbglog("dux.priv.start  :: Program returned!\n");
	}
	else {stat = ::dux::priv::exitstat;}
	while (::dux::priv::onexitlock.load()) {} /* Wait for the remaining onexit function to be registered, if any. */
	if (::dux::priv::numonexitfns > dux_uwrdl(0x0)) {
		using ::dux::priv::onexitfns;
		for (::dux::uwrd n {::dux::priv::numonexitfns};n > 0x0;--n) {
			auto const fn {onexitfns[n - dux_uwrdl(0x1)]};
			::dux::dbglog("dux.exit        :: Calling registered function #%zu at %p!\n",n - dux_uwrdl(0x1),reinterpret_cast<void *>(fn));
			if (fn == nullptr) [[unlikely]] {
				::dux::dbglog("dux.exit        :: Registered function is invalid (address is null)!\n");
				::dux::raise(::dux::sig::segv);
			}
			try {fn(stat);} /* Registered functions may not throw exceptions. */
			catch (...) {
				::dux_priv_logstderr("dux.exit        :: Registered function threw an exception!\n");
				::dux::abrt();
			}
		}
	}
	::dux::dbglog("dux.exit        :: Exiting with system code (%i)!\n",static_cast<int>(stat));
	return static_cast<int>(stat);
}
