/*
	Copyright 2021 Gabriel Jensen

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

#include <dux/io>

#include <cerrno>
#include <signal.h>
#if defined(dux_os_linux)
#include <sys/syscall.h>
#include <unistd.h>
#endif

#include "priv.hh"

namespace dux::_static {
	static auto (* _sighandls[::dux::numsig])(::dux::sig) -> void;

	static auto _sigwrap(int sig) -> void;
}

static auto ::dux::_static::_sigwrap(int const _sig) -> void {
#if !defined(dux_os_posix)
	::signal(_sig,::dux::_static::sigwrap);
#endif
	auto const sig = [&]() {
		switch(_sig) {
		default:
			::dux::abrt();
		case SIGABRT:
			return ::dux::sig::abrt;
		case SIGFPE:
			return ::dux::sig::fpe;
		case SIGILL:
			return ::dux::sig::ill;
		case SIGINT:
			return ::dux::sig::int_;
		case SIGSEGV:
			return ::dux::sig::segv;
		case SIGTERM:
			return ::dux::sig::term;
		}
	}();
	::dux::_static::_sighandls[static_cast<::dux::usz>(sig)](sig);
}

auto ::dux::sighandl(::dux::sig const _sig,auto (* const _handl)(::dux::sig) -> void) -> auto (&)(::dux::sig) -> void {
	::dux::print(U"dux :: Setting signal handler!\n");
	auto &     handl    = ::dux::_static::_sighandls[static_cast<::dux::usz>(_sig)];
	auto const oldhandl = handl;
	           handl    = _handl;
	auto const sig = ::dux::_sigtocsig(_sig);
	if (_handl == ::dux::dflsighandl) {
		::signal(sig,SIG_DFL);
		goto ret;
	}
	{
#if defined(dux_os_posix)
		struct ::sigaction sigact{};
		sigact.sa_handler = ::dux::_static::_sigwrap;
		::sigemptyset(&sigact.sa_mask);
		sigact.sa_flags = SA_RESTART;
#endif
		if ([&]() {
//#if defined(dux_os_linux)
//			return ::syscall(__NR_rt_sigaction,sig,&sigact,nullptr,sizeof(::sigset_t)) == -0x1l; /* This syscall returns EINVAL and I could not get it to work. */
//#elif defined(dux_os_posix)
#if defined(dux_os_posix)
			return ::sigaction(sig,&sigact,nullptr) == -0x1;
#else
			return ::std::signal(sig,::dux::_static::_sigwrap) == SIG_ERR;
#endif
		}()) [[unlikely]] {
			throw ::dux::runerr("Unable to set signal handler!");
		}
	}
ret:;
	return *oldhandl;
}
