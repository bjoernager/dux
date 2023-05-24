#include <cassert>
#include <cstdlib>
#include <dux/io.h>
#include <iostream>
#include <zp/str>

int main() {
	//::dux_pri("dux {i04}.{i04}, demo\n",dux_api,dux_ext);
	::std::cout << "dux " << dux_api << '.' << dux_ext << ", demo" << ::std::endl;

	::dux_err err = ::dux_err_oky;

	auto const chkerr = [&err](char const * const msg) noexcept {
		if (err != ::dux_err_oky) {
			::std::cout << msg << ": " << ::dux_errmsg(err) << ::std::endl;
			::std::exit(EXIT_FAILURE);
		}
	};

	err = ::dux_crtdir("testdir",0755u);
	chkerr("unable to create directory");

	::dux_fil * fil = nullptr;

	err = ::dux_crt(&fil,"testdir/dux-demo-file",0644u);
	chkerr("unable to create file");

	char const src[] =
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

	err = ::dux_wrtstr(fil,src);
	chkerr("unable to write to file");

	err = ::dux_cls(fil);
	chkerr("unable to close file");

	::dux_pthinf pthinf;
	err = ::dux_sttpth(&pthinf,"testdir/dux-demo-file");
	chkerr("unable to stat file");

	assert(pthinf.siz == sizeof (src)-0x1u);

	err = ::dux_cpy("testdir/dux-demo-file.c","testdir/dux-demo-file",0644u);
	chkerr("unable to copy file");

	err = ::dux_opn(&fil,"testdir/dux-demo-file.c");
	chkerr("unable to open file");

	char buf[sizeof (src)];

	err = ::dux_red(buf,fil,sizeof (src),nullptr);
	chkerr("unable to read file");

	assert(::zp::strequ(buf,src));

	err = ::dux_cls(fil);
	chkerr("unable to close file");
}
