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
	template<typename T> class arr {
	public:
		                        [[nodiscard]] constexpr arr()                                                                             noexcept :                                _isalloc(false)                       {}
		                        [[nodiscard]] constexpr arr(::dux::arr<T> &&   _oth)                                                      noexcept : _dat(_oth._dat),               _isalloc(_oth._isalloc),_sz(_oth._sz) {_oth.kill();}
		                        [[nodiscard]] constexpr arr(T * const restrict _dat,   ::dux::uwrd const _sz,bool const _isalloc = false) noexcept : _dat(_dat),                    _isalloc(_isalloc),     _sz(_sz)      {}
		template<::dux::uwrd N> [[nodiscard]] constexpr arr(T const (&        _arr)[N])                                                   noexcept : _dat(const_cast<char *>(_arr)),_isalloc(false),        _sz(N)        {}

		constexpr auto operator = (::dux::arr<T> const & _oth) noexcept -> ::dux::arr<T> const & {
			if (_oth._isalloc) {
				this->alloc(_oth.sz());
				::dux::cpy(_oth.raw(),_oth.sz(),this->raw());
			}
			else {this->setraw(_oth._dat,_oth._sz,_oth._isalloc);}
			return *this;
		}

		constexpr auto operator = (::dux::arr<T> const && _oth) noexcept -> ::dux::arr<T> const & {
			this->setraw(_oth.alloc,_oth._dat,_oth._sz);
			_oth._isalloc = false; /* Mutable field. */
			return *this;
		}

		constexpr ~arr() noexcept {if (this->_isalloc) {::dux::free(this->_dat);}}

		constexpr auto craw() const noexcept -> T const *   {return this->_dat;}
		constexpr auto raw()        noexcept -> T *         {return this->_dat;}
		constexpr auto raw()  const noexcept -> T const *   {return this->_dat;}
		constexpr auto sz()   const noexcept -> ::dux::uwrd {return this->_sz;}

		constexpr auto begin()        noexcept -> T *       {return this->raw();}
		constexpr auto begin()  const noexcept -> T const * {return this->raw();}
		constexpr auto end()          noexcept -> T *       {return this->raw() + this->sz();}
		constexpr auto end()    const noexcept -> T const * {return this->raw() + this->sz();}
		constexpr auto cbegin() const noexcept -> T const * {return this->begin();}
		constexpr auto cend()   const noexcept -> T const * {return this->end();}

		constexpr auto operator [] (::dux::uwrd const _n)       noexcept -> T &       {return this->_dat[_n];}
		constexpr auto operator [] (::dux::uwrd const _n) const noexcept -> T const & {return this->_dat[_n];}

		constexpr auto setraw(T * const restrict _dat,::dux::uwrd const _sz,bool const _isalloc = false) noexcept -> void {
			this->_isalloc = _isalloc;
			this->_dat     = _dat;
			this->_sz      = _sz;
		}
		constexpr auto setraw(T const * const restrict _dat,::dux::uwrd const _sz) noexcept -> void {
			this->_isalloc = false;
			this->_dat     = const_cast<T *>(_dat);
			this->_sz      = _sz;
		}

		constexpr auto kill() noexcept -> void {
			this->_dat     = nullptr;
			this->_isalloc = false;
		}

		constexpr auto alloc(::dux::uwrd const _sz) noexcept -> void {
			this->_dat = ::dux::alloc<T>(_sz);
			if (::dux::haserr()) [[unlikely]] {
				this->_isalloc = false;
				return;
			}
			this->_isalloc = true;
			this->_sz    = _sz;
		}
		constexpr auto free() noexcept -> void {
			if (!this->_isalloc) [[unlikely]] {return;}
			::dux::free(this->_dat);
			this->_isalloc = false;
			this->_sz    = dux_uwrdl(0x0);
		}
	private:
		T *          _dat;
		bool mutable _isalloc;
		::dux::uwrd  _sz;
	};
}
