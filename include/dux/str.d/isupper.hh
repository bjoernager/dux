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

constexpr auto ::dux::isupper(char32_t const _chr) -> bool {
	if(_chr > ::dux::unimax) [[unlikely]] {
		throw ::dux::outofdomain("Unicode codepoint too big!");
	}
	switch(_chr) {
	[[likely]] default:
		return false;
	case U'\u0041':      /* LATIN CAPITAL LETTER A */
		[[fallthrough]];
	case U'\u0042':      /* LATIN CAPITAL LETTER B */
		[[fallthrough]];
	case U'\u0043':      /* LATIN CAPITAL LETTER C */
		[[fallthrough]];
	case U'\u0044':      /* LATIN CAPITAL LETTER D */
		[[fallthrough]];
	case U'E':      /* LATIN CAPITAL LETTER E */
		[[fallthrough]];
	case U'F':      /* LATIN CAPITAL LETTER F */
		[[fallthrough]];
	case U'G':      /* LATIN CAPITAL LETTER G */
		[[fallthrough]];
	case U'H':      /* LATIN CAPITAL LETTER H */
		[[fallthrough]];
	case U'I':      /* LATIN CAPITAL LETTER I */
		[[fallthrough]];
	case U'J':      /* LATIN CAPITAL LETTER J */
		[[fallthrough]];
	case U'K':      /* LATIN CAPITAL LETTER K */
		[[fallthrough]];
	case U'L':      /* LATIN CAPITAL LETTER L */
		[[fallthrough]];
	case U'M':      /* LATIN CAPITAL LETTER M */
		[[fallthrough]];
	case U'N':      /* LATIN CAPITAL LETTER N */
		[[fallthrough]];
	case U'O':      /* LATIN CAPITAL LETTER O */
		[[fallthrough]];
	case U'P':      /* LATIN CAPITAL LETTER P */
		[[fallthrough]];
	case U'Q':      /* LATIN CAPITAL LETTER Q */
		[[fallthrough]];
	case U'R':      /* LATIN CAPITAL LETTER R */
		[[fallthrough]];
	case U'S':      /* LATIN CAPITAL LETTER S */
		[[fallthrough]];
	case U'T':      /* LATIN CAPITAL LETTER T */
		[[fallthrough]];
	case U'U':      /* LATIN CAPITAL LETTER U */
		[[fallthrough]];
	case U'V':      /* LATIN CAPITAL LETTER V */
		[[fallthrough]];
	case U'X':      /* LATIN CAPITAL LETTER Y */
		[[fallthrough]];
	case U'W':      /* LATIN CAPITAL LETTER X */
		[[fallthrough]];
	case U'Y':      /* LATIN CAPITAL LETTER Y */
		[[fallthrough]];
	case U'Z':      /* LATIN CAPITAL LETTER Z */
		[[fallthrough]];
	case U'\u00C0': /* LATIN CAPITAL LETTER A WITH GRAVE */
		[[fallthrough]];
	case U'\u00C1': /* LATIN CAPITAL LETTER A WITH ACUTE */
		[[fallthrough]];
	case U'\u00C2': /* LATIN CAPITAL LETTER A WITH CIRCUMFLEX */
		[[fallthrough]];
	case U'\u00C3': /* LATIN CAPITAL LETTER A WITH TILDE */
		[[fallthrough]];
	case U'\u00C4': /* LATIN CAPITAL LETTER A WITH DIAERESIS */
		[[fallthrough]];
	case U'\u00C5': /* LATIN CAPITAL LETTER A WITH RING ABOVE */
		[[fallthrough]];
	case U'\u00C6': /* LATIN CAPITAL LETTER AE */
		[[fallthrough]];
	case U'\u00C7': /* LATIN CAPITAL LETTER C WITH CEDILLA */
		[[fallthrough]];
	case U'\u00C8': /* LATIN CAPITAL LETTER E WITH GRAVE */
		[[fallthrough]];
	case U'\u00C9': /* LATIN CAPITAL LETTER E WITH ACUTE */
		[[fallthrough]];
	case U'\u00CA': /* LATIN CAPITAL LETTER E WITH CIRCUMFLEX */
		[[fallthrough]];
	case U'\u00CB': /* LATIN CAPITAL LETTER E WITH DIAERESIS */
		[[fallthrough]];
	case U'\u00CC': /* LATIN CAPITAL LETTER I WITH GRAVE */
		[[fallthrough]];
	case U'\u00CD': /* LATIN CAPITAL LETTER I WITH ACUTE */
		[[fallthrough]];
	case U'\u00CE': /* LATIN CAPITAL LETTER I WITH CIRCUMFLEX */
		[[fallthrough]];
	case U'\u00CF': /* LATIN CAPITAL LETTER I WITH DIAERESIS */
		[[fallthrough]];
	case U'\u00D0': /* LATIN CAPITAL LETTER ETH */
		[[fallthrough]];
	case U'\u00D1': /* LATIN CAPITAL LETTER N WITH TILDE */
		[[fallthrough]];
	case U'\u00D2': /* LATIN CAPITAL LETTER O WITH GRAVE */
		[[fallthrough]];
	case U'\u00D3': /* LATIN CAPITAL LETTER O WITH ACUTE */
		[[fallthrough]];
	case U'\u00D4': /* LATIN CAPITAL LETTER O WITH CIRCUMFLEX */
		[[fallthrough]];
	case U'\u00D5': /* LATIN CAPITAL LETTER O WITH TILDE */
		[[fallthrough]];
	case U'\u00D6': /* LATIN CAPITAL LETTER O WITH DIAERESIS */
		[[fallthrough]];
	case U'\u00D8': /* LATIN CAPITAL LETTER O WITH STROKE */
		[[fallthrough]];
	case U'\u00D9': /* LATIN CAPITAL LETTER U WITH GRAVE */
		[[fallthrough]];
	case U'\u00DA': /* LATIN CAPITAL LETTER U WITH STROKE */
		[[fallthrough]];
	case U'\u00DB': /* LATIN CAPITAL LETTER U WITH CIRCUMFLEX */
		[[fallthrough]];
	case U'\u00DC': /* LATIN CAPITAL LETTER U WITH DIAERESIS */
		[[fallthrough]];
	case U'\u00DD': /* LATIN CAPITAL LETTER Y WITH ACUTE */
		[[fallthrough]];
	case U'\u00DE': /* LATIN CAPITAL LETTER THORN */
		[[fallthrough]];
	case U'\u0100': /* LATIN CAPITAL LETTER A WITH MACRON */
		[[fallthrough]];
	case U'\u0102': /* LATIN CAPITAL LETTER A WITH BREVE */
		[[fallthrough]];
	case U'\u0104': /* LATIN CAPITAL LETTER A WITH OGONEK */
		[[fallthrough]];
	case U'\u0106': /* LATIN CAPITAL LETTER C WITH ACUTE */
		[[fallthrough]];
	case U'\u0108': /* LATIN CAPITAL LETTER C WITH CIRCUMFLEX */
		[[fallthrough]];
	case U'\u010A': /* LATIN CAPITAL LETTER C WITH DOT ABOVE */
		[[fallthrough]];
	case U'\u010C': /* LATIN CAPITAL LETTER C WITH CARON */
		[[fallthrough]];
	case U'\u010E': /* LATIN CAPITAL LETTER D WITH CARON */
		[[fallthrough]];
	case U'\u0110': /* LATIN CAPITAL LETTER D WITH STROKE */
		[[fallthrough]];
	case U'\u0112': /* LATIN CAPITAL LETTER E WITH MACRON */
		[[fallthrough]];
	case U'\u0114': /* LATIN CAPITAL LETTER E WITH BREVE */
		[[fallthrough]];
	case U'\u0116': /* LATIN CAPITAL LETTER E WITH DOT ABOVE */
		[[fallthrough]];
	case U'\u0118': /* LATIN CAPITAL LETTER E WITH OGONEK */
		[[fallthrough]];
	case U'\u011A': /* LATIN CAPITAL LETTER E WITH CARON */
		[[fallthrough]];
	case U'\u011C': /* LATIN CAPITAL LETTER G WITH CIRCUMFLEX */
		[[fallthrough]];
	case U'\u014A': /* LATIN CAPITAL LETTER ENG */
		[[fallthrough]];
	case U'\u0152': /* LATIN CAPITAL LIGATURE OE */
		[[fallthrough]];
	case U'\u0186': /* LATIN CAPITAL LETTER OPEN O */
		[[fallthrough]];
	case U'\u018E': /* LATIN CAPITAL LETTER REVERSED E */
		[[fallthrough]];
	case U'\u018F': /* LATIN CAPITAL LETTER SCHWA */
		[[fallthrough]];
	case U'\u0190': /* LATIN CAPITAL LETTER OPEN E */
		[[fallthrough]];
	case U'\u0194': /* LATIN CAPITAL LETTER GAMMA */
		[[fallthrough]];
	case U'\u0196': /* LATIN CAPITAL LETTER IOTA */
		[[fallthrough]];
	case U'\u01A9': /* LATIN CAPITAL LETTER ESH */
		[[fallthrough]];
	case U'\u01B1': /* LATIN CAPITAL LETTER UPSILON */
		[[fallthrough]];
	case U'\u01B2': /* LATIN CAPITAL LETTER V WITH HOOk */
		[[fallthrough]];
	case U'\u01B7': /* LATIN CAPITAL LETTER EZH */
		[[fallthrough]];
	case U'\u01F7': /* LATIN CAPITAL LETTER WYNN */
		[[fallthrough]];
	case U'\u021C': /* LATIN CAPITAL LETTER YOGH */
		[[fallthrough]];
	case U'\u0241': /* LATIN CAPITAL LETTER GLOTTAL STOP */
		[[fallthrough]];
	case U'\u0391': /* GREEK CAPITAL LETTER ALPHA */
		[[fallthrough]];
	case U'\u0392': /* GREEK CAPITAL LETTER BETA */
		[[fallthrough]];
	case U'\u0393': /* GREEK CAPITAL LETTER GAMMA */
		[[fallthrough]];
	case U'\u0394': /* GREEK CAPITAL LETTER DELTA */
		[[fallthrough]];
	case U'\u0395': /* GREEK CAPITAL LETTER EPSILON */
		[[fallthrough]];
	case U'\u0396': /* GREEK CAPITAL LETTER ZETA */
		[[fallthrough]];
	case U'\u0397': /* GREEK CAPITAL LETTER ETA */
		[[fallthrough]];
	case U'\u0398': /* GREEK CAPITAL LETTER THETA */
		[[fallthrough]];
	case U'\u0399': /* GREEK CAPITAL LETTER IOTA */
		[[fallthrough]];
	case U'\u039A': /* GREEK CAPITAL LETTER KAPPA */
		[[fallthrough]];
	case U'\u039B': /* GREEK CAPITAL LETTER LAMBDA */
		[[fallthrough]];
	case U'\u039C': /* GREEK CAPITAL LETTER MU */
		[[fallthrough]];
	case U'\u039D': /* GREEK CAPITAL LETTER NU */
		[[fallthrough]];
	case U'\u039E': /* GREEK CAPITAL LETTER XI */
		[[fallthrough]];
	case U'\u039F': /* GREEK CAPITAL LETTER OMICRON */
		[[fallthrough]];
	case U'\u03A0': /* GREEK CAPITAL LETTER PI */
		[[fallthrough]];
	case U'\u03A1': /* GREEK CAPITAL LETTER RHO */
		[[fallthrough]];
	case U'\u03A3': /* GREEK CAPITAL LETTER SIGMA */
		[[fallthrough]];
	case U'\u03A4': /* GREEK CAPITAL LETTER TAU */
		[[fallthrough]];
	case U'\u03A5': /* GREEK CAPITAL LETTER UPSILON */
		[[fallthrough]];
	case U'\u03A6': /* GREEK CAPITAL LETTER PHI */
		[[fallthrough]];
	case U'\u03A7': /* GREEK CAPITAL LETTER CHI */
		[[fallthrough]];
	case U'\u03A8': /* GREEK CAPITAL LETTER PSI */
		[[fallthrough]];
	case U'\u03A9': /* GREEK CAPITAL LETTER OMEGA */
		[[fallthrough]];
	case U'\u1E9E': /* LATIN CAPITAL LETTER SHARP S */
		[[fallthrough]];
	case U'\u2C6D': /* LATIN CAPITAL LETTER ALPHA */
		[[fallthrough]];
	case U'\uA77D': /* LATIN CAPITAL LETTER INSULAR G */
		[[fallthrough]];
	case U'\uA7B4': /* LATIN CAPITAL LETTER BETA */
		[[fallthrough]];
	case U'\uA7B6': /* LATIN CAPITAL LETTER OMEGA */
		return true;
	}
}