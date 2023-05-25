#include <cstdlib>
#include <dux/io.h>
#include <iostream>
#include <zp/str>

template<typename ltyp,typename rtyp> static auto chk(long const lin,::zp::i8 const mth,ltyp const& lval,rtyp const& rval) {
	auto const cmp = [](::zp::i8 const mth,auto const& lval,auto const& rval) -> bool {
		switch (mth) {
		default:
			::zp::unrch();
		case 0x0u:
			return lval == rval;
		case 0x1u:
			return lval >= rval;
		case 0x2u:
			return lval >  rval;
		case 0x3u:
			return lval <= rval;
		case 0x4u:
			return lval <  rval;
		case 0x5u:
			return lval != rval;
		}
	};

	auto const str = [](::zp::i8 const mth) -> char const * {
		switch (mth) {
		default:
			::zp::unrch();
		case 0x0u:
			return "!=";
		case 0x1u:
			return "<";
		case 0x2u:
			return "<=";
		case 0x3u:
			return ">";
		case 0x4u:
			return ">=";
		case 0x5u:
			return "==";
		}
	};

	if (!cmp(mth,lval,rval)) {
		::std::cout << lin << ": " << lval << ' ' << str(mth) << ' ' << rval << ::std::endl;
		::std::exit(EXIT_SUCCESS);
	}
};
#define chkeq(lval,rval) (::chk(__LINE__,0x0u,(lval),(rval)))
#define chkge(lval,rval) (::chk(__LINE__,0x1u,(lval),(rval)))
#define chkgt(lval,rval) (::chk(__LINE__,0x2u,(lval),(rval)))
#define chkle(lval,rval) (::chk(__LINE__,0x3u,(lval),(rval)))
#define chklt(lval,rval) (::chk(__LINE__,0x4u,(lval),(rval)))
#define chkne(lval,rval) (::chk(__LINE__,0x5u,(lval),(rval)))

int main() {
	//::dux_pri("dux {i04}.{i04}, demo\n",dux_api,dux_ext);
	::std::cout << "dux " << dux_api << '.' << dux_ext << ", demo" << ::std::endl;

	::dux_err err = ::dux_err_oky;

	auto const chkerr = [&err](char const* const msg) noexcept {
		if (err != ::dux_err_oky) {
			::zp::siz const errmsglen = ::dux_errmsg(nullptr,err);
			char *    const errmsg    = new char[errmsglen+0x1u];
			
			::dux_errmsg(errmsg,err);
			errmsg[errmsglen] = '\x00';

			::std::cout << msg << ": " << errmsg << ::std::endl;
			delete[] errmsg;

			::std::exit(EXIT_FAILURE);
		}
	};

	::zp::siz const homdirlen = ::dux_homdir(nullptr);
	char * const    homdir    = new char[homdirlen+0x1u];

	::dux_homdir(homdir);
	homdir[homdirlen] = '\x00';

	::std::cout << "Home directory: " << homdir << ::std::endl;
	delete[] homdir;

	err = ::dux_crtdir("testdir",0755u);
	chkerr("unable to create directory");

	::dux_fil * fil = nullptr;

	err = ::dux_crt(&fil,"testdir/dux-demo-file",0644u);
	chkerr("unable to create file");

	constexpr char src[] =
		"static void msg(void);\n"
		"\n"
		"int main(void) {\n"
		"\tmsg();\n"
		"\treturn 0x45;\n"
		"}\n"
		"\n"
		"#include <ly/io.h>\n"
		"\n"
		"static void msg(void) {\n"
		"\tly_wrtstr(ly_dflout,\"flux ftw\\n\");\n"
		"} /* Remember the last newline -> */\n";
	constexpr ::zp::siz srclen = sizeof (src)-0x1u;

	err = ::dux_wrtstr(fil,src);
	chkerr("unable to write to file");

	err = ::dux_cls(fil);
	chkerr("unable to close file");

	::dux_pthinf pthinf;
	err = ::dux_sttpth(&pthinf,"testdir/dux-demo-file");
	chkerr("unable to stat file");

	chkeq(pthinf.siz,srclen);

	err = ::dux_cpy("testdir/dux-demo-file.c","testdir/dux-demo-file",0644u);
	chkerr("unable to copy file");

	err = ::dux_opn(&fil,"testdir/dux-demo-file.c");
	chkerr("unable to open file");

	char buf[srclen+0x1u];
	buf[srclen] = '\x00';

	::zp::siz numred = 0x0u;
	err = ::dux_red(buf,fil,srclen,&numred);
	chkerr("unable to read file");

	chkeq(numred,srclen);

	chkeq(::zp::strequ(buf,src),true);

	err = ::dux_cls(fil);
	chkerr("unable to close file");
}
