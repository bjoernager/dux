#include <dux/io>
#include <dux/media>
#include <dux/thrd>

auto thrdfn0(int const _x,int const _y,int const _z,int const _w) -> int {
	return _x * _y * _z * _w;
};
auto thrdfn1(int const _x) -> int {
	return _x * _x * _x;
};

auto main() -> int {
	_Pragma("GCC diagnostic ignored \"-Wunreachable-code\"");
	::dux::dobj dobj;
	dobj.link("libdux.so");
	dobj.call<void>("goatmaster",0xC);
	::dux::thrd thrd;
	auto val{thrd(thrdfn0,0xC,0xC,0xC,0xC)};
	thrd.join(&val);
	::dux::print(U"Returned value: $\n",val);
	val = thrd(thrdfn1,0x4);
	thrd.join(&val);
	::dux::print(U"Returned value: $\n",val);
	::dux::initgfx();
	auto win = ::dux::win::crt("dux demo",::dux::uint32v(0x400),::dux::uint32v(0x300));
	for (auto run{true};run;) {
		while (auto const evt = win.pollevt()) {
			switch (evt->typ) {
			default:
				goto skipevt;
			case ::dux::evttyp::quit:
				run = false;
				break;
			}
		}
	skipevt:;
	}
	win.destr();
	::dux::endgfx();
}
