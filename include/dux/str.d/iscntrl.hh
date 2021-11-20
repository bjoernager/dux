// --C++--
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

constexpr auto ::dux::iscntrl(char32_t const _chr) -> bool {
	if(_chr > ::dux::unimax) [[unlikely]] {
		throw ::dux::outofdomain("Unicode codepoint too big!");
	}
	switch(_chr) {
	[[likely]] default:
		return false;
	case U'\u0000':    /* NULL */
		[[fallthrough]];
	case U'\u0001':    /* START OF HEADING */
		[[fallthrough]];
	case U'\u0002':    /* START OF TEXT */
		[[fallthrough]];
	case U'\u0003':    /* END OF TEXT */
		[[fallthrough]];
	case U'\u0004':    /* END OF TRANSMISSION */
		[[fallthrough]];
	case U'\u0005':    /* ENQUIRY */
		[[fallthrough]];
	case U'\u0006':    /* ACKNOWLEDGE */
		[[fallthrough]];
	case U'\a':     /* BELL */
		[[fallthrough]];
	case U'\b':     /* BACKSPACE */
		[[fallthrough]];
	case U'\t':     /* HORIZONTAL TABULATION */
		[[fallthrough]];
	case U'\n':     /* NEW LINE */
		[[fallthrough]];
	case U'\v':     /* VERTICAL TABULATION */
		[[fallthrough]];
	case U'\f':     /* FORM FEED */
		[[fallthrough]];
	case U'\r':     /* CARRIAGE RETURN */
		[[fallthrough]];
	case U'\u000E':    /* SHIFT OUT */
		[[fallthrough]];
	case U'\u000F':    /* SHIFT IN */
		[[fallthrough]];
	case U'\x10':   /* DATA LINK ESCAPE */
		[[fallthrough]];
	case U'\x11':   /* DEVICE CONTROL ONE */
		[[fallthrough]];
	case U'\x12':   /* DEVICE CONTROL TWO */
		[[fallthrough]];
	case U'\x13':   /* DEVICE CONTROL THREE */
		[[fallthrough]];
	case U'\x14':   /* DEVICE CONTROL FOUR */
		[[fallthrough]];
	case U'\x15':   /* NEGATIVE ACKNOWLEDGE */
		[[fallthrough]];
	case U'\x16':   /* SYNCHRONOUS IDLE */
		[[fallthrough]];
	case U'\x17':   /* END OF TRANSMISSION BLOCK */
		[[fallthrough]];
	case U'\x18':   /* CANCEL */
		[[fallthrough]];
	case U'\x19':   /* END OF MEDIUM */
		[[fallthrough]];
	case U'\x1A':   /* SUBSTITUTE */
		[[fallthrough]];
	case U'\u001B':   /* ESCAPE */
		[[fallthrough]];
	case U'\x1C':   /* FILE SEPERATOR */
		[[fallthrough]];
	case U'\x1D':   /* GROUP SEPERATOR */
		[[fallthrough]];
	case U'\x1E':   /* RECORD SEPERATOR */
		[[fallthrough]];
	case U'\x1F':   /* UNIT SEPERATOR */
		[[fallthrough]];
	case U'\x7F':   /* DELETE */
		[[fallthrough]];
	case U'\x80':   /* <CONTROL> */
		[[fallthrough]];
	case U'\x81':   /* <CONTROL */
		[[fallthrough]];
	case U'\x82':   /* BREAK PERMITTED HERE */
		[[fallthrough]];
	case U'\x83':   /* NO BREAK HERE */
		[[fallthrough]];
	case U'\x84':   /* INDEX */
		[[fallthrough]];
	case U'\x85':   /* NEXT LINE */
		[[fallthrough]];
	case U'\x86':   /* START OF SELECTED AREA */
		[[fallthrough]];
	case U'\x87':   /* END OF SELECTED AREA */
		[[fallthrough]];
	case U'\x88':   /* CHARACTER TABULATION SET */
		[[fallthrough]];
	case U'\x89':   /* CHARACTER TABULATION SET WITH JUSTIFICATION */
		[[fallthrough]];
	case U'\x8A':   /* LINE TABULATION SET */
		[[fallthrough]];
	case U'\x8B':   /* PARTIAL LINE FORWARD */
		[[fallthrough]];
	case U'\x8C':   /* PARTIAL LINE BACKWARD */
		[[fallthrough]];
	case U'\x8D':   /* REVERSE LINE FEED */
		[[fallthrough]];
	case U'\x8E':   /* SINGLE SHIFT TWO */
		[[fallthrough]];
	case U'\x8F':   /* SINGLE SHIFT THREE */
		[[fallthrough]];
	case U'\x90':   /* DEVICE CONTROL STRING */
		[[fallthrough]];
	case U'\x91':   /* PRIVATE USE ONE */
		[[fallthrough]];
	case U'\x92':   /* PRIVATE USE TWO */
		[[fallthrough]];
	case U'\x93':   /* SET TRANSMIT STATE */
		[[fallthrough]];
	case U'\x94':   /* CANCEL CHARACTER */
		[[fallthrough]];
	case U'\x95':   /* MESSAGE WAITING */
		[[fallthrough]];
	case U'\x96':   /* START OF GUARDED AREA */
		[[fallthrough]];
	case U'\x97':   /* END OF GUARDED AREA */
		[[fallthrough]];
	case U'\x98':   /* START OF STRING */
		[[fallthrough]];
	case U'\x99':   /* <CONTROL> */
		[[fallthrough]];
	case U'\x9A':   /* SINGLE CHARACTER INTRODUCER */
		[[fallthrough]];
	case U'\x9B':   /* CONTROL SEQUENCE INTRODUCER */
		[[fallthrough]];
	case U'\x9C':   /* STRING TERMINATOR */
		[[fallthrough]];
	case U'\x9D':   /* OPERATING SYSTEM COMMAND */
		[[fallthrough]];
	case U'\x9E':   /* PRIVACY MESSAGE */
		[[fallthrough]];
	case U'\x9F':   /* APPLICATION PROGRAM COMMAND */
		[[fallthrough]];
	case U'\xA0':   /* NO-BREAK SPACE */
		[[fallthrough]];
	case U'\u2028': /* LINE SEPERATOR */
		[[fallthrough]];
	case U'\u2029': /* PARAGRAPH SEPERATOR */
		[[fallthrough]];
	case U'\u202D': /* LEFT-TO-RIGHT OVERRIDE */
		[[fallthrough]];
	case U'\u202E': /* RIGHT-TO-LEFT OVERRIDE */
		[[fallthrough]];
	case U'\u2068': /* FIRST STRONG ISOLATE */
		[[fallthrough]];
	case U'\u2069': /* POP DIRECTIONAL ISOLATE */
		return true;
	}
}
