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
	template<typename Fn,typename... Ts,::dux::usz... N> [[nodiscard]] constexpr auto _tupapply(Fn && fn,::dux::tup<Ts...> const & tup,::dux::intseq<::dux::usz,N...>) -> decltype(auto);
}

template<typename Fn,typename... Ts,::dux::usz... N> [[nodiscard]] constexpr auto ::dux::_tupapply(Fn && _fn,::dux::tup<Ts...> const & _tup,::dux::intseq<::dux::usz,N...>) -> decltype(auto) {
	return _fn(_tup.template get<N>()...);
}
template<typename T,typename... Ts> template<typename Fn> constexpr auto ::dux::tup<T,Ts...>::apply(Fn const & _fn) const -> decltype(auto) {
	return ::dux::_tupapply(_fn,*this,dux::mkintseq<::dux::usz,0x1uz + sizeof...(Ts)>{});
}
template<typename T,typename... Ts> template<::dux::usz N> constexpr auto ::dux::tup<T,Ts...>::get() const noexcept -> auto {
	return static_cast<::dux::_tupbase<N,typename ::dux::_tupgettyp<N,T,Ts...>::typ> const *>(this)->get();
}
template<typename T,typename... Ts> template<typename T0,typename... Ts0> constexpr auto ::dux::tup<T,Ts...>::operator == (::dux::tup<T0,Ts0...> const & _oth) noexcept -> bool {
	if constexpr (!::dux::issame<decltype(*this),decltype(_oth)>) {
		return false;
	}
	else {
		constexpr auto num{sizeof...(Ts)};
		if constexpr (num == 0x0uz) {
			return true;
		}
	}
}
