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

/*
	It is up to the user to make sure each signal is available on the target system before it is raised. Raising a signal that is not supported (such as SIGALRM on MS Windows) will invoke undefined behaviour, unless the mentioned signal is one of:
	- SIGTERM: Invokes ::dux::exit(::dux::stat::err);
	- SIGTRAP: Invokes ::dux::trap();
*/
enum dux_priv_sig { /* Refer to `man 7 signal` for values. */
	dux_priv_sig_abrt   = 0x6,
	dux_priv_sig_alrm   = 0xE,
# if defined(dux_os_freebsd)
	dux_priv_sig_bus    = 0xA,
# elif defined(dux_os_linux)
# if defined(dux_arch_alpha) || defined(dux_arch_mips) || defined(dux_arch_sparc)
	dux_priv_sig_bus    = 0xA,
# else
	dux_priv_sig_bus    = 0x7,
# endif
# endif
# if defined(dux_os_freebsd)
	dux_priv_sig_chld   = 0x14,
# elif defined(dux_os_linux)
# if defined(dux_arch_alpha) || defined(dux_arch_sparc)
	dux_priv_sig_chld   = 0x14,
# elif defined(dux_arch_mips)
	dux_priv_sig_chld   = 0x12,
# else
	dux_priv_sig_chld   = 0x11,
# endif
# endif
# if defined(dux_os_freebsd)
	dux_priv_sig_cont   = 0x13,
# elif defined(dux_os_linux)
	dux_priv_sig_cont   = 0x12,
# endif
	dux_priv_sig_fpe    = 0x8,
	dux_priv_sig_hup    = 0x1,
	dux_priv_sig_ill    = 0x4,
# if defined(dux_os_freebsd)
	dux_priv_sig_io     = 0x17,
# elif defined(dux_os_linux)
	dux_priv_sig_io     = 0x1D,
# endif
	dux_priv_sig_iot    = 0x6,
	dux_priv_sig_intr   = 0x2,
	dux_priv_sig_kill   = 0x9,
	dux_priv_sig_pipe   = 0xD,
# if defined(dux_os_linux)
	dux_priv_sig_poll   = 0x1D,
# else
	dux_priv_sig_poll   = 0xFF,
# endif
# if defined(dux_os_freebsd)
	dux_priv_sig_prof   = 0x1B,
# elif defined(dux_os_linux)
# if defined(dux_arch_mips)
	dux_priv_sig_prof   = 0x1D,
# else
	dux_priv_sig_prof   = 0x1B,
# endif
# endif
# if defined(dux_os_linux)
# if defined(dux_arch_alpha) || defined(dux_arch_sparc)
	dux_priv_sig_pwr    = 0x1D,
# elif defined(dux_arch_mips)
	dux_priv_sig_pwr    = 0x13,
# else
	dux_priv_sig_pwr    = 0x1E,
# endif
# else
	dux_priv_sig_pwr    = 0xFF,
# endif
	dux_priv_sig_quit   = 0x3,
	dux_priv_sig_segv   = 0xB,
# if defined(dux_os_freebsd)
	dux_priv_sig_stop   = 0x11,
# elif defined(dux_os_linux)
# if defined(dux_arch_alpha) || defined(dux_arch_sparc)
	dux_priv_sig_stop   = 0x11,
# elif defined(dux_arch_mips)
	dux_priv_sig_stop   = 0x17,
# else
	dux_priv_sig_stop   = 0x13,
# endif
# endif
# if defined(dux_os_freebsd)
	dux_priv_sig_sys    = 0xC,
# elif defined(dux_os_linux)
# if defined(dux_arch_alpha) || defined(dux_arch_mips) || defined(dux_arch_sparc)
	dux_priv_sig_sys    = 0xC,
# else
	dux_priv_sig_sys    = 0x1F,
# endif
# endif
	dux_priv_sig_term   = 0xF,
	dux_priv_sig_trap   = 0x5,
# if defined(dux_os_freebsd)
	dux_priv_sig_tstp   = 0x12,
# elif defined(dux_os_linux)
# if defined(dux_arch_alpha) || defined(dux_arch_sparc)
	dux_priv_sig_tstp   = 0x12,
# elif defined(dux_arch_mips)
	dux_priv_sig_tstp   = 0x18,
# else
	dux_priv_sig_tstp   = 0x14,
# endif
# endif
# if defined(dux_os_freebsd)
	dux_priv_sig_ttin   = 0x15,
# elif defined(dux_os_linux)
# if defined(dux_arch_mips)
	dux_priv_sig_ttin   = 0x1A,
# else
	dux_priv_sig_ttin   = 0x15,
# endif
# endif
# if defined(dux_os_freebsd)
	dux_priv_sig_ttou   = 0x16,
# elif defined(dux_os_linux)
# if defined(dux_arch_mips)
	dux_priv_sig_ttou   = 0x1B,
# else
	dux_priv_sig_ttou   = 0x16,
# endif
# endif
# if defined(dux_os_freebsd)
	dux_priv_sig_urg    = 0x10,
# elif defined(dux_os_linux)
# if defined(dux_arch_mips)
	dux_priv_sig_urg    = 0x1C,
# else
	dux_priv_sig_urg    = 0x17,
# endif
# endif
# if defined(dux_os_freebsd)
	dux_priv_sig_usr1    = 0x1E,
# elif defined(dux_os_linux)
# if defined(dux_arch_alpha) || defined(dux_arch_sparc)
	dux_priv_sig_usr1   = 0x1E,
# elif defined(dux_arch_mips)
	dux_priv_sig_usr1   = 0x10,
# else
	dux_priv_sig_usr1   = 0xA,
# endif
# endif
# if defined(dux_os_freebsd)
	dux_priv_sig_usr2    = 0x1F,
# elif defined(dux_os_linux)
# if defined(dux_arch_alpha) || defined(dux_arch_sparc)
	dux_priv_sig_usr2   = 0x1F,
# elif defined(dux_arch_mips)
	dux_priv_sig_usr2   = 0x11,
# else
	dux_priv_sig_usr2   = 0xC,
# endif
# endif
# if defined(dux_os_freebsd)
	dux_priv_sig_vtalrm = 0x1A,
# elif defined(dux_os_linux)
# if defined(dux_arch_mips)
	dux_priv_sig_vtalrm = 0x1C,
# else
	dux_priv_sig_vtalrm = 0x1A,
# endif
# endif
# if defined(dux_os_freebsd)
	dux_priv_sig_winch  = 0x1C,
# elif defined(dux_os_linux)
# if defined(dux_arch_mips)
	dux_priv_sig_winch  = 0x14,
# else
	dux_priv_sig_winch  = 0x1C,
# endif
# endif
# if defined(dux_os_freebsd)
	dux_priv_sig_xcpu   = 0x18,
# elif defined(dux_os_linux)
# if defined(dux_arch_mips)
	dux_priv_sig_xcpu   = 0x1E,
# else
	dux_priv_sig_xcpu   = 0x18,
# endif
# endif
# if defined(dux_os_freebsd)
	dux_priv_sig_xfsz   = 0x19,
# elif defined(dux_os_linux)
# if defined(dux_arch_mips)
	dux_priv_sig_xfsz   = 0x1F,
# else
	dux_priv_sig_xfsz   = 0x19,
# endif
# endif
};
# define dux_priv_numsig dux_uint8l(0x20)

# if defined(dux_lang_c)
# define dux_priv_ctyp_sighandl dux_sighandl
# elif defined(dux_lang_cxx)
typedef auto (* dux_priv_ctyp_sighandl)(::dux_priv_sig sig) -> bool;
# endif
# define dux_priv_dflcsighandl (dux_priv_ctyp_sighandl)((dux_priv_uint8 *)dux_uwrdl(-0x1))
