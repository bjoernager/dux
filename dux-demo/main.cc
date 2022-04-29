# include <dux/arr>
# include <dux/io>
# include <dux/math>
# include <dux/media>
# include <dux/mem>
# include <dux/seq>
# include <dux/sig>
# include <dux/str>
# include <dux/thrd>
# include <dux/time>

# include <signal.h>

static_assert(sizeof (::dux::uwrd) >= sizeof (void *),"::dux::uwrd must be capable of holding a pointer value");

static_assert(::dux::abs(0x10)  == 0x10);
static_assert(::dux::abs(-0x10) == 0x10);

static_assert(::dux::fac(0x1) == 0x1);
static_assert(::dux::fac(0x2) == 0x2);
static_assert(::dux::fac(0x3) == 0x6);
static_assert(::dux::fac(0x4) == 0x18);

static_assert(::dux::msb(0b1) == 0b1);
static_assert(::dux::msb(0b10) == 0b10);
static_assert(::dux::msb(0b101) == 0b100);
static_assert(::dux::msb(0b1010) == 0b1000);
static_assert(::dux::msb(0b10101) == 0b10000);
static_assert(::dux::msb(0b101010) == 0b100000);

namespace dux::local {
	static auto gotsig {false};
}

static_assert([] {
	auto chk {[] (::dux::sig const _sig0,int const _sig1) {
		return static_cast<int>(_sig0) == _sig1;
	}};
	static_assert(chk(::dux::sig::abrt,  SIGABRT));
	static_assert(chk(::dux::sig::alrm,  SIGALRM));
	static_assert(chk(::dux::sig::bus,   SIGBUS));
	static_assert(chk(::dux::sig::chld,  SIGCHLD));
	static_assert(chk(::dux::sig::cont,  SIGCONT));
	static_assert(chk(::dux::sig::fpe,   SIGFPE));
	static_assert(chk(::dux::sig::hup,   SIGHUP));
	static_assert(chk(::dux::sig::ill,   SIGILL));
	static_assert(chk(::dux::sig::io,    SIGIO));
	static_assert(chk(::dux::sig::intr,  SIGINT));
	static_assert(chk(::dux::sig::kill,  SIGKILL));
	static_assert(chk(::dux::sig::file,  SIGPIPE));
	static_assert(chk(::dux::sig::prof,  SIGPROF));
	static_assert(chk(::dux::sig::quit,  SIGQUIT));
	static_assert(chk(::dux::sig::segv,  SIGSEGV));
	static_assert(chk(::dux::sig::stop,  SIGSTOP));
	static_assert(chk(::dux::sig::sys,   SIGSYS));
	static_assert(chk(::dux::sig::term,  SIGTERM));
	static_assert(chk(::dux::sig::trap,  SIGTRAP));
	static_assert(chk(::dux::sig::tstp,  SIGTSTP));
	static_assert(chk(::dux::sig::ttin,  SIGTTIN));
	static_assert(chk(::dux::sig::ttou,  SIGTTOU));
	static_assert(chk(::dux::sig::urg,   SIGURG));
	static_assert(chk(::dux::sig::usr1,  SIGUSR1));
	static_assert(chk(::dux::sig::usr2,  SIGUSR2));
	static_assert(chk(::dux::sig::vtalrm,SIGVTALRM));
	static_assert(chk(::dux::sig::winch, SIGWINCH));
	static_assert(chk(::dux::sig::xcpu,  SIGXCPU));
	static_assert(chk(::dux::sig::xfsz,  SIGXFSZ));
# if defined(SIGPOLL)
	static_assert(chk(::dux::sig::poll,  SIGPOLL));
# endif
# if defined(SIGPWR)
	static_assert(chk(::dux::sig::pwr,   SIGPWR));
# endif
	return true;
}());

extern "C" auto ctest(void const * params) -> void;

extern "C" auto dux_main(::dux::mainparams const * const restrict _params) -> ::dux::stat {
	if (_params->num() == dux_uwrdl(0x0)) {::dux::dbglog("dux.demo        :: No parameters!\n");}
	else {for (auto n {dux_uwrdl(0x0)};n < _params->num();++n) {::dux::dbglog("dux.demo        :: Parameter #%zu: %s\n",n + dux_uwrdl(0x1),_params->param(n).ptr);}}
	{
		constexpr auto estim {dux_uint64l(0x100)};
		::dux::dbglog("dux.demo        :: Trying to roll two identical 8-bit numbers in a row. Estimated number of tries: " dux_printfuint64 ".\n",estim);
		auto num0 {::dux::rnd<::dux::uint8>()};
		auto num1 {::dux::rnd<::dux::uint8>()};
		for (auto n = dux_uint64l(0x1);;++n) {
			if (num0 == num1) [[unlikely]] {
				::dux::dbglog("dux.demo        :: Done! Took " dux_printfuint64 " attempts (estimated: " dux_printfuint64 ") to roll the same 8-bit number (" dux_printfuint8 ") two times in a row.\n",n,estim,num0);
				::dux::dbglog("dux.demo        :: Odds: %f%%",((double)n / (double)estim) * (double)100.0);
				if (n == dux_uint64l(0x45)) {::dux::dbglog(" - Nice!");} /* 69 */
				else if (n == dux_uint64l(0x1)) {::dux::dbglog(" - bruh");}
				::dux::dbglog("\n");
				goto test;
			}
			num0 = ::dux::rnd<::dux::uint8>();
			num1 = ::dux::rnd<::dux::uint8>();
		}
	}
test:;
	auto const time = ::dux::gettime();
	::dux::dbglog("dux.demo        :: Current time: " dux_printfsint64 "\n",time);
	dux_ass("",time >= dux_sint64l(0x5C10DFA4));
	{
		::dux::reseterr();
		auto const ptr {::dux::alloc<char>()};
		dux_ass("Memory allocation failed!",!::dux::haserr());
		::dux::free(ptr);
	}
	{
		constexpr auto val {dux_uint8l(0xC4)};
		dux_ass("",::dux::getbit(val,0x0) == false);
		dux_ass("",::dux::getbit(val,0x1) == false);
		dux_ass("",::dux::getbit(val,0x2) == true);
		dux_ass("",::dux::getbit(val,0x3) == false);
		dux_ass("",::dux::getbit(val,0x4) == false);
		dux_ass("",::dux::getbit(val,0x5) == false);
		dux_ass("",::dux::getbit(val,0x6) == true);
		dux_ass("",::dux::getbit(val,0x7) == true);
	}
	{
		constexpr auto arrsz {dux_uwrdl(0x5)};
		constexpr ::dux::uint16 arr0[] {
			dux_uint16l(0xF),
			dux_uint16l(0x1F),
			dux_uint16l(0x3F),
			dux_uint16l(0x7F),
			dux_uint16l(0xFF),
		};
		auto const arr1 {::dux::alloc<::dux::uint16>(arrsz)};
		::dux::cpy(arr0,arrsz,arr1);
		dux_ass("",arr1[dux_uwrdl(0x0)] == dux_uint16l(0xF));
		dux_ass("",arr1[dux_uwrdl(0x1)] == dux_uint16l(0x1F));
		dux_ass("",arr1[dux_uwrdl(0x2)] == dux_uint16l(0x3F));
		dux_ass("",arr1[dux_uwrdl(0x3)] == dux_uint16l(0x7F));
		dux_ass("",arr1[dux_uwrdl(0x4)] == dux_uint16l(0xFF));
		::dux::free(arr1);
	}
	/*{
		auto * restrict ptr = ::dux::alloc<::dux::uint16>(dux_uwrdl(0x1));
		*ptr = dux_uint16l(0x10);
		dux_ass("",*ptr == dux_uint16l(0x10));
		ptr = ::dux::realloc(ptr,dux_uwrdl(0x2));
		ptr[dux_uwrdl(0x1)] = dux_uint16l(0x20);
		dux_ass("",ptr[dux_uwrdl(0x0)] == dux_uint16l(0x10));
		dux_ass("",ptr[dux_uwrdl(0x1)] == dux_uint16l(0x20));
		::dux::free(ptr);
	}*/ /* Does not work as realloc currently does not support reallocating aligned allocations. */
	{
		constexpr auto arrsz {dux_uwrdl(0x2)};
		::dux::uint64 arr[arrsz];
		::dux::bytefill(arr,arrsz,dux_uint8l(0xFF));
		dux_ass("",arr[dux_uwrdl(0x0)] >= dux_uint64l(0xFFFFFFFFFFFFFFFF));
		::dux::bytefill(arr,arrsz,dux_uint8l(0x7F));
		dux_ass("",arr[dux_uwrdl(0x1)] >= dux_uint64l(0x7F7F7F7F7F7F7F7F));
	}
	{
		::dux::seterr(::dux::errcd::test);
		dux_ass("Error setter didn't work!",::dux::geterr() >::dux::errcd::noerr);
		::dux::reseterr();
	}
	{
		auto x = 0x45;
		auto y = 0x1A4;
		::dux::swp(x,y);
		dux_ass("",x == 0x1A4);
		dux_ass("",y == 0x45);
	}
	{
		::dux::setsighandl(::dux::sig::intr,[](::dux::sig const _sig) {
			dux_ass("",_sig == ::dux::sig::intr);
			::dux::local::gotsig = true;
			return false;
		});
		::dux::raise(::dux::sig::intr);
		dux_ass("",::dux::local::gotsig);
		::dux::setsighandl(::dux::sig::intr,::dux::sighandl::dfl());
	}
	{
		auto handl {[](::dux::sig) {return false;}};
		::dux::setsighandl(::dux::sig::abrt,handl);
		auto goterr {false};
		if (::dux::haserr()) [[unlikely]] {
			goterr = true;
			::dux::reseterr();
		}
		dux_ass("",goterr);
	}
	{
		auto const start {::dux::gettime()};
		::dux::sleep(dux_uint64l(0x2));
		auto const stop {::dux::gettime()};
		dux_ass("",stop - start == dux_uint64l(0x2));
	}
	{
		constexpr auto arrsz {dux_uwrdl(0x8)};
		bool arr[arrsz];
		::dux::plot(arr,arrsz,[](::dux::uwrd const _n) {return ::dux::isprime(_n);});
		dux_ass("",arr[dux_uwrdl(0x0)] == false);
		dux_ass("",arr[dux_uwrdl(0x1)] == false);
		dux_ass("",arr[dux_uwrdl(0x2)] == true);
		dux_ass("",arr[dux_uwrdl(0x3)] == true);
		dux_ass("",arr[dux_uwrdl(0x4)] == false);
		dux_ass("",arr[dux_uwrdl(0x5)] == true);
		dux_ass("",arr[dux_uwrdl(0x6)] == false);
		dux_ass("",arr[dux_uwrdl(0x7)] == true);
	}
	{
		dux_ass("",::dux::memeq("ABC",dux_uwrdl(0x3),"ABC"));
		auto file {::dux::crtfile("dux-io-demo")};
		file.write("Hello there!");
		file.open("dux-io-demo",::dux::iotyp::r);
		auto const dat {file.read(dux_uwrdl(0xC))};
		dux_ass("",dat.sz() == dux_uwrdl(0xC));
		dux_ass("",::dux::memeq(dat.craw(),dat.sz(),"Hello there!"));
		file.close();
	}
	if (::dux::haserr()) [[unlikely]] {
		::dux::dbglog("dux.\x1B[91mdemo\x1B[0m        :: Got error %S!\n",::dux::errcdnm(::dux::geterr()));
		::dux::exit(::dux::stat::err);
	}
	::ctest(_params);
	::dux::onexit([](::dux::stat) {
		::dux::onexit([](::dux::stat) {});
		dux_ass("",::dux::haserr());
		::dux::dbglog("dux.demo        :: All tests passed!\n");
	});
	::dux::exit(::dux::stat::ok);
}
