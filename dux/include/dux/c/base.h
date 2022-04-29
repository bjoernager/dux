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

# define dux_likely(  _expr) dux_priv_likely(  _expr)
# define dux_unlikely(_expr) dux_priv_unlikely(_expr)

typedef dux_priv_uint8  dux_uint8;
typedef dux_priv_sint8  dux_sint8;
typedef dux_priv_uint16 dux_uint16;
typedef dux_priv_sint16 dux_sint16;
typedef dux_priv_uint32 dux_uint32;
typedef dux_priv_sint32 dux_sint32;
typedef dux_priv_uint64 dux_uint64;
typedef dux_priv_sint64 dux_sint64;

typedef dux_priv_uwrd   dux_uwrd;
typedef dux_priv_swrd   dux_swrd;

typedef dux_priv_chr16 dux_chr16;
typedef dux_priv_chr32 dux_chr32;
typedef dux_priv_chr8  dux_chr8;
typedef dux_priv_wchr  dux_wchr;

/* Identifications for fundamental types: */
enum dux_typid {
	dux_typid_bool,
	dux_typid_chr,
	dux_typid_chr16,
	dux_typid_chr32,
	dux_typid_chr8,
	dux_typid_dbl,
	dux_typid_flt,
	dux_typid_flt128,
	dux_typid_int,
	dux_typid_int128,
	dux_typid_ldbl,
	dux_typid_llng,
	dux_typid_lng,
	dux_typid_nullptrtyp,
	dux_typid_schr,
	dux_typid_shrt,
	dux_typid_uchr,
	dux_typid_unknwn,
	dux_typid_ushrt,
	dux_typid_uint,
	dux_typid_uint128,
	dux_typid_ullng,
	dux_typid_ulng,
	dux_typid_void,
	dux_typid_wchr,
};

enum dux_stat {
	dux_stat_badop = dux_priv_stat_badop,
	dux_stat_err   = dux_priv_stat_err,
	dux_stat_illop = dux_priv_stat_illop,
	dux_stat_max   = dux_priv_stat_max,
	dux_stat_ok    = dux_priv_stat_ok,
};

enum dux_errcd {
	dux_errcd_noerr      = dux_priv_errcd_noerr,
	dux_errcd_again      = dux_priv_errcd_again,
	dux_errcd_badacs     = dux_priv_errcd_badacs,
	dux_errcd_badaddr    = dux_priv_errcd_badaddr,
	dux_errcd_badalloc   = dux_priv_errcd_badalloc,
	dux_errcd_badperms   = dux_priv_errcd_badperms,
	dux_errcd_badfile    = dux_priv_errcd_badfile,
	dux_errcd_badseq     = dux_priv_errcd_badseq,
	dux_errcd_badstr     = dux_priv_errcd_badstr,
	dux_errcd_badutf     = dux_priv_errcd_badutf,
	dux_errcd_bigfile    = dux_priv_errcd_bigfile,
	dux_errcd_illcallseq = dux_priv_errcd_illcallseq,
	dux_errcd_illparam   = dux_priv_errcd_illparam,
	dux_errcd_illsz      = dux_priv_errcd_illsz,
	dux_errcd_ioerr      = dux_priv_errcd_ioerr,
	dux_errcd_matherr    = dux_priv_errcd_matherr,
	dux_errcd_nodir      = dux_priv_errcd_nodir,
	dux_errcd_nofile     = dux_priv_errcd_nofile,
	dux_errcd_nospc      = dux_priv_errcd_nospc,
	dux_errcd_outofrange = dux_priv_errcd_outofrange,
	dux_errcd_runerr     = dux_priv_errcd_runerr,
	dux_errcd_test       = dux_priv_errcd_test,
	dux_errcd_thrderr    = dux_priv_errcd_thrderr,
};

# if dux_dbg
# define dux_dbglog(...) dux_priv_dbglog(__VA_ARGS__)
# else
# define dux_dbglog(...)
# endif

dux_attr_inline dux_attr_useret inline enum dux_errcd dux_geterr()                           {return (enum dux_errcd)dux_priv_curerrcd;}
dux_attr_inline dux_attr_useret inline bool           dux_haserr()                           {return dux_priv_curerrcd == dux_priv_errcd_noerr;}
dux_attr_inline                 inline void           dux_reseterr()                         {dux_priv_curerrcd = dux_priv_errcd_noerr;}
dux_attr_inline                 inline void           dux_seterr(  enum dux_errcd const _cd) {dux_priv_curerrcd = (enum dux_priv_errcd)_cd;}

# define dux_unreach() dux_priv_unreach()

# define dux_syscall dux_priv_syscall

dux_attr_cold   _Noreturn void           dux_abrt(            void);
dux_attr_hot    _Noreturn void           dux_die(             void);
dux_attr_cold   _Noreturn void           dux_exit(            enum dux_stat stat);
dux_attr_useret           struct dux_str dux_getenv(          char const *  envvarname);
dux_attr_useret           struct dux_str dux_getmainparam(    void const *  params,    dux_uwrd n);
dux_attr_useret           dux_uwrd       dux_getnummainparams(void const *  params);
dux_attr_cold   _Noreturn void           dux_qexit(           enum dux_stat stat);
                          void           dux_onexit(          void (*       fn)(                  enum dux_stat));
dux_attr_cold   _Noreturn void           dux_thrdexit(        enum dux_stat stat);
dux_attr_cold   _Noreturn void           dux_trap(            void);
