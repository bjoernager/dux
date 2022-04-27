# include <dux/io>
# include <dux/math>
# include <dux/media>
# include <dux/mem>
# include <dux/seq>
# include <dux/sig>
# include <dux/str>
# include <dux/thrd>
# include <dux/time>

#include <stdio.h>

bool dux_local_gotsig = false;

static bool dux_local_sighandl(enum dux_sig const _sig) {
	dux_ass("",_sig == dux_sig_intr);
	dux_local_gotsig = true;
	return false;
}

void ctest(void const * const restrict _params) {
	dux_dbglog("dux :: demo :: Performing C-tests!\n");
	if (dux_getnummainparams(_params) == dux_uwrdl(0x0)) {dux_dbglog("dux :: demo :: No parameters!\n");}
	else {for (dux_uwrd n = dux_uwrdl(0x0);n < dux_getnummainparams(_params);++n) {dux_dbglog("dux :: demo :: Parameter %zu: %s\n",n + dux_uwrdl(0x1),dux_getmainparam(_params,n));}}
	{
		dux_setsighandl(dux_sig_intr,dux_local_sighandl);
		dux_raise(dux_sig_intr);
		dux_setsighandl(dux_sig_intr,dux_dflsighandl);
		dux_ass("",dux_local_gotsig);
	}
	/*{
		int arr0[] = {
			0xF,
			0xFF,
			0xFFF,
			0xFFFF,
		};
		int * const restrict arr1 = dux_alloc(sizeof (arr0));
		dux_cpy(arr0,sizeof (arr0),arr1,sizeof (arr0[dux_uwrdl(0x0)]));
		dux_ass("",arr1[dux_uwrdl(0x0)] == 0xF);
		dux_ass("",arr1[dux_uwrdl(0x1)] == 0xFF);
		dux_ass("",arr1[dux_uwrdl(0x2)] == 0xFFF);
		dux_ass("",arr1[dux_uwrdl(0x3)] == 0xFFFF);
		dux_free(arr1);
	}*/
}
