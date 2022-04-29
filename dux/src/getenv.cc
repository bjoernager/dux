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

# include <dux/priv>

# include <dux/str>

extern char * * environ;

auto ::dux::getenv(char const * const restrict _envvarname) noexcept -> ::dux::str {
	::dux::str str;
	constexpr auto envvarnamebufsz {dux_uwrdl(0xFF)};
	static char envvarnamebuf[envvarnamebufsz];
	if (environ == nullptr) [[unlikely]] {
		str.ptr = nullptr;
		return str;
	}
	for (auto envvars = const_cast<char const * const *>(environ);*envvars != nullptr;++envvars) {
		auto       envvar     = *envvars;
		auto const eqpos      = ::dux::fndchr(envvar,'=');
		auto       envvarname = envvarnamebuf;
		::dux::cpy(envvar,eqpos,envvarname);
		envvarname[eqpos] = '\u0000';
		if (::dux::streq(envvarname,_envvarname)) [[unlikely]] {
			str.ptr = envvar + eqpos + dux_uwrdl(0x1);
			str.sz  = eqpos;
			::dux::dbglog("dux.getenv :: Got value of environment variable %s: \"%s\"\n",_envvarname,str.ptr);
			return str;
		}
	}
	str.ptr = "";
	str.sz  = dux_uwrdl(0x0);
	::dux::dbglog("dux.getenv :: Environment variable %s did not exist!\n",_envvarname);
	return str;
}

# pragma GCC diagnostic ignored "-Wmissing-declarations"

extern "C" auto dux_getenv(char const * const restrict _envvarname) -> ::dux::str {return ::dux::getenv(_envvarname);}
