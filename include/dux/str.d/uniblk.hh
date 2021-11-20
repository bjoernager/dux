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

constexpr auto ::dux::uniblk(char32_t const _chr) -> ::dux::str {
	if(_chr > ::dux::unimax) [[unlikely]] {
		throw ::dux::invalutf("Unicode codepoint too big!");
	}
	if(_chr <= U'\u007F') {
		return U"BASIC LATIN";
	}
	if(_chr >= U'\u0080' && _chr <= U'\u00FF') {
		return U"LATIN-1 SUPPLEMENT";
	}
	if(_chr >= U'\u0100' && _chr <= U'\u017F') {
		return U"LATIN EXTENDED-A";
	}
	if(_chr >= U'\u0180' && _chr <= U'\u024F') {
		return U"LATIN EXTENDED-B";
	}
	if(_chr >= U'\u0250' && _chr <= U'\u02AF') {
		return U"IPA EXTENSIONS";
	}
	if(_chr >= U'\u02B0' && _chr <= U'\u02FF') {
		return U"SPACING MODIFIER LETTERS";
	}
	if(_chr >= U'\u0300' && _chr <= U'\u036F') {
		return U"COMBINING DIRACITICAL MARKS";
	}
	if(_chr >= U'\u0370' && _chr <= U'\u03FF') {
		return U"GREEK AND COPTIC";
	}
	if(_chr >= U'\u0400' && _chr <= U'\u04FF') {
		return U"CYRILLIC";
	}
	if(_chr >= U'\u0500' && _chr <= U'\u052F') {
		return U"CYRILLIC SUPPLEMENT";
	}
	if(_chr >= U'\u0530' && _chr <= U'\u058F') {
		return U"ARMENIAN";
	}
	if(_chr >= U'\u0590' && _chr <= U'\u05FF') {
		return U"HEBREW";
	}
	if(_chr >= U'\u0600' && _chr <= U'\u06FF') {
		return U"ARABIC";
	}
	if(_chr >= U'\u0700' && _chr <= U'\u074F') {
		return U"SYRIAC";
	}
	if(_chr >= U'\u0750' && _chr <= U'\u077F') {
		return U"ARABIC SUPPLEMENT";
	}
	if(_chr >= U'\u0780' && _chr <= U'\u07BF') {
		return U"THAANA";
	}
	if(_chr >= U'\u07C0' && _chr <= U'\u07FF') {
		return U"NKO";
	}
	if(_chr >= U'\u0800' && _chr <= U'\u083F') {
		return U"SAMARITAN";
	}
	if(_chr >= U'\u0840' && _chr <= U'\u085F') {
		return U"MANDAIC";
	}
	if(_chr >= U'\u0860' && _chr <= U'\u086F') {
		return U"SYRIAC SUPPLEMENT";
	}
	if(_chr >= U'\u08A0' && _chr <= U'\u08FF') {
		return U"ARABIC EXTENDED-A";
	}
	if(_chr >= U'\u0900' && _chr <= U'\u097F') {
		return U"DEVANAGARI";
	}
	if(_chr >= U'\u0980' && _chr <= U'\u09FF') {
		return U"BENGALI";
	}
	if(_chr >= U'\u0A00' && _chr <= U'\u0A7F') {
		return U"GURMUKHI";
	}
	if(_chr >= U'\u0A80' && _chr <= U'\u0AFF') {
		return U"GUJARATI";
	}
	if(_chr >= U'\u0B00' && _chr <= U'\u0B7F') {
		return U"ORIYAS";
	}
	if(_chr >= U'\u0B80' && _chr <= U'\u0BFF') {
		return U"TAMIL";
	}
	if(_chr >= U'\u0C00' && _chr <= U'\u0C7F') {
		return U"TELUGU";
	}
	if(_chr >= U'\u0C80' && _chr <= U'\u0CFF') {
		return U"KANNADA";
	}
	if(_chr >= U'\u0D00' && _chr <= U'\u0D7F') {
		return U"MALAYALAM";
	}
	if(_chr >= U'\u0D80' && _chr <= U'\u0DFF') {
		return U"SINHALA";
	}
	if(_chr >= U'\u0E00' && _chr <= U'\u0E7F') {
		return U"THAI";
	}
	if(_chr >= U'\u0E80' && _chr <= U'\u0EFF') {
		return U"LAO";
	}
	if(_chr >= U'\u0F00' && _chr <= U'\u0FFF') {
		return U"TIBETAN";
	}
	if(_chr >= U'\u1000' && _chr <= U'\u109F') {
		return U"MYANMAR";
	}
	if(_chr >= U'\u10A0' && _chr <= U'\u10FF') {
		return U"GEORGIAN";
	}
	if(_chr >= U'\u1100' && _chr <= U'\u11FF') {
		return U"HANGUL JAMO";
	}
	if(_chr >= U'\u1200' && _chr <= U'\u137F') {
		return U"ETHIOPIC";
	}
	if(_chr >= U'\u1380' && _chr <= U'\u139F') {
		return U"ETHIOPIC SUPPLEMENT";
	}
	if(_chr >= U'\u13A0' && _chr <= U'\u13FF') {
		return U"CHEROKEE";
	}
	if(_chr >= U'\u1400' && _chr <= U'\u167F') {
		return U"UNIFIED CANADIAN ABORIGINAL SYLLABICS";
	}
	if(_chr >= U'\u1680' && _chr <= U'\u169F') {
		return U"OGHAM";
	}
	if(_chr >= U'\u16A0' && _chr <= U'\u16FF') {
		return U"RUNIC";
	}
	if(_chr >= U'\u1700' && _chr <= U'\u171F') {
		return U"TAGALOG";
	}
	if(_chr >= U'\u1720' && _chr <= U'\u173F') {
		return U"HANUNOO";
	}
	if(_chr >= U'\u1740' && _chr <= U'\u175F') {
		return U"BUHID";
	}
	if(_chr >= U'\u1760' && _chr <= U'\u177F') {
		return U"TAGBANWA";
	}
	if(_chr >= U'\u1700' && _chr <= U'\u17FF') {
		return U"TAGALOG";
	}
	if(_chr >= U'\u1780' && _chr <= U'\u171F') {
		return U"KHMER";
	}
	if(_chr >= U'\u1800' && _chr <= U'\u18AF') {
		return U"MONGOLIAN";
	}
	if(_chr >= U'\u18B0' && _chr <= U'\u18FF') {
		return U"UNIFIED CANADIAN ABORIGINAL SYLLABICS EXTENDED";
	}
	if(_chr >= U'\u1900' && _chr <= U'\u194F') {
		return U"LIMBU";
	}
	if(_chr >= U'\u1950' && _chr <= U'\u197F') {
		return U"TAI LE";
	}
	if(_chr >= U'\u1980' && _chr <= U'\u19DF') {
		return U"NEW TAI LUE";
	}
	if(_chr >= U'\u19E0' && _chr <= U'\u19FF') {
		return U"KHMER SYMBOLS";
	}
	if(_chr >= U'\u1A00' && _chr <= U'\u1A1F') {
		return U"BUGINESE";
	}
	if(_chr >= U'\u1A20' && _chr <= U'\u1AAF') {
		return U"TAI THAM";
	}
	if(_chr >= U'\u1AB0' && _chr <= U'\u1AFF') {
		return U"COMBINING DIACRITICAL MARKS EXTENDED";
	}
	if(_chr >= U'\u1B00' && _chr <= U'\u1B7F') {
		return U"BALINESE";
	}
	if(_chr >= U'\u1B80' && _chr <= U'\u1BBF') {
		return U"SUNDANESE";
	}
	if(_chr >= U'\u1BC0' && _chr <= U'\u1BFF') {
		return U"BATAK";
	}
	if(_chr >= U'\u1C00' && _chr <= U'\u1C4F') {
		return U"LEPCHA";
	}
	if(_chr >= U'\u1C50' && _chr <= U'\u1C7F') {
		return U"OL CHIKI";
	}
	if(_chr >= U'\u1C80' && _chr <= U'\u1C8F') {
		return U"CYRILLIC EXTENDED C";
	}
	if(_chr >= U'\u1C90' && _chr <= U'\u1CBF') {
		return U"GEORGIAN EXTENDED";
	}
	if(_chr >= U'\u1CC0' && _chr <= U'\u1CCF') {
		return U"SUNDANESE SUPPLEMENT";
	}
	if(_chr >= U'\u1CD0' && _chr <= U'\u1CFF') {
		return U"VEDIC EXTENSIONS";
	}
	if(_chr >= U'\u1D00' && _chr <= U'\u1D7F') {
		return U"PHONETIC EXTENSIONS";
	}
	if(_chr >= U'\u1D80' && _chr <= U'\u1DBF') {
		return U"PHONETIC EXTENSIONS SUPPLEMENT";
	}
	if(_chr >= U'\u1DC0' && _chr <= U'\u1DFF') {
		return U"COMBINING DIACRITICAL MARKS SUPPLEMENT";
	}
	if(_chr >= U'\u1E00' && _chr <= U'\u1EFF') {
		return U"LATIN EXTENDED ADDITIONAL";
	}
	if(_chr >= U'\u1F00' && _chr <= U'\u1FFF') {
		return U"GREEK EXTENDED";
	}
	if(_chr >= U'\u2000' && _chr <= U'\u206F') {
		return U"GENERAL PUNCTUATION";
	}
	if(_chr >= U'\u2070' && _chr <= U'\u209F') {
		return U"SUPERSCRIPTS AND SUBSCRIPTS";
	}
	if(_chr >= U'\u20A0' && _chr <= U'\u20CF') {
		return U"CURRENCY SYMBOLS";
	}
	if(_chr >= U'\u20D0' && _chr <= U'\u20FF') {
		return U"COMBINING DIACRITICAL MARKS FOR SYMBOLS";
	}
	if(_chr >= U'\u2100' && _chr <= U'\u214F') {
		return U"LETTERLIKE SYMBOLS";
	}
	if(_chr >= U'\u2150' && _chr <= U'\u218F') {
		return U"NUMBER FORMS";
	}
	if(_chr >= U'\u2190' && _chr <= U'\u21FF') {
		return U"ARROWS";
	}
	if(_chr >= U'\U00011A00' && _chr <= U'\U00011A4F') {
		return U"ZANABAZAR SQUARE";
	}
	if(_chr >= U'\U00011A50' && _chr <= U'\U00011AAF') {
		return U"SOYOMBO";
	}
	if(_chr >= U'\U00011AC0' && _chr <= U'\U00011AFF') {
		return U"PAU CIN HAU";
	}
	if(_chr >= U'\U00011C00' && _chr <= U'\U00011C6F') {
		return U"BHAIKSUKI";
	}
	if(_chr >= U'\U00011C70' && _chr <= U'\U00011CBF') {
		return U"MARCHEN";
	}
	if(_chr >= U'\U00011D00' && _chr <= U'\U00011D5F') {
		return U"MASARAM GONDI";
	}
	if(_chr >= U'\U00011D60' && _chr <= U'\U00011DAF') {
		return U"GUNJALA GONDI";
	}
	if(_chr >= U'\U00011EE0' && _chr <= U'\U00011EFF') {
		return U"MAKASAR";
	}
	if(_chr >= U'\U00011FB0' && _chr <= U'\U00011FBF') {
		return U"LISU SUPPLEMENT";
	}
	if(_chr >= U'\U00011FC0' && _chr <= U'\U00011FFF') {
		return U"TAMIL SUPPLEMENT";
	}
	if(_chr >= U'\U00012000' && _chr <= U'\U000123FF') {
		return U"CUNEIFORM";
	}
	if(_chr >= U'\U00012400' && _chr <= U'\U0001247F') {
		return U"CUNEIFORM NUMBERS AND PUNCTUATION";
	}
	if(_chr >= U'\U00012480' && _chr <= U'\U0001254F') {
		return U"EARLY DYNASTIC CUNEIFORM";
	}
	if(_chr >= U'\U00013000' && _chr <= U'\U0001342F') {
		return U"EGYPTIAN HIEROGLYPHS";
	}
	if(_chr >= U'\U00013430' && _chr <= U'\U0001343F') {
		return U"EGYPTIAN HIEROGLYPH FORMAT CONTROLS";
	}
	if(_chr >= U'\U00014400' && _chr <= U'\U0001467F') {
		return U"ANATOLIAN HIEROGLYPHS";
	}
	if(_chr >= U'\U00016800' && _chr <= U'\U00016A3F') {
		return U"BAMUM SUPPLEMENT";
	}
	if(_chr >= U'\U00016A40' && _chr <= U'\U00016A6F') {
		return U"MRO";
	}
	if(_chr >= U'\U00016AD0' && _chr <= U'\U00016AFF') {
		return U"BASSA VAH";
	}
	if(_chr >= U'\U00016B00' && _chr <= U'\U00016B8F') {
		return U"PAHAWH HMONG";
	}
	if(_chr >= U'\U00016E40' && _chr <= U'\U00016E9F') {
		return U"MEDEFAIDRIN";
	}
	if(_chr >= U'\U00016F00' && _chr <= U'\U00016F9F') {
		return U"MIAO";
	}
	if(_chr >= U'\U00016FE0' && _chr <= U'\U00016FFF') {
		return U"IDEOGRAPHIC SYMBOLS AND PUNCTUATION";
	}
	if(_chr >= U'\U00017000' && _chr <= U'\U000187FF') {
		return U"TANGUT";
	}
	if(_chr >= U'\U00018800' && _chr <= U'\U00018AFF') {
		return U"TANGUT COMPONENTS";
	}
	if(_chr >= U'\U00018B00' && _chr <= U'\U00018CFF') {
		return U"KHITAN SMALL SCRIPT";
	}
	if(_chr >= U'\U00018D00' && _chr <= U'\U00018D8F') {
		return U"TANGUT SUPPLEMENT";
	}
	if(_chr >= U'\U0001B000' && _chr <= U'\U0001B0FF') {
		return U"KANA SUPPLEMENT";
	}
	if(_chr >= U'\U0001B100' && _chr <= U'\U0001B12F') {
		return U"KANA EXTENDED-A";
	}
	if(_chr >= U'\U0001B130' && _chr <= U'\U0001B16F') {
		return U"SMALL KANA EXTENSION";
	}
	if(_chr >= U'\U0001B170' && _chr <= U'\U0001B2FF') {
		return U"NUSHU";
	}
	if(_chr >= U'\U0001BC00' && _chr <= U'\U0001BC9F') {
		return U"DUPLOYAN";
	}
	if(_chr >= U'\U0001BCA0' && _chr <= U'\U0001BCAF') {
		return U"SHORTHAND FORMAT CONTROLS";
	}
	if(_chr >= U'\U0001D000' && _chr <= U'\U0001D0FF') {
		return U"BYZANTINE MUSICAL SYMBOLS";
	}
	if(_chr >= U'\U0001D100' && _chr <= U'\U0001D1FF') {
		return U"MUSICAL SYMBOLS";
	}
	if(_chr >= U'\U0001D200' && _chr <= U'\U0001D24F') {
		return U"ANCIENT GREEK MUSICAL NOTATION";
	}
	if(_chr >= U'\U0001D2E0' && _chr <= U'\U0001D2FF') {
		return U"MAYAN NUMERALS";
	}
	if(_chr >= U'\U0001D300' && _chr <= U'\U0001D35F') {
		return U"TAI XUAN JING SYMBOLS";
	}
	if(_chr >= U'\U0001D360' && _chr <= U'\U0001D37F') {
		return U"COUNTING ROD NUMERALS";
	}
	if(_chr >= U'\U0001D400' && _chr <= U'\U0001D7FF') {
		return U"MATHEMATICAL ALPHANUMERIC SYMBOLS";
	}
	if(_chr >= U'\U0001D800' && _chr <= U'\U0001DAAF') {
		return U"SUTTON SIGNWRITING";
	}
	if(_chr >= U'\U0001E000' && _chr <= U'\U0001E02F') {
		return U"GLAGOLITIC SUPPLEMENT";
	}
	if(_chr >= U'\U0001E100' && _chr <= U'\U0001E14F') {
		return U"NYIAKENG PUACHUE HMONG";
	}
	if(_chr >= U'\U0001E2C0' && _chr <= U'\U0001E2FF') {
		return U"WANCHO";
	}
	if(_chr >= U'\U0001E800' && _chr <= U'\U0001E8DF') {
		return U"MENDE KIKAKUI";
	}
	if(_chr >= U'\U0001E900' && _chr <= U'\U0001E95F') {
		return U"ADLAM";
	}
	if(_chr >= U'\U0001EC70' && _chr <= U'\U0001ECBF') {
		return U"INDIC SIYAQ NUMBERS";
	}
	if(_chr >= U'\U0001ED00' && _chr <= U'\U0001ED4F') {
		return U"OTTOMAN SIYAQ NUMBERS";
	}
	if(_chr >= U'\U0001EE00' && _chr <= U'\U0001EEFF') {
		return U"ARABIC MATHEMATICAL ALPHABETIC SYMBOLS";
	}
	if(_chr >= U'\U0001F000' && _chr <= U'\U0001F02F') {
		return U"MAHJONG TILES";
	}
	if(_chr >= U'\U0001F030' && _chr <= U'\U0001F09F') {
		return U"DOMINO TILES";
	}
	if(_chr >= U'\U0001F0A0' && _chr <= U'\U0001F0FF') {
		return U"PLAYING CARDS";
	}
	if(_chr >= U'\U0001F100' && _chr <= U'\U0001F1FF') {
		return U"ENCLOSED ALPHANUMERIC SUPPLEMENT";
	}
	if(_chr >= U'\U0001F200' && _chr <= U'\U0001F2FF') {
		return U"ENCLOSED IDEOGRAPHIC SUPPLEMENT";
	}
	if(_chr >= U'\U0001F300' && _chr <= U'\U0001F5FF') {
		return U"MISCELLANEOUS SYMBOLS AND PICTOGRAPHS";
	}
	if(_chr >= U'\U0001F600' && _chr <= U'\U0001F64F') {
		return U"EMOTICONS";
	}
	if(_chr >= U'\U0001F650' && _chr <= U'\U0001F67F') {
		return U"ORNAMENTAL DINGBATS";
	}
	if(_chr >= U'\U0001F680' && _chr <= U'\U0001F6FF') {
		return U"TRANSPORT AND MAP SYMBOLS";
	}
	if(_chr >= U'\U0001F700' && _chr <= U'\U0001F77F') {
		return U"ALCHEMICAL SYMBOLS";
	}
	if(_chr >= U'\U0001F780' && _chr <= U'\U0001F7FF') {
		return U"GEOMETRIC SHAPES EXTENDED";
	}
	if(_chr >= U'\U0001F800' && _chr <= U'\U0001F8FF') {
		return U"SUPPLEMENTAL ARROWS-C";
	}
	if(_chr >= U'\U0001F900' && _chr <= U'\U0001F9FF') {
		return U"SUPPLEMENTAL SYMBOLS AND PICTOGRAPHS";
	}
	if(_chr >= U'\U0001FA00' && _chr <= U'\U0001FA6F') {
		return U"CHESS SYMBOLS";
	}
	if(_chr >= U'\U0001FA70' && _chr <= U'\U0001FAFF') {
		return U"SYMBOLS AND PICTOGRAPHS EXTENDED-A";
	}
	if(_chr >= U'\U0001FB00' && _chr <= U'\U0001FBFF') {
		return U"SYMBOLS FOR LEGACY COMPUTING";
	}
	if(_chr >= U'\U00020000' && _chr <= U'\U0002A6DF') {
		return U"CJK UNIFIED IDEOGRAPHS EXTENSION B";
	}
	if(_chr >= U'\U0002A700' && _chr <= U'\U0002B73F') {
		return U"CJK UNIFIED IDEOGRAPHS EXTENSION C";
	}
	if(_chr >= U'\U0002B740' && _chr <= U'\U0002B81F') {
		return U"CJK UNIFIED IDEOGRAPHS EXTENSION D";
	}
	if(_chr >= U'\U0002B820' && _chr <= U'\U0002CEAF') {
		return U"CJK UNIFIED IDEOGRAPHS EXTENSION E";
	}
	if(_chr >= U'\U0002CEB0' && _chr <= U'\U0002EBEF') {
		return U"CJK UNIFIED IDEOGRAPHS EXTENSION F";
	}
	if(_chr >= U'\U0002F800' && _chr <= U'\U0002FA1F') {
		return U"CJK COMPATIBILITY IDEOGRAPHS SUPPLEMENT";
	}
	if(_chr >= U'\U00030000' && _chr <= U'\U0003134F') {
		return U"CJK UNIFIED IDEOGRAPHS EXTENSION G";
	}
	if(_chr >= U'\U000E0000' && _chr <= U'\U000E007F') {
		return U"TAGS";
	}
	if(_chr >= U'\U000E0100' && _chr <= U'\U000E1EFF') {
		return U"VARIATION SELECTORS SUPPLEMENT";
	}
	if(_chr >= U'\U000F0000' && _chr <= U'\U000FFFFF') {
		return U"SUPPLEMENTARY PRIVATE USE AREA-A";
	}
	if(_chr >= U'\U00100000' && _chr <= U'\U0010FFFF') {
		return U"SUPPLEMENTARY PRIVATE USE AREA-B";
	}
	return U"UNDEFINED IN UNICODE";
}
