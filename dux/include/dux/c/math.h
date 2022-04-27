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

# define dux_num_cbrt2 (dux_priv_num_cbrt2)
# define dux_num_e     (dux_priv_num_e)
# define dux_num_lg2   (dux_priv_num_lg2)
# define dux_num_ln2   (dux_priv_num_ln2)
# define dux_num_phi   (dux_priv_num_phi)
# define dux_num_pi    (dux_priv_num_pi)
# define dux_num_sqrt2 (dux_priv_num_sqrt2)
# define dux_num_sqrt3 (dux_priv_num_sqrt3)

# define dux_inf(_typ) (_Generic((_typ){0x0},double:dux_priv_infd,float:dux_priv_inff,long double:dux_priv_infld))

# define dux_nan(_typ) (_Generic((_typ){0x0},double:dux_priv_nand,float:dux_priv_nanf,long double:dux_priv_nanld))

# define dux_abs(  _val)           (dux_priv_abs(  _val))
# define dux_fma(  _x,   _y,   _z) (dux_priv_fma(  _x,   _y,_z))
# define dux_isnan(_val)           (dux_priv_isnan(_val))
# define dux_max(  _val0,_val1)    (dux_priv_max(  _val0,_val1))
# define dux_min(  _val0,_val1)    (dux_priv_min(  _val0,_val1))

dux_attr_const dux_attr_useret dux_uint16 dux_priv_msb16(  dux_uint16  val);                  /* Most significant bit of val (also equal to ceil(lb(val + 1))) */
dux_attr_const dux_attr_useret dux_uint32 dux_priv_msb32(  dux_uint32  val);
dux_attr_const dux_attr_useret dux_uint64 dux_priv_msb64(  dux_uint64  val);
dux_attr_const dux_attr_useret dux_uint8  dux_priv_msb8(   dux_uint8   val);

# define dux_ceil( _val)       (_Generic(_val, double:    dux_priv_ceild, float:     dux_priv_ceilf, long double:dux_priv_ceilld)(                         _val))
# define dux_exp(  _base,_exp) (_Generic(_base,double:    dux_priv_expd,  float:     dux_priv_expf,  long double:dux_priv_expld)(                          _base,_exp))
# define dux_floor(_val)       (_Generic(_val, double:    dux_priv_floord,float:     dux_priv_floorf,long double:dux_priv_floorld)(                        _val))
# define dux_log(  _base,_val) (_Generic(_val, double:    dux_priv_logd,  float:     dux_priv_logf,  long double:dux_priv_logld)(                          _base,_val))
# define dux_msb(  _val)       (_Generic(_val, dux_uint16:dux_priv_msb16, dux_uint32:dux_priv_msb32, dux_uint64: dux_priv_msb64,  dux_uint8:dux_priv_msb8)(_val))
# define dux_root( _exp,_val)  (_Generic(_val, double:    dux_priv_rootd, float:     dux_priv_rootf, long double:dux_priv_rootld )(                        _exp, _val))
# define dux_round(_val)       (_Generic(_val, double:    dux_priv_roundd,float:     dux_priv_roundf,long double:dux_priv_roundld)(                        _val))
# define dux_sqrt(_val)        (_Generic(_val, double:    dux_priv_sqrtd, float:     dux_priv_sqrtf, long double:dux_priv_sqrtld)(                         _val))
# define dux_trunc(_val)       (_Generic(_val, double:    dux_priv_truncd,float:     dux_priv_truncf,long double:dux_priv_truncld)(                        _val))

dux_attr_useret dux_uint16 dux_rnd16(void); /* Random N-bit number */
dux_attr_useret dux_uint32 dux_rnd32(void);
dux_attr_useret dux_uint64 dux_rnd64(void);
dux_attr_useret dux_uint8  dux_rnd8( void);

void dux_priv_swp(void * lvar,void * rvar,dux_uwrd sz);
# define dux_swp(_lvar,_rvar) (dux_swpsz(&_lvar,&_rvar,sizeof (_lvar)))
