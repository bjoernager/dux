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

namespace dux {
	class thrderr : public ::dux::except {
	public:
		using ::dux::except::except;
	};

	class thrd {
	public:
		template<typename T  = ::dux::ubyte>                                     auto join(        T *               ret = nullptr)                             -> void;
		template<typename T>                                                     auto join(        ::dux::nullptrtyp)                                                             = delete;
		template<typename Fn,               typename... Ts>                      auto operator () (Fn const &        fn,           Ts const &... args)          -> auto;
		template<typename Fn,               typename... Ts>                      auto run(         Fn const &        fn,           Ts const &... args)          -> decltype(auto);
		                                                    [[nodiscard]] inline      thrd();
		                                                                  inline      ~thrd()                                                          noexcept;
	private:
		bool                   _isjoin{true};
		void * const dux_restr _pthrdhandl;
	};

#if defined(dux_os_posix)
	auto _freepthrdhandl(void * handl)                                                 noexcept -> void;
	auto _getpthrdhandl()                                                                       -> void *;
	auto _pthrdcrt(      void * handl,auto (* fn)( void *) -> void *,void const * arg)          -> void;
	auto _pthrdjoin(     void * handl)                                                          -> void *;
#endif
}

#include <dux/thrd.d/thrd.hh>