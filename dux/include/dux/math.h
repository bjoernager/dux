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

/* These numbers must be rounded to 64 digits. */
# define dux_priv_num_cbrt2 (1.2599210498948731647672106072782283505702514647015079800819751122l)
# define dux_priv_num_e     (2.7182818284590452353602874713526624977572470936999595749669676277l)
# define dux_priv_num_lg2   (0.3010299956639811952137388947244930267681898814621085413104274611l)
# define dux_priv_num_ln2   (0.6931471805599453094172321214581765680755001343602552541206800095l)
# define dux_priv_num_phi   (1.6180339887498948482045868343656381177203091798057628621354486227l)
# define dux_priv_num_pi    (3.1415926535897932384626433832795028841971693993751058209749445923l)
# define dux_priv_num_sqrt2 (1.4142135623730950488016887242096980785696718753769480731766797380l)
# define dux_priv_num_sqrt3 (1.7320508075688772935274463415058723669428052538103806280558069795l)

# if dux_hasbuiltin(__builtin_huge_val) && dux_hasbuiltin(__builtin_huge_valf) && dux_hasbuiltin(__builtin_huge_vall)
# define dux_priv_infd  __builtin_huge_val()
# define dux_priv_inff  __builtin_huge_valf()
# define dux_priv_infld __builtin_huge_vall()
# else
# define dux_priv_infd  dux_dblmax
# define dux_priv_inff  dux_fltmax
# define dux_priv_infld dux_ldblmax
# endif

# if dux_hasbuiltin(__builtin_nan) && dux_hasbuiltin(__builtin_nanf) && dux_hasbuiltin(__builtin_nanl)
# define dux_priv_nand  __builtin_nan("")
# define dux_priv_nanf  __builtin_nanf("")
# define dux_priv_nanld __builtin_nanl("")
# else
# define dux_priv_nand  dux_dblmax
# define dux_priv_nanf  dux_fltmax
# define dux_priv_nanld dux_ldblmax
# endif

/* Functions we can implement using simple expressions (these may be used in constant evaluation): */
# define dux_priv_abs(  _val)           ((_val) < (dux_priv_uint8)0x0 ? -(_val) : (_val))
# define dux_priv_fma(  _x,   _y,   _z) ((_x) * (_y) + (_z))
# define dux_priv_isnan(_val)           ((_val) != (_val))
# define dux_priv_max(  _val0,_val1)    ((_val0) > (_val1) ? (_val0) : (_val1))
# define dux_priv_min(  _val0,_val1)    ((_val0) > (_val1) ? (_val1) : (_val0))

dux_priv_begincdecls

dux_attr_const dux_attr_useret double      dux_priv_ceild(  double      val);                  /* The ceiling of val */
dux_attr_const dux_attr_useret float       dux_priv_ceilf(  float       val);
dux_attr_const dux_attr_useret long double dux_priv_ceilld( long double val);
dux_attr_const dux_attr_useret double      dux_priv_expd(   double      base,double      exp); /* base raised to the power exp */
dux_attr_const dux_attr_useret float       dux_priv_expf(   float       base,float       exp);
dux_attr_const dux_attr_useret long double dux_priv_expld(  long double base,long double exp);
dux_attr_const dux_attr_useret double      dux_priv_floord( double      val);                  /* The floor of val */
dux_attr_const dux_attr_useret float       dux_priv_floorf( float       val);
dux_attr_const dux_attr_useret long double dux_priv_floorld(long double val);
dux_attr_const dux_attr_useret double      dux_priv_logd(   double      base,double      val); /* Logarithm of base e of val */
dux_attr_const dux_attr_useret float       dux_priv_logf(   float       base,float       val);
dux_attr_const dux_attr_useret long double dux_priv_logld(  long double base,long double val);
dux_attr_const dux_attr_useret double      dux_priv_rootd(  double      exp, double      val); /* Root number exp of val */
dux_attr_const dux_attr_useret float       dux_priv_rootf(  float       exp, float       val);
dux_attr_const dux_attr_useret long double dux_priv_rootld( long double exp, long double val);
dux_attr_const dux_attr_useret double      dux_priv_roundd( double      val);                  /* val rounded to the nearest whole number */
dux_attr_const dux_attr_useret float       dux_priv_roundf( float       val);
dux_attr_const dux_attr_useret long double dux_priv_roundld(long double val);
dux_attr_const dux_attr_useret double      dux_priv_sqrtd(  double      val);                  /* Square root  */
dux_attr_const dux_attr_useret float       dux_priv_sqrtf(  float       val);
dux_attr_const dux_attr_useret long double dux_priv_sqrtld( long double val);
dux_attr_const dux_attr_useret double      dux_priv_truncd( double      val);                  /* val rounded to the nearest whole number torwards zero */
dux_attr_const dux_attr_useret float       dux_priv_truncf( float       val);
dux_attr_const dux_attr_useret long double dux_priv_truncld(long double val);

dux_priv_endcdecls
