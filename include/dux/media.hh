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
	enum class evttyp : ::dux::ubyte {
		kbd,
		mus,
		quit,
		resz,
		unknwn,
	};

	class evt {
	public:
		::dux::evttyp typ{::dux::evttyp::unknwn};
	};

	class win {
	public:
		                     auto close()                                                                 -> void;
		                     auto mv(     ::dux::uint16      x, ::dux::uint16 y)                          -> void;
		[[nodiscard]] static auto crt(    char const *       nm,::dux::uint16 w,::dux::uint16 h)          -> ::dux::win;
		                     auto destr()                                                        noexcept -> void;
		                     auto open()                                                                  -> void;
		                     auto renm(   char const *       nm)                                          -> void;
		                     auto resz(   ::dux::uint16      w, ::dux::uint16 h)                          -> void;
		                     auto pollevt()                                                      noexcept -> ::dux::opt<::dux::evt>;
		[[nodiscard]]             win();
		[[nodiscard]]             win(    ::dux::win const & oth);
		                          ~win()                                                         noexcept;
	private:
		void * const dux_restr _dat;
		bool                   _isopen{false};
	};

	auto endgfx()  -> void;
	auto initgfx() -> void;
}
