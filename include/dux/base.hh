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

/*
	base > algo ─>┬> arr ─>┬> str > sys >┬> io
	              └> cstr >┘             ├> media
	                                     └> thrd
*/

#if defined(__clang__)
#define dux_cmp_clang
#endif
#if defined(__INTEL_COMPILER)
#define dux_cmp_icc
#endif
#if defined(_MSC_VER)
#define dux_cmp_msvc
#endif
#if defined(__GNUG__) && (!defined(dux_cmp_clang) || !defined(dux_cmp_icc))
#define dux_cmp_gcc
#endif

#if defined(__TOS_AIX__) || defined(_AIX)
#define dux_os_aix
#endif
#if defined(__amigaos__)
#define dux_os_amigaos
#endif
#if defined(__ANDROID__)
#define dux_os_android
#endif
#if defined(__THW_BLUEGENE__) || defined(__TOS_BGQ__) || defined(__bg__) || defined(__bgq__)
#define dux_os_bluegene
#endif
#if defined(__DragonFly__)
#define dux_os_dragonflybsd
#endif
#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
#define dux_os_freebsd
#endif
#if defined(__BEOS__)
#define dux_os_haiku
#endif
#if defined(__hpux) || defined(_hpux)
#define dux_os_hpux
#endif
#if defined(__GNU__) || defined(__gnu_hurd__)
#define dux_os_hurd
#endif
#if defined(__OS400__) || defined(__OS400_TGTVRM__)
#define dux_os_ibmi
#endif
#if defined(__INTEGRITY)
#define dux_os_integrity
#endif
#if defined(__APPLE__) || defined(__MACH__)
#define dux_os_mac
#endif
#if defined(__minix)
#define dux_os_minix
#endif
#if defined(__DOS__) || defined(__MSDOS__) || defined(_MSDOS)
#define dux_os_msdos
#endif
#if defined(__NetBSD__)
#define dux_os_netbsd
#endif
#if defined(__OpenBSD__)
#define dux_os_openbsd
#endif
#if defined(__OS2__) || defined(__TOS_OS2__) || defined(_OS2)
#define dux_os_os2
#endif
#if defined(__sun)
#define dux_os_solaris
#endif
#if defined(__TOS_WIN__) || defined(__WIN32__) || defined(__WINDOWS__) || defined(_WIN16) || defined(_WIN32) || defined(_WIN32_CE) || defined(_WIN64)
#define dux_os_win
#endif
#if defined(__HOS_MVS__) || defined(__MVS__) || defined(__TOS_MVS__)
#define dux_os_zos
#endif
#if defined(_SYSTYPE_BSD) || defined(dux_os_dragonflybsd) || defined(dux_os_freebsd) || defined(dux_os_netbsd) || defined(dux_os_openbsd)
#define dux_os_bsd
#elif __has_include(<sys/param.h>)
#include <sys/param.h>
#if defined(BSD)
#define dux_os_bsd
#endif
#endif
#if defined(__linux__) || defined(dux_os_android)
#define dux_os_linux
#endif
#if defined(__unix) || defined(__unix__) || defined(dux_os_aix) || defined(dux_os_android)|| defined(dux_os_bsd) || defined(dux_os_hpux) || defined(dux_os_hurd) || defined(dux_os_linux) || defined(dux_os_mac) || defined(dux_os_minix) || defined(dux_os_solaris)
#define dux_os_posix
#elif __has_include(<unistd.h>)
#include <unistd.h>
#if defined(_POSIX_VERSION)
#define dux_os_posix
#endif
#endif

#include <exception> /* This is the one STDLIB dependency which we cannot get rid of. By making our exception class ((::dux::except)) inherit from (::std::exception), we can get the exception message to be displayed on terminate. Luckily, this header is (in theory) small. */

#if defined(__has_builtin)
#define dux_hasbuiltin(builtin) __has_builtin(builtin)
#else
#define dux_hasbuiltin(builtin) false
#endif

#if defined(dux_os_posix) /* POSIX requires the size of bytes (in bits) to be exactly 8. We can use this knowledge to decrease our STDLIB dependencies. */
#define dux_bytesz 0x8u
#elif defined(dux_cmp_clang) || defined(dux_cmp_gcc) /* Nice! Clang and GCC define the (__CHAR_BIT) macro. */
#define dux_bytesz __CHAR_BIT
#else /* :( */
#include <climits> /* CHAR_BIT */
#define dux_bytesz CHAR_BIT
#endif

#if defined(dux_cmp_clang) || defined(dux_cmp_gcc)
#define dux_intmax   __INT_MAX__
#define dux_llongmax __LONG_LONG_MAX__
#define dux_longmax  __LONG_MAX__
#define dux_shrtmax  __SHRT_MAX__
#else
#include <climits>
#define dux_intmax   INT_MAX
#define dux_llongmax LLONG_MAX
#define dux_longmax  LONG_MAX
#define dux_shrtmax  SHRT_MAX
#endif

#if defined(dux_cmp_clang) || defined(dux_cmp_gcc) || defined(dux_cmp_icc)
#define dux_attr_abitag(    ...) gnu::abi_tag(__VA_ARGS__)
#define dux_attr_allocsz(   ...) gnu::alloc_size(__VA_ARGS__)
#define dux_attr_artif           gnu::artificial
#define dux_attr_cold            gnu::cold
#define dux_attr_const           gnu::const
#define dux_attr_fmt             gnu::format
#define dux_attr_malloc          gnu::malloc
#define dux_attr_nonnull(   ...) gnu::nonnull(__VA_ARGS__)
#define dux_attr_hot             gnu::hot
#define dux_attr_inline          gnu::always_inline
#define dux_attr_pure            gnu::pure
#define dux_attr_retnonnull      gnu::returns_nonnull
#define dux_attr_sect(      ...) gnu::section(__VA_ARGS__)
#else
#define dux_attr_abitag(    ...)
#define dux_attr_allocsz(   ...)
#define dux_attr_artif
#define dux_attr_cold
#define dux_attr_const
#define dux_attr_fmt
#define dux_attr_hot
#define dux_attr_inline
#define dux_attr_malloc
#define dux_attr_nonnull(   ...)
#define dux_attr_pure
#define dux_attr_retnonnull
#define dux_attr_sect(      ...)
#endif
#if defined(dux_cmp_clang)
#define dux_attr_noderef      clang::noderef
#define dux_attr_noesc(  ...) clang::noescape(__VA_ARGS__)
#else
#define dux_attr_noderef
#define dux_attr_noesc(  ...)
#endif

#if defined(dux_cmp_clang) || defined(dux_cmp_gcc) || defined(dux_cmp_icc)
#define dux_fnnm __PRETTY_FUNCTION__
#elif defined(dux_cmp_msvc)
#define dux_fnnm __FUNCSIG__
#else
#define dux_fnnm __func__
#endif


#if defined(dux_cmp_clang) || defined(dux_cmp_gcc)
#define dux_restr __restrict__
#elif defined(dux_cmp_icc) || defined(dux_cmp_msvc)
#define dux_restr __restrict
#else
#define dux_restr
#endif

namespace dux {
	using ubyte = unsigned char;
	using sbyte = signed char;
	template<typename T> consteval auto ubytev(T const & _val) noexcept {return static_cast<::dux::ubyte>(_val);}
	template<typename T> consteval auto sbytev(T const & _val) noexcept {return static_cast<::dux::sbyte>(static_cast<::dux::ubyte>(_val));} /* We cast to the unsigned equivalent type first to avoid undefined behavoir, which will stop compilation, as we are in an immediate function. */

	constexpr auto bytesz{static_cast<::dux::ubyte>(dux_bytesz)};

	template<typename T,typename T0> struct _issame      {constexpr static auto issame{false};};
	template<typename T>             struct _issame<T,T> {constexpr static auto issame{true};};
	template<typename T,typename T0> constexpr auto issame{::dux::_issame<T,T0>::issame};

	template<typename T> struct _remconst          {using t = T;};
	template<typename T> struct _remconst<T const> {using t = T;};
	template<typename T> using remconst = typename ::dux::_remconst<T>::t;

	template<typename T> struct _remrestr                {using t = T;};
	template<typename T> struct _remrestr<T * dux_restr> {using t = T *;};
	template<typename T> using remrestr = typename ::dux::_remrestr<T>::t;

	template<typename T> struct _remvolat             {using t = T;};
	template<typename T> struct _remvolat<T volatile> {using t = T;};
	template<typename T> using remvolat = typename ::dux::_remvolat<T>::t;

	template<typename T> using remcr  = typename ::dux::remrestr<::dux::remconst<T>>;
	template<typename T> using remcrv = typename ::dux::remrestr<::dux::remvolat<::dux::remconst<T>>>;
	template<typename T> using remcv  = typename ::dux::remvolat<::dux::remconst<T>>;
	template<typename T> using remvr  = typename ::dux::remrestr<::dux::remvolat<T>>;

	using _flt128 = 
#if defined(dux_cmp_clang) || defined(dux_cmp_gcc)
		__float128;
#else
		long double;
#endif
	using _uint128 =
#if defined(dux_cmp_clang) || defined(dux_cmp_gcc)
		unsigned __int128;
#else
		unsigned long long;
#endif
	using _sint128 =
#if defined(dux_cmp_clang) || defined(dux_cmp_gcc)
		__int128;
#else
		long long;
#endif

	template<typename T,typename T0> constexpr auto iscnvto      = requires {static_cast<T>(T0{});};
	template<typename T,typename T0> concept        cnvto        = ::dux::iscnvto<T,T0>;
	template<typename T>             constexpr auto issint       = ::dux::issame<T,::dux::_sint128> || ::dux::issame<T,int> || ::dux::issame<T,long> || ::dux::issame<T,long long> || ::dux::issame<T,short> || ::dux::issame<T,signed char>;
	template<typename T>             concept        sint         = ::dux::issint<T>;
	template<typename T>             constexpr auto isuint       = ::dux::issame<T,::dux::_uint128> || ::dux::issame<T,unsigned> || ::dux::issame<T,unsigned char> || ::dux::issame<T,unsigned long> || ::dux::issame<T,unsigned long long> || ::dux::issame<T,unsigned short>;
	template<typename T>             concept        uint         = ::dux::isuint<T>;
	template<typename T>             constexpr auto ischr        = ::dux::issame<T,char> || ::dux::issame<T,char16_t> || ::dux::issame<T,char32_t> || ::dux::issame<T,char8_t> || ::dux::issame<T,wchar_t>;
	template<typename T>             concept        chr          = ::dux::ischr<T>;
	template<typename T>             constexpr auto isflt        = ::dux::issame<T,::dux::_flt128> || ::dux::issame<T,double> || ::dux::issame<T,float> || ::dux::issame<T,long double>;
	template<typename T>             concept        flt          = ::dux::isflt<T>;
	template<typename T>             constexpr auto isnullptrtyp = ::dux::issame<T,decltype(nullptr)>;
	template<typename T>             constexpr auto isutf        = ::dux::issame<T,char16_t> || ::dux::issame<T,char32_t> || ::dux::issame<T,char8_t>;
	template<typename T>             concept        utf          = ::dux::isutf<T>;
	template<typename T>             constexpr auto isvoid       = ::dux::issame<T,void>;
	template<typename T>             concept        void_        = ::dux::isvoid<T>;

	template<typename T> struct _isptr      {constexpr static auto isptr{false};};
	template<typename T> struct _isptr<T *> {constexpr static auto isptr{true};};
	template<typename T> constexpr auto isptr = ::dux::_isptr<T>::isptr;

	template<typename T> constexpr auto isint = ::dux::issame<T,char> || ::dux::issint<T> || ::dux::isuint<T>;
	template<typename T> concept        int_  = ::dux::isint<T>;

	template<typename T> constexpr auto isarith = ::dux::isflt<T> || ::dux::isint<T>;
	template<typename T> concept        arith   = ::dux::isarith<T>;

	template<typename T> struct _sign                     {using t = T;};
	template<>           struct _sign<char>               {using t = signed char;};
	template<>           struct _sign<unsigned>           {using t = int;};
	template<>           struct _sign<unsigned char>      {using t = signed char;};
	template<>           struct _sign<unsigned long>      {using t = long;};
	template<>           struct _sign<unsigned long long> {using t = long long;};
#if defined(dux_cmp_clang) || defined(dux_cmp_gcc)
	template<>           struct _sign<unsigned __int128>  {using t = __int128;};
#endif
	template<::dux::int_ T> using sign = typename ::dux::_sign<T>::t;

	template<typename T> struct _unsign              {using t = T;};
	template<>           struct _unsign<char>        {using t = unsigned char;};
	template<>           struct _unsign<int>         {using t = unsigned;};
	template<>           struct _unsign<long>        {using t = unsigned long;};
	template<>           struct _unsign<long long>   {using t = unsigned long long;};
	template<>           struct _unsign<signed char> {using t = unsigned char;};
#if defined(dux_cmp_clang) || defined(dux_cmp_gcc)
	template<>           struct _unsign<__int128>    {using t = unsigned __int128;};
#endif
	template<::dux::int_ T> using unsign = typename ::dux::_unsign<T>::t;

	using uint16 =
#if dux_bytesz >= 0x10u
		unsigned char;
#else
		unsigned short;
#endif
	using uint32 =
#if dux_bytesz >= 0x20u
		unsigned char;
#elif dux_shrtmax >= 0x7FFFFFFFu
		unsigned short;
#elif dux_intmax >= 0x7FFFFFFFu
		unsigned int;
#else
		unsigned long;
#endif
	using uint64 =
#if dux_bytesz >= 0x40u
		unsigned char;
#elif dux_shrtmax >= 0x7FFFFFFFFFFFFFFFu
		unsigned short;
#elif dux_intmax >= 0x7FFFFFFFFFFFFFFFu
		unsigned int;
#elif dux_longmax >= 0x7FFFFFFFFFFFFFFFu
		unsigned long;
#else
		unsigned long long;
#endif
	using sint16 = ::dux::sign<::dux::uint16>;
	using sint32 = ::dux::sign<::dux::uint32>;
	using sint64 = ::dux::sign<::dux::uint64>;
	template<typename T> consteval auto uint16v(T const & _val) noexcept {return static_cast<::dux::uint16>(_val);}
	template<typename T> consteval auto sint16v(T const & _val) noexcept {return static_cast<::dux::sint16>(static_cast<::dux::uint16>(_val));}
	template<typename T> consteval auto uint32v(T const & _val) noexcept {return static_cast<::dux::uint32>(_val);}
	template<typename T> consteval auto sint32v(T const & _val) noexcept {return static_cast<::dux::sint32>(static_cast<::dux::uint32>(_val));}
	template<typename T> consteval auto uint64v(T const & _val) noexcept {return static_cast<::dux::uint64>(_val);}
	template<typename T> consteval auto sint64v(T const & _val) noexcept {return static_cast<::dux::sint64>(static_cast<::dux::uint64>(_val));}
	
	using usz        = decltype(0x0uz);
	using ssz        = decltype(0x0z);

	using nullptrtyp = decltype(nullptr);

	enum class endi : bool {
		big    = true,
		little = false,
	};

	enum class stat : ::dux::ubyte {
		err = ::dux::ubytev(0x1),
		ok  = ::dux::ubytev(0x0),
	};

	class except : public ::std::exception {
	public:
		[[nodiscard]]              except()                         noexcept                 : _what("")    {}
		[[nodiscard]]              except(char const * _what)       noexcept                 : _what(_what) {}
		              virtual auto what()                     const noexcept -> char const *                {return this->_what;}
	private:
		char const * const dux_restr _what;
	};
	class badalloc : public ::dux::except {
	public:
		using ::dux::except::except;
	};
	class badio : public ::dux::except {
	public:
		using ::dux::except::except;
	};
	class badoptacs : public ::dux::except {
	public:
		using ::dux::except::except;
	};
	class invalarg : public ::dux::except {
	public:
		using ::dux::except::except;
	};
	class invalutf : public ::dux::except {
	public:
		using ::dux::except::except;
	};
	class outofdomain : public ::dux::except {
	public:
		using ::dux::except::except;
	};
	class runerr : public ::dux::except {
	public:
		using ::dux::except::except;
	};

	template<::dux::int_ T,T... Ints> class intseq {
	public:
		constexpr static auto sz{0x1uz + sizeof...(Ints)};
	};
	template<::dux::int_ T,T N> using mkintseq =
#if dux_hasbuiltin(__make_integer_seq) /* Clang has this builtin for this exact purpose. */
		__make_integer_seq<::dux::intseq,T,N>;
#elif dux_hasbuiltin(__integer_pack)
		::dux::intseq<__integer_pack(N)...>;
#else
		::dux::intseq<T,N>;
_Pragma("message \"Cannot implement (::dux::mkintseq)!\"");
#endif

	template<typename T> class opt {
	public:
		[[nodiscard]] constexpr auto          operator * ()                             const          -> T const &;
		[[nodiscard]] constexpr auto          operator -> ()                            const          -> T const *;
		              constexpr auto          operator = (   ::dux::opt<T> const & oth)                -> ::dux::opt<T> const &;
		[[nodiscard]] constexpr      explicit operator bool ()                          const noexcept                          {return this->_has;}
		[[nodiscard]] constexpr               opt()                                           noexcept                          = default;
		[[nodiscard]] constexpr               opt(           T const &             val)       noexcept;
		[[nodiscard]] constexpr               opt(           ::dux::opt<T> const & oth)       noexcept;
		              constexpr auto          set(           T const &             val)       noexcept;
		              constexpr auto          reset()                                         noexcept -> void;
	private:
		bool _has{false};
		T    _val;
	};
	
	template<::dux::usz N,typename T> class _tupbase {
	public:
		[[nodiscard]] constexpr      _tupbase()                     noexcept              = default;
		[[nodiscard]] constexpr      _tupbase(T const & _val)       noexcept              {this->_val = _val;}
		[[nodiscard]] constexpr auto get()                    const noexcept -> T const & {return this->_val;}
	private:
		T _val;
	};
	template<::dux::usz N, typename... Ts>                class _tuprecurbase                                                                                       {};
	template<::dux::usz N, typename    T, typename... Ts> class _tuprecurbase<N,T,Ts...> : public ::dux::_tupbase<N,T>,public ::dux::_tuprecurbase<N + 0x1uz,Ts...> {
	public:
		                                      [[nodiscard]] constexpr _tuprecurbase()                                     noexcept = default;
		template<typename T0,typename... Ts0> [[nodiscard]] constexpr _tuprecurbase(T0 const & _val,Ts0 const &... _vals) noexcept : ::dux::_tupbase<N,T0>(_val), ::dux::_tuprecurbase<N + 0x1uz,Ts...>(_vals...) {};
	};
	template<::dux::usz N,typename T,typename... Ts> class _tupgettyp {
	public:
		using typ = typename ::dux::_tupgettyp<N - 0x1uz,Ts...>::typ;
	};
	template<typename T,typename... Ts> class _tupgettyp<0x0uz,T,Ts...> {
	public:
		using typ = T;
	};
	template<typename   T, typename... Ts> class tup : public ::dux::_tuprecurbase<0x0uz,T,Ts...> {
	public:
		template<typename   Fn>                  [[nodiscard]] constexpr auto apply(       Fn const &                    fn)                       const          -> decltype(auto);
		template<::dux::usz N>                   [[nodiscard]] constexpr auto get()                                                                const noexcept -> auto;
		template<typename   T0, typename... Ts0> [[nodiscard]] constexpr auto operator == (::dux::tup<T0,Ts0...> const & oth)                            noexcept -> bool;
		                                         [[nodiscard]] constexpr      tup()                                                                      noexcept         = default;
		                                         [[nodiscard]] constexpr      tup(         T const &                     _val,Ts const &... _vals)       noexcept         : ::dux::_tuprecurbase<0x0uz,T,Ts...>(_val,_vals...) {}

		constexpr static auto sz{0x1uz + sizeof...(Ts)};
	};

	constexpr auto dbg{[]() {
#if defined(NDEBUG)
		return false;
#else
		return true;
#endif
	}()};
	constexpr auto lorem {U"Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum."};
	constexpr auto npos  {-0x1uz};
	constexpr auto unimax{U'\U00010FFF'};
	constexpr auto ver   {::dux::uint64v(0x1D)};
}

#include <dux/base.d/opt.hh>
#include <dux/base.d/tup.hh>
