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

constexpr auto ::dux::islower(char32_t const _chr) -> bool {
	if(_chr > ::dux::unimax) [[unlikely]] {
		throw ::dux::outofdomain("Unicode codepoint too big!");
	}
	switch(_chr) {
	[[likely]] default:
		return false;
	case U'\u0061':  /* LATIN SMALL LETTER A */
		[[fallthrough]];
	case U'\u0062':  /* LATIN SMALL LETTER B */
		[[fallthrough]];
	case U'\u0063':  /* LATIN SMALL LETTER C */
		[[fallthrough]];
	case U'\u0064':  /* LATIN SMALL LETTER D */
		[[fallthrough]];
	case U'\u0065':  /* LATIN SMALL LETTER E */
		[[fallthrough]];
	case U'\u0066':  /* LATIN SMALL LETTER F */
		[[fallthrough]];
	case U'\u0067':  /* LATIN SMALL LETTER G */
		[[fallthrough]];
	case U'\u0068':  /* LATIN SMALL LETTER H */
		[[fallthrough]];
	case U'\u0069':  /* LATIN SMALL LETTER I */
		[[fallthrough]];
	case U'\u006A':  /* LATIN SMALL LETTER J */
		[[fallthrough]];
	case U'\u006B':  /* LATIN SMALL LETTER K */
		[[fallthrough]];
	case U'\u006C':  /* LATIN SMALL LETTER L */
		[[fallthrough]];
	case U'\u006D':  /* LATIN SMALL LETTER M */
		[[fallthrough]];
	case U'\u006E':  /* LATIN SMALL LETTER N */
		[[fallthrough]];
	case U'\u006F':  /* LATIN SMALL LETTER O */
		[[fallthrough]];
	case U'\u0070':  /* LATIN SMALL LETTER P */
		[[fallthrough]];
	case U'\u0071':  /* LATIN SMALL LETTER Q */
		[[fallthrough]];
	case U'\u0072':  /* LATIN SMALL LETTER R */
		[[fallthrough]];
	case U'\u0073':  /* LATIN SMALL LETTER S */
		[[fallthrough]];
	case U'\u0074':  /* LATIN SMALL LETTER T */
		[[fallthrough]];
	case U'\u0075':  /* LATIN SMALL LETTER U */
		[[fallthrough]];
	case U'\u0076':  /* LATIN SMALL LETTER V */
		[[fallthrough]];
	case U'\u0077':  /* LATIN SMALL LETTER W */
		[[fallthrough]];
	case U'\u0078':  /* LATIN SMALL LETTER X */
		[[fallthrough]];
	case U'\u0079':  /* LATIN SMALL LETTER Y */
		[[fallthrough]];
	case U'\u007A':  /* LATIN SMALL LETTER Z */
		[[fallthrough]];
	case U'\u00DF': /* LATIN SMALL LETTER SHARP S */
		[[fallthrough]];
	case U'\u00E0': /* LATIN SMALL LETTER A WITH GRAVE */
		[[fallthrough]];
	case U'\u00E1': /* LATIN SMALL LETTER A WITH ACUTE */
		[[fallthrough]];
	case U'\u00E2': /* LATIN SMALL LETTER A WITH CIRCUMFLEX */
		[[fallthrough]];
	case U'\u00E3': /* LATIN SMALL LETTER A WITH TILDE */
		[[fallthrough]];
	case U'\u00E4': /* LATIN SMALL LETTER A WITH DIAERESIS */
		[[fallthrough]];
	case U'\u00E5': /* LATIN SMALL LETTER A WITH RING ABOVE */
		[[fallthrough]];
	case U'\u00E6': /* LATIN SMALL LETTER AE */
		[[fallthrough]];
	case U'\u00E7': /* LATIN SMALL LETTER C WITH CEDILLA */
		[[fallthrough]];
	case U'\u00E8': /* LATIN SMALL LETTER E WITH GRAVE */
		[[fallthrough]];
	case U'\u00E9': /* LATIN SMALL LETTER E WITH ACUTE */
		[[fallthrough]];
	case U'\u00EA': /* LATIN SMALL LETTER E WITH CIRCUMFLEX */
		[[fallthrough]];
	case U'\u00EB': /* LATIN SMALL LETTER E WITH DIAERESIS */
		[[fallthrough]];
	case U'\u00EC': /* LATIN SMALL LETTER I WITH GRAVE */
		[[fallthrough]];
	case U'\u00ED': /* LATIN SMALL LETTER I WITH ACUTE */
		[[fallthrough]];
	case U'\u00EE': /* LATIN SMALL LETTER I WITH CIRCUMFLEX */
		[[fallthrough]];
	case U'\u00EF': /* LATIN SMALL LETTER I WITH DIAERESIS */
		[[fallthrough]];
	case U'\u00F0': /* LATIN SMALL LETTER ETH */
		[[fallthrough]];
	case U'\u00F1': /* LATIN SMALL LETTER N WITH TILDE */
		[[fallthrough]];
	case U'\u00F2': /* LATIN SMALL LETTER O WITH GRAVE */
		[[fallthrough]];
	case U'\u00F3': /* LATIN SMALL LETTER O WITH ACUTE */
		[[fallthrough]];
	case U'\u00F4': /* LATIN SMALL LETTER O WITH CIRCUMFLEX */
		[[fallthrough]];
	case U'\u00F5': /* LATIN SMALL LETTER O WITH TILDE */
		[[fallthrough]];
	case U'\u00F6': /* LATIN SMALL LETTER O WITH DIAERESIS */
		[[fallthrough]];
	case U'\u00F8': /* LATIN SMALL LETTER O WITH STROKE */
		[[fallthrough]];
	case U'\u00F9': /* LATIN SMALL LETTER U WITH GRAVE */
		[[fallthrough]];
	case U'\u00FA': /* LATIN SMALL LETTER U WITH ACUTE */
		[[fallthrough]];
	case U'\u00FB': /* LATIN SMALL LETTER U WITH CIRCUMFLEX */
		[[fallthrough]];
	case U'\u00FC': /* U WITH TWO DOTS */
		[[fallthrough]];
	case U'\u00FD': /* LATIN SMALL LETTER Y WITH ACUTE */
		[[fallthrough]];
	case U'\u00FE': /* LATIN SMALL LETTER THORN */
		[[fallthrough]];
	case U'\u00FF': /* LATIN SMALL LETTER Y WITH DIAERESIS */
		[[fallthrough]];
	case U'\u0105': /* LATIN SMALL LETTER A WITH OGONEK */
		[[fallthrough]];
	case U'\u0107': /* LATIN SMALL LETTER C WITH ACUTE */
		[[fallthrough]];
	case U'\u010D': /* LATIN SMALL LETTER C WITH CARON */
		[[fallthrough]];
	case U'\u010F': /* LATIN SMALL LETTER D WITH CARON */
		[[fallthrough]];
	case U'\u0119': /* LATIN SMALL LETTER E WITH OGONEK */
		[[fallthrough]];
	case U'\u011B': /* LATIN SMALL LETTER E WITH CARON */
		[[fallthrough]];
	case U'\u011F': /* LATIN SMALL LETTER G WITH BREVE */
		[[fallthrough]];
	case U'\u0131': /* LATIN SMALL LETTER DOTLESS I */
		[[fallthrough]];
	case U'\u0133': /* LATIN SMALL LIGATURE IJ */
		[[fallthrough]];
	case U'\u0138': /* LATIN SMALL LETTER KRA */
		[[fallthrough]];
	case U'\u0142': /* LATIN SMALL LETTER L WITH STROKE */
		[[fallthrough]];
	case U'\u0144': /* LATIN SMALL LETTER N WITH ACUTE */
		[[fallthrough]];
	case U'\u0148': /* LATIN SMALL LETTER N WITH CARON */
		[[fallthrough]];
	case U'\u014B': /* LATIN SMALL LETTER ENG */
		[[fallthrough]];
	case U'\u0153': /* LATIN SMALL LIGATURE OE */
		[[fallthrough]];
	case U'\u0159': /* LATIN SMALL LETTER R WITH CARON */
		[[fallthrough]];
	case U'\u015B': /* LATIN SMALL LETTER S WITH ACUTE */
		[[fallthrough]];
	case U'\u015F': /* LATIN SMALL LETTER S WITH CEDILLA */
		[[fallthrough]];
	case U'\u0161': /* LATIN SMALL LETTER S WITH CARON */
		[[fallthrough]];
	case U'\u0165': /* LATIN SMALL LETTER T WITH CARON */
		[[fallthrough]];
	case U'\u016F': /* LATIN SMALL LETTER U WITH RING ABOVE */
		[[fallthrough]];
	case U'\u017A': /* LATIN SMALL LETTER Z WITH ACUTE */
		[[fallthrough]];
	case U'\u017C': /* LATIN SMALL LETTER Z WITH DOT ABOVE */
		[[fallthrough]];
	case U'\u017E': /* LATIN SMALL LETTER Z WITH CARON */
		[[fallthrough]];
	case U'\u01BF': /* LATIN LETTER WYNN */
		[[fallthrough]];
	case U'\u01DD': /* LATIN SMALL LETTER TURNED E */
		[[fallthrough]];
	case U'\u021D': /* LATIN SMALL LETTER YOGH */
		[[fallthrough]];
	case U'\u0242': /* LATIN SMALL LETTER GLOTTAL STOP */
		[[fallthrough]];
	case U'\u0250': /* LATIN SMALL LETTER TURNED A */
		[[fallthrough]];
	case U'\u0251': /* LATIN SMALL LETTER ALPHA */
		[[fallthrough]];
	case U'\u0252': /* LATIN SMALL LETTER TURNED ALPHA */
		[[fallthrough]];
	case U'\u0253': /* LATIN SMALL LETTER B WITH HOOk */
		[[fallthrough]];
	case U'\u0254': /* LATIN SMALL LETTER OPEN O */
		[[fallthrough]];
	case U'\u0255': /* LATIN SMALL LETTER C WITH CURL */
		[[fallthrough]];
	case U'\u0256': /* LATIN SMALL LETTER D WITH TAIL */
		[[fallthrough]];
	case U'\u0257': /* LATIN SMALL LETTER D WITH HOOk */
		[[fallthrough]];
	case U'\u0258': /* LATIN SMALL LETTER REVERSED E */
		[[fallthrough]];
	case U'\u0259': /* LATIN SMALL LETTER SCHWA */
		[[fallthrough]];
	case U'\u025A': /* LATIN SMALL LETTER SCHWA WITH HOOK */
		[[fallthrough]];
	case U'\u025B': /* LATIN SMALL LETTER OPEN E */
		[[fallthrough]];
	case U'\u025C': /* LATIN SMALL LETTER REVERSED OPEN E */
		[[fallthrough]];
	case U'\u025D': /* LATIN SMALL LETTER REVERSED OPEN E WITH HOOK */
		[[fallthrough]];
	case U'\u025E': /* LATIN SMALL LETTER CLOSED REVERSED OPEN E */
		[[fallthrough]];
	case U'\u025F': /* LATIN SMALL LETTER DOTLESS J WITH STROKE */
		[[fallthrough]];
	case U'\u0260': /* LATIN SMALL LETTER G WITH HOOK */
		[[fallthrough]];
	case U'\u0261': /* LATIN SMALL LETTER SCRIPT G */
		[[fallthrough]];
	case U'\u0262': /* LATIN LETTER SMALL CAPITAL G */
		[[fallthrough]];
	case U'\u0263': /* LATIN SMALL LETTER GAMMA */
		[[fallthrough]];
	case U'\u0264': /* LATIN SMALL LETTER RAMS HORN */
		[[fallthrough]];
	case U'\u0265': /* LATIN SMALL LETTER TURNED H */
		[[fallthrough]];
	case U'\u0266': /* LATIN SMALL LETTER H WITH HOOK */
		[[fallthrough]];
	case U'\u0267': /* LATIN SMALL LETTER HENG WITH HOOK */
		[[fallthrough]];
	case U'\u0268': /* LATIN SMALL LETTER I WITH STROKE */
		[[fallthrough]];
	case U'\u0269': /* LATIN SMALL LETTER IOTA */
		[[fallthrough]];
	case U'\u026A': /* LATIN LETTER SMALL CAPITAL I */
		[[fallthrough]];
	case U'\u026B': /* LATIN SMALL LETTER L WITH MIDDLE TILDE */
		[[fallthrough]];
	case U'\u026C': /* LATIN SMALL LETTER L WITH BELT */
		[[fallthrough]];
	case U'\u026D': /* LATIN SMALL LETTER L WITH RETROFLEX HOOK */
		[[fallthrough]];
	case U'\u026E': /* LATIN SMALL LETTER LEZH */
		[[fallthrough]];
	case U'\u026F': /* LATIN SMALL LETTER TURNED M */
		[[fallthrough]];
	case U'\u0270': /* LATIN SMALL LETTER TURNED M WITH LONG LEG */
		[[fallthrough]];
	case U'\u0271': /* LATIN SMALL LETTER M WITH HOOK */
		[[fallthrough]];
	case U'\u0272': /* LATIN SMALL LETTER N WITH LEFT HOOK */
		[[fallthrough]];
	case U'\u0273': /* LATIN SMALL LETTER N WITH RETROFLEX HOOK */
		[[fallthrough]];
	case U'\u0283': /* LATIN SMALL LETTER ESH */
		[[fallthrough]];
	case U'\u028A': /* LATIN SMALL LETTER UPSILON */
		[[fallthrough]];
	case U'\u028B': /* LATIN SMALL LETTER V WITH HOOK */
		[[fallthrough]];
	case U'\u0292': /* LATIN SMALL LETTER EZH */
		[[fallthrough]];
	case U'\u0294': /* LATIN SMALL LETTER GLOTTAL STOP */
		[[fallthrough]];
	case U'\u03B1': /* GREEK SMALL LETTER ALPHA */
		[[fallthrough]];
	case U'\u03B2': /* GREEK SMALL LETTER BETA */
		[[fallthrough]];
	case U'\u03B3': /* GREEK SMALL LETTER GAMMA */
		[[fallthrough]];
	case U'\u03B4': /* GREEK SMALL LETTER DELTA */
		[[fallthrough]];
	case U'\u03B5': /* GREEK SMALL LETTER EPSILON */
		[[fallthrough]];
	case U'\u03B6': /* GREEK SMALL LETTER ZETA */
		[[fallthrough]];
	case U'\u03B7': /* GREEK SMALL LETTER ETA */
		[[fallthrough]];
	case U'\u03B8': /* GREEK SMALL LETTER THETA */
		[[fallthrough]];
	case U'\u03B9': /* GREEK SMALL LETTER IOTA */
		[[fallthrough]];
	case U'\u03BA': /* GREEK SMALL LETTER KAPPA */
		[[fallthrough]];
	case U'\u03BB': /* GREEK SMALL LETTER LAMBDA */
		[[fallthrough]];
	case U'\u03BC': /* GREEK SMALL LETTER MU */
		[[fallthrough]];
	case U'\u03BD': /* GREEK SMALL LETTER NU */
		[[fallthrough]];
	case U'\u03BE': /* GREEK SMALL LETTER XI */
		[[fallthrough]];
	case U'\u03BF': /* GREEK SMALL LETTER OMICRON */
		[[fallthrough]];
	case U'\u03C0': /* GREEK SMALL LETTER PI */
		[[fallthrough]];
	case U'\u03C1': /* GREEK SMALL LETTER RHO */
		[[fallthrough]];
	case U'\u03C2': /* GREEK SMALL LETTER FINAL SIGMA */
		[[fallthrough]];
	case U'\u03C3': /* GREEK SMALL LETTER SIGMA */
		[[fallthrough]];
	case U'\u03C4': /* GREEK SMALL LETTER TAU */
		[[fallthrough]];
	case U'\u03C5': /* GREEK SMALL LETTER UPSILON */
		[[fallthrough]];
	case U'\u03C6': /* GREEK SMALL LETTER PHI */
		[[fallthrough]];
	case U'\u03C7': /* GREEK SMALL LETTER CHI */
		[[fallthrough]];
	case U'\u03C8': /* GREEK SMALL LETTER PSI */
		[[fallthrough]];
	case U'\u03C9': /* GREEK SMALL LETTER OMEGA */
		[[fallthrough]];
	case U'\u1D79': /* LATIN SMALL LETTER INSULAR G */
		[[fallthrough]];
	case U'\uA7B7': /* LATIN SMALL LETTER OMEGA */
		[[fallthrough]];
	case U'\uFB00': /* LATIN SMALL LIGATURE FF */
		return true;
	}
}