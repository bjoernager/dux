/*
	Copyright 2021 Gabriel Jensen

	This file is part of dux.

	dux is free software:
	you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

	dux is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
	without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
	See the GNU Affero General Public License for more details.

	You should have received a copy of the GNU Affero General Public License along with dux.
	If not, see <https://www.gnu.org/licenses/>.
*/

/*
	thrd implementation:
		(To-do) On Linux, we will use our own wrappers for the Linux system calls (syscalls) that enable multithreading;
		On POSIX, we will use our own wrappers for the POSIX Threads API, as to not polute the global scope;
*/


namespace dux {
#if defined(dux_os_posix)
	template<typename Fn,typename... Ts> class _thrdwrapdat {
	public:
		::dux::tup<Ts...> args;
		Fn *              fn   {nullptr};
	};
#endif
}
template<typename T> auto ::dux::thrd::join(T * const dux_restr _ret) -> void {
	if (this->_isjoin) [[unlikely]] { /* We do not need to do anything if the thread has joined. */
		return;
	}
#if defined(dux_os_posix)
	auto const ret{static_cast<T *>(::dux::_pthrdjoin(this->_pthrdhandl))}; /* POSIX Threads return the pointer passed to (::pthread_exit) on joining of thread. */
	if constexpr (!::dux::isvoid<T>) { /* (void) is an incomplete type, and we do not need to operate on it. */
		if (_ret) { /* Safe: "A prvalue of integral, floating-point, unscoped enumeration, __pointer__, and pointer-to-member types can be converted to a prvalue of type bool.", cppreference, 2021-11-17T15:40:00+0100 */
			*_ret = *ret;
		}
	}
	::delete ret; /* Free the allocated memory we got from the wrapper lambda in (::dux::thrd::operator ()). */
#else
	_Pragma("GCC message Unable to implement (::dux::thrd::join)!");
#endif
	this->_isjoin = true;
}
template<typename Fn,typename... Ts> auto ::dux::thrd::operator () (Fn const & _fn, Ts const &... _args) -> auto {
	using T = decltype(_fn(Ts{}...));
#if defined(dux_os_posix)
	auto thrdwrap{[](void * const dux_restr _dat) -> void * { /* POSIX Threads use functions of type (void * (void *)). We will create a wrapper lambda, which calls the provided function (_fn). */
		auto const dat {static_cast<::dux::_thrdwrapdat<Fn,Ts...> *>(_dat)};
		auto const fn  {dat->fn};
		auto const args{dat->args};
		::delete dat;
		auto const ret{::new T};
		*ret = args.apply(fn);
		return ret;
	}};
	auto const thrdwrapdat{::new ::dux::_thrdwrapdat<Fn,Ts...>};
	thrdwrapdat->fn       = _fn;
	thrdwrapdat->args     = ::dux::tup{_args...};
	::dux::_pthrdcrt(this->_pthrdhandl,thrdwrap,thrdwrapdat);
#else
	_Pragma("GCC message Unable to implement (::dux::thrd::operator ())!");
#endif
	this->_isjoin = false;
	return T{};
}
template<typename Fn,typename... Ts> auto ::dux::thrd::run(Fn const & _fn, Ts const &... _args) -> decltype(auto) { /* This is a wrapper for (::dux::thrd::operator ()) to be used in cases of the thread being accessed using a handle ((thrd->run(...)) is prettier than (thrc->operator () (...))). */
	return this->operator () (_fn,_args...);
}
#if defined(dux_os_posix)
::dux::thrd::thrd() : _pthrdhandl(::dux::_getpthrdhandl()) {}
#else
::dux::thrd::thrd() {}
#endif
::dux::thrd::~thrd() noexcept {
	if (!this->_isjoin) [[unlikely]] { /* The programmer did not join the thread before it got out of scope. We want safe programming, so we will __not__ recover from this. */
		::dux::abrt(U"dux :: Active thread got out of scope!");
	}
#if defined(dux_os_posix)
	::dux::_freepthrdhandl(this->_pthrdhandl);
#endif
}
