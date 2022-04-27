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

# include <dux/time>

# include <time.h>
# if defined(dux_os_freebsd)
# include <errno.h>
# include <sys/syscall.h>
# elif defined(dux_os_linux)
# include <linux/unistd.h>
# include <linux/errno.h>
# endif

auto ::dux::sleep(::dux::uint64 const _sec) noexcept -> void {
	struct timespec timespec {};
	timespec.tv_sec  = static_cast<::time_t>(_sec);
	timespec.tv_nsec = 0x0l;
	::dux::dbglog("dux :: sleep :: Initiating sleep for (" dux_printfuint64 ") %s!\n",_sec,timespec.tv_sec == ::time_t {0x1} ? "second" : "seconds");
	while (timespec.tv_sec > static_cast<::time_t>(0x0)) { /* In case the sleep was interrupted, we must sleep the remaining time away. */
		if (::dux_priv_posix_nanosleep(&timespec,&timespec) == -0x1) [[unlikely]] {
			if (dux_priv_errno == EINTR) {
				::dux::dbglog("dux :: sleep :: Sleep was interrupted! Slept for " dux_printfuint64 " %s.\n",static_cast<::dux::uint64>(timespec.tv_sec),timespec.tv_sec == ::time_t {0x1} ? "second" : "seconds");
				continue;
			}
			::dux::dbglog("dux :: \x1B[91msleep\x1B[0m :: Sleep failed!\n");
			::dux::seterr(::dux::errcd::runerr);
			return;
		}
		break; /* If the sleep was not interrupted, the remaining time will not be written to timespec. As we already checked for errors, we know the sleep was successful. */
	}
}

# pragma GCC diagnostic ignored "-Wmissing-declarations"

extern "C" auto dux_sleep(::dux::uint64 const _sec) -> void {::dux::sleep(_sec);}
