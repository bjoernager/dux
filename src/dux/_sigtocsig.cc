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
#include <signal.h>

#include "priv.hh"

auto ::dux::_sigtocsig(::dux::sig const _sig) noexcept -> int {
	switch (_sig) {
	default:
		::dux::print(U"dux :: _::dux::_sigtocsig recieved unknown signal!\n");
		::dux::abrt();
	case ::dux::sig::abrt:
		return SIGABRT;
	case ::dux::sig::fpe:
		return SIGFPE;
	case ::dux::sig::ill:
		return SIGILL;
	case ::dux::sig::int_:
		return SIGINT;
	case ::dux::sig::segv:
		return SIGSEGV;
	case ::dux::sig::term:
		return SIGTERM;
#if defined(dux_os_posix)
	case ::dux::sig::alrm:
		return SIGALRM;
	case ::dux::sig::bus:
		return SIGBUS;
	case ::dux::sig::cont:
		return SIGCONT;
	case ::dux::sig::hup:
		return SIGHUP;
	case ::dux::sig::iot:
		return SIGIOT;
	case ::dux::sig::kill:
		return SIGKILL;
	case ::dux::sig::pipe:
		return SIGPIPE;
	case ::dux::sig::poll:
		return SIGPOLL;
	case ::dux::sig::prof:
		return SIGPROF;
	case ::dux::sig::quit:
		return SIGQUIT;
	case ::dux::sig::rtmax:
		return SIGRTMAX;
	case ::dux::sig::rtmin:
		return SIGRTMIN;
	case ::dux::sig::stop:
		return SIGSTOP;
	case ::dux::sig::sys:
		return SIGSYS;
	case ::dux::sig::trap:
		return SIGTRAP;
	case ::dux::sig::tstp:
		return SIGTSTP;
	case ::dux::sig::ttin:
		return SIGTTIN;
	case ::dux::sig::ttou:
		return SIGTTOU;
	case ::dux::sig::urg:
		return SIGURG;
	case ::dux::sig::usr1:
		return SIGUSR1;
	case ::dux::sig::usr2:
		return SIGUSR2;
	case ::dux::sig::vtalrm:
		return SIGVTALRM;
	case ::dux::sig::winch:
		return SIGWINCH;
	case ::dux::sig::xcpu:
		return SIGXCPU;
	case ::dux::sig::xfsz:
		return SIGXFSZ;
#endif
	}
};
