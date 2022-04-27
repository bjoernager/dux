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

# if !defined(dux_hdr_sysinfo)
# define dux_hdr_sysinfo

/*
	It is a requirement for all headers to be includable from every edition of ISO C.
	It is, however, not a requirement for them to declare - let alone define - anything in all versions.

	This header may only define macros, who themselves must be compatible with an C89 preprocessor (so variadic function-like macros are not allowed).

	The minimum required version of C++ for all identifieres in all headers to be available is C++20. For C, it is C11.
*/
# if defined(__STDC__) && !defined(__cplusplus) /* C++ compilers may define the macros (__STDC__) and (__STDC_VERSION__). */
# define dux_lang_c
# if defined(__STDC_VERSION__)
# if __STDC_VERSION__ > 0x313EE
# define dux_lang_c90
# define dux_lang_c95
# define dux_lang_c99
# define dux_lang_c11
# define dux_lang_c17
# define dux_lang_c23
# elif __STDC_VERSION__ > 0x31198
# define dux_lang_c90
# define dux_lang_c95
# define dux_lang_c99
# define dux_lang_c11
# define dux_lang_c17
# elif __STDC_VERSION__ > 0x30CDD
# define dux_lang_c90
# define dux_lang_c95
# define dux_lang_c99
# define dux_lang_c11
# elif __STDC_VERSION__ > 0x30AF1
# define dux_lang_c90
# define dux_lang_c95
# define dux_lang_c99
# else
# define dux_lang_c90
# define dux_lang_c95
# endif
# else
# define dux_lang_c90
# endif
# elif defined(__cplusplus)
# define dux_lang_cxx
# if __cplusplus > 0x31512
# define dux_lang_cxx98
# define dux_lang_cxx11
# define dux_lang_cxx14
# define dux_lang_cxx17
# define dux_lang_cxx20
# define dux_lang_cxx23
# elif __cplusplus > 0x313E7
# define dux_lang_cxx98
# define dux_lang_cxx11
# define dux_lang_cxx14
# define dux_lang_cxx17
# define dux_lang_cxx20
# elif __cplusplus > 0x312BA
# define dux_lang_cxx98
# define dux_lang_cxx11
# define dux_lang_cxx14
# define dux_lang_cxx17
# elif __cplusplus > 0x3118F
# define dux_lang_cxx98
# define dux_lang_cxx11
# define dux_lang_cxx14
# elif __cplusplus > 0x30C1F
# define dux_lang_cxx98
# define dux_lang_cxx11
# else
# define dux_lang_cxx98
# endif
# endif

/*
	Compiler detection:
	Please refer to the compiler in question for a list of predefined macros it defines.
*/
# if defined(__clang__)
# define dux_cmpl_clang
# endif
# if defined(__xlC__)
# define dux_cmpl_ibmxl
# endif
# if defined(__INTEL_COMPILER)
# define dux_cmpl_icc
# endif
# if defined(_MSC_VER)
# define dux_cmpl_msvc
# endif
# if defined(__TINYC__)
# define dux_cmpl_tcc
# endif
# if defined(__PCC__)
# define dux_cmpl_pcc
# endif
# if defined(__GNUC__) || defined(__GNUG__) && (!defined(dux_cmpl_clang) && !defined(dux_cmpl_icc) && !defined(dux_cmpl_pcc))
# define dux_cmpl_gcc
# endif

/* Arch detection: only test for macros that ARE defined by our supported compilers (those we have an identification macro for). */
# if defined(__alpha__) || defined(_M_ALPHA)
# define dux_arch_alpha
# endif
# if defined(__aarch64__) || defined(__arm__) || defined(__thumb__) || defined(_M_ARM) || defined(_M_ARMT)
# define dux_arch_arm
# endif
# if defined(__mips) || defined(__mips__)
# define dux_arch_mips
# endif
# if defined(__PPC64__) || defined(__POWERPC) || defined(__PPC__) || defined(__powerpc) || defined(__powerpc__) || defined(__powerpc64__) || defined(__ppc__) || defined(__ppc64__) || defined(_ARCH_PPC) || defined(_ARCH_PPC64) || defined(_M_PPC) || defined(_M_PPC64)
# define dux_arch_ppc
# endif
# if defined(__riscv)
# define dux_arch_riscv
# endif
# if defined(__sparc__)
# define dux_arch_sparc
# endif
# if defined(__THW_INTEL__) || defined(__amd64) || defined(__amd64__) || defined(__i386) || defined(__i386__) || defined(__x86_64) || defined(__x86_64__) || defined(_M_AMD64) || defined(_M_I86) || defined(_M_IX86)
# define dux_arch_x86
# endif

# if !defined(dux_bytesz) /* We will give the user the ability to define the size of bytes in case we can't figure it out. */
# if defined(dux_arch_arm) || defined(dux_arch_mips) || defined(dux_arch_ppc) || defined(dux_arch_riscv) || defined(dux_arch_sparc) || defined(dux_arch_x86) || defined(dux_os_posix) || defined(dux_os_win) /* These architectures use 8 bits per byte. POSIX requires the size of bytes (in bits) to be exactly 8. Windows also uses 8 bits per byte. */
# define dux_bytesz 0x8
# elif defined(__CHAR_BIT__)
# define dux_bytesz __CHAR_BIT__
# else
# error Unable to get the size of bytes in bits! Define (dux_bytesz) to remove this message!
# endif
# endif

# if defined(__ILP32__) || defined(_ILP32) || (defined(_WIN32) && !defined(_WIN64))
# define dux_priv_datmodl_ilp32
# elif defined(_WIN64)
# define dux_priv_datmodl_llp64
# elif defined(__LP64__) || defined(_LP64)
# define dux_priv_datmodl_lp64
# endif

# if !defined(dux_wrdsz)
/* For detecting word size, we will check for helpers in the following order: Data model, machine arcitechture, compiler, operating system */
# if defined(dux_priv_datmodl_ilp32) || defined(dux_priv_datmodl_lp32)
# define dux_wrdsz 0x20
# elif defined(dux_priv_datmodl_ilp64) || defined(dux_priv_datmodl_llp64) || defined(dux_priv_datmodl_lp64) || defined(dux_priv_datmodl_silp64)
# define dux_wrdsz 0x40
# elif defined(__PPC64__) || defined(__aarch64__) || defined(__amd64) || defined(__amd64__) || defined(__powerpc64__) || defined(__ppc64__) || defined(__x86_64) || defined(__x86_64__) || defined(_ARCH_PPC64) || defined(_M_AMD64) || defined(_M_PPC64)
# define dux_wrdsz 0x40
# elif defined(__riscv_xlen)
# define dux_wrdsz __riscv_xlen
# elif defined(dux_cmpl_clang) || defined(dux_cmpl_gcc)
# define dux_wrdsz __SIZE_WIDTH__
# elif defined(_WIN16)
# define dux_wrdsz 0x10
# elif defined(_WIN32)
# define dux_wrdsz 0x20
# elif defined(_WIN64)
# define dux_wrdsz 0x40
# else
# error Unable to get the size of words! Define (dux_wrdsz) to remove this error!
# endif
# endif

# if defined(__CHAR_UNSIGNED__) || (defined(dux_cmpl_icc) && !defined(__SIGNED_CHARS__)) || (defined(dux_cmpl_msvc) && defined(_CHAR_UNSIGNED))
# define dux_uchr true
# else
# define dux_uchr false
# endif

# if defined(__DBL_MAX__) && defined(__FLT_MAX__) && defined(__LDBL_MAX__) && defined(__WCHAR_MAX__)
# define dux_dblmax   __DBL_MAX__
# define dux_fltmax   __FLT_MAX__
# define dux_ldblmax  __LDBL_MAX__
# define dux_wchrmax  __WCHAR_MAX__
# endif
# if defined(dux_priv_datmodl_ilp32)
# define dux_intmax  0x7FFFFFFF
# define dux_llngmax 0x7FFFFFFFFFFFFFFF
# define dux_lngmax  0x7FFFFFFF
# define dux_schrmax 0x7F
# define dux_shrtmax 0x7FFF
# elif defined(dux_priv_datmodl_lp32)
# define dux_intmax  0x7FFF
# define dux_llngmax 0x7FFFFFFFFFFFFFFF
# define dux_lngmax  0x7FFFFFFF
# define dux_schrmax 0x7F
# define dux_shrtmax 0x7FFF
# elif defined(dux_priv_datmodl_ilp64)
# define dux_intmax  0x7FFFFFFFFFFFFFFF
# define dux_llngmax 0x7FFFFFFFFFFFFFFF
# define dux_lngmax  0x7FFFFFFFFFFFFFFF
# define dux_schrmax 0x7F
# define dux_shrtmax 0x7FFF
# elif defined(dux_priv_datmodl_llp64)
# define dux_intmax  0x7FFFFFFF
# define dux_llngmax 0x7FFFFFFFFFFFFFFF
# define dux_lngmax  0x7FFFFFFF
# define dux_schrmax 0x7F
# define dux_shrtmax 0x7FFF
# elif defined(dux_priv_datmodl_lp64)
# define dux_intmax  0x7FFFFFFF
# define dux_llngmax 0x7FFFFFFFFFFFFFFF
# define dux_lngmax  0x7FFFFFFFFFFFFFFF
# define dux_schrmax 0x7F
# define dux_shrtmax 0x7FFF
# elif defined(dux_priv_datmodl_silp64)
# define dux_intmax  0x7FFFFFFFFFFFFFFF
# define dux_llngmax 0x7FFFFFFFFFFFFFFF
# define dux_lngmax  0x7FFFFFFFFFFFFFFF
# define dux_schrmax 0x7F
# define dux_shrtmax 0x7FFFFFFFFFFFFFFF
# elif defined(__INT_MAX__) && defined(__LONG_LONG_MAX__) && defined(__LONG_MAX__) && defined(__SCHAR_MAX__) && defined(__SHRT_MAX__)
# define dux_intmax  __INT_MAX__
# define dux_llngmax __LONG_LONG_MAX__
# define dux_lngmax  __LONG_MAX__
# define dux_schrmax __SCHAR_MAX__
# define dux_shrtmax __SHRT_MAX__
# endif
# define dux_chr16max 0xFFFF
# define dux_chr32max 0xFFFFFFFF
# define dux_chr8max  0xFF
# define dux_uchrmax  (dux_schrmax * 0x2u + 0x1u)
# define dux_uintmax  (dux_intmax * 0x2u + 0x1u)
# define dux_ullngmax (dux_llngmax * 0x2ull + 0x1ull)
# define dux_ulngmax  (dux_lngmax * 0x2ul + 0x1ul)
# define dux_ushrtmax (dux_shrtmax * 0x2u + 0x1u)
# if dux_uchr
# define dux_chrmax dux_uchrmax
# else
# define dux_chrmax dux_schrmax
# endif

/* Operating system detection: we will only support "modern" operating systems (those, that are still supported). */
# if defined(__TOS_AIX__) || defined(_AIX)
# define dux_os_aix
# define dux_osstr "aix"
# endif
# if defined(__amigaos__)
# define dux_os_amiga
# define dux_osstr "amiga"
# endif
# if defined(__ANDROID__)
# define dux_os_android
# define dux_osstr "android"
# endif
# if defined(__OS2__) || defined(__TOS_OS2__) || defined(_OS2) /* I assume ArcaOS has the same predefined macros as OS/2. */
# define dux_os_arca
# define dux_osstr "arca"
# endif
# if defined(__THW_BLUEGENE__) || defined(__TOS_BGQ__) || defined(__bg__) || defined(__bgq__)
# define dux_os_bluegene
# define dux_osstr "bluegene"
# endif
# if defined(__APPLE__) || defined(__MACH__)
# define dux_os_darwin
# define dux_osstr "darwin"
# endif
# if defined(__DragonFly__)
# define dux_os_dragonflybsd
# define dux_osstr "dragonflybsd"
# endif
# if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
# define dux_os_freebsd
# define dux_osstr "freebsd"
# endif
# if defined(__BEOS__)
# define dux_os_haiku
# define dux_osstr "haiku"
# endif
# if defined(__hpux) || defined(_hpux)
# define dux_os_hpux
# define dux_osstr "hpux"
# endif
# if defined(__GNU__) || defined(__gnu_hurd__)
# define dux_os_hurd
# define dux_osstr "hurd"
# endif
# if defined(__OS400__) || defined(__OS400_TGTVRM__)
# define dux_os_ibmi
# define dux_osstr "ibmi"
# endif
# if defined(__DOS__) || defined(__MSDOS__) || defined(_MSDOS)
# define dux_os_msdos
# define dux_osstr "msdos"
# endif
# if defined(__NetBSD__)
# define dux_os_netbsd
# define dux_osstr "netbsd"
# endif
# if defined(__OpenBSD__)
# define dux_os_openbsd
# define dux_osstr "openbsd"
# endif
# if defined(__sun)
# define dux_os_solaris
# define dux_osstr "solaris"
# endif
# if defined(__VMS) || defined(__vms)
# define dux_os_openvms
# define dux_osstr "openvms"
# endif
# if defined(__TOS_WIN__) || defined(__WIN32__) || defined(__WINDOWS__) || defined(_WIN16) || defined(_WIN32) || defined(_WIN32_CE) || defined(_WIN64)
# define dux_os_win
# define dux_osstr "win"
# endif
# if defined(_SYSTYPE_BSD) || defined(dux_os_dragonflybsd) || defined(dux_os_freebsd) || defined(dux_os_netbsd) || defined(dux_os_openbsd)
# define dux_os_bsd
# if !defined(dux_osstr)
# define dux_osstr "bsd-misc"
# endif
# endif
# if defined(__linux) || defined(__linux__) || defined(dux_os_android)
# define dux_os_linux
# define dux_osstr "linux"
# endif
# if defined(__unix) || defined(__unix__) || defined(dux_os_aix) || defined(dux_os_android)|| defined(dux_os_bsd) || defined(dux_os_hpux) || defined(dux_os_hurd) || defined(dux_os_linux) || defined(dux_os_darwin) || defined(dux_os_solaris)
# define dux_os_posix
# if !defined(dux_osstr)
# define dux_osstr "posix-misc"
# endif
# endif
# if !defined(dux_osstr)
# define dux_osstr "unknown"
# endif

# if defined(dux_os_win)
# define dux_priv_abi_win
# elif defined(dux_os_posix)
# define dux_priv_abi_sysv
# endif

# if defined(dux_priv_abi_sysv)
# define dux_priv_abistr "sysv"
# elif defined(dux_priv_abi_win)
# define dux_priv_abistr "win"
# else
# endif

# if defined(dux_arch_arm)
# if dux_wrdsz == 0x40
# define dux_archstr "aarch64"
# else
# define dux_archstr "arm"
# endif
# elif defined(dux_arch_mips)
# define dux_archstr "mips"
# elif defined(dux_arch_ppc)
# if dux_wrdsz == 0x40
# define dux_archstr "powerpc64"
# else
# define dux_archstr "powerpc"
# endif
# elif defined(dux_arch_risv)
# define dux_archstr "riscv"
# elif defined(dux_arch_sparc)
# define dux_archstr "sparc"
# elif defined(dux_arch_x86)
# if dux_wrdsz == 0x40
# define dux_archstr "amd64"
# else
# define dux_archstr "x86"
# endif
# else
# define dux_archstr "unknown"
# endif

# endif
