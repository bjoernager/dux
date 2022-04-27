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

enum dux_sig {
	dux_sig_abrt   = dux_priv_sig_abrt,
	dux_sig_alrm   = dux_priv_sig_alrm,
	dux_sig_bus    = dux_priv_sig_bus,
	dux_sig_chld   = dux_priv_sig_chld,
	dux_sig_cont   = dux_priv_sig_cont,
	dux_sig_fpe    = dux_priv_sig_fpe,
	dux_sig_hup    = dux_priv_sig_hup,
	dux_sig_ill    = dux_priv_sig_ill,
	dux_sig_io     = dux_priv_sig_io,
	dux_sig_iot    = dux_priv_sig_iot,
	dux_sig_intr   = dux_priv_sig_intr,
	dux_sig_kill   = dux_priv_sig_kill,
	dux_sig_pipe   = dux_priv_sig_pipe,
	dux_sig_poll   = dux_priv_sig_poll,
	dux_sig_prof   = dux_priv_sig_prof,
	dux_sig_pwr    = dux_priv_sig_pwr,
	dux_sig_quit   = dux_priv_sig_quit,
	dux_sig_segv   = dux_priv_sig_segv,
	dux_sig_stop   = dux_priv_sig_stop,
	dux_sig_sys    = dux_priv_sig_sys,
	dux_sig_term   = dux_priv_sig_term,
	dux_sig_trap   = dux_priv_sig_trap,
	dux_sig_tstp   = dux_priv_sig_tstp,
	dux_sig_ttin   = dux_priv_sig_ttin,
	dux_sig_ttou   = dux_priv_sig_ttou,
	dux_sig_urg    = dux_priv_sig_urg,
	dux_sig_usr1   = dux_priv_sig_usr1,
	dux_sig_usr2   = dux_priv_sig_usr2,
	dux_sig_vtalrm = dux_priv_sig_vtalrm,
	dux_sig_winch  = dux_priv_sig_winch,
	dux_sig_xcpu   = dux_priv_sig_xcpu,
	dux_sig_xfsz   = dux_priv_sig_xfsz,
};
# define dux_numsig dux_priv_numsig

typedef bool (* dux_sighandl)(enum dux_sig sig);
# define dux_dflsighandl dux_priv_dflcsighandl

void dux_raise(      enum dux_sig sig);
void dux_setsighandl(enum dux_sig sig,dux_sighandl handl);
