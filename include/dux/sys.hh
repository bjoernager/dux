/*
	Copyright 2021 Gabriel Jensen

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

#define dux_ass(expr,msg) \
	([&]() { \
		if constexpr (::dux::dbg) { \
			::dux::_ass(__FILE__,static_cast<unsigned long>(__LINE__),dux_fnnm,expr,#expr,msg); \
		} \
	}())

namespace dux {
	enum class sig : ::dux::ubyte {
		abrt,
		fpe,
		ill,
		int_,
		kill,
		segv,
		term,
		trap,
#if defined(dux_os_posix)
		alrm,
		bus,
		cont,
		hup,
		iot,
		pipe,
		poll,
		prof,
		quit,
		rtmax,
		rtmin,
		stop,
		sys,
		tstp,
		ttin,
		ttou,
		urg,
		usr1,
		usr2,
		vtalrm,
		winch,
		xcpu,
		xfsz,
#endif
	};
	constexpr auto numsig{static_cast<::dux::ubyte>([]() {
#if defined(dux_os_posix)
		return ::dux::sig::xfsz;
#else
		return ::dux::sig::trap;
#endif
	}()) + ::dux::ubytev(0x1)};

	class dobj {
	public:
		template<typename T,typename... Ts> [[nodiscard]] inline auto call(  char const * fn, Ts const &... args)          -> T;
		                                    [[nodiscard]] inline      dobj();
		                                                  inline auto link(  char const * lib)                             -> void;
		                                                  inline auto unlink()                                    noexcept -> void;
		                                                  inline      ~dobj()                                     noexcept;
	private:
		void * const dux_restr _dat;
	};

		          constexpr auto _ass(    char const *       fl,                     unsigned long ln,                                              char const *  fn,                         bool expr,char const * exprstr,char const * msg) noexcept -> bool;
	[[noreturn]]            auto abrt()                                                                                                                                                                                                        noexcept -> void;
	[[noreturn]]            auto abrt(    ::dux::str const & msg)                                                                                                                                                                              noexcept -> void;
	[[noreturn]]            auto exit(    ::dux::stat        stat = ::dux::stat::ok)                                                                                                                                                           noexcept -> void;
	[[nodiscard]]           auto getenv(  char const *       var)                                                                                                                                                                                       -> char const *;
	[[noreturn]]            auto qexit(   ::dux::stat        stat = ::dux::stat::err)                                                                                                                                                          noexcept -> void;
	                        auto raise(   ::dux::sig         sig)                                                                                                                                                                              noexcept -> void;
	                        auto sighandl(::dux::sig         sig,                    auto (*       handl)(::dux::sig) -> void)                                                                                                                          -> auto (&)(::dux::sig) -> void; 
	                        auto sleep(   ::dux::uint64      sec,                    ::dux::uint64 nsecx                      = ::dux::uint64v(0x0),::dux::uint64 nsecy = ::dux::uint64v(0x1))                                                 noexcept -> void;
	[[noreturn]]            auto trap()                                                                                                                                                                                                        noexcept -> void;
	[[noreturn]]            auto unreach()                                                                                                                                                                                                     noexcept -> void;

	constexpr auto (* dflsighandl)(::dux::sig) -> void {nullptr};
}

#include <dux/sys.d/_ass.hh>
#include <dux/sys.d/dobj.hh>
