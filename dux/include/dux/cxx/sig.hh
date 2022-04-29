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
	enum class sig : ::dux::uint8 {
		abrt   = static_cast<::dux::uint8>(dux_priv_sig_abrt),
		alrm   = static_cast<::dux::uint8>(dux_priv_sig_alrm),
		bus    = static_cast<::dux::uint8>(dux_priv_sig_bus),
		chld   = static_cast<::dux::uint8>(dux_priv_sig_chld),
		cont   = static_cast<::dux::uint8>(dux_priv_sig_cont),
		fpe    = static_cast<::dux::uint8>(dux_priv_sig_fpe),
		hup    = static_cast<::dux::uint8>(dux_priv_sig_hup),
		ill    = static_cast<::dux::uint8>(dux_priv_sig_ill),
		io     = static_cast<::dux::uint8>(dux_priv_sig_io),
		iot    = static_cast<::dux::uint8>(dux_priv_sig_iot),
		intr   = static_cast<::dux::uint8>(dux_priv_sig_intr),
		kill   = static_cast<::dux::uint8>(dux_priv_sig_kill),
		file   = static_cast<::dux::uint8>(dux_priv_sig_file),
		poll   = static_cast<::dux::uint8>(dux_priv_sig_poll),
		prof   = static_cast<::dux::uint8>(dux_priv_sig_prof),
		pwr    = static_cast<::dux::uint8>(dux_priv_sig_pwr),
		quit   = static_cast<::dux::uint8>(dux_priv_sig_quit),
		segv   = static_cast<::dux::uint8>(dux_priv_sig_segv),
		stop   = static_cast<::dux::uint8>(dux_priv_sig_stop),
		sys    = static_cast<::dux::uint8>(dux_priv_sig_sys),
		term   = static_cast<::dux::uint8>(dux_priv_sig_term),
		trap   = static_cast<::dux::uint8>(dux_priv_sig_trap),
		tstp   = static_cast<::dux::uint8>(dux_priv_sig_tstp),
		ttin   = static_cast<::dux::uint8>(dux_priv_sig_ttin),
		ttou   = static_cast<::dux::uint8>(dux_priv_sig_ttou),
		urg    = static_cast<::dux::uint8>(dux_priv_sig_urg),
		usr1   = static_cast<::dux::uint8>(dux_priv_sig_usr1),
		usr2   = static_cast<::dux::uint8>(dux_priv_sig_usr2),
		vtalrm = static_cast<::dux::uint8>(dux_priv_sig_vtalrm),
		winch  = static_cast<::dux::uint8>(dux_priv_sig_winch),
		xcpu   = static_cast<::dux::uint8>(dux_priv_sig_xcpu),
		xfsz   = static_cast<::dux::uint8>(dux_priv_sig_xfsz),
	};

	constexpr auto numsig {dux_priv_numsig};
}

namespace dux {
	class sighandl;
}

namespace dux {
	auto raise(      ::dux::sig sig)                          noexcept -> void;
	auto setsighandl(::dux::sig sig,::dux::sighandl sighandl) noexcept -> void;
}

namespace dux {
	class sighandl {
	public:
		[[nodiscard]] sighandl() noexcept = default;

		template<typename Fn> [[nodiscard]] constexpr sighandl(Fn const & _handl) noexcept {
			this->_isdfl = false;
			this->handl  = _handl;
		}

		[[nodiscard]] consteval static auto dfl() noexcept -> ::dux::sighandl {
			::dux::sighandl sighandl;
			sighandl.handl  = nullptr;
			sighandl._isdfl = true;
			return sighandl;
		}

		[[nodiscard]] constexpr auto operator == (::dux::sighandl const & _oth) const noexcept -> bool {
			if (this->_isdfl && _oth._isdfl) {return true;}
			return this->handl == _oth.handl;
		}

		auto (* handl)(::dux::sig sig) -> bool;

		friend auto ::dux::setsighandl(::dux::sig sig,::dux::sighandl sighandl) noexcept -> void;
	private:
		bool _isdfl = true;
	};
}
