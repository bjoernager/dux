/*
	Copyright 2021 Gabriel Jensen

	This file is part of u8c.

	u8c is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

	u8c is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

	See the	GNU Affero General Public License for more details.

	You should have received a copy of the GNU Affero General Public License along with u8c.

	If not, see <https://www.gnu.org/licenses/>.
*/
/* Size constant */
# if !defined SIZE_C
# include <limits.h>
# include <stdint.h>
# if SIZE_MAX == USHRT_MAX
# if defined(__cplusplus)
/* C++ : Use variable initialisation. */
# define SIZE_C(val) (unsigned short{val})
# else
/* C : Use compound literal. */
# define SIZE_C(val) ((unsigned short){val})
# endif
# elif SIZE_MAX == UINT_MAX
# define SIZE_C(val) val
# elif SIZE_MAX == ULONG_MAX
# define SIZE_C(val) val ## ul
# elif SIZE_MAX == ULLONG_MAX
# define SIZE_C(val) val ## ull
# elif SIZE_MAX == UINTMAX_MAX
# define SIZE_C(val) UINTMAX_C(val)
# else
/* Cannot match width; construct new element of type "size_t" */
# if defined(__cplusplus)
# define SIZE_C(val) (std::size_t{val})
# else
# define SIZE_C(val) ((size_t){val})
# endif
# endif
# endif