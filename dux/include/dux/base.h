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
	This is the base of the "dux General Library", a library aimed at replacing the C++ standard library.

	We must implement as much as humanly possible ourselves. We are never allowed to include third-party headers EXCEPT the "exception" header.
*/

/*
	Header dependencies:

	sysinfo.h > base >┬> math ─> seq > mem >┬> arr > io >
	                  │                     ╰> str ─────>
	                  ├> media ─────────────────────────>
	                  ├> sig ───────────────────────────>
	                  ├> thrd ──────────────────────────>
	                  ╰> time ──────────────────────────>

	All headers up to (and including) "runmath" and "sys" are C-compatible. Moreover, this header is C90-compatible.
*/

# if defined(dux_lang_c)
# if !defined(dux_lang_c11)
# error Header must be included from C11 or later!
# endif
# elif defined(dux_lang_cxx)
# if !defined(dux_lang_cxx20)
# error Header must be included from C++20 or later!
# endif
# else
# error Header must be included from C or C++!
# endif

# if defined(dux_lang_c)
# include <stdbool.h> /* We really want the bool macros. We can't define them ourselves, as that would be UB (note: read next line), as we may not declare nor define anything the standard library defines. */
# undef false /* NOT UB: cppreference: "A program may undefine and perhaps then redefine the macros bool, true and false." (cppreference) */
# undef true
/* We want to define our own values for true and false, as, prior to C2x, their types were int instead of _Bool. */
# define false ((_Bool)+0u)
# define true  ((_Bool)+1u)
# endif

# if defined(dux_lang_cxx)
# undef restrict
# if defined(dux_priv_gnuc) || defined(dux_cmpl_msvc)
# define restrict __restrict
# else
# define restrict
# endif
# endif

# define dux_priv_ver 0x1F

# if !defined(dux_dbg)
# if defined(_DEBUG) || !defined(NDEBUG)
# define dux_dbg true
# else
# define dux_dbg false
# endif
# else
# if dux_dbg != false && dux_dbg != true
# error Invalid user-defined value for dux_dbg!
# endif
# endif

# if defined(__GNUC__)
# define dux_priv_gnuc
# endif

# if defined(__clang__)
# define dux_priv_hasclangattr true
# else
# define dux_priv_hasclangattr false
# endif
# if defined(dux_priv_gnuc)
# define dux_priv_hasgnuattr true
# else
# define dux_priv_hasgnuattr false
# endif
# if defined(_MSC_VER)
# define dux_priv_hasmsvcattr true
# else
# define dux_priv_hasmsvcattr false
# endif

# if defined(__has_builtin)
# define dux_hasbuiltin(_builtin) __has_builtin(_builtin)
# else
# define dux_hasbuiltin(_builtin) false
# endif

# if dux_hasbuiltin(__builtin_FILE) && dux_hasbuiltin(__builtin_FUNCTION) && dux_hasbuiltin(__builtin_LINE)
# define dux_priv_builtinfile() (__builtin_FILE())
# define dux_priv_builtinfunc() (__builtin_FUNCTION())
# define dux_priv_builtinline() ((long)__builtin_LINE())
# else
# define dux_priv_builtinfile() ("")
# define dux_priv_builtinfunc() ("")
# define dux_priv_builtinline() (0x0l)
# endif

# define dux_priv_pragmanostr(_str) _Pragma(#_str)
# if defined(dux_cmpl_msvc)
# define dux_ppmsg(_msg) dux_priv_pragmanostr(message("\"" _msg "\""))
# elif defined(dux_priv_gnuc)
# define dux_ppmsg(_msg) dux_priv_pragmanostr(message "\"" _msg "\"")
# else
# define dux_ppmsg(_msg)
# endif

# if defined(dux_lang_c)
# define dux_priv_noret _Noreturn
# elif defined(dux_lang_cxx)
# define dux_priv_noret [[noreturn]]
# endif

# if defined(dux_lang_c)
# define dux_priv_thrdlocal _Thread_local
# elif defined(dux_lang_cxx)
# define dux_priv_thrdlocal thread_local
# endif

# if defined(dux_lang_c23) || defined(dux_lang_cxx)
# define dux_attr_unused [[maybe_unused]]
# elif dux_priv_hasgnuattr
# define dux_attr_unused __attribute__((unused))
# else
# define dux_attr_unused
# endif
# if defined(dux_lang_c23) || defined(dux_lang_cxx)
# define dux_attr_useret [[nodiscard]]
# elif dux_priv_hasgnuattr
# define dux_attr_useret __attribute__((warn_unused_result))
# else
# define dux_attr_useret
# endif
# if dux_priv_hasgnuattr
# if defined(dux_lang_c23) || defined(dux_lang_cxx)
# define dux_attr_allocsz(   ...) [[gnu::alloc_size(__VA_ARGS__)]]
# define dux_attr_artif           [[gnu::artificial]]
# define dux_attr_cold            [[gnu::cold]]
# define dux_attr_const           [[gnu::const]]
# define dux_attr_flatten         [[gnu::flatten]]
# define dux_attr_hot             [[gnu::hot]]
# define dux_attr_inline          [[gnu::always_inline]]
# define dux_attr_malloc          [[gnu::malloc]]
# define dux_attr_nonnull(   ...) [[gnu::nonnull(__VA_ARGS__)]]
# define dux_attr_pure            [[gnu::pure]]
# define dux_attr_retnonnull      [[gnu::returns_nonnull]]
# define dux_attr_sect(      ...) [[gnu::section(__VA_ARGS__)]]
# else
# define dux_attr_allocsz(   ...) __attribute__((alloc_size(__VA_ARGS__)))
# define dux_attr_artif           __attribute__((artificial))
# define dux_attr_cold            __attribute__((cold))
# define dux_attr_const           __attribute__((const))
# define dux_attr_flatten         __attribute__((flatten))
# define dux_attr_hot             __attribute__((hot))
# define dux_attr_inline          __attribute__((always_inline))
# define dux_attr_malloc          __attribute__((malloc))
# define dux_attr_nonnull(   ...) __attribute__((nonnull(__VA_ARGS__)))
# define dux_attr_pure            __attribute__((pure))
# define dux_attr_retnonnull      __attribute__((returns_nonnull))
# define dux_attr_sect(      ...) __attribute__((section(__VA_ARGS__)))
# endif
# else
# define dux_attr_allocsz(   ...)
# define dux_attr_artif
# define dux_attr_cold
# define dux_attr_const
# define dux_attr_flatten
# define dux_attr_hot
# define dux_attr_inline
# define dux_attr_malloc
# define dux_attr_nonnull(   ...)
# define dux_attr_pure
# define dux_attr_retnonnull
# define dux_attr_sect(      ...)
# endif
# if dux_priv_hasclangattr
# if defined(dux_lang_c23) || defined(dux_lang_cxx)
# define dux_attr_noderef      [[clang::noderef]]
# define dux_attr_noesc(  ...) [[clang::noescape(__VA_ARGS__)]]
# else
# define dux_attr_noderef      __attribute__((noderef))
# define dux_attr_noesc(  ...) __attribute__((noescape(__VA_ARGS__)))
# endif
# else
# define dux_attr_noderef
# define dux_attr_noesc(  ...)
# endif

# if defined(dux_lang_c)
# define dux_fnnm __func__
# elif defined(dux_lang_cxx)
# if defined(dux_priv_gnuc)
# define dux_fnnm __PRETTY_FUNCTION__
# elif defined(dux_cmpl_msvc)
# define dux_fnnm __FUNCSIG__
# else
# define dux_fnnm __func__
# endif
# endif

# if defined(dux_lang_c)
# define dux_priv_nullptr ((void *)0x0)
# define dux_nullptr      dux_priv_nullptr
# elif defined(dux_lang_cxx)
# define dux_priv_nullptr nullptr
# endif

/* Cross-language branch prediction: */
# if defined(dux_lang_c)
# if dux_hasbuiltin(__builtin_expect)
# define dux_priv_likely(_expr)   if (__builtin_expect(_expr,true))
# define dux_priv_unlikely(_expr) if (__builtin_expect(_expr,false))
# else
# define dux_priv_likely(_expr)   if (_expr)
# define dux_priv_unlikely(_expr) if (_expr)
# endif
# elif defined(dux_lang_cxx)
# define dux_priv_likely(_expr)   if (_expr) [[likely]]
# define dux_priv_unlikely(_expr) if (_expr) [[unlikely]]
# endif

/* If-consteval before C++23: */
# if defined(dux_lang_cxx)
# if defined(__cpp_if_consteval)
# define dux_priv_ifconsteval    if consteval
# define dux_priv_ifnotconsteval if not consteval
# else
# define dux_priv_ifconsteval    if (__builtin_is_constant_evaluated())
# define dux_priv_ifnotconsteval if (!__builtin_is_constant_evaluated())
# endif
# endif

/* C-declerations in C++:<2 */
# if defined(dux_lang_c)
# define dux_priv_begincdecls
# define dux_priv_endcdecls
# elif defined(dux_lang_cxx)
# define dux_priv_begincdecls extern "C" {
# define dux_priv_endcdecls   }
# endif

# define dux_priv_uint8max (dux_uchrmax)
# define dux_priv_sint8max (dux_schrmax)
# define dux_uint8l(_lit) ((unsigned char)_lit)
# define dux_sint8l(_lit) ((signed char)_lit)
# define dux_printfuint8 "%hhu"
# define dux_printfsint8 "%hhi"
typedef unsigned char dux_priv_uint8;
typedef signed char   dux_priv_sint8;

# if dux_bytesz >= 0x10
# define dux_priv_uint16max (dux_uchrmax)
# define dux_priv_sint16max (dux_schrmax)
# define dux_uint16l(_lit) (unsigned char)_lit
# define dux_sint16l(_lit) (signed char)_lit
# define dux_printfuint16 "%hhu"
# define dux_printfsint16 "%hhi"
typedef unsigned char dux_priv_uint16;
typedef signed char   dux_priv_sint16;
# else
# define dux_priv_uint16max (dux_ushrtmax)
# define dux_priv_sint16max (dux_shrtmax)
# define dux_uint16l(_lit) (unsigned short)_lit
# define dux_sint16l(_lit) (short)_lit
# define dux_printfuint16 "%hu"
# define dux_printfsint16 "%hi"
typedef unsigned short dux_priv_uint16;
typedef short          dux_priv_sint16;
# endif

# if dux_bytesz >= 0x20
# define dux_priv_uint32max (dux_uchrmax)
# define dux_priv_sint32max (dux_schrmax)
# define dux_uint32l(_lit) (unsigned char)_lit
# define dux_sint32l(_lit) (signed char)_lit
# define dux_printfuint32 "%hhu"
# define dux_printfsint32 "%hhi"
typedef unsigned char dux_priv_uint32;
typedef signed char   dux_priv_sint32;
# elif dux_shrtmax >= 0x7FFFFFFF
# define dux_priv_uint32max (dux_ushrtmax)
# define dux_priv_sint32max (dux_shrtmax)
# define dux_uint32l(_lit) (unsigned short)_lit
# define dux_sint32l(_lit) (short)_lit
# define dux_printfuint32 "%hu"
# define dux_printfsint32 "%hi"
typedef unsigned short dux_priv_uint32;
typedef short          dux_priv_sint32;
# elif dux_intmax >= 0x7FFFFFFF
# define dux_priv_uint32max (dux_uintmax)
# define dux_priv_sint32max (dux_intmax)
# define dux_uint32l(_lit) _lit ## u
# define dux_sint32l(_lit) _lit
# define dux_printfuint32 "%u"
# define dux_printfsint32 "%i"
typedef unsigned int dux_priv_uint32;
typedef int          dux_priv_sint32;
# else
# define dux_priv_uint32max (dux_ulngmax)
# define dux_priv_sint32max (dux_lngmax)
# define dux_uint32l(_lit) _lit ## ul
# define dux_sint32l(_lit) _lit ## l
# define dux_printfuint32 "%lu"
# define dux_printfsint32 "%li"
typedef unsigned long dux_priv_uint32;
typedef long          dux_priv_sint32;
# endif

# if dux_bytesz >= 0x40
# define dux_priv_uint64max (dux_uchrmax)
# define dux_priv_sint64max (dux_schrmax)
# define dux_uint64l(_lit) (unsigned char)_lit
# define dux_sint64l(_lit) (signed char)_lit
# define dux_printfuint64 "%hhu"
# define dux_printfsint64 "%hhi"
typedef unsigned char dux_priv_uint64;
typedef signed char   dux_priv_sint64;
# elif dux_shrtmax >= 0x7FFFFFFFFFFFFFFF
# define dux_priv_uint64max (dux_ushrtmax)
# define dux_priv_sint64max (dux_shrtmax)
# define dux_uint64l(_lit) (unsigned short>_lit
# define dux_sint64l(_lit) (short)_lit
# define dux_printfuint64 "%hu"
# define dux_printfsint64 "%hi"
typedef unsigned short dux_priv_uint64;
typedef short          dux_priv_sint64;
# elif dux_intmax >= 0x7FFFFFFFFFFFFFFF
# define dux_priv_uint64max (dux_uintmax)
# define dux_priv_sint64max (dux_intmax)
# define dux_uint64l(_lit) _lit ## u
# define dux_sint64l(_lit) _lit
# define dux_printfuint64 "%u"
# define dux_printfsint64 "%i"
typedef unsigned int dux_priv_uint64;
typedef int          dux_priv_sint64;
# elif dux_lngmax >= 0x7FFFFFFFFFFFFFFF
# define dux_priv_uint64max (dux_ulngmax)
# define dux_sint64max (dux_lngmax)
# define dux_uint64l(_lit) _lit ## ul
# define dux_sint64l(_lit) _lit ## l
# define dux_printfuint64 "%lu"
# define dux_printfsint64 "%li"
typedef unsigned long dux_priv_uint64;
typedef long          dux_priv_sint64;
# else
# define dux_priv_uint64max (dux_ullngmax)
# define dux_priv_sint64max (dux_llngmax)
# define dux_uint64l(_lit) _lit ## ull
# define dux_sint64l(_lit) _lit ## l
# define dux_printfuint64 "%llu"
# define dux_printfsint64 "%lli"
typedef unsigned long long dux_priv_uint64;
typedef long long          dux_priv_sint64;
# endif

# if dux_wrdsz == 0x8
# define dux_priv_uwrdmax (dux_uint8max)
# define dux_priv_swrdmax (dux_sint8max)
# define dux_uwrdl(_lit) dux_uint8l(_lit)
# define dux_swrdl(_lit) dux_sint8l(_lit)
/* We do not need to define the printf conversion specifier strings, as printf has a built-in one ("zi" and "zu"). */
typedef dux_priv_uint8 dux_priv_uwrd;
typedef dux_priv_sint8 dux_priv_swrd;
# elif dux_wrdsz == 0x10
# define dux_priv_uwrdmax (dux_uint16max)
# define dux_priv_swrdmax (dux_sint16max)
# define dux_uwrdl(_lit) dux_uint16l(_lit)
# define dux_swrdl(_lit) dux_sint16l(_lit)
typedef dux_priv_uint16 dux_priv_uwrd;
typedef dux_priv_sint16 dux_priv_swrd;
# elif dux_wrdsz == 0x20
# define dux_priv_uwrdmax (dux_uint32max)
# define dux_priv_swrdmax (dux_sint32max)
# define dux_uwrdl(_lit) dux_uint32l(_lit)
# define dux_swrdl(_lit) dux_sint32l(_lit)
typedef dux_priv_uint32 dux_priv_uwrd;
typedef dux_priv_sint32 dux_priv_swrd;
# elif dux_wrdsz == 0x40
# define dux_priv_uwrdmax (dux_uint64max)
# define dux_priv_swrdmax (dux_sint64max)
# define dux_uwrdl(_lit) dux_uint64l(_lit)
# define dux_swrdl(_lit) dux_sint64l(_lit)
typedef dux_priv_uint64 dux_priv_uwrd;
typedef dux_priv_sint64 dux_priv_swrd;
# else /* The word size was larger than the size of dux_*int64, meaning we will have to resort the the largest integer type with literals. This is long long, which may be larger than dux_int64. */
# define dux_priv_uwrdmax (dux_ullngmax)
# define dux_priv_swrdmax (dux_llngmax)
# define dux_uwrdl(_lit) _lit ## ull
# define dux_swrdl(_lit) _lit ## ll
typedef unsigned long long dux_priv_uwrd;
typedef long long          dux_priv_swrd;
# endif
# if defined(dux_lang_cxx23) /* C++23 has literals for the type ::std::size_t, which dux_wrd replaces. Use these instead, if available. */
# undef dux_uwrdl
# undef dux_swrdl
# define dux_uwrdl(_lit) _lit ## uz
# define dux_swrdl(_lit) _lit ## z
# endif

# if defined(dux_lang_c)
typedef dux_priv_uint16 dux_priv_chr16;
typedef dux_priv_uint32 dux_priv_chr32;
typedef dux_priv_uint8  dux_priv_chr8;
# elif defined(dux_lang_cxx)
typedef char16_t dux_priv_chr16;
typedef char32_t dux_priv_chr32;
typedef char8_t  dux_priv_chr8;
# endif

# if defined(dux_lang_c)
# if defined(__WCHAR_TYPE__)
typedef __WCHAR_TYPE__ dux_priv_wchr;
# else
typedef dux_priv_sint32 dux_priv_wchr;
# endif
# elif defined(dux_lang_cxx)
using dux_priv_wchr = wchar_t;
# endif

enum dux_priv_stat {
# if defined(dux_os_openvms) /* On OpenVMS, 0 indicates error and 1 indicates success. Source: <https://web.archive.org/web/20120319171215/http://h71000.www7.hp.com/commercial/c/docs/5492profile_016.html> */
	dux_priv_stat_err   = 0x0,  /* Error */
	dux_priv_stat_ok    = 0x1,  /* Okay */
# else
	dux_priv_stat_err   = 0x1,
	dux_priv_stat_ok    = 0x0,
# endif
	dux_priv_stat_badop = 0x7F, /* Bad operation */
	dux_priv_stat_illop = 0x7E, /* Illegal operation */
	dux_priv_stat_max   = 0xFF, /* Maximum valid status code */
};

/*
	dux has it's own error handling system.
	It works by having a global, thread-lcaol variable, which can be accessed by dux_geterr, set by dux_seterr, and reset by dux_reseterr. If an error has occured, dux_onerr can be used.
	The error codes are somewhat inspired by the ones POSIX uses for errno.
*/
enum dux_priv_errcd {
	dux_priv_errcd_noerr       = 0x0, /* No error:              No error has occured */
	dux_priv_errcd_again,             /* Again:                 Try operating again */
	dux_priv_errcd_badacs,            /* Bad access:            Access denied */
	dux_priv_errcd_badaddr,           /* Bad address:           Addres was out of bounds or invalid */
	dux_priv_errcd_badalloc,          /* Bad allocation:        Memory allocation failed */
	dux_priv_errcd_badio,             /* Bad input/output:      Unable to read or write to pipe */
	dux_priv_errcd_badperms,          /* Bad permissions:       Operation was not permitted */
	dux_priv_errcd_badpipe,           /* Bad pipe:              Pipe was not valid */
	dux_priv_errcd_badseq,            /* Bad sequence:          Memory sequence is illegal */
	dux_priv_errcd_badstr,            /* Bad string:            String was invalid */
	dux_priv_errcd_badutf,            /* Bad UTF:               UTF codepoint was illegal */
	dux_priv_errcd_bigfile,           /* Big file:              File cannot grow */
	dux_priv_errcd_illcallseq,        /* Illegal call sequence: Function was called in an illegal order */
	dux_priv_errcd_illparam,          /* Illegal parameter:     Provided parameter was not valid */
	dux_priv_errcd_illsz,             /* Illegal size:          Size was illegal */
	dux_priv_errcd_matherr,           /* Mathematical error:    Mathematical operation(s) could not be performed */
	dux_priv_errcd_nodir,             /* No directory:          Directory does not exist */
	dux_priv_errcd_nofile,            /* No file:               File does not exist */
	dux_priv_errcd_noimpl,            /* No implementaton:      The function is not implemented on the target platform */
	dux_priv_errcd_nospc,             /* No space:              Destination is out of available space */
	dux_priv_errcd_outofrange,        /* Out of range:          Provided value is out of range */
	dux_priv_errcd_runerr,            /* Runtime error:         An unpredictable error occured */
	dux_priv_errcd_test,              /* Test:                  The error system is being tested */
	dux_priv_errcd_thrderr,           /* Thread error:          Unable to manipulate thread */
};

# if defined(dux_lang_c)
# define dux_priv_str dux_str
# elif defined(dux_lang_cxx)
# define dux_priv_str dux_priv_str
# endif
struct dux_priv_str {
	char const *  ptr;
	dux_priv_uwrd sz;
};
# undef dux_priv_str

dux_priv_begincdecls

dux_attr_hot dux_priv_uwrd dux_priv_syscall(dux_priv_uwrd syscallid,...);

/* POSIX functions we implement ourselves. If the function uses a non-fundamental type, we put it in the private header. */
int           dux_priv_posix_close(    int    fildes);
dux_priv_swrd dux_priv_posix_write(    int    fildes, void const *  buf,     dux_priv_uwrd nbyte);
dux_priv_swrd dux_priv_posix_getrandom(void * buf,    dux_priv_uwrd buflen,  unsigned int  flags);
int           dux_priv_posix_openat(   int    fd,     char const *  pathname,int           flags);

dux_priv_endcdecls

# if !defined(dux_os_posix)
# define dux_priv_nosigtrap
# endif

# if defined(dux_lang_c)
# define dux_priv_trap() dux_trap()
# elif defined(dux_lang_cxx)
# define dux_priv_trap() ::dux::trap()
# endif

dux_priv_begincdecls

dux_priv_noret void dux_priv_dbgunreach(char const * file,long line);

dux_priv_endcdecls

# if dux_dbg
# define dux_priv_unreach() dux_priv_dbgunreach(__FILE__,__LINE__)
# elif defined(dux_cmpl_icc) || defined(dux_cmpl_msvc)
# define dux_priv_unreach() (__assume(false))
# elif dux_hasbuiltin(__builtin_unreachable)
# define dux_priv_unreach() (__builtin_unreachable())
# elif dux_hasbuiltin(__builtin_trap)
# define dux_priv_unreach() (__builtin_trap())
# else
# define dux_priv_unreach() (dux_priv_trap())
# endif

extern dux_priv_thrdlocal enum dux_priv_errcd dux_priv_curerrcd;

# if defined(dux_lang_c)
# define dux_priv_reseterr() dux_reseterr()
# elif defined(dux_lang_cxx)
# define dux_priv_reseterr() ::dux::reseterr()
# endif

dux_priv_begincdecls

dux_attr_cold dux_priv_noret void dux_priv_assfail(char const * filenm,unsigned long ln,char const * fn,char const * msg,char const * exprestr);
# if dux_dbg
# define dux_ass(_msg,_expr) (!(_expr) ? dux_priv_assfail(__FILE__,(unsigned long)__LINE__,dux_fnnm,_msg,#_expr) : (void)0x0)
# else
# define dux_ass(_msg,_expr)
# endif

dux_attr_nonnull(0x1) void dux_priv_logstderr(char const * str);

dux_attr_nonnull(0x1) void dux_priv_dbglog(char const * str,...);

dux_priv_endcdecls
