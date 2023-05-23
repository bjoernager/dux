#include <cstdlib>
#include <dux/io.h>
#include <dux/thr.h>
#include <iostream>

int main() {
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

	err = ::dux_wrtstr(fil,
		"static void msg(void);\n"
		"\n"
		"int main(void) {\n"
		"\tmsg();\n"
		"\treturn 0x45;\n"
		"}\n"
	);
	chkerr("unable to write to file");

	err = ::dux_cls(fil);
	chkerr("unable to close file");
}
