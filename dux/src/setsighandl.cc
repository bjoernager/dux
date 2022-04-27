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

# include <dux/sig>

# include <signal.h>
# if defined(dux_os_freebsd)
# include <sys/syscall.h>
# elif defined(dux_os_linux)
# include <linux/unistd.h>
# endif

namespace dux::local {
	static ::dux::sighandl sighandls[static_cast<::dux::uwrd>(::dux::numsig)] {};
}

auto ::dux::setsighandl(::dux::sig const _sig,::dux::sighandl const _handl) noexcept -> void {
	switch (_sig) { /* We don't allow signal handler to be registered for every signal. */
	[[likely]] default:
		break;
	case ::dux::sig::abrt:
		[[fallthrough]];
	case ::dux::sig::kill:
		[[fallthrough]];
	case ::dux::sig::trap:
		if (!_handl._isdfl) [[unlikely]] {
			::dux::dbglog("dux :: \x1B[91msetsighandl\x1B[0m :: Attempted setting custom signal handler for SIGABRT, SIGKILL or SIGTRAP (not allowed)!\n");
			::dux::seterr(::dux::errcd::badperms);
			return;
		}
	}
	if constexpr (::dux::dbg) {
		if (!_handl._isdfl) {
			if (_handl.handl == nullptr) [[unlikely]] {
				::dux::dbglog("dux :: \x1B[91msetsighandl\x1B[0m :: Handler invalid (address is null)!\n");
				::dux::seterr(::dux::errcd::illparam);
				return;
			}
		}
	}
	           ::dux::local::sighandls[static_cast<::dux::uwrd>(_sig)] = _handl;
	auto const sig                                                      {static_cast<int>(_sig)};
	{
		auto handlwrap {[](int const _sig) {
			auto const & handl    {::dux::local::sighandls[static_cast<::dux::uwrd>(_sig)]};
			auto const   handlret {handl.handl(static_cast<::dux::sig>(_sig))};
			auto const   handlptr {reinterpret_cast<void *>(handl.handl)};
			if (handlret) [[unlikely]] {
				::dux::dbglog("dux :: \x1B[91mraise\x1B[0m :: Signal handler for #%i (at %p) indicated error!\n",_sig,handlptr);
				::dux::abrt();
			}
			switch (_sig) {
			[[likely]] default:
				break;
			case SIGFPE:
				[[fallthrough]];
			case SIGILL:
				[[fallthrough]];
			case SIGSEGV:
				::dux::dbglog("dux :: \x1B[91mraise\x1B[0m :: Signal handler for SIGFPE, SIGILL or SIGSEGV (at %p) returned and did not indicate error (not allowed)!\n",handlptr);
				::dux::abrt();
			}
		}};
		struct ::sigaction sigact {};
		if (_handl == ::dux::sighandl::dfl()) {
			::dux::dbglog("dux :: setsighandl :: Setting default signal handler for signal #%i!\n",sig);
			sigact.sa_handler = SIG_DFL;
		}
		else {
			::dux::dbglog("dux :: setsighandl :: Setting signal handler (at %p) for signal #%i!\n",_handl.handl,sig);
			sigact.sa_handler = handlwrap;
		}
		::sigemptyset(&sigact.sa_mask);
		sigact.sa_flags = SA_RESTART;
		struct ::sigaction oldsigact;
		if (::sigaction(sig,&sigact,&oldsigact) == -0x1) [[unlikely]] { /* priv.posix.sigaction does not work for some reason on Linux, so we just use the POSIX function directly. */
			::dux::seterr(::dux::errcd::runerr);
			return;
		}
	}
}

# pragma GCC diagnostic ignored "-Wmissing-declarations"

extern "C" auto dux_setsighandl(::dux_priv_sig const _sig,::dux_priv_ctyp_sighandl const _handl) -> void {
	auto const cxxhandl {[&] {
		if (_handl == dux_priv_dflcsighandl) {return ::dux::sighandl::dfl();}
		return ::dux::sighandl {reinterpret_cast<auto (*)(::dux::sig) -> bool>(reinterpret_cast<void *>(_handl))};
	}()};
	::dux::setsighandl(static_cast<::dux::sig>(_sig),cxxhandl);
}
