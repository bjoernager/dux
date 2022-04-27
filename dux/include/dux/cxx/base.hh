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

namespace dux {
	constexpr auto dbg {dux_dbg};
	constexpr auto ver {dux_priv_ver};
}

namespace dux {
	using uint8  = dux_priv_uint8;
	using sint8  = dux_priv_sint8;
	using uint16 = dux_priv_uint16;
	using sint16 = dux_priv_sint16;
	using uint32 = dux_priv_uint32;
	using sint32 = dux_priv_sint32;
	using uint64 = dux_priv_uint64;
	using sint64 = dux_priv_sint64;
	using uwrd   = dux_priv_uwrd;
	using swrd   = dux_priv_swrd;

	using nullptrtyp = decltype (nullptr);
}

namespace dux { /* Clang (13.0.1) complains about multiple definitions here. Clang is retarded. */
	template<typename T> constexpr auto maxval                     {T {0x0}};
	template<>           constexpr auto maxval<bool>               {static_cast<bool>(              true)};
	template<>           constexpr auto maxval<char>               {static_cast<char>(              dux_chrmax)};
	template<>           constexpr auto maxval<char16_t>           {static_cast<char16_t>(          dux_chr16max)};
	template<>           constexpr auto maxval<char32_t>           {static_cast<char32_t>(          dux_chr32max)};
	template<>           constexpr auto maxval<char8_t>            {static_cast<char8_t>(           dux_chr8max)};
	template<>           constexpr auto maxval<double>             {static_cast<double>(            dux_dblmax)};
	template<>           constexpr auto maxval<int>                {static_cast<int>(               dux_intmax)};
	template<>           constexpr auto maxval<long>               {static_cast<long>(              dux_lngmax)};
	template<>           constexpr auto maxval<long double>        {static_cast<long double>(       dux_ldblmax)};
	template<>           constexpr auto maxval<long long>          {static_cast<long long>(         dux_llngmax)};
	template<>           constexpr auto maxval<::dux::nullptrtyp>  {                                nullptr};
	template<>           constexpr auto maxval<short>              {static_cast<short>(             dux_shrtmax)};
	template<>           constexpr auto maxval<signed char>        {static_cast<signed char>(       dux_schrmax)};
	template<>           constexpr auto maxval<unsigned char>      {static_cast<unsigned char>(     dux_uchrmax)};
	template<>           constexpr auto maxval<unsigned int>       {static_cast<unsigned int>(      dux_uintmax)};
	template<>           constexpr auto maxval<unsigned long>      {static_cast<unsigned long>(     dux_ulngmax)};
	template<>           constexpr auto maxval<unsigned long long> {static_cast<unsigned long long>(dux_ullngmax)};
	template<>           constexpr auto maxval<unsigned short>     {static_cast<unsigned short>(    dux_ushrtmax)};
	template<>           constexpr auto maxval<wchar_t>            {static_cast<wchar_t>(           dux_wchrmax)};
}

namespace dux::priv {
	template<typename T,typename T0> struct issame      {constexpr static auto val {false};};
	template<typename T>             struct issame<T,T> {constexpr static auto val {true};};
}
namespace dux {
	template<typename T,typename T0> constexpr auto issame {::dux::priv::issame<T,T0>::val};
}
# if defined(dux_lang_cxx23)
static_assert(::dux::issame<decltype(0x0uz),::dux::uwrd>);
# endif

namespace dux::priv {
	template<typename T> struct isptrtyp      {constexpr static auto val {false};};
	template<typename T> struct isptrtyp<T *> {constexpr static auto val {true};};
}
namespace dux {
	template<typename T> constexpr auto isptrtyp {::dux::priv::isptrtyp<T>::val};
}

namespace dux {
	template<typename T>             constexpr auto ischrtyp   {::dux::issame<T,char> || ::dux::issame<T,char16_t> || ::dux::issame<T,char32_t> || ::dux::issame<T,char8_t> || ::dux::issame<T,wchar_t>};
	template<typename T,typename T0> constexpr auto iscnvto    {requires {static_cast<T0>(T {});}};
	template<typename T>             constexpr auto isflttyp   {::dux::issame<T,double> || ::dux::issame<T,float> || ::dux::issame<T,long double>};
	template<typename T>             constexpr auto issinttyp  {::dux::issame<T,int> || ::dux::issame<T,long> || ::dux::issame<T,long long> || ::dux::issame<T,short> || ::dux::issame<T,signed char>};
	template<typename T>             constexpr auto isuinttyp  {::dux::issame<T,unsigned char> || ::dux::issame<T,unsigned int> || ::dux::issame<T,unsigned long> || ::dux::issame<T,unsigned long long> || ::dux::issame<T,unsigned short>};

	template<typename T>             constexpr auto isinttyp   {::dux::issinttyp<T> || ::dux::isuinttyp<T>};

	template<typename T>             constexpr auto isarithtyp {::dux::isflttyp<T> || ::dux::isinttyp<T>};
}

namespace dux {
	template<typename T>             concept arithtyp = ::dux::isarithtyp<T>;
	template<typename T,typename T0> concept cnvto    = ::dux::iscnvto<T,T0>;
	template<typename T>             concept chrtyp   = ::dux::ischrtyp<T>;
	template<typename T>             concept flttyp   = ::dux::isflttyp<T>;
	template<typename T>             concept inttyp   = ::dux::isinttyp<T>;
	template<typename T>             concept ptrtyp   = ::dux::isptrtyp<T>;
	template<typename T>             concept sinttyp  = ::dux::issinttyp<T>;
	template<typename T>             concept uinttyp  = ::dux::isuinttyp<T>;

}

namespace dux::priv {
	template<typename T> struct remconst          {using t = T;};
	template<typename T> struct remconst<T const> {using t = T;};

	template<typename T> struct remrestr               {using t = T;};
	template<typename T> struct remrestr<T * restrict> {using t = T *;};

	template<typename T> struct remref             {using t = T;};
	template<typename T> struct remref<T &>        {using t = T;};
	template<typename T> struct remref<T const &>  {using t = T;};
	template<typename T> struct remref<T &&>       {using t = T;};
	template<typename T> struct remref<T const &&> {using t = T;};
}
namespace dux {
	template<typename T> using remconst = typename ::dux::priv::remconst<T>::t;

	template<typename T> using remrestr = typename ::dux::priv::remrestr<T>::t;

	template<typename T> using remcr  = typename ::dux::remrestr<::dux::remconst<T>>;

	template<typename T> using remref = typename ::dux::priv::remref<T>::t;
}

namespace dux::priv {
	template<typename T> struct sign                     {using t = T;};
	template<>           struct sign<char>               {using t = signed char;};
	template<>           struct sign<unsigned int>       {using t = int;};
	template<>           struct sign<unsigned char>      {using t = signed char;};
	template<>           struct sign<unsigned long>      {using t = long;};
	template<>           struct sign<unsigned long long> {using t = long long;};

	template<typename T> struct unsign              {using t = T;};
	template<>           struct unsign<char>        {using t = unsigned char;};
	template<>           struct unsign<int>         {using t = unsigned int;};
	template<>           struct unsign<long>        {using t = unsigned long;};
	template<>           struct unsign<long long>   {using t = unsigned long long;};
	template<>           struct unsign<signed char> {using t = unsigned char;};
}
namespace dux {
	template<::dux::inttyp T> using sign   = typename ::dux::priv::sign<T>::t;
	template<::dux::inttyp T> using unsign = typename ::dux::priv::unsign<T>::t;
}

namespace dux {
	template<typename T> inline auto getbit(T const & _val,::dux::uwrd const _pos) noexcept -> bool {
		auto const bit {[&_pos,&_val] {
			auto const getbit {[&_pos]<typename T0>(T0 const _val) {return static_cast<bool>(_val >> _pos & T {0x1});}};
			if constexpr (sizeof (T) > sizeof (::dux::uwrd)) {
				auto const ptr  {reinterpret_cast<::dux::uint8 const *>(&_val)};
				auto const byte {ptr[_pos % dux_uwrdl(0x8)]};
				return getbit(byte);
			}
			else {return getbit(_val);}
		}()};
		return bit;
	}
}

namespace dux {
	enum class stat : ::dux::uint8 {
		badop = static_cast<::dux::uint8>(::dux_priv_stat_badop),
		err   = static_cast<::dux::uint8>(::dux_priv_stat_err),
		illop = static_cast<::dux::uint8>(::dux_priv_stat_illop),
		max   = static_cast<::dux::uint8>(::dux_priv_stat_max),
		ok    = static_cast<::dux::uint8>(::dux_priv_stat_ok),
	};
}

namespace dux {
	enum class errcd : ::dux::uint8 {
		noerr      = ::dux_priv_errcd_noerr,
		again      = ::dux_priv_errcd_again,
		badacs     = ::dux_priv_errcd_badacs,
		badaddr    = ::dux_priv_errcd_badaddr,
		badalloc   = ::dux_priv_errcd_badalloc,
		badio      = ::dux_priv_errcd_badio,
		badperms   = ::dux_priv_errcd_badperms,
		badpipe    = ::dux_priv_errcd_badpipe,
		badseq     = ::dux_priv_errcd_badseq,
		badstr     = ::dux_priv_errcd_badstr,
		badutf     = ::dux_priv_errcd_badutf,
		bigfile    = ::dux_priv_errcd_bigfile,
		illcallseq = ::dux_priv_errcd_illcallseq,
		illparam   = ::dux_priv_errcd_illparam,
		illsz      = ::dux_priv_errcd_illsz,
		matherr    = ::dux_priv_errcd_matherr,
		nodir      = ::dux_priv_errcd_nodir,
		nofile     = ::dux_priv_errcd_nofile,
		noimpl     = ::dux_priv_errcd_noimpl,
		nospc      = ::dux_priv_errcd_nospc,
		outofrange = ::dux_priv_errcd_outofrange,
		runerr     = ::dux_priv_errcd_runerr,
		test       = ::dux_priv_errcd_test,
		thrderr    = ::dux_priv_errcd_thrderr,
	};
}

namespace dux {
	using str = ::dux_priv_str;
}
namespace dux::priv {
	template<::dux::uwrd N> [[nodiscard]] consteval auto strlittoduxstr(char const (& _strlit)[N]) noexcept -> ::dux::str {
		::dux::str str;
		str.ptr = _strlit;
		str.sz  = N - dux_uwrdl(0x1);
		return str;
	}
}

namespace dux {
	template<::dux::inttyp T,T... Ints> class intseq {
	public:
		constexpr static auto sz {dux_uwrdl(0x1) + sizeof...(Ints)};
	};
	template<::dux::inttyp T,T N> using mkintseq =
# if dux_hasbuiltin(__make_integer_seq)
		__make_integer_seq<::dux::intseq,T,N>;
# elif dux_hasbuiltin(__integer_pack)
		::dux::intseq<T,__integer_pack(N)...>;
# else
# error Unable to implement (::dux::mkintseq)!
# endif
}

namespace dux {
	template<typename T,typename... Ts> class tup;
}
namespace dux::priv {
	template<::dux::uwrd N,typename T> class tupbase {
	public:
		[[nodiscard]] constexpr      tupbase()                     noexcept              = default;
		[[nodiscard]] constexpr      tupbase(T const & _val)       noexcept              {this->_val = _val;}
		[[nodiscard]] constexpr auto get()                   const noexcept -> T const & {return this->_val;}
	private:
		T _val;
	};
	template<::dux::uwrd N,typename... Ts>                class tuprecurbase                                                                                                          {};
	template<::dux::uwrd N,typename    T, typename... Ts> class tuprecurbase<N,T,Ts...> : public ::dux::priv::tupbase<N,T>,public ::dux::priv::tuprecurbase<N + dux_uwrdl(0x1),Ts...> {
	public:
		                                      [[nodiscard]] constexpr tuprecurbase()                                     noexcept = default;
		template<typename T0,typename... Ts0> [[nodiscard]] constexpr tuprecurbase(T0 const & _val,Ts0 const &... _vals) noexcept : ::dux::priv::tupbase<N,T0>(_val), ::dux::priv::tuprecurbase<N + dux_uwrdl(0x1),Ts...>(_vals...) {}
	};
	template<::dux::uwrd N,typename T,typename... Ts> class tupgettyp {
	public:
		using typ = typename ::dux::priv::tupgettyp<N - dux_uwrdl(0x1),Ts...>::typ;
	};
	template<typename T,typename... Ts> class tupgettyp<dux_uwrdl(0x0),T,Ts...> {
	public:
		using typ = T;
	};
	template<typename Fn,typename... Ts,::dux::uwrd... N> [[nodiscard]] constexpr auto tupapply(Fn && _fn,::dux::tup<Ts...> const & _tup,::dux::intseq<::dux::uwrd,N...>) -> decltype (auto) {
		return _fn(_tup.template get<N>()...);
	}
}
namespace dux {
	template<typename T,typename... Ts> class tup : public ::dux::priv::tuprecurbase<dux_uwrdl(0x0),T,Ts...> {
	public:
		template<typename    Fn> [[nodiscard]] constexpr auto apply(Fn const & _fn)                      const          -> decltype (auto)  {return ::dux::priv::tupapply(_fn,*this,dux::mkintseq<::dux::uwrd,dux_uwrdl(0x1) + sizeof...(Ts)> {});}
		template<::dux::uwrd N>  [[nodiscard]] constexpr auto get()                                      const noexcept -> auto             {return static_cast<::dux::priv::tupbase<N,typename ::dux::priv::tupgettyp<N,T,Ts...>::typ> const *>(this)->get();}
		                         [[nodiscard]] constexpr      tup()                                            noexcept                    = default;
		                         [[nodiscard]] constexpr      tup(  T const &  _val,Ts const &... _vals)       noexcept                    : ::dux::priv::tuprecurbase<dux_uwrdl(0x0),T,Ts...>(_val,_vals...) {}

		constexpr static auto sz {dux_uwrdl(0x1) + sizeof...(Ts)};
	};
}

namespace dux {
	class mainparams {
	public:
		[[nodiscard]] mainparams()  noexcept;
		              ~mainparams() noexcept;

		auto fromstd(int const argc,char const * const * const argv) noexcept -> void;

		[[nodiscard]] auto num()                       const noexcept -> ::dux::uwrd;
		[[nodiscard]] auto param(::dux::uwrd const _n) const noexcept -> ::dux::str;
	private:
		bool         _alloc;
		::dux::str * _params;
		::dux::uwrd  _num;
	};
}

namespace dux {
	template<typename T> constexpr auto fwd(T & _ref) noexcept -> ::dux::remref<T> && {return static_cast<::dux::remref<T> &&>(_ref);}
}

namespace dux {
	[[nodiscard]]                 constexpr auto errcdnm( ::dux::errcd const cd)  noexcept -> ::dux::str;
	[[nodiscard]] dux_attr_inline inline    auto haserr()                         noexcept -> bool {return ::dux_priv_curerrcd != ::dux_priv_errcd_noerr;}
	              dux_attr_inline inline    auto reseterr()                       noexcept -> void {::dux_priv_curerrcd = ::dux_priv_errcd_noerr;}
	              dux_attr_inline inline    auto seterr(  ::dux::errcd const _cd) noexcept -> void {::dux_priv_curerrcd = static_cast<::dux_priv_errcd>(_cd);}

	[[nodiscard]] dux_attr_inline inline auto geterr() noexcept -> ::dux::errcd {
		auto const errcd {static_cast<::dux::errcd>(::dux_priv_curerrcd)};
		::dux::reseterr();
		return errcd;
	}
}

namespace dux {
	template<typename... Ts> dux_attr_hot auto syscall(::dux::uwrd _syscallid,Ts const... _args) noexcept -> ::dux::uwrd {return ::dux_priv_syscall(_syscallid,_args...);}
}

namespace dux::priv {
	class qexit    {};
	class thrdexit {};
}
namespace dux {
	constexpr ::dux::priv::qexit    qexit;
	constexpr ::dux::priv::thrdexit thrdexit;

	dux_attr_cold [[noreturn]] auto exit(::dux::stat stat)                       noexcept -> void;
	dux_attr_cold [[noreturn]] auto exit(::dux::stat stat,::dux::priv::qexit)    noexcept -> void;
	dux_attr_cold [[noreturn]] auto exit(::dux::stat stat,::dux::priv::thrdexit) noexcept -> void;
}

namespace dux::priv {
	using onexitfn = auto (*)(::dux::stat) -> void;
}
namespace dux {
	auto onexit(::dux::priv::onexitfn fn) noexcept -> void;
}

namespace dux {
	dux_attr_cold [[noreturn]] auto abrt() noexcept -> void;
	dux_attr_cold [[noreturn]] auto trap() noexcept -> void;

	dux_attr_cold dux_attr_inline [[noreturn]] inline auto unreach(char const * const restrict _file = dux_priv_builtinfile(),long const _line = dux_priv_builtinline()) noexcept -> ::dux::uwrd {
		if constexpr (::dux::dbg) {::dux_priv_dbgunreach(_file,_line);}
		else                      {dux_priv_unreach();}
	}
}

namespace dux {
	[[nodiscard]] auto getenv( char const * envvarname) noexcept -> ::dux::str;
}

constexpr auto ::dux::errcdnm(::dux::errcd const _cd) noexcept -> ::dux::str {
	switch (_cd) {
	case ::dux::errcd::again:
		return ::dux::priv::strlittoduxstr("AGAIN");
	case ::dux::errcd::badacs:
		return ::dux::priv::strlittoduxstr("BADACS");
	case ::dux::errcd::badaddr:
		return ::dux::priv::strlittoduxstr("BADADDR");
	case ::dux::errcd::badalloc:
		return ::dux::priv::strlittoduxstr("BADALLOC");
	case ::dux::errcd::badio:
		return ::dux::priv::strlittoduxstr("BADIO");
	case ::dux::errcd::badperms:
		return ::dux::priv::strlittoduxstr("BADPERMS");
	case ::dux::errcd::badpipe:
		return ::dux::priv::strlittoduxstr("BADPIPE");
	case ::dux::errcd::badseq:
		return ::dux::priv::strlittoduxstr("BADSEQ");
	case ::dux::errcd::badstr:
		return ::dux::priv::strlittoduxstr("BADSTR");
	case ::dux::errcd::badutf:
		return ::dux::priv::strlittoduxstr("BADUTF");
	case ::dux::errcd::bigfile:
		return ::dux::priv::strlittoduxstr("BIGFILE");
	case ::dux::errcd::illcallseq:
		return ::dux::priv::strlittoduxstr("ILLCALLSEQ");
	case ::dux::errcd::illparam:
		return ::dux::priv::strlittoduxstr("ILLPARAM");
	case ::dux::errcd::illsz:
		return ::dux::priv::strlittoduxstr("ILLSZ");
	case ::dux::errcd::matherr:
		return ::dux::priv::strlittoduxstr("MATHERR");
	case ::dux::errcd::nodir:
		return ::dux::priv::strlittoduxstr("NODIR");
	case ::dux::errcd::noerr:
		return ::dux::priv::strlittoduxstr("NOERR");
	case ::dux::errcd::nofile:
		return ::dux::priv::strlittoduxstr("NOFILE");
	case ::dux::errcd::noimpl:
		return ::dux::priv::strlittoduxstr("NOIMPL");
	case ::dux::errcd::nospc:
		return ::dux::priv::strlittoduxstr("NOSPC");
	case ::dux::errcd::outofrange:
		return ::dux::priv::strlittoduxstr("OUTOFRANGE");
	case ::dux::errcd::runerr:
		return ::dux::priv::strlittoduxstr("RUNERR");
	case ::dux::errcd::test:
		return ::dux::priv::strlittoduxstr("TEST");
	case ::dux::errcd::thrderr:
		return ::dux::priv::strlittoduxstr("THRDERR");
	}
	::dux::unreach();
}

namespace dux {
	template<typename... Ts> dux_attr_hot constexpr auto dbglog(char const * const restrict _msg,Ts... _vals) noexcept -> void {
		if constexpr (::dux::dbg) {dux_priv_ifnotconsteval {::dux_priv_dbglog(_msg,_vals...);}}
	}
}
