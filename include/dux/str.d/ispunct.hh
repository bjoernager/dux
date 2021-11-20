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

constexpr auto ::dux::ispunct(char32_t const _chr) -> bool {
	if(_chr > ::dux::unimax) [[unlikely]] {
		throw ::dux::outofdomain("Unicode codepoint too big!");
	}
	switch(_chr) {
	[[likely]] default:
		return false;
	case U'\u0021':     /* EXCLAMATION MARK */
		[[fallthrough]];
	case U'\u0022':     /* QUOTATION MARK */
		[[fallthrough]];
	case U'\u0023':     /* NUMBER SIGN */
		[[fallthrough]];
	case U'\u0024':     /* DOLLAR SIGN */
		[[fallthrough]];
	case U'\u0025':     /* PERCENT SIGN */
		[[fallthrough]];
	case U'\u0026':     /* AMPERSAND */
		[[fallthrough]];
	case U'\u0027':     /* APOSTROPHE */
		[[fallthrough]];
	case U'\u0028':     /* LEFT PARANTHESIS */
		[[fallthrough]];
	case U'\u0029':     /* RIGHT PARANTHESIS */
		[[fallthrough]];
	case U'\u002A':     /* ASTERISK */
		[[fallthrough]];
	case U'\u002B':     /* PLUS SIGN */
		[[fallthrough]];
	case U'\u002C':     /* COMMA */
		[[fallthrough]];
	case U'\u002D':     /* HYPHEN-MINUS */
		[[fallthrough]];
	case U'\u002E':     /* FULL STOP */
		[[fallthrough]];
	case U'\u002F':     /* SOLIDUS */
		[[fallthrough]];
	case U'\u003A':     /* COLON */
		[[fallthrough]];
	case U'\u003B':     /* SEMICOLON */
		[[fallthrough]];
	case U'\u003C':     /* LESS-THAN SIGN */
		[[fallthrough]];
	case U'\u003D':     /* EQUALS SIGN */
		[[fallthrough]];
	case U'\u003E':     /* GREATER-THAN SIGN */
		[[fallthrough]];
	case U'\u003F':     /* QUESTION MARK */
		[[fallthrough]];
	case U'\u0040':     /* COMMERCIAL AT */
		[[fallthrough]];
	case U'\u005B':     /* LEFT SQUARE BRACKET */
		[[fallthrough]];
	case U'\u005C':     /* REVERSE SOLIDUS */
		[[fallthrough]];
	case U'\u005D':     /* RIGHT SQUARE BRACKET */
		[[fallthrough]];
	case U'\u005E':     /* CIRCUMFLEX ACCENT */
		[[fallthrough]];
	case U'\u005F':     /* LOW LINE */
		[[fallthrough]];
	case U'\u0060':     /* GRAVE ACCENT */
		[[fallthrough]];
	case U'\u007B':     /* LEFT CURLY BRACKET */
		[[fallthrough]];
	case U'\u007C':     /* VERTICAL LINE */
		[[fallthrough]];
	case U'\u007D':     /* RIGHT CURLY BRACKET */
		[[fallthrough]];
	case U'\u007E':     /* TILDE */
		[[fallthrough]];
	case U'\u00A1':     /* INVERT EXCLAMATION MARK */
		[[fallthrough]];
	case U'\u00A2':     /* CENT SIGN */
		[[fallthrough]];
	case U'\u00A3':     /* POUND SIGN */
		[[fallthrough]];
	case U'\u00A4':     /* CURRENCY SIGN */
		[[fallthrough]];
	case U'\u00A5':     /* YEN SIGN */
		[[fallthrough]];
	case U'\u00A6':     /* BROKEN BAR */
		[[fallthrough]];
	case U'\u00A7':     /* SECTION SIGN */
		[[fallthrough]];
	case U'\u00A8':     /* DIAERESIS */
		[[fallthrough]];
	case U'\u00A9':     /* COPYRIGHT SIGN */
		[[fallthrough]];
	case U'\u00AA':     /* FEMININE ORDINAL INDICATOR */
		[[fallthrough]];
	case U'\u00AB':     /* LEFT-POINTING DOUBLE ANGLE QUOTATION MARK */
		[[fallthrough]];
	case U'\u00AC':     /* NOT SIGN */
		[[fallthrough]];
	case U'\u00AE':     /* REGISTERED SIGN */
		[[fallthrough]];
	case U'\u00AF':     /* MACRON */
		[[fallthrough]];
	case U'\u00B0':     /* DEGREE SIGN */
		[[fallthrough]];
	case U'\u00B1':     /* PLUS MINUS SYMBOL */
		[[fallthrough]];
	case U'\u00B2':     /* SUPERSCRIPT TWO */
		[[fallthrough]];
	case U'\u00B3':     /* SUPERSCRIPT THREE */
		[[fallthrough]];
	case U'\u00B4':     /* ACUTE ACCENT */
		[[fallthrough]];
	case U'\u00B5':     /* MICRO SIGN */
		[[fallthrough]];
	case U'\u00B6':     /* PILCROW SIGN */
		[[fallthrough]];
	case U'\u00B7':     /* MIDDLE DOT */
		[[fallthrough]];
	case U'\u00B8':     /* CEDILLA */
		[[fallthrough]];
	case U'\u00B9':     /* SUPERSCRIPT ONE */
		[[fallthrough]];
	case U'\u00BA':     /* MASCULINE ORDINAL INDICATOR */
		[[fallthrough]];
	case U'\u00BB':     /* RIGHT-POINTING DOUBLE ANGLE QUOTATION MARK */
		[[fallthrough]];
	case U'\u00BC':     /* VULGAR FRACTION ONE QUARTER */
		[[fallthrough]];
	case U'\u00BD':     /* VULGAR FRACTION ONE HALF */
		[[fallthrough]];
	case U'\u00BE':     /* VULGAR FRACTION THREE QUARTERS */
		[[fallthrough]];
	case U'\u00BF':     /* INVERT QUESTION MARK */
		[[fallthrough]];
	case U'\u00D7':     /* MULTIPLICATION SIGN */
		[[fallthrough]];
	case U'\u00F7':     /* DIVISION SIGN */
		[[fallthrough]];
	case U'\u2010':     /* HYPHEN */
		[[fallthrough]];
	case U'\u2013':     /* EN DASH */
		[[fallthrough]];
	case U'\u2014':     /* EM DASH */
		[[fallthrough]];
	case U'\u2018':     /* LEFT SINGLE QUOTATION MARK */
		[[fallthrough]];
	case U'\u2019':     /* RIGHT SINGLE QUOTATION MARK */
		[[fallthrough]];
	case U'\u201C':     /* LEFT DOUBLE QUOTATION MARK */
		[[fallthrough]];
	case U'\u201D':     /* RIGHT DOUBLE QUOTATION MARK */
		[[fallthrough]];
	case U'\u2026':     /* HORIZONTAL ELLIPSIS */
		[[fallthrough]];
	case U'\u2030':     /* PER MILLE SIGN */
		[[fallthrough]];
	case U'\u2031':     /* PER TEN THOUSAND SIGN */
		[[fallthrough]];
	case U'\u2032':     /* PRIME */
		[[fallthrough]];
	case U'\u2033':     /* DOUBLE PRIME */
		[[fallthrough]];
	case U'\u2034':     /* TRIPLE PRIME */
		[[fallthrough]];
	case U'\u2035':     /* REVERSED PRIME */
		[[fallthrough]];
	case U'\u2036':     /* REVERSED DOUBLE PRIME */
		[[fallthrough]];
	case U'\u2037':     /* REVERSED TRIPLE PRIME */
		[[fallthrough]];
	case U'\u203C':     /* DOUBLE EXCLAMATION MARK */
		[[fallthrough]];
	case U'\u203D':     /* INTERROBANG */
		[[fallthrough]];
	case U'\u2047':     /* DOUBLE QUOTATION MARK */
		[[fallthrough]];
	case U'\u2048':     /* QUESTION EXCLAMATION MARK */
		[[fallthrough]];
	case U'\u2049':     /* EXCLAMATION QUESTION MARK */
		[[fallthrough]];
	case U'\u20A3':     /* FRENCH FRANC SIGN */
		[[fallthrough]];
	case U'\u20A4':     /* LIRA SIGN */
		[[fallthrough]];
	case U'\u20A8':     /* RUPEE SIGN */
		[[fallthrough]];
	case U'\u20A9':     /* WON SIGN */
		[[fallthrough]];
	case U'\u20AC':     /* EURO SIGN */
		[[fallthrough]];
	case U'\u20B9':     /* INDIAN RUPEE SIGN */
		[[fallthrough]];
	case U'\u20BF':     /* BITCOIN SIGN */
		[[fallthrough]];
	case U'\u2103':     /* DEGREE CELSIUS */
		[[fallthrough]];
	case U'\u2107':     /* EULER CONSTANT */
		[[fallthrough]];
	case U'\u2109':     /* DEGREE FAHRENHEIT */
		[[fallthrough]];
	case U'\u210E':     /* PLANCK CONSTANT */
		[[fallthrough]];
	case U'\u2117':     /* SOUND RECORDING COPYRIGHT */
		[[fallthrough]];
	case U'\u2122':     /* TRADE MARK SIGN */
		[[fallthrough]];
	case U'\u2125':     /* OUNCE SIGN */
		[[fallthrough]];
	case U'\u2126':     /* OHM SIGN */
		[[fallthrough]];
	case U'\u212A':     /* KELVIN SIGN */
		[[fallthrough]];
	case U'\u214D':     /* AKTIESELSKAB */
		[[fallthrough]];
	case U'\u2205':     /* EMPTY SET */
		[[fallthrough]];
	case U'\u2212':     /* MINUS SIGN */
		[[fallthrough]];
	case U'\u221A':     /* SQUARE ROOT */
		[[fallthrough]];
	case U'\u221B':     /* CUBE ROOT */
		[[fallthrough]];
	case U'\u221C':     /* FOURTH ROOT */
		[[fallthrough]];
	case U'\u221E':     /* INFINITY */
		[[fallthrough]];
	case U'\u2228':     /* LOGICAL OR */
		[[fallthrough]];
	case U'\u2248':     /* ALMOST EQUAL TO */
		[[fallthrough]];
	case U'\u2260':     /* NOT EQUAL TO */
		[[fallthrough]];
	case U'\u2264':     /* LESS-THAN OR EQUAL TO */
		[[fallthrough]];
	case U'\u2265':     /* GREATER-THAN OR EQUAL TO */
		[[fallthrough]];
	case U'\u2609':     /* SUN */
		[[fallthrough]];
	case U'\u263F':     /* MERCURY */
		[[fallthrough]];
	case U'\u2640':     /* FEMALE SIGN */
		[[fallthrough]];
	case U'\u2641':     /* EARTH */
		[[fallthrough]];
	case U'\u2642':     /* MALE SIGN */
		[[fallthrough]];
	case U'\u2643':     /* JUPITER */
		[[fallthrough]];
	case U'\u2644':     /* SATURN */
		[[fallthrough]];
	case U'\u2645':     /* URANUS */
		[[fallthrough]];
	case U'\u2646':     /* NEPTUNE */
		[[fallthrough]];
	case U'\u2647':     /* PLUTO */
		[[fallthrough]];
	case U'\u26A2':     /* DOUBLED FEMALE SIGN */
		[[fallthrough]];
	case U'\u26A3':     /* DOUBLED MALE SIGN */
		[[fallthrough]];
	case U'\u26A4':     /* INTERLOCKED FEMALE AND MALE SIGN */
		[[fallthrough]];
	case U'\u26A5':     /* MALE AND FEMALE SIGN */
		[[fallthrough]];
	case U'\u26B3':     /* CERES */
		[[fallthrough]];
	case U'\u26B4':     /* PALLAS */
		[[fallthrough]];
	case U'\u26B5':     /* JUNO */
		[[fallthrough]];
	case U'\u26B6':     /* VESTA */
		[[fallthrough]];
	case U'\u26B7':     /* CHIRON */
		[[fallthrough]];
	case U'\u2BD8':     /* PROSERPINA */
		[[fallthrough]];
	case U'\u2BD9':     /* ASTRAEA */
		[[fallthrough]];
	case U'\u2BDA':     /* HYGIEA */
		[[fallthrough]];
	case U'\u2BDB':     /* PHOLOS */
		[[fallthrough]];
	case U'\u2BDC':     /* NESSUS */
		[[fallthrough]];
	case U'\u2E2E':     /* INVERTED QUESTION MARK */
		[[fallthrough]];
	case U'\u33D7':     /* SQUARE PH */
		[[fallthrough]];
	case U'\uFDFC':     /* RIAL SIGN */
		[[fallthrough]];
	case U'\U0001F10D': /* CIRCLED ZERO WITH SLASH */
		[[fallthrough]];
	case U'\U0001F10E': /* CIRCLED ANTICKLOCKWISE ARROW */
		[[fallthrough]];
	case U'\U0001F10F': /* CIRCLED DOLLAR SIGN WITH OVERLAID BACKSLASH */
		[[fallthrough]];
	case U'\U0001F12F': /* COPYLEFT SYMBOL */
		[[fallthrough]];
	case U'\U0001F16D': /* CIRCLED CC */
		[[fallthrough]];
	case U'\U0001F16E': /* CIRCLED C WITH OVERLAID BACKSLASH */
		[[fallthrough]];
	case U'\U0001F16F': /* CIRCLED HUMAN FIGURE */
		return true;
	}
}
