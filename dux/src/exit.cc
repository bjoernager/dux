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

# include <sys/types.h>
# if defined(dux_os_freebsd)
# include <sys/syscall.h>
# elif defined(dux_os_linux)
# include <linux/unistd.h>
# endif

auto ::dux::exit(::dux::stat const _stat) noexcept -> void {
# if defined(dux_os_linux)
	if (::dux_priv_posix_getpid() != static_cast<::pid_t>(::dux::syscall(__NR_gettid))) [[unlikely]] { /* Check if calling thread is also the main thread. Only thread exit and quick exit are allowed outside the main thread. */
		::dux::dbglog("dux :: \x1B[91mexit\x1B[0m :: Standard exit invoked outside main thread!\n");
		::dux::abrt();
	}
# endif
	::dux::priv::exitlock.store(true);
	::dux::priv::exitstat = _stat;
	::std::longjmp(::dux::priv::exitjmp,0x1);
}

auto ::dux::exit(::dux::stat const _stat,::dux::priv::qexit) noexcept -> void {
	using ::dux::priv::exitlock;
	if (exitlock.load()) [[unlikely]] {for (;;) {}}
	exitlock.store(true);
	auto const stat {static_cast<int>(_stat)};
	for (;;) {
# if defined(dux_os_freebsd)
		::dux::syscall(SYS_exit,stat);
# elif defined(dux_os_linux)		
		::dux::syscall(__NR_exit_group,stat);
		::dux::syscall(__NR_exit,stat);
# endif
	}
}

auto ::dux::exit(::dux::stat const _stat,::dux::priv::thrdexit) noexcept -> void {
	auto const stat {static_cast<int>(_stat)};
	for (;;) {
# if defined(dux_os_freebsd)
		::dux::syscall(SYS_exit,stat);
# elif defined(dux_os_linux)		
		::dux::syscall(__NR_exit,stat);
# endif
	}
}

# pragma GCC diagnostic ignored "-Wmissing-declarations"

extern "C" dux_attr_cold auto dux_exit(    ::dux::stat const _stat) -> void {::dux::exit(_stat);}
extern "C" dux_attr_cold auto dux_qexit(   ::dux::stat const _stat) -> void {::dux::exit(_stat,::dux::qexit);}
extern "C" dux_attr_cold auto dux_thrdexit(::dux::stat const _stat) -> void {::dux::exit(_stat,::dux::thrdexit);}
