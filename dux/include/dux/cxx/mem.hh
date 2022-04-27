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

namespace dux {
	template<typename T> constexpr auto alloc() noexcept -> T * {
		static_assert(!::dux::issame<T,void>,"You may not allocate void objects!");
		dux_priv_ifconsteval {
			try {return ::new T;}
			catch (...) {
				::dux::seterr(::dux::errcd::badalloc);
				return nullptr;
			}
		}
		else {
			auto const ptr {static_cast<T *>(::dux_priv_alloc(sizeof (T),alignof (T)))}; /* This is not UB, as the pointer will be correctly alligned to any type. */
			*ptr = T {};
			return ptr;
		}
	}
	template<typename T> constexpr auto alloc(::dux::uwrd const _sz) noexcept -> T * {
		static_assert(!::dux::issame<T,void>,"You may not allocate void objects!");
		if (_sz == dux_uwrdl(0x0)) [[unlikely]] {return nullptr;}
		dux_priv_ifconsteval {
			try {return ::new T[_sz];}
			catch (...) {
				::dux::seterr(::dux::errcd::badalloc);
				return nullptr;
			}
		}
		else {
			auto const olderr {::dux::geterr()};
			::dux::reseterr();
			auto const ptr {static_cast<T *>(::dux_priv_alloc(_sz * sizeof (T),alignof (T)))};
			if (::dux::haserr()) [[unlikely]] {return nullptr;}
			::dux::seterr(olderr);
			if (_sz > dux_uwrdl(0x1)) [[likely]] {for (auto tmp {ptr};tmp < ptr + _sz;++tmp) {*tmp = T {};}}
			return ptr;
		}
	}

	[[noreturn]] auto free(::dux::nullptrtyp) noexcept -> void;
	template<typename T> constexpr auto free(T * const restrict _ptr) noexcept -> void { /* TO-DO: Call destructors. Cannot be implemented before getallocsz. */
		static_assert(!::dux::issame<T,void>,"You may not free void objects!");
		dux_priv_ifconsteval {::delete[] _ptr;}
		else {::dux_priv_free(_ptr);}
	}

	template<typename T> constexpr auto renew(T * const restrict _ptr,::dux::uwrd const _newsz) -> T * {
		auto * const restrict newptr = ::new T[_newsz];
		auto const oldsz {::__builtin_object_size(_ptr,0x0)};
		::dux::cpy(_ptr,::dux::min(oldsz,_newsz),newptr);
		::delete[] _ptr;
		return newptr;
	}
}

namespace dux::priv {
	auto getallocsz(void * ptr) noexcept -> ::dux::uwrd;
}
namespace dux {
	template<typename T> constexpr auto getallocsz(T * const restrict _ptr) noexcept -> ::dux::uwrd {
		dux_priv_ifconsteval {return ::__builtin_object_size(_ptr,0x0);}
		else {return ::dux::priv::getallocsz(_ptr);}
	}
}

namespace dux::priv {
	auto realloc(void * ptr,::dux::uwrd newsz) noexcept -> void *;
}
namespace dux {
	template<typename T> constexpr auto realloc(T * const restrict _ptr,::dux::uwrd const _newsz) noexcept -> T * {
		static_assert(!::dux::issame<T,void>,"You may not allocate void objects!");
		dux_priv_ifconsteval {return ::dux::renew(_ptr,_newsz);}
		else {return static_cast<T *>(::dux::priv::realloc(_ptr,_newsz * sizeof (T)));}
	}
}
