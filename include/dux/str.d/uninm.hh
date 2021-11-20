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

constexpr auto ::dux::uninm(char32_t const _chr) -> ::dux::str{
	switch(_chr) {
	[[unlikely]] default:
		if(_chr > ::dux::unimax) [[unlikely]] {
			throw ::dux::invalutf("Character out of range.");
		}
		return U"UNDEFINED IN UNICODE";
	/* BASIC LATIN: */
	case U'\u0000':
		return U"NULL";
	case U'\u0001':
		return U"START OF HEADING";
	case U'\u0002':
		return U"START OF TEXT";
	case U'\u0003':
		return U"END OF TEXT";
	case U'\u0004':
		return U"END OF TRANSMISSION";
	case U'\u0005':
		return U"ENQUIRY";
	case U'\u0006':
		return U"ACKNOWLEDGE";
	case U'\u0007':
		return U"BELL";
	case U'\u0008':
		return U"BACKSPACE";
	case U'\u0009':
		return U"HORIZONTAL TABULATION";
	case U'\u000A':
		return U"NEW LINE";
	case U'\u000B':
		return U"VERTICAL TABULATION";
	case U'\u000C':
		return U"FORM FEED";
	case U'\u000D':
		return U"CARRIAGE RETURN";
	case U'\u000E':
		return U"SHIFT OUT";
	case U'\u000F':
		return U"SHIFT IN";
	case U'\u0010':
		return U"DATA LINK ESCAPE";
	case U'\u0011':
		return U"DEVICE CONTROL ONE";
	case U'\u0012':
		return U"DEVICE CONTROL TWO";
	case U'\u0013':
		return U"DEVICE CONTROL THREE";
	case U'\u0014':
		return U"DEVICE CONTROL FOUR";
	case U'\u0015':
		return U"NEGATIVE ACKNOWLEDGE";
	case U'\u0016':
		return U"SYNCHRONOUS IDLE";
	case U'\u0017':
		return U"END OF TRANSMISSION BLOCk";
	case U'\u0018':
		return U"CANCEL";
	case U'\u0019':
		return U"END OF MEDIUM";
	case U'\u001A':
		return U"SUBSTITUTE";
	case U'\u001B':
		return U"ESCAPE";
	case U'\u001C':
		return U"FILE SEPERATOR";
	case U'\u001D':
		return U"GROUP SEPERATOR";
	case U'\u001E':
		return U"RECORD SEPERATOR";
	case U'\u001F':
		return U"UNIT SEPERATOR";
	case U'\u0020':
		return U"SPACE";
	case U'\u0021':
		return U"EXCLAMATION MARK";
	case U'\u0022':
		return U"QUOTATION MARK";
	case U'\u0023':
		return U"NUMBER SIGN";
	case U'\u0024':
		return U"DOLLAR SIGN";
	case U'\u0025':
		return U"PERCENT SIGN";
	case U'\u0026':
		return U"AMPERSAND";
	case U'\u0027':
		return U"APOSTROPHE";
	case U'\u0028':
		return U"LEFT PARANTHESIS";
	case U'\u0029':
		return U"RIGHT PARANTHESIS";
	case U'\u002A':
		return U"ASTERISK";
	case U'\u002B':
		return U"PLUS SIGN";
	case U'\u002C':
		return U"COMMA";
	case U'\u002D':
		return U"HYPHEN-MINUS";
	case U'\u002E':
		return U"FULL STOP";
	case U'\u002F':
		return U"SOLIDUS";
	case U'\u0030':
		return U"DIGIT ZERO";
	case U'\u0031':
		return U"DIGIT ONE";
	case U'\u0032':
		return U"DIGIT TWO";
	case U'\u0033':
		return U"DIGIT THREE";
	case U'\u0034':
		return U"DIGIT FOUR";
	case U'\u0035':
		return U"DIGIT FIVE";
	case U'\u0036':
		return U"DIGIT SIX";
	case U'\u0037':
		return U"DIGIT SEVEN";
	case U'\u0038':
		return U"DIGIT EIGHT";
	case U'\u0039':
		return U"DIGIT NINE";
	case U'\u003A':
		return U"COLON";
	case U'\u003B':
		return U"SEMICOLON";
	case U'\u003C':
		return U"LESS-THAN SIGN";
	case U'\u003D':
		return U"EQUALS SIGN";
	case U'\u003E':
		return U"GREATER-THAN SIGN";
	case U'\u003F':
		return U"QUESTION MARK";
	case U'\u0040':
		return U"COMMERCIAL AT";
	case U'\u0041':
		return U"LATIN CAPITAL LETTER A";
	case U'\u0042':
		return U"LATIN CAPITAL LETTER B";
	case U'\u0043':
		return U"LATIN CAPITAL LETTER C";
	case U'\u0044':
		return U"LATIN CAPITAL LETTER D";
	case U'\u0045':
		return U"LATIN CAPITAL LETTER E";
	case U'\u0046':
		return U"LATIN CAPITAL LETTER F";
	case U'\u0047':
		return U"LATIN CAPITAL LETTER G";
	case U'\u0048':
		return U"LATIN CAPITAL LETTER H";
	case U'\u0049':
		return U"LATIN CAPITAL LETTER I";
	case U'\u004A':
		return U"LATIN CAPITAL LETTER J";
	case U'\u004B':
		return U"LATIN CAPITAL LETTER K";
	case U'\u004C':
		return U"LATIN CAPITAL LETTER L";
	case U'\u004D':
		return U"LATIN CAPITAL LETTER M";
	case U'\u004E':
		return U"LATIN CAPITAL LETTER N";
	case U'\u004F':
		return U"LATIN CAPITAL LETTER O";
	case U'\u0050':
		return U"LATIN CAPITAL LETTER P";
	case U'\u0051':
		return U"LATIN CAPITAL LETTER Q";
	case U'\u0052':
		return U"LATIN CAPITAL LETTER R";
	case U'\u0053':
		return U"LATIN CAPITAL LETTER S";
	case U'\u0054':
		return U"LATIN CAPITAL LETTER T";
	case U'\u0055':
		return U"LATIN CAPITAL LETTER U";
	case U'\u0056':
		return U"LATIN CAPITAL LETTER V";
	case U'\u0057':
		return U"LATIN CAPITAL LETTER W";
	case U'\u0058':
		return U"LATIN CAPITAL LETTER X";
	case U'\u0059':
		return U"LATIN CAPITAL LETTER Y";
	case U'\u005A':
		return U"LATIN CAPITAL LETTER Z";
	case U'\u005B':
		return U"LEFT SQUARE BRACKET";
	case U'\u005C':
		return U"REVERSE SOLIDUS";
	case U'\u005D':
		return U"RIGHT SQUARE BRACKET";
	case U'\u005E':
		return U"CIRCUMFLEX ACCENT";
	case U'\u005F':
		return U"LOW LINE";
	case U'\u0060':
		return U"GRAVE ACCENT";
	case U'\u0061':
		return U"LATIN SMALL LETTER A";
	case U'\u0062':
		return U"LATIN SMALL LETTER B";
	case U'\u0063':
		return U"LATIN SMALL LETTER C";
	case U'\u0064':
		return U"LATIN SMALL LETTER D";
	case U'\u0065':
		return U"LATIN SMALL LETTER E";
	case U'\u0066':
		return U"LATIN SMALL LETTER F";
	case U'\u0067':
		return U"LATIN SMALL LETTER G";
	case U'\u0068':
		return U"LATIN SMALL LETTER H";
	case U'\u0069':
		return U"LATIN SMALL LETTER I";
	case U'\u006A':
		return U"LATIN SMALL LETTER J";
	case U'\u006B':
		return U"LATIN SMALL LETTER K";
	case U'\u006C':
		return U"LATIN SMALL LETTER L";
	case U'\u006D':
		return U"LATIN SMALL LETTER M";
	case U'\u006E':
		return U"LATIN SMALL LETTER N";
	case U'\u006F':
		return U"LATIN SMALL LETTER O";
	case U'\u0070':
		return U"LATIN SMALL LETTER P";
	case U'\u0071':
		return U"LATIN SMALL LETTER Q";
	case U'\u0072':
		return U"LATIN SMALL LETTER R";
	case U'\u0073':
		return U"LATIN SMALL LETTER S";
	case U'\u0074':
		return U"LATIN SMALL LETTER T";
	case U'\u0075':
		return U"LATIN SMALL LETTER U";
	case U'\u0076':
		return U"LATIN SMALL LETTER V";
	case U'\u0077':
		return U"LATIN SMALL LETTER W";
	case U'\u0078':
		return U"LATIN SMALL LETTER X";
	case U'\u0079':
		return U"LATIN SMALL LETTER Y";
	case U'\u007A':
		return U"LATIN SMALL LETTER Z";
	case U'\u007B':
		return U"LEFT CURLY BRACKET";
	case U'\u007C':
		return U"VERTICAL LINE";
	case U'\u007D':
		return U"RIGHT CURLY BRACKET";
	case U'\u007E':
		return U"TILDE";
	case U'\u007F':
		return U"DELETE";
	/* LATIN-1 SUPPLEMENT: */
	case U'\u0080':
		return U"PADDING CHARACTER";
	case U'\u0081':
		return U"HIGH OCTET PRESET";
	case U'\u0082':
		return U"BREAK PERMITTED HERE";
	case U'\u0083':
		return U"NO BREAK HERE";
	case U'\u0084':
		return U"INDEX";
	case U'\u0085':
		return U"NEXT LINE";
	case U'\u0086':
		return U"START OF SELECTED AREA";
	case U'\u0087':
		return U"END OF SELECTED AREA";
	case U'\u0088':
		return U"CHARACTER TABULATION SET";
	case U'\u0089':
		return U"CHARACTER TABULATION WITH JUSTIFICATION";
	case U'\u008A':
		return U"LINE TABULATION SET";
	case U'\u008B':
		return U"PARTIAL LINE FORWARD";
	case U'\u008C':
		return U"PARTIAL LINE BACKWARD";
	case U'\u008D':
		return U"REVERSE LINE FEED";
	case U'\u008E':
		return U"SINGLE SHIFT TWO";
	case U'\u008F':
		return U"SINGLE SHIFT THREE";
	case U'\u0090':
		return U"DEVICE CONTROL STRING";
	case U'\u0091':
		return U"PRIVATE USE ONE";
	case U'\u0092':
		return U"PRIVATE USE TWO";
	case U'\u0093':
		return U"SET TRANSMIT STATE";
	case U'\u0094':
		return U"CANCEL CHARACTER";
	case U'\u0095':
		return U"MESSAGE WAITING";
	case U'\u0096':
		return U"START OF GUARDED AREA";
	case U'\u0097':
		return U"END OF GUARDED AREA";
	case U'\u0098':
		return U"START OF STRING";
	case U'\u0099':
		return U"SINGLE GRAPHIC CHARACTER INTRODUCER";
	case U'\u009A':
		return U"SINGLE CHARACTER INTRODUCER";
	case U'\u009B':
		return U"CONTROL SEQUENCE INTRODUCER";
	case U'\u009C':
		return U"STRING TERMINATOR";
	case U'\u009D':
		return U"OPERATING SYSTEM COMMAND";
	case U'\u009E':
		return U"PRIVACY MESSAGE";
	case U'\u009F':
		return U"APPLICATION PROGRAM COMMAND";
	case U'\u00A0':
		return U"NO-BREAK SPACE";
	case U'\u00A1':
		return U"INVERTED EXCLAMATION MARK";
	case U'\u00A2':
		return U"CENT SIGN";
	case U'\u00A3':
		return U"POUND SIGN";
	case U'\u00A4':
		return U"CURRENCY SIGN";
	case U'\u00A5':
		return U"YEN SIGN";
	case U'\u00A6':
		return U"BROKEN BAR";
	case U'\u00A7':
		return U"SECTION SIGN";
	case U'\u00A8':
		return U"DIAERESIS";
	case U'\u00A9':
		return U"COPYRIGHT SIGN";
	case U'\u00AA':
		return U"FEMININE ORDINAL INDICATOR";
	case U'\u00AB':
		return U"LEFT-POINTING DOUBLE ANGLE QUOTATION MARK";
	case U'\u00AC':
		return U"NOT SIGN";
	case U'\u00AD':
		return U"SOFT HYPHEN";
	case U'\u00AE':
		return U"REGISTERED SIGN";
	case U'\u00AF':
		return U"MACRON";
	case U'\u00B0':
		return U"DEGREE SIGN";
	case U'\u00B1':
		return U"PLUS MINUS SYMBOL";
	case U'\u00B2':
		return U"SUPERSCRIPT TWO";
	case U'\u00B3':
		return U"SUPERSCRIPT THREE";
	case U'\u00B4':
		return U"ACUTE ACCENT";
	case U'\u00B5':
		return U"MICRO SIGN";
	case U'\u00B6':
		return U"PILCROW SIGN";
	case U'\u00B7':
		return U"MIDDLE DOT";
	case U'\u00B8':
		return U"CEDILLA";
	case U'\u00B9':
		return U"SUPERSCRIPT ONE";
	case U'\u00BA':
		return U"MASCULINE ORDINAL INDICATOR";
	case U'\u00BB':
		return U"RIGHT-POINTING DOUBLE ANGLE QUOTATION MARK";
	case U'\u00BC':
		return U"VULGAR FRACTION ONE QUARTER";
	case U'\u00BD':
		return U"VULGAR FRACTION ONE HALF";
	case U'\u00BE':
		return U"VULGAR FRACTION THREE QUARTERS";
	case U'\u00BF':
		return U"INVERTED QUESTION MARK";
	case U'\u00C0':
		return U"LATIN CAPITAL LETTER A WITH GRAVE";
	case U'\u00C1':
		return U"LATIN CAPITAL LETTER A WITH ACUTE";
	case U'\u00C2':
		return U"LATIN CAPITAL LETTER A WITH CIRCUMFLEX";
	case U'\u00C3':
		return U"LATIN CAPITAL LETTER A WITH TILDE";
	case U'\u00C4':
		return U"LATIN CAPITAL LETTER A WITH DIAERESIS";
	case U'\u00C5':
		return U"LATIN CAPITAL LETTER A WITH RING ABOVE";
	case U'\u00C6':
		return U"LATIN CAPITAL LETTER AE";
	case U'\u00C7':
		return U"LATIN CAPITAL LETTER C WITH CEDILLA";
	case U'\u00C8':
		return U"LATIN CAPITAL LETTER E WITH GRAVE";
	case U'\u00C9':
		return U"LATIN CAPITAL LETTER E WITH ACUTE";
	case U'\u00CA':
		return U"LATIN CAPITAL LETTER E WITH CIRCUMFLEX";
	case U'\u00CB':
		return U"LATIN CAPITAL LETTER E WITH DIAERESIS";
	case U'\u00CC':
		return U"LATIN CAPITAL LETTER I WITH GRAVE";
	case U'\u00CD':
		return U"LATIN CAPITAL LETTER I WITH ACUTE";
	case U'\u00CE':
		return U"LATIN CAPITAL LETTER I WITH CIRCUMFLEX";
	case U'\u00CF':
		return U"LATIN CAPITAL LETTER I WITH DIAERESIS";
	case U'\u00D0':
		return U"LATIN CAPITAL LETTER ETH";
	case U'\u00D1':
		return U"LATIN CAPITAL LETTER N WITH TILDE";
	case U'\u00D2':
		return U"LATIN CAPITAL LETTER O WITH GRAVE";
	case U'\u00D3':
		return U"LATIN CAPITAL LETTER O WITH ACUTE";
	case U'\u00D4':
		return U"LATIN CAPITAL LETTER O WITH CIRCUMFLEX";
	case U'\u00D5':
		return U"LATIN CAPITAL LETTER O WITH TILDE";
	case U'\u00D6':
		return U"LATIN CAPITAL LETTER O WITH DIAERESIS";
	case U'\u00D7':
		return U"MULTIPLICATION SIGN";
	case U'\u00D8':
		return U"LATIN CAPITAL LETTER O WITH STROKE";
	case U'\u00D9':
		return U"LATIN CAPITAL LETTER U WITH GRAVE";
	case U'\u00DA':
		return U"LATIN CAPITAL LETTER U WITH ACUTE";
	case U'\u00DB':
		return U"LATIN CAPITAL LETTER U WITH CIRCUMFLEX";
	case U'\u00DC':
		return U"LATIN CAPITAL LETTER U WITH DIAERESIS";
	case U'\u00DD':
		return U"LATIN CAPITAL LETTER Y WITH ACUTE";
	case U'\u00DE':
		return U"LATIN CAPITAL LETTER THORN";
	case U'\u00DF':
		return U"LATIN SMALL LETTER SHARP S";
	case U'\u00E0':
		return U"LATIN SMALL LETTER A WITH GRAVE";
	case U'\u00E1':
		return U"LATIN SMALL LETTER A WITH ACUTE";
	case U'\u00E2':
		return U"LATIN SMALL LETTER A WITH CIRCUMFLEX";
	case U'\u00E3':
		return U"LATIN SMALL LETTER A WITH TILDE";
	case U'\u00E4':
		return U"LATIN SMALL LETTER A WITH DIAERESIS";
	case U'\u00E5':
		return U"LATIN SMALL LETTER A WITH RING ABOVE";
	case U'\u00E6':
		return U"LATIN SMALL LETTER AE";
	case U'\u00E7':
		return U"LATIN SMALL LETTER C WITH CEDILLA";
	case U'\u00E8':
		return U"LATIN SMALL LETTER E WITH GRAVE";
	case U'\u00E9':
		return U"LATIN SMALL LETTER E WITH ACUTE";
	case U'\u00EA':
		return U"LATIN SMALL LETTER E WITH CIRCUMFLEX";
	case U'\u00EB':
		return U"LATIN SMALL LETTER E WITH DIAERESIS";
	case U'\u00EC':
		return U"LATIN SMALL LETTER I WITH GRAVE";
	case U'\u00ED':
		return U"LATIN SMALL LETTER I WITH ACUTE";
	case U'\u00EE':
		return U"LATIN SMALL LETTER I WITH CIRCUMFLEX";
	case U'\u00EF':
		return U"LATIN SMALL LETTER I WITH DIAERESIS";
	case U'\u00F0':
		return U"LATIN SMALL LETTER ETH";
	case U'\u00F1':
		return U"LATIN SMALL LETTER N WITH TILDE";
	case U'\u00F2':
		return U"LATIN SMALL LETTER O WITH GRAVE";
	case U'\u00F3':
		return U"LATIN SMALL LETTER O WITH ACUTE";
	case U'\u00F4':
		return U"LATIN SMALL LETTER O WITH CIRCUMFLEX";
	case U'\u00F5':
		return U"LATIN SMALL LETTER O WITH TILDE";
	case U'\u00F6':
		return U"LATIN SMALL LETTER O WITH DIAERESIS";
	case U'\u00F7':
		return U"DIVISION SIGN";
	case U'\u00F8':
		return U"LATIN SMALL LETTER O WITH STROKE";
	case U'\u00F9':
		return U"LATIN SMALL LETTER U WITH GRAVE";
	case U'\u00FA':
		return U"LATIN SMALL LETTER U WITH ACUTE";
	case U'\u00FB':
		return U"LATIN SMALL LETTER U WITH CIRCUMFLEX";
	case U'\u00FC':
		return U"U WITH TWO DOTS";
	case U'\u00FD':
		return U"LATIN SMALL LETTER Y WITH ACUTE";
	case U'\u00FE':
		return U"LATIN SMALL LETTER THORN";
	case U'\u00FF':
		return U"LATIN SMALL LETTER Y WITH DIAERESIS";
	/* LATIN EXTENDED-A: */
	case U'\u0100':
		return U"LATIN CAPITAL LETTER A WITH MACRON";
	case U'\u0101':
		return U"LATIN SMALL LETTER A WITH MACRON";
	case U'\u0102':
		return U"LATIN CAPITAL LETTER A WITH BREVE";
	case U'\u0103':
		return U"LATIN SMALL LETTER A WITH BREVE";
	case U'\u0104':
		return U"LATIN CAPITAL LETTER A WITH OGONEK";
	case U'\u0105':
		return U"LATIN SMALL LETTER A WITH OGONEK";
	case U'\u0106':
		return U"LATIN CAPITAL LETTER C WITH ACUTE";
	case U'\u0107':
		return U"LATIN SMALL LETTER C WITH ACUTE";
	case U'\u0108':
		return U"LATIN CAPITAL LETTER C WITH CIRCUMFLEX";
	case U'\u0109':
		return U"LATIN SMALL LETTER C WITH CIRCUMFLEX";
	case U'\u010A':
		return U"LATIN CAPITAL LETTER C WITH DOT ABOVE";
	case U'\u010B':
		return U"LATIN SMALL LETTER C WITH DOT ABOVE";
	case U'\u010C':
		return U"LATIN CAPITAL LETTER C WITH CARON";
	case U'\u010D':
		return U"LATIN SMALL LETTER C WITH CARON";
	case U'\u010E':
		return U"LATIN CAPITAL LETTER D WITH CARON";
	case U'\u010F':
		return U"LATIN SMALL LETTER D WITH CARON";
	case U'\u0110':
		return U"LATIN CAPITAL LETTER D WITH STROKE";
	case U'\u0111':
		return U"LATIN SMALL LETTER D WITH STROKE";
	case U'\u0112':
		return U"LATIN CAPITAL LETTER E WITH MACRON";
	case U'\u0113':
		return U"LATIN SMALL LETTER E WITH MACRON";
	case U'\u0114':
		return U"LATIN CAPITAL LETTER E WITH BREVE";
	case U'\u0115':
		return U"LATIN SMALL LETTER E WITH BREVE";
	case U'\u0116':
		return U"LATIN CAPITAL LETTER E WITH DOT ABOVE";
	case U'\u0117':
		return U"LATIN SMALL LETTER E WITH DOT ABOVE";
	case U'\u0118':
		return U"LATIN CAPITAL LETTER E WITH OGONEK";
	case U'\u0119':
		return U"LATIN SMALL LETTER E WITH OGONEK";
	case U'\u011A':
		return U"LATIN CAPITAL LETTER E WITH CARON";
	case U'\u011B':
		return U"LATIN SMALL LETTER E WITH CARON";
	case U'\u011C':
		return U"LATIN CAPITAL LETTER G WITH CIRCUMFLEX";
	case U'\u011D':
		return U"LATIN SMALL LETTER G WITH CIRCUMFLEX";
	case U'\u011E':
		return U"LATIN CAPITAL LETTER G WITH BREVE";
	case U'\u011F':
		return U"LATIN SMALL LETTER G WITH BREVE";
	case U'\u0120':
		return U"LATIN CAPITAL LETTER G WITH DOT ABOVE";
	case U'\u0121':
		return U"LATIN SMALL LETTER G WITH DOT ABOVE";
	case U'\u0122':
		return U"LATIN CAPITAL LETTER G WITH CEDILLA";
	case U'\u0123':
		return U"LATIN SMALL LETTER G WITH CEDILLA";
	case U'\u0124':
		return U"LATIN CAPITAL LETTER H WITH CIRCUMFLEX";
	case U'\u0125':
		return U"LATIN SMALL LETTER H WITH CIRCUMFLEX";
	case U'\u0126':
		return U"LATIN CAPITAL LETTER H WITH STROKE";
	case U'\u0127':
		return U"LATIN SMALL LETTER H WITH STROKE";
	case U'\u0128':
		return U"LATIN CAPITAL LETTER I WITH TILDE";
	case U'\u0129':
		return U"LATIN SMALL LETTER I WITH TILDE";
	case U'\u012A':
		return U"LATIN CAPITAL LETTER I WITH MACRON";
	case U'\u012B':
		return U"LATIN SMALL LETTER I WITH MACRON";
	case U'\u012C':
		return U"LATIN CAPITAL LETTER I WITH BREVE";
	case U'\u012D':
		return U"LATIN SMALL LETTER I WITH BREVE";
	case U'\u012E':
		return U"LATIN CAPITAL LETTER I WITH OGONEK";
	case U'\u012F':
		return U"LATIN SMALL LETTER I WITH OGONEK";
	case U'\u0130':
		return U"LATIN CAPITAL LETTER I WITH DOT ABOVE";
	case U'\u0131':
		return U"LATIN SMALL LETTER DOTLESS I";
	case U'\u0132':
		return U"LATIN CAPITAL LIGATURE IJ";
	case U'\u0133':
		return U"LATIN SMALL LIGATURE IJ";
	case U'\u0134':
		return U"LATIN CAPITAL LETTER J WITH CIRCUMFLEX";
	case U'\u0135':
		return U"LATIN SMALL LETTER J WITH CIRCUMFLEX";
	case U'\u0136':
		return U"LATIN CAPITAL LETTER K WITH CEDILLA";
	case U'\u0137':
		return U"LATIN SMALL LETTER K WITH CEDILLA";
	case U'\u0138':
		return U"LATIN SMALL LETTER KRA";
	case U'\u0139':
		return U"LATIN CAPITAL LETTER L WITH ACUTE";
	case U'\u013A':
		return U"LATIN SMALL LETTER L WITH ACUTE";
	case U'\u013B':
		return U"LATIN CAPITAL LETTER L WITH CEDILLA";
	case U'\u013C':
		return U"LATIN SMALL LETTER L WITH CEDILLA";
	case U'\u013D':
		return U"LATIN CAPITAL LETTER L WITH CARON";
	case U'\u013E':
		return U"LATIN SMALL LETTER L WITH CARON";
	case U'\u013F':
		return U"LATIN CAPITAL LETTER L WITH MDDLE DOT";
	case U'\u0140':
		return U"LATIN SMALL LETTER L WITH MIDDLE DOT";
	case U'\u0141':
		return U"LATIN CAPITAL LETTER L WITH STROKE";
	case U'\u0142':
		return U"LATIN SMALL LETTER L WITH STROKE";
	case U'\u0143':
		return U"LATIN CAPITAL LETTER N WITH ACUTE";
	case U'\u0144':
		return U"LATIN SMALL LETTER N WITH ACUTE";
	case U'\u0145':
		return U"LATIN CAPITAL LETTER N WITH CEDILLA";
	case U'\u0146':
		return U"LATIN SMALL LETTER N WITH CEDILLA";
	case U'\u0147':
		return U"LATIN CAPITAL LETTER N WITH CARON";
	case U'\u0148':
		return U"LATIN SMALL LETTER N WITH CARON";
	case U'\u0149':
		return U"LATIN SMALL LETTER N PRECEDED BY APOSTROPHE";
	case U'\u014A':
		return U"LATIN CAPITAL LETTER ENG";
	case U'\u014B':
		return U"LATIN SMALL LETTER ENG";
	case U'\u014C':
		return U"LATIN CAPITAL LETTER O WITH MACRON";
	case U'\u014D':
		return U"LATIN SMALL LETTER O WITH MACRON";
	case U'\u014E':
		return U"LATIN CAPITAL LETTER O WITH BREVE";
	case U'\u014F':
		return U"LATIN SMALL LETTER O WITH BREVE";
	case U'\u0150':
		return U"LATIN CAPITAL LETTER O WITH DOUBLE ACUTE";
	case U'\u0160':
		return U"LATIN CAPITAL LETTER S WITH CARON";
	case U'\u0170':
		return U"LATIN CAPITAL LETTER U WITH DOUBLE ACUTE";
	/* LATIN EXTENDED-B: */
	case U'\u0180':
		return U"LATIN SMALL LETTER B WITH STROKE";
	case U'\u0190':
		return U"LATIN CAPITAL LETTER OPEN E";
	case U'\u01A0':
		return U"LATIN CAPITAL LETTER O WITH HORN";
	case U'\u01B0':
		return U"LATIN SMALL LETTER U WITH HORN";
	case U'\u01C0':
		return U"LATIN LETTER DENTAL CLICK";
	case U'\u01D0':
		return U"LATIN SMALL LETTER I WITH CARON";
	case U'\u01E0':
		return U"LATIN CAPITAL LETTER A WITH DOT ABOVE AND MACRON";
	case U'\u01F0':
		return U"LATIN SMALL LETTER J WITH CARON";
	case U'\u0200':
		return U"LATIN CAPITAL LETTER A WITH DOUBLE GRAVE";
	case U'\u0210':
		return U"LATIN CAPITAL LETTER R WITH DOUBLE GRAVE";
	case U'\u0220':
		return U"LATIN CAPITAL LETTER N WITH LONG RIGHT LEG";
	case U'\u0230':
		return U"LATIN CAPITAL LETTER O WITH DOT ABOVE AND MACRON";
	case U'\u0240':
		return U"LATIN SMALL LETTER Z WITH SWASH TAIL";
	/* IPA EXTENSIONS: */
	case U'\u0250':
		return U"LATIN SMALL LETTER TURNED A";
	case U'\u0251':
		return U"LATIN SMALL LETTER ALPHA";
	case U'\u0252':
		return U"LATIN SMALL LETTER TURNED ALPHA";
	case U'\u0253':
		return U"LATIN SMALL LETTER B WITH HOOK";
	case U'\u0254':
		return U"LATIN SMALL LETTER OPEN O";
	case U'\u0255':
		return U"LATIN SMALL LETTER C WITH CURL";
	case U'\u0256':
		return U"LATIN SMALL LETTER D WITH TAIL";
	case U'\u0257':
		return U"LATIN SMALL LETTER D WITH HOOK";
	case U'\u0258':
		return U"LATIN SMALL LETTER REVERSED E";
	case U'\u0259':
		return U"LATIN SMALL LETTER SCHWA";
	case U'\u025A':
		return U"LATIN SMALL LETTER SCHWA WITH HOOK";
	case U'\u025B':
		return U"LATIN SMALL LETTER OPEN E";
	case U'\u025C':
		return U"LATIN SMALL LETTER REVERSED OPEN E";
	case U'\u025D':
		return U"LATIN SMALL LETTER REVERSED OPEN E WITH HOOK";
	case U'\u025E':
		return U"LATIN SMALL LETTER CLOSED REVERSED OPEN E";
	case U'\u025F':
		return U"LATIN SMALL LETTER DOTLESS J WITH STROKE";
	case U'\u0260':
		return U"LATIN SMALL LETTER G WITH HOOK";
	case U'\u0261':
		return U"LATIN SMALL LETTER SCRIPT G";
	case U'\u0262':
		return U"LATIN LETTER SMALL CAPITAL G";
	case U'\u0263':
		return U"LATIN SMALL LETTER GAMMA";
	case U'\u0264':
		return U"LATIN SMALL LETTER RAMS HORN";
	case U'\u0265':
		return U"LATIN SMALL LETTER TURNED H";
	case U'\u0266':
		return U"LATIN SMALL LETTER H WITH HOOK";
	case U'\u0267':
		return U"LATIN SMALL LETTER HENG WITH HOOK";
	case U'\u0268':
		return U"LATIN SMALL LETTER I WITH STROKE";
	case U'\u0269':
		return U"LATIN SMALL LETTER IOTA";
	case U'\u026A':
		return U"LATIN LETTER SMALL CAPITAL I";
	case U'\u026B':
		return U"LATIN SMALL LETTER L WITH MIDDLE TILDE";
	case U'\u026C':
		return U"LATIN SMALL LETTER L WITH BELT";
	case U'\u026D':
		return U"LATIN SMALL LETTER L WITH RETROFLEX HOOK";
	case U'\u026E':
		return U"LATIN SMALL LETTER LEZH";
	case U'\u026F':
		return U"LATIN SMALL LETTER TURNED M";
	case U'\u0270':
		return U"LATIN SMALL LETTER TURNED M WITH LONG LEG";
	case U'\u0271':
		return U"LATIN SMALL LETTER M WITH HOOK";
	case U'\u0272':
		return U"LATIN SMALL LETTER N WITH LEFT HOOK";
	case U'\u0273':
		return U"LATIN SMALL LETTER N WITH RETROFLEX HOOK";
	case U'\u0274':
		return U"LATIN LETTER SMALL CAPITAL N";
	case U'\u0275':
		return U"LATIN SMALL LETTER BARRED O";
	case U'\u0276':
		return U"LATIN LETTER SMALL CAPITAL OE";
	case U'\u0277':
		return U"LATIN SMALL LETTER CLOSED OMEGA";
	case U'\u0278':
		return U"LATIN SMALL LETTER PHI";
	case U'\u0279':
		return U"LATIN SMALL LETTER TURNED R";
	case U'\u027A':
		return U"LATIN SMALL LETTER TURNED R WITH LONG LEG";
	case U'\u027B':
		return U"LATIN SMALL LETTER TURNED R WITH HOOK";
	case U'\u027C':
		return U"LATIN SMALL LETTER R WITH LONG LEG";
	case U'\u027D':
		return U"LATIN SMALL LETTER R WITH TAIL";
	case U'\u027E':
		return U"LATIN SMALL LETTER R WITH FISHHOOK";
	case U'\u027F':
		return U"LATIN SMALL LETTER REVERSED R WITH FISHHOOK";
	case U'\u0280':
		return U"LATIN LETTER SMALL CAPITAL R";
	case U'\u0281':
		return U"LATIN LETTER SMALL CAPITAL INVERTED R";
	case U'\u0282':
		return U"LATIN SMALL LETTER S WITH HOOK";
	case U'\u0283':
		return U"LATIN SMALL LETTER ESH";
	case U'\u0284':
		return U"LATIN SMALL LETTER DOTLESS J WITH STROKE AND HOOK";
	case U'\u0285':
		return U"LATIN SMALL LETTER SQUAT REVERSED ESH";
	case U'\u0286':
		return U"LATIN SMALL LETTER SH WITH CURL";
	case U'\u0287':
		return U"LATIN SMALL LETTER TURNED T";
	case U'\u0288':
		return U"LATIN SMALL LETTER T WITH RETROFLEX HOOK";
	case U'\u0289':
		return U"LATIN SMALL LETTER U BAR";
	case U'\u028A':
		return U"LATIN SMALL LETTER UPSILON";
	case U'\u028B':
		return U"LATIN SMALL LETTER V WTIH HOOK";
	case U'\u028C':
		return U"LATIN SMALL LETTER TURNED V";
	case U'\u028D':
		return U"LATIN SMALL LETTER TURNED W";
	case U'\u028E':
		return U"LATIN SMALL LETTER TURNED Y";
	case U'\u028F':
		return U"LATIN LETTER SMALL CAPITAL Y";
	case U'\u0290':
		return U"LATIN SMALL LETTER Z WITH RETROFLEX HOOK";
	case U'\u0291':
		return U"LATIN SMALL LETTER Z WITH RETROFLEX";
	case U'\u0292':
		return U"LATIN SMALL LETTER EZH";
	case U'\u0293':
		return U"LATIN SMALL LETTER EZH WITH CURL";
	case U'\u0294':
		return U"LATIN LETTER GLOTTAL STOP";
	case U'\u0295':
		return U"LATIN LETTER PHARYNGEAL VOICED FRICATIVE";
	case U'\u0296':
		return U"LATIN LETTER INVERTED GLOTTAL STOP";
	case U'\u0297':
		return U"LATIN LETTER STRETCHED C";
	case U'\u0298':
		return U"LATIN LETTER BILABIAL CLICK";
	case U'\u0299':
		return U"LATIN LETTER SMALL CAPITAL B";
	case U'\u029A':
		return U"LATIN SMALL LETTER CLOSED OPEN E";
	case U'\u029B':
		return U"LATIN LETTER SMALL CAPITAL G WITH HOOK";
	case U'\u029C':
		return U"LATIN LETTER SMALL CAPITAL H";
	case U'\u029D':
		return U"LATIN SMALL LETTER J WITH CROSSED-TAIL";
	case U'\u029E':
		return U"LATIN SMALL LETTER TURNED K";
	case U'\u029F':
		return U"LATIN LETTER SMALL CAPITAL L";
	case U'\u02A0':
		return U"LATIN SMALL LETTER Q WITH HOOK";
	case U'\u02A1':
		return U"LATIN LETTER GLOTTAL STOP WITH STROKE";
	case U'\u02A2':
		return U"LATIN LETTER REVERSED GLOTTAL STOP WITH STROKE";
	case U'\u02A3':
		return U"LATIN SMALL LETTER DZ DIGRAPH";
	case U'\u02A4':
		return U"LATIN SMALL LETTER DEZH DIGRAPH";
	case U'\u02A5':
		return U"LATIN SMALL LETTER DZ DIGRAPH WITH CURL";
	case U'\u02A6':
		return U"LATIN SMALL LETTER TS DIGRAPH";
	case U'\u02A7':
		return U"LATIN SMALL LETTER TESH DIGRAPH";
	case U'\u02A8':
		return U"LATIN SMALL LETTER TC DIGRAPH WITH CURL";
	case U'\u02A9':
		return U"LATIN SMALL LETTER FENG DIGRAPH";
	case U'\u02AA':
		return U"LATIN SMALL LETTER LS DIGRAPH";
	case U'\u02AB':
		return U"LATIN SMALL LETTER LZ DIGRAPH";
	case U'\u02AC':
		return U"LATIN LETTER BILABIAL PERCUSSIVE";
	case U'\u02AD':
		return U"LATIN LETTER BIDENTAL PERCUSSIVE";
	case U'\u02AE':
		return U"LATIN SMALL LETTER TURNED H WITH FISHHOOK";
	case U'\u02AF':
		return U"LATIN SMALL LETTER TURNED H WITH FISHHOOK AND TAIL";
	/* SPACING MODIFIER LETTERS: */
	case U'\u02B0':
		return U"MODIFIER LETTER SMALL H";
	case U'\u02B1':
		return U"MODIFIER LETTER SMALL H WITH HOOK";
	case U'\u02B2':
		return U"MODIFIER LETTER SMALL J";
	case U'\u02B3':
		return U"MODIFIER LETTER SMALL R";
	case U'\u02B4':
		return U"MODIFIER LETTER SMALL TURNED R";
	case U'\u02B5':
		return U"MODIFIER LETTER SMALL TURNED R WITH HOOK";
	case U'\u02B6':
		return U"MODIFIER LETTER SMALL CAPITAL INVERTED R";
	case U'\u02B7':
		return U"MODIFIER LETTER SMALL W";
	case U'\u02B8':
		return U"MODIFIER LETTER SMALL Y";
	case U'\u02B9':
		return U"MODIFIER LETTER PRIME";
	case U'\u02BA':
		return U"MODIFIER LETTER DOUBLE PRIME";
	case U'\u02BB':
		return U"MODIFIER LETTER TURNED COMMA";
	case U'\u02BC':
		return U"MODIFIER LETTER APOSTROPHE";
	case U'\u02BD':
		return U"MODIFIER LETTER REVERSED COMMA";
	case U'\u02BE':
		return U"MODIFIER LETTER RIGHT HALF RING";
	case U'\u02BF':
		return U"MODIFIER LETTER LEFT HALF RING";
	case U'\u02C0':
		return U"MODIFIER LETTER GLOTTAL STOP";
	case U'\u02C1':
		return U"MODIFIER LETTER REVERSED GLOTTAL STOP";
	case U'\u02C2':
		return U"MODIFIER LETTER LEFT ARROWHEAD";
	case U'\u02C3':
		return U"MODIFIER LETTER RIGHT ARROWHEAD";
	case U'\u02C4':
		return U"MODIFIER LETTER UP ARROWHEAD";
	case U'\u02C5':
		return U"MODIFIER LETTER DOWN ARROWHEAD";
	case U'\u02C6':
		return U"MODIFIER LETTER CIRCUMFLEX";
	case U'\u02C7':
		return U"CARON";
	case U'\u02C8':
		return U"MODIFIER LETTER VERTICAL LINE";
	case U'\u02C9':
		return U"MODIFIER LETTER MACRON";
	case U'\u02CA':
		return U"MODIFIER LETTER ACUTE ACCENT";
	case U'\u02CB':
		return U"MODIFIER LETTER GRAVE ACCENT";
	case U'\u02CC':
		return U"MODIFIER LETTER LOW VERTICAL LINE";
	case U'\u02CD':
		return U"MODIFIER LETTER LOW MACRON";
	case U'\u02CE':
		return U"MODIFIER LETTER LOW GRAVE ACCENT";
	case U'\u02CF':
		return U"MODIFIER LETTER LOW ACUTE ACCENT";
	case U'\u02D0':
		return U"MODIFIER LETTER TRIANGULAR COLON";
	case U'\u02D1':
		return U"MODIFIER LETTER HALF TRIANGULAR COLON";
	case U'\u02D2':
		return U"MODIFIER LETTER CENTRED RIGHT HALF RING";
	case U'\u02D3':
		return U"MODIFIER LETTER CENTRED LEFT HALF RING";
	case U'\u02D4':
		return U"MODIFIER LETTER UP TACK";
	case U'\u02D5':
		return U"MODIFIER LETTER DOWN TACK";
	case U'\u02D6':
		return U"MODIFIER LETTER PLUS SIGN";
	case U'\u02D7':
		return U"MODIFIER LETTER MINUS SIGN";
	case U'\u02D8':
		return U"BREVE";
	case U'\u02D9':
		return U"DOT ABOVE";
	case U'\u02DA':
		return U"RING ABOVE";
	case U'\u02DB':
		return U"OGONEK";
	case U'\u02DC':
		return U"SMALL TILDE";
	case U'\u02DD':
		return U"DOUBLE ACUTE ACCENT";
	case U'\u02DE':
		return U"MODIFIER LETTER RHOTIC HOOK";
	case U'\u02DF':
		return U"MODIFIER LETTER CROSS ACCENT";
	case U'\u02E0':
		return U"MODIFIER LETTER SMALL GAMMA";
	case U'\u02E1':
		return U"MODIFIER LETTER SMALL L";
	case U'\u02E2':
		return U"MODIFIER LETTER SMALL S";
	case U'\u02E3':
		return U"MODIFIER LETTER SMALL X";
	case U'\u02E4':
		return U"MODIFIER LETTER SMALL REVERSED GLOTTAL STOP";
	case U'\u02E5':
		return U"MODIFIER LETTER EXTRA-HIGH TONE BAR";
	case U'\u02E6':
		return U"MODIFIER LETTER HIGH TONE BAR";
	case U'\u02E7':
		return U"MODIFIER LETTER MID TONE BAR";
	case U'\u02E8':
		return U"MODIFIER LETTER LOW TONE BAR";
	case U'\u02E9':
		return U"MODIFIER LETTER EXTRA-LOW TONE BAR";
	case U'\u02EA':
		return U"MODIFIER LETTER YIN DEPARTING TONE MARK";
	case U'\u02EB':
		return U"MODIFIER LETTER YANG DEPARTING TONE MARK";
	case U'\u02EC':
		return U"MODIFIER LETTER VOICING";
	case U'\u02ED':
		return U"MODIFIER LETTER UNASPIRATED";
	case U'\u02EE':
		return U"MODIFIER LETTER DOUBLE APOSTROPHE";
	case U'\u02EF':
		return U"MODIFIER LETTER LOW DOWN ARROWHEAD";
	case U'\u02F0':
		return U"MODIFIER LETTER LOW UP ARROWHEAD";
	case U'\u02F1':
		return U"MODIFIER LETTER LOW LEFT ARROWHEAD";
	case U'\u02F2':
		return U"MODIFIER LETTER LOW RIGHT ARROWHEAD";
	case U'\u02F3':
		return U"MODIFIER LETTER LOW RING";
	case U'\u02F4':
		return U"MODIFIER LETTER MIDDLE GRAVE ACCENT";
	case U'\u02F5':
		return U"MODIFIER LETTER MIDDLE DOUBLE GRAVE ACCENT";
	case U'\u02F6':
		return U"MODIFIER LETTER MIDDLE DOUBLE ACUTE ACCENT";
	case U'\u02F7':
		return U"MODIFIER LETTER LOW TILDE";
	case U'\u02F8':
		return U"MODIFIER LETTER RAISED COLON";
	case U'\u02F9':
		return U"MODIFIER LETTER BEGIN HIGH TONE";
	case U'\u02FA':
		return U"MODIFIER LETTER END HIGH TONE";
	case U'\u02FB':
		return U"MODIFIER LETTER BEGIN LOW TONE";
	case U'\u02FC':
		return U"MODIFIER LETTER END LOW TONE";
	case U'\u02FD':
		return U"MODIFIER LETTER SHELF";
	case U'\u02FE':
		return U"MODIFIER LETTER OPEN SHELF";
	case U'\u02FF':
		return U"MODIFIER LETTER LOW LEFT ARROWHEAD";
	/* COMBINING DIACRITICAL MARKS: */
	case U'\u0300':
		return U"COMBINING GRAVE ACCENT";
	case U'\u0301':
		return U"COMBINING ACUTE ACCENT";
	case U'\u0302':
		return U"COMBINING CIRCUMFLEX ACCENT";
	case U'\u0303':
		return U"COMBINING TILDE";
	case U'\u0304':
		return U"COMBINING MACRON";
	case U'\u0305':
		return U"COMBINING OVERLINE";
	case U'\u0306':
		return U"COMBINING BREVE";
	case U'\u0307':
		return U"COMBINING DOT ABOVE";
	case U'\u0308':
		return U"COMBINING DIAERESIS";
	case U'\u0309':
		return U"COMBINING HOOK ABOVE";
	case U'\u030A':
		return U"COMBINING RING ABOVE";
	case U'\u030B':
		return U"COMBINING DOUBLE ACUTE ACCENT";
	case U'\u030C':
		return U"COMBINING CARON";
	case U'\u030D':
		return U"COMBINING VERTICAL LINE ABOVE";
	case U'\u030E':
		return U"COMBINING DOUBLE VERTICAL LINE ABOVE";
	case U'\u030F':
		return U"COMBINING DOUBLE GRAVE ACCENT";
	case U'\u0310':
		return U"COMBINING CANDRABINDU";
	case U'\u0311':
		return U"COMBINING INVERTED BREVE";
	case U'\u0312':
		return U"COMBINING TURNED COMMA ABOVE";
	case U'\u0313':
		return U"COMBINING COMMA ABOVE";
	case U'\u0314':
		return U"COMBINING REVERSED COMMA ABOVE";
	case U'\u0315':
		return U"COMBINING COMMA ABOVE RIGHT";
	case U'\u0316':
		return U"COMBINING GRAVE ACCENT BELOW";
	case U'\u0317':
		return U"COMBINING ACUTE ACCENT BELOW";
	case U'\u0318':
		return U"COMBINING LEFT TACK BELOW";
	case U'\u0319':
		return U"COMBINING RIGHT TACK BELOW";
	case U'\u031A':
		return U"COMBINING LEFT ANGLE ABOVE";
	case U'\u031B':
		return U"COMBINING HORN";
	case U'\u031C':
		return U"COMBINING LEFT HALF RING BELOW";
	case U'\u031D':
		return U"COMBINING UP TACK BELOW";
	case U'\u031E':
		return U"COMBINING DOWN TACK BELOW";
	case U'\u031F':
		return U"COMBINING PLUS SIGN BELOW";
	case U'\u0320':
		return U"COMBINING MINUS SIGN BELOW";
	case U'\u0321':
		return U"COMBINING PALATALIZED HOOK BELOW";
	case U'\u0322':
		return U"COMBINING RETROFLEX HOOK BELOW";
	case U'\u0323':
		return U"COMBINING DOT BELOW";
	case U'\u0324':
		return U"COMBINING DIAERESIS BELOW";
	case U'\u0325':
		return U"COMBINING RING BELOW";
	case U'\u0326':
		return U"COMBINING COMMA BELOW";
	case U'\u0327':
		return U"COMBINING CEDILLA";
	case U'\u0328':
		return U"COMBINING OGONEK";
	case U'\u0329':
		return U"COMBINING VERTICAL LINE BELOW";
	case U'\u032A':
		return U"COMBINING BRDIGE BELOW";
	case U'\u032B':
		return U"COMBINING INVERTED DOUBLE ARCH BELOW";
	case U'\u032C':
		return U"COMBINING CARON BELOW";
	case U'\u032D':
		return U"COMBINING CIRCUMFLEX ACCENT BELOW";
	case U'\u032E':
		return U"COMBINING BREVE BELOW";
	case U'\u032F':
		return U"COMBINING INVERTED BREVE BELOW";
	case U'\u0330':
		return U"COMBINING TILDE BELOW";
	case U'\u0331':
		return U"COMBINING MACRON BELOW";
	case U'\u0332':
		return U"COMBINING LOW LINE";
	case U'\u0333':
		return U"COMBINING DOUBLE LOW LINE";
	case U'\u0334':
		return U"COMBINING TILDE OVERLAY";
	case U'\u0335':
		return U"COMBINING SHORT STROKE OVERLAY";
	case U'\u0336':
		return U"COMBINING LONG STROKE OVERLAY";
	case U'\u0337':
		return U"COMBINING SHORT SOLIDUS OVERLAY";
	case U'\u0338':
		return U"COMBINING LONG SOLIDUS OVERLAY";
	case U'\u0339':
		return U"COMBINING RIGHT HALF RING BELOW";
	case U'\u033A':
		return U"COMBINING INVERTED BRIDGE BELOW";
	case U'\u033B':
		return U"COMBINING SQUARE BELOW";
	case U'\u033C':
		return U"COMBINING SEAGULL BELOW";
	case U'\u033D':
		return U"COMBINING X ABOVE";
	case U'\u033E':
		return U"COMBINING VERTICAL TILDE";
	case U'\u033F':
		return U"COMBINING DOUBLE OVERLINE";
	case U'\u0340':
		return U"COMBINING GRAVE TONE MARK";
	case U'\u0341':
		return U"COMBINING ACUTE TONE MARK";
	case U'\u0342':
		return U"COMBINING GREEK PERISPOMENI";
	case U'\u0343':
		return U"COMBINING GREEK KORONIS";
	case U'\u0344':
		return U"COMBINING GREEK DIALYTIKA TONOS";
	case U'\u0345':
		return U"COMBINING GREEK YPOGEGRAMMENI";
	case U'\u0346':
		return U"COMBINING BRIDGE ABOVE";
	case U'\u0347':
		return U"COMBINING EQUALS SIGN BELOW";
	case U'\u0348':
		return U"COMBINING DOUBLE VERTICAL LINE BELOW";
	case U'\u0349':
		return U"COMBINING LEFT ANGLE BELOW";
	case U'\u034A':
		return U"COMBINING NOT TILDE ABOVE";
	case U'\u034B':
		return U"COMBINING HOMOTHETIC ABOVE";
	case U'\u034C':
		return U"COMBINING ALMOST EQUAL TO ABOVE";
	case U'\u034D':
		return U"COMBINING LEFT RIGHT ARROW BELOW";
	case U'\u034E':
		return U"COMBINING UPWARDS ARROW BELOW";
	case U'\u034F':
		return U"COMBINING GRAPHEME JOINER";
	case U'\u0350':
		return U"COMBINING RIGHT ARROWHEAD ABOVE";
	case U'\u0351':
		return U"COMBINING LEFT HALF RING ABOVE";
	case U'\u0352':
		return U"COMBINING FERMATA";
	case U'\u0353':
		return U"COMBINING X BELOW";
	case U'\u0354':
		return U"COMBINING LEFT ARROWHEAD BELOW";
	case U'\u0355':
		return U"COMBINING RIGHT ARROWHEAD BELOW";
	case U'\u0356':
		return U"COMBINING RIGHT ARROWHEAD AND UP ARROWHEAD BELOW";
	case U'\u0357':
		return U"COMBINING RIGHT HALF RING ABOVE";
	case U'\u0358':
		return U"COMBINING DOT ABOVE RIGHT";
	case U'\u0359':
		return U"COMBINING ASTERISK BELOW";
	case U'\u035A':
		return U"COMBINING DOUBLE RING BELOW";
	case U'\u035B':
		return U"COMBINING ZIGZAG ABOVE";
	case U'\u035C':
		return U"COMBINING DOUBLE BREVE BELOW";
	case U'\u035D':
		return U"COMBINING DOUBLE BREVE";
	case U'\u035E':
		return U"COMBINING DOUBLE MACRON";
	case U'\u035F':
		return U"COMBINING DOUBLE MACRON BELOW";
	case U'\u0360':
		return U"COMBINING DOUBLE TILDE";
	case U'\u0361':
		return U"COMBINING DOUBLE INVERTED BREVE";
	case U'\u0362':
		return U"COMBINING DOUBLE RIGHTWARDS ARROW BELOW";
	case U'\u0363':
		return U"COMBINING LATIN SMALL LETTER A";
	case U'\u0364':
		return U"COMBINING LATIN SMALL LETTER E";
	case U'\u0365':
		return U"COMBINING LATIN SMALL LETTER I";
	case U'\u0366':
		return U"COMBINING LATIN SMALL LETTER O";
	case U'\u0367':
		return U"COMBINING LATIN SMALL LETTER U";
	case U'\u0368':
		return U"COMBINING LATIN SMALL LETTER C";
	case U'\u0369':
		return U"COMBINING LATIN SMALL LETTER D";
	case U'\u036A':
		return U"COMBINING LATIN SMALL LETTER H";
	case U'\u036B':
		return U"COMBINING LATIN SMALL LETTER M";
	case U'\u036C':
		return U"COMBINING LATIN SMALL LETTER R";
	case U'\u036D':
		return U"COMBINING LATIN SMALL LETTER T";
	case U'\u036E':
		return U"COMBINING LATIN SMALL LETTER V";
	case U'\u036F':
		return U"COMBINING LATIN SMALL LETTER X";
	/* GREEK AND COPTIC: */
	case U'\u0370':
		return U"GREEK CAPITAL LETTER HETA";
	case U'\u0371':
		return U"GREEK SMALL LETTER HETA";
	case U'\u0372':
		return U"GREEK CAPITAL LETTER ARCHAIC SAMPI";
	case U'\u0373':
		return U"GREEK SMALL LETTER ARCHAIC SAMPI";
	case U'\u0374':
		return U"GREEK NUMERAL SIGN";
	case U'\u0375':
		return U"GREEK LOWER NUMERAL SIGN";
	case U'\u0376':
		return U"GREEK CAPITAL LETTER PAMPHYLIAN DIGAMMA";
	case U'\u0377':
		return U"GREEK SMALL LETTER PAMPHYLIAN DIGAMMA";
	case U'\u037A':
		return U"GREEK YPOGEGRAMMENI";
	case U'\u037B':
		return U"GREEK SMALL REVERSED LUNATE SIGMA SYMBOL";
	case U'\u037C':
		return U"GREEK SMALL DOTTED LUNATE SIGMA SYMBOL";
	case U'\u037D':
		return U"GREEK SMALL REVERSED DOTTED LUNATE SIGMAL SYMBOL";
	case U'\u037E':
		return U"GREEK QUESTION MARK";
	case U'\u037F':
		return U"GREEK CAPITAL LETTER YOT";
	case U'\u0384':
		return U"GREEK TONOS";
	case U'\u0385':
		return U"GREEK DIALYTIKA TONOS";
	case U'\u0386':
		return U"GREEK CAPITAL LETTER ALPHA WITH TONOS";
	case U'\u0387':
		return U"GREEK ANO TELEIA";
	case U'\u0388':
		return U"GREEK CAPITAL LETTER EPSILON WITH TONOS";
	case U'\u0389':
		return U"GREEK CAPITAL LETTER ETA WITH TONOS";
	case U'\u038A':
		return U"GREEK CAPITAL LETTER IOTA WITH TONOS";
	case U'\u038C':
		return U"GREEK CAPITAL LETTER OMICRON WITH TONOS";
	case U'\u038E':
		return U"GREEK CAPITAL LETTER USPILON WITH TONOS";
	case U'\u038F':
		return U"GREEK CAPITAL LETTER OMEGA WITH TONOS";
	case U'\u0390':
		return U"GREEK SMALL LETTER IOTA WITH DIALYTIKA AND TONOS";
	case U'\u0391':
		return U"GREEK CAPITAL LETTER ALPHA";
	case U'\u0392':
		return U"GREEK CAPITAL LETTER BETA";
	case U'\u0393':
		return U"GREEK CAPITAL LETTER GAMMA";
	case U'\u0394':
		return U"GREEK CAPITAL LETTER DELTA";
	case U'\u0395':
		return U"GREEK CAPITAL LETTER EPSILON";
	case U'\u0396':
		return U"GREEK CAPITAL LETTER ZETA";
	case U'\u0397':
		return U"GREEK CAPITAL LETTER ETA";
	case U'\u0398':
		return U"GREEK CAPITAL LETTER THETA";
	case U'\u0399':
		return U"GREEK CAPITAL LETTER IOTA";
	case U'\u039A':
		return U"GREEK CAPITAL LETTER KAPPA";
	case U'\u039B':
		return U"GREEK CAPITAL LETTER LAMBDA";
	case U'\u039C':
		return U"GREEK CAPITAL LETTER MU";
	case U'\u039D':
		return U"GREEK CAPITAL LETTER NU";
	case U'\u039E':
		return U"GREEK CAPITAL LETTER XI";
	case U'\u039F':
		return U"GREEK CAPITAL LETTER OMICRON";
	case U'\u03A0':
		return U"GREEK CAPITAL LETTER PI";
	case U'\u03A1':
		return U"GREEK CAPITAL LETTER RHO";
	case U'\u03A3':
		return U"GREEK CAPITAL LETTER SIGMA";
	case U'\u03A4':
		return U"GREEK CAPITAL LETTER TAU";
	case U'\u03A5':
		return U"GREEK CAPITAL LETTER UPSILON";
	case U'\u03A6':
		return U"GREEK CAPITAL LETTER PHI";
	case U'\u03A7':
		return U"GREEK CAPITAL LETTER CHI";
	case U'\u03A8':
		return U"GREEK CAPITAL LETTER PSI";
	case U'\u03A9':
		return U"GREEK CAPITAL LETTER OMEGA";
	case U'\u03AA':
		return U"GREEK CAPITAL LETTER IOTA WITH DIALYTIKA";
	case U'\u03AB':
		return U"GREEK CAPITAL LETTER UPSILON WITH DIALYTIKA";
	case U'\u03AC':
		return U"GREEK SMALL LETTER ALPHA WITH TONOS";
	case U'\u03AD':
		return U"GREEK SMALL LETTER EPSILON WITH TONOS";
	case U'\u03AE':
		return U"GREEK SMALL LETTER ETA WITH TONOS";
	case U'\u03AF':
		return U"GREEK SMALL LETTER IOTA WITH TONOS";
	case U'\u03B0':
		return U"GREEK SMALL LETTER UPSILON WITH DIALYTIKA AND TONOS";
	case U'\u03B1':
		return U"GREEK SMALL LETTER ALPHA";
	case U'\u03B2':
		return U"GREEK SMALL LETTER BETA";
	case U'\u03B3':
		return U"GREEK SMALL LETTER GAMMA";
	case U'\u03B4':
		return U"GREEK SMALL LETTER DELTA";
	case U'\u03B5':
		return U"GREEK SMALL LETTER EPSILON";
	case U'\u03B6':
		return U"GREEK SMALL LETTER ZETA";
	case U'\u03B7':
		return U"GREEK SMALL LETTER ETA";
	case U'\u03B8':
		return U"GREEK SMALL LETTER THETA";
	case U'\u03B9':
		return U"GREEK SMALL LETTER IOTA";
	case U'\u03BA':
		return U"GREEK SMALL LETTER KAPPA";
	case U'\u03BB':
		return U"GREEK SMALL LETTER LAMBDA";
	case U'\u03BC':
		return U"GREEK SMALL LETTER MU";
	case U'\u03BD':
		return U"GREEK SMALL LETTER NU";
	case U'\u03BE':
		return U"GREEK SMALL LETTER XI";
	case U'\u03BF':
		return U"GREEK SMALL LETTER OMICRON";
	case U'\u03C0':
		return U"GREEK SMALL LETTER PI";
	case U'\u03C1':
		return U"GREEK SMALL LETTER RHO";
	case U'\u03C2':
		return U"GREEK SMALL LETTER FINAL SIGMA";
	case U'\u03C3':
		return U"GREEK SMALL LETTER SIGMA";
	case U'\u03C4':
		return U"GREEK SMALL LETTER TAU";
	case U'\u03C5':
		return U"GREEK SMALL LETTER UPSILON";
	case U'\u03C6':
		return U"GREEK SMALL LETTER PHI";
	case U'\u03C7':
		return U"GREEK SMALL LETTER CHI";
	case U'\u03C8':
		return U"GREEK SMALL LETTER PSI";
	case U'\u03C9':
		return U"GREEK SMALL LETTER OMEGA";
	case U'\u03CA':
		return U"GREEK SMALL LETTER IOTA WITH DIALYTIKA";
	case U'\u03CB':
		return U"GREEK SMALL LETTER UPSILON WITH DIALYTIKA";
	case U'\u03CC':
		return U"GREEK SMALL LETTER OMICRON WITH TONOS";
	case U'\u03CD':
		return U"GREEK SMALL LETTER UPSILON WITH TONOS";
	case U'\u03CE':
		return U"GREEK SMALL LETTER OMEGA WITH TONOS";
	case U'\u03CF':
		return U"GREEK CAPITAL KAI SYMBOL";
	case U'\u03D0':
		return U"GREEK BETA SYMBOL";
	case U'\u03D1':
		return U"GREEK THETA SYMBOL";
	case U'\u03D2':
		return U"GREEK UPSILON WITH HOOK SYMBOL";
	case U'\u03D3':
		return U"GREEK UPSILON WITH ACUTE AND HOOK SYMBOL";
	case U'\u03D4':
		return U"GREEK UPSILON WITH DIAERESIS AND HOOK SYMBOL";
	case U'\u03D5':
		return U"GREEK PHI SYMBOL";
	case U'\u03D6':
		return U"GREEK PI SYMBOL";
	case U'\u03D7':
		return U"GREEK KAI SYMBOL";
	case U'\u03D8':
		return U"GREEK LETTER ARCHAIC KOPPA";
	case U'\u03D9':
		return U"GREEK SMALL LETTER ARCHAIC KOPPA";
	case U'\u03DA':
		return U"GREEK LETTER STIGMA";
	case U'\u03DB':
		return U"GREEK SMALL LETTER STIGMA";
	case U'\u03DC':
		return U"GREEK LETTER DIGAMMA";
	case U'\u03DD':
		return U"GREEK SMALL LETTER DIGAMMA";
	case U'\u03DE':
		return U"GREEK LETTER KOPPA";
	case U'\u03DF':
		return U"GREEK SMALL LETTER KOPPA";
	case U'\u03E0':
		return U"GREEK LETTER SAMPI";
	case U'\u03F0':
		return U"GREEK KAPPA SYMBOL";
	/* HEBREW: */
	case U'\u05D0':
		return U"HEBREW LETTER ALEF";
	case U'\u05D1':
		return U"HEBREW LETTER BET";
	case U'\u05D2':
		return U"HEBREW LETTER GIMEL";
	case U'\u05D3':
		return U"HEBREW LETTER DALET";
	case U'\u05D4':
		return U"HEBREW LETTER HE";
	case U'\u05D5':
		return U"HEBREW LETTER VAV";
	case U'\u05D6':
		return U"HEBREW LETTER ZAYIN";
	case U'\u05D7':
		return U"HEBREW LETTER HET";
	case U'\u05D8':
		return U"HEBREW LETTER TET";
	case U'\u05D9':
		return U"HEBREW LETTER YOD";
	case U'\u05DA':
		return U"HEBREW LETTER FINAL KAF";
	case U'\u05DB':
		return U"HEBREW LETTER KAF";
	case U'\u05DC':
		return U"HEBREW LETTER LAMED";
	case U'\u05DD':
		return U"HEBREW LETTER FINAL MEM";
	case U'\u05DE':
		return U"HEBREW LETTER MEM";
	case U'\u05DF':
		return U"HEBREW LETTER FINAL NUN";
	case U'\u05E0':
		return U"HEBREW LETTER NUN";
	case U'\u05E1':
		return U"HEBREW LETTER SAMEKH";
	case U'\u05E2':
		return U"HEBREW LETTER AYIN";
	case U'\u05E3':
		return U"HEBREW LETTER FINAL PE";
	case U'\u05E4':
		return U"HEBREW LETTER PE";
	case U'\u05E5':
		return U"HEBREW LETTER FINAL TSADI";
	case U'\u05E6':
		return U"HEBREW LETTER TSADI";
	case U'\u05E7':
		return U"HEBREW LETTER QOF";
	case U'\u05E8':
		return U"HEBREW LETTER RESH";
	case U'\u05E9':
		return U"HEBREW LETTER SHIN";
	case U'\u05EA':
		return U"HEBREW LETTER TAV";
	case U'\u05EF':
		return U"HEBREW YOD TRIANGLE";
	/* CYRILLIC: */
	case U'\u0400':
		return U"CYRILLIC CAPITAL LETTER LE WITH GRAVE";
	case U'\u0401':
		return U"CYRILLIC CAPITAL LETTER LO";
	case U'\u0402':
		return U"CYRILLIC CAPITAL LETTER DJE";
	case U'\u0403':
		return U"CYRILLIC CAPITAL LETTER GJE";
	case U'\u0404':
		return U"CYRILLIC CAPITAL LETTER UKRAINIAN LE";
	case U'\u0405':
		return U"CYRILLIC CAPITAL LETTER DZE";
	case U'\u0406':
		return U"CYRILLIC CAPITAL LETTER BYELORUSSIAN-UKRAINIAN I";
	case U'\u0407':
		return U"CYRILLIC CAPITAL LETTER YI";
	case U'\u0408':
		return U"CYRILLIC CAPITAL LETTER JE";
	case U'\u0409':
		return U"CYRILLIC CAPITAL LETTER LJE";
	case U'\u040A':
		return U"CYRILLIC CAPITAL LETTER NJE";
	case U'\u040B':
		return U"CYRILLIC CAPITAL LETTER TSHE";
	case U'\u040C':
		return U"CYRILLIC CAPITAL LETTER KJE";
	case U'\u040D':
		return U"CYRILLIC CAPITAL LETTER I WITH GRAVE";
	case U'\u040E':
		return U"CYRILLIC CAPITAL LETTER SHORT U";
	case U'\u040F':
		return U"CYRILLIC CAPITAL LETTER DZHE";
	case U'\u0410':
		return U"CYRILLIC CAPITAL LETTER A";
	case U'\u0420':
		return U"CYRILLIC CAPITAL LETTER ER";
	case U'\u0430':
		return U"CYRILLIC SMALL LETTER A";
	case U'\u0440':
		return U"CYRILLIC SMALL LETTER ER";
	case U'\u0450':
		return U"CYRILLIC SMALL LETTER LE WITH GRAVE";
	case U'\u0460':
		return U"CYRILLIC CAPITAL LETTER OMEGA";
	case U'\u0470':
		return U"CYRILLIC CAPITAL LETTER PSI";
	case U'\u0480':
		return U"CYRILLIC CAPITAL LETTER KOPPA";
	case U'\u0490':
		return U"CYRILLIC CAPITAL LETTER GHE WITH UPTURN";
	case U'\u04A0':
		return U"CYRILLIC CAPITAL LETTER BASHKIR KA";
	case U'\u04B0':
		return U"CYRILLIC CAPITAL LETTER STRAIGHT U WITH STROKE";
	case U'\u04C0':
		return U"CYRILLIC LETTER PALOCHKA";
	case U'\u04D0':
		return U"CYRILLIC CAPITAL LETTER A WITH BREVE";
	case U'\u04E0':
		return U"CYRILLIC CAPITAL LETTER ABKHASIAN DZE";
	case U'\u04F0':
		return U"CYRILLIC CAPITAL LETTER U WITH DIAERESIS";
	/* SYRIAC SUPPLEMENT: */
	case U'\u0860':
		return U"SYRIAC LETTER MALAYALAM NGA";
	case U'\u0861':
		return U"SYRIAC LETTER MALAYALAM JA";
	case U'\u0862':
		return U"SYRIAC LETTER MALAYALAM NYA";
	case U'\u0863':
		return U"SYRIAC LETTER MALAYALAM TTA";
	case U'\u0864':
		return U"SYRIAC LETTER MALAYALAM NNA";
	case U'\u0865':
		return U"SYRIAC LETTER MALAYALAM NNNA";
	case U'\u0866':
		return U"SYRIAC LETTER MALAYALAM BHA";
	case U'\u0867':
		return U"SYRIAC LETTER MALAYALAM RA";
	case U'\u0868':
		return U"SYRIAC LETTER MALAYALAM LLA";
	case U'\u0869':
		return U"SYRIAC LETTER MALAYALAM LLLA";
	case U'\u086A':
		return U"SYRIAC LETTER MALAYALAM SSA";
	/* RUNIC: */
	case U'\u16A0':
		return U"RUNIC LETTER FEHU FEOH FE F";
	case U'\u16A1':
		return U"RUNIC LETTER V";
	case U'\u16A2':
		return U"RUNIC LETTER URUZ UR U";
	case U'\u16A3':
		return U"RUNIC LETTER YR";
	case U'\u16A4':
		return U"RUNIC LETTER Y";
	case U'\u16A5':
		return U"RUNIC LETTER W";
	case U'\u16A6':
		return U"RUNIC LETTER THURISAZ THURS THORN";
	case U'\u16A7':
		return U"RUNIC LETTER ETH";
	case U'\u16A8':
		return U"RUNIC LETTER ANSUZ A";
	case U'\u16A9':
		return U"RUNIC LETTER OS O";
	case U'\u16AA':
		return U"RUNIC LETTER AC A";
	case U'\u16AB':
		return U"RUNIC LETTER AESC";
	case U'\u16AC':
		return U"RUNIC LETTER LONG-BRANCHED-OSS O";
	case U'\u16AD':
		return U"RUNIC LETTER SHORT-TWIG-OSS O";
	case U'\u16AE':
		return U"RUNIC LETTER O";
	case U'\u16AF':
		return U"RUNIC LETTER OE";
	case U'\u16B0':
		return U"RUNIC LETTER ON";
	case U'\u16C0':
		return U"RUNIC LETTER DOTTED-N";
	case U'\u16D0':
		return U"RUNIC LETTER SHORT-TWIG-TYR T";
	case U'\u16E0':
		return U"RUNIC LETTER EAR";
	case U'\u16F0':
		return U"RUNIC BELGTHOR SYMBOL";
	/* CYRILLIC EXTENDED C: */
	case U'\u1C80':
		return U"CYRILLIC SMALL LETTER ROUNDED VE";
	case U'\u1C81':
		return U"CYRILLIC SMALL LETTER LONG-LEGGED DE";
	case U'\u1C82':
		return U"CYRILLIC SMALL LETTER NARROW O";
	case U'\u1C83':
		return U"CYRILLIC SMALL LETTER WIDE ES";
	case U'\u1C84':
		return U"CYRILLIC SMALL LETTER TALL TE";
	case U'\u1C85':
		return U"CYRILLIC SMALL LETTER THREE-LEGGED TE";
	case U'\u1C86':
		return U"CYRILLIC SMALL LETTER TALL HARD SIGN";
	case U'\u1C87':
		return U"CYRILLIC SMALL LETTER TALL YAT";
	case U'\u1C88':
		return U"CYRILLIC SMALL LETTER UNBLENDED UK";
	/* GENERAL PUNCTUATION: */
	case U'\u2000':
		return U"EN QUAD";
	case U'\u2001':
		return U"EM QUAD";
	case U'\u2002':
		return U"EN SPACE";
	case U'\u2003':
		return U"EM SPACE";
	case U'\u2004':
		return U"THREE-PER-EM SPACE";
	case U'\u2005':
		return U"FOUR-PER-EM SPACE";
	case U'\u2006':
		return U"SIX-PER-EM SPACE";
	case U'\u2007':
		return U"FIGURE SPACE";
	case U'\u2008':
		return U"PUNCTUATION SPACE";
	case U'\u2009':
		return U"THIN SPACE";
	case U'\u200A':
		return U"HAIR SPACE";
	case U'\u203C':
		return U"DOUBLE EXCLAMATION MARK";
	case U'\u2047':
		return U"DOUBLE QUOTATION MARK";
	case U'\u2048':
		return U"QUESTION EXCLAMATION MARK";
	case U'\u2049':
		return U"EXCLAMATION QUESTION MARK";
	/* CURRENCY SYMBOLS: */
	case U'\u20A0':
		return U"EURO-CURRENCY SIGN";
	case U'\u20A1':
		return U"COLON SIGN";
	case U'\u20A2':
		return U"CRUZEIRO SIGN";
	case U'\u20A3':
		return U"FRENCH FRANC SIGN";
	case U'\u20A4':
		return U"LIRA SIGN";
	case U'\u20A5':
		return U"MILL SIGN";
	case U'\u20A6':
		return U"NAIRA SIGN";
	case U'\u20A7':
		return U"PESETA SIGN";
	case U'\u20A8':
		return U"RUPEE SIGN";
	case U'\u20A9':
		return U"WON SIGN";
	case U'\u20AA':
		return U"NEW SHEQEL SIGN";
	case U'\u20AB':
		return U"DONG SIGN";
	case U'\u20AC':
		return U"EURO SIGN";
	case U'\u20AD':
		return U"KIP SIGN";
	case U'\u20AE':
		return U"TUGRIK SIGN";
	case U'\u20AF':
		return U"DRACHMA SIGN";
	case U'\u20B0':
		return U"GERMAN PENNY SIGN";
	case U'\u20B1':
		return U"PESO SIGN";
	case U'\u20B2':
		return U"GUARANI SIGN";
	case U'\u20B3':
		return U"AUSTRAL SIGN";
	case U'\u20B4':
		return U"HRYVNIA SIGN";
	case U'\u20B5':
		return U"CEDI SIGN";
	case U'\u20B6':
		return U"LIVRE TOURNOIS SIGN";
	case U'\u20B7':
		return U"SPESMILO SIGN";
	case U'\u20B8':
		return U"TENGE SIGN";
	case U'\u20BA':
		return U"TURKISH LIRA SIGN";
	case U'\u20BB':
		return U"NORDIC MARK SIGN";
	case U'\u20BC':
		return U"MANAT SIGN";
	case U'\u20BD':
		return U"RUBLE SYMBOL";
	case U'\u20BE':
		return U"LARI SIGN";
	case U'\u20BF':
		return U"BITCOIN SIGN";
	/* LETTERLIKE SYMBOLS: */
	case U'\u2100':
		return U"ACCOUNT OF";
	case U'\u2101':
		return U"ADRESSED TO THE SUBJECT";
	case U'\u2102':
		return U"DOUBLE-STRUCK CAPITAL C";
	case U'\u2103':
		return U"DEGREE CELSIUS";
	case U'\u2104':
		return U"CENTRE LINE SYMBOL";
	case U'\u2105':
		return U"CARE OF";
	case U'\u2106':
		return U"CADA UNA";
	case U'\u2107':
		return U"EULER CONSTANT";
	case U'\u2108':
		return U"SCRUPLE";
	case U'\u2109':
		return U"DEGREE FAHRENHEIT";
	case U'\u210A':
		return U"SCRIPT SMALL G";
	case U'\u210B':
		return U"SCRIPT CAPITAL H";
	case U'\u210C':
		return U"BLACK-LETTER CAPITAL H";
	case U'\u210D':
		return U"DOUBLE-STRUCK CAPITAL H";
	case U'\u210E':
		return U"PLANCK CONSTANT";
	case U'\u210F':
		return U"PLANCK CONSTANT OVER TWO PI";
	case U'\u2110':
		return U"SCRIPT CAPITAL I";
	case U'\u2111':
		return U"BLACK-LETTER CAPITAL I";
	case U'\u2112':
		return U"SCRIPT CAPITAL L";
	case U'\u2113':
		return U"SCRIPT SMALL L";
	case U'\u2114':
		return U"L B BAR SYMBOL";
	case U'\u2115':
		return U"DOUBLE-STRUCK CAPITAL N";
	case U'\u2116':
		return U"NUMERO SIGN";
	case U'\u2117':
		return U"SOUND RECORDING COPYRIGHT";
	case U'\u2118':
		return U"SCRIPT CAPITAL P";
	case U'\u2119':
		return U"DOUBLE-STRUCK CAPITAL P";
	case U'\u211A':
		return U"DOUBLE-STRUCK CAPITAL Q";
	case U'\u211B':
		return U"SCRIPT CAPITAL R";
	case U'\u211C':
		return U"BLACK-LETTER CAPITAL R";
	case U'\u211D':
		return U"DOUBLE-STRUCK CAPITAL R";
	case U'\u211E':
		return U"PRESCRIPTION TAKE";
	case U'\u211F':
		return U"RESPONSE";
	case U'\u2120':
		return U"SERVICE MARK";
	case U'\u2121':
		return U"TELEPHONE SIGN";
	case U'\u2122':
		return U"TRADE MARK SIGN";
	case U'\u2123':
		return U"VERSICLE";
	case U'\u2124':
		return U"DOUBLE-STRUCK CAPITAL Z";
	case U'\u2125':
		return U"OUNCE SIGN";
	case U'\u2126':
		return U"OHM SIGN";
	case U'\u2127':
		return U"INVERTED OHM SIGN";
	case U'\u2128':
		return U"BLACK-LETTER CAPITAL Z";
	case U'\u2129':
		return U"TURNED GREEK SMALL LETTER IOTA";
	case U'\u212A':
		return U"KELVIN SIGN";
	case U'\u212B':
		return U"ANGSTROM SIGN";
	case U'\u212C':
		return U"SCRIPT CAPITAL B";
	case U'\u212D':
		return U"BLACK-LETTER CAPITAL C";
	case U'\u212E':
		return U"ESTIMATED SYMBOL";
	case U'\u212F':
		return U"SCRIPT SMALL E";
	case U'\u2130':
		return U"SCRIPT CAPITAL E";
	case U'\u2131':
		return U"SCRIPT CAPITAL F";
	case U'\u2132':
		return U"TURNED CAPITAL F";
	case U'\u2133':
		return U"SCRIPT CAPITAL M";
	case U'\u2134':
		return U"SCRIPT SMALL O";
	case U'\u2135':
		return U"ALEF SYMBOL";
	case U'\u2136':
		return U"BET SYMBOL";
	case U'\u2137':
		return U"GIMEL SYMBOL";
	case U'\u2138':
		return U"DALET SYMBOL";
	case U'\u2139':
		return U"INFORMATION SOURCE";
	case U'\u213A':
		return U"ROTATED CAPITAL Q";
	case U'\u213B':
		return U"FACSIMILE SIGN";
	case U'\u213C':
		return U"DOUBLE-STRUCK SMALL PI";
	case U'\u213D':
		return U"DOUBLE-STRUCK SMALL GAMMA";
	case U'\u213E':
		return U"DOUBLE-STRUCK CAPITAL GAMMA";
	case U'\u213F':
		return U"DOUBLE-STRUCK CAPITAL PI";
	case U'\u2140':
		return U"DOUBLE-STRUCK N-ARY SUMMATION";
	case U'\u2141':
		return U"TURNED SANS-SERIF CAPITAL G";
	case U'\u2142':
		return U"TURNED SANS-SERIF CAPITAL L";
	case U'\u2143':
		return U"REVERSED SANS-SERIF CAPITAL L";
	case U'\u2144':
		return U"TURNED SANS-SERIF CAPITAL Y";
	case U'\u2145':
		return U"DOUBLE-STRUCK ITALIC CAPITAL D";
	case U'\u2146':
		return U"DOUBLE-STRUCK ITALIC SMALL D";
	case U'\u2147':
		return U"DOUBLE-STRUCK ITALIC SMALL E";
	case U'\u2148':
		return U"DOUBLE-STRUCK ITALIC SMALL I";
	case U'\u2149':
		return U"DOUBLE-STRUCK ITALIC SMALL J";
	case U'\u214A':
		return U"PROPERTY LINE";
	case U'\u214B':
		return U"TURNED AMPERSAND";
	case U'\u214C':
		return U"PER SIGN";
	case U'\u214D':
		return U"AKTIESELSKAB";
	case U'\u214E':
		return U"TURNED SMALL F";
	case U'\u214F':
		return U"SYMBOL FOR SAMARITAN SOURCE";
	/* NUMBER FORMS: */
	case U'\u2150':
		return U"VULGAR FRACTION ONE SEVENTH";
	case U'\u2151':
		return U"VULGAR FRACTION ONE NINTH";
	case U'\u2152':
		return U"VULGAR FRACTION ONE TENTH";
	case U'\u2153':
		return U"VULGAR FRACTION ONE THIRD";
	case U'\u2154':
		return U"VULGAR FRACTION TWO THIRDS";
	case U'\u2155':
		return U"VULGAR FRACTION ONE FIFTH";
	case U'\u2156':
		return U"VULGAR FRACTION TWO FIFTHS";
	case U'\u2157':
		return U"VULGAR FRACTION THREE FIFTHS";
	case U'\u2158':
		return U"VULGAR FRACTION FOUR FIFTHS";
	case U'\u2159':
		return U"VULGAR FRACTION ONE SIXTH";
	case U'\u215A':
		return U"VULGAR FRACTION FIVE SIXTHS";
	case U'\u215B':
		return U"VULGAR FRACTION ONE EIGTH";
	case U'\u215C':
		return U"VULGAR FRACTION THREE EIGTHS";
	case U'\u215D':
		return U"VULGAR FRACTION FIVE EIGHTS";
	case U'\u215E':
		return U"VULGAR FRACTION SEVEN EIGTHS";
	case U'\u215F':
		return U"FRACTION NUMERATOR ONE";
	case U'\u2160':
		return U"ROMAN NUMERAL ONE";
	case U'\u2161':
		return U"ROMAN NUMERAL TWO";
	case U'\u2162':
		return U"ROMAN NUMERAL THREE";
	case U'\u2163':
		return U"ROMAN NUMERAL FOUR";
	case U'\u2164':
		return U"ROMAN NUMERAL FIVE";
	case U'\u2165':
		return U"ROMAN NUMERAL SIX";
	case U'\u2166':
		return U"ROMAN NUMERAL SEVEN";
	case U'\u2167':
		return U"ROMAN NUMERAL EIGHT";
	case U'\u2168':
		return U"ROMAN NUMERAL NINE";
	case U'\u2169':
		return U"ROMAN NUMERAL TEN";
	case U'\u216A':
		return U"ROMAN NUMERAL ELEVEN";
	case U'\u216B':
		return U"ROMAN NUMERAL TWELVE";
	case U'\u216C':
		return U"ROMAN NUMERAL FIFTY";
	case U'\u216D':
		return U"ROMAN NUMERAL ONE HUNDRED";
	case U'\u216E':
		return U"ROMAN NUMERAL FIVE HUNDRED";
	case U'\u216F':
		return U"ROMAN NUMERAL ONE THOUSAND";
	case U'\u2170':
		return U"SMALL ROMAN NUMERAL ONE";
	case U'\u2171':
		return U"SMALL ROMAN NUMERAL TWO";
	case U'\u2172':
		return U"SMALL ROMAN NUMERAL THREE";
	case U'\u2173':
		return U"SMALL ROMAN NUMERAL FOUR";
	case U'\u2174':
		return U"SMALL ROMAN NUMERAL FIVE";
	case U'\u2175':
		return U"SMALL ROMAN NUMERAL SIX";
	case U'\u2176':
		return U"SMALL ROMAN NUMERAL SEVEN";
	case U'\u2177':
		return U"SMALL ROMAN NUMERAL EIGHT";
	case U'\u2178':
		return U"SMALL ROMAN NUMERAL NINE";
	case U'\u2179':
		return U"SMALL ROMAN NUMERAL TEN";
	case U'\u217A':
		return U"SMALL ROMAN NUMERAL ELEVEN";
	case U'\u217B':
		return U"SMALL ROMAN NUMERAL TWELVE";
	case U'\u217C':
		return U"SMALL ROMAN NUMERAL FIFTY";
	case U'\u217D':
		return U"SMALL ROMAN NUMERAL ONE HUNDRED";
	case U'\u217E':
		return U"SMALL ROMAN NUMERAL FIVE HUNDRED";
	case U'\u217F':
		return U"SMALL ROMAN NUMERAL ONE THOUSAND";
	case U'\u2180':
		return U"ROMAN NUMERAL ONE THOUSAND C D";
	case U'\u2181':
		return U"ROMAN NUMERAL FIVE THOUSAND";
	case U'\u2182':
		return U"ROMAN NUMERAL TEN THOUSAND";
	case U'\u2183':
		return U"ROMAN NUMERAL REVERSED ONE HUNDRED";
	case U'\u2184':
		return U"LATIN SMALL LETTER REVERSED C";
	case U'\u2185':
		return U"ROMAN NUMERAL SIX LATE FORM";
	case U'\u2186':
		return U"ROMAN NUMERAL FIFTY EARLY FORM";
	case U'\u2187':
		return U"ROMAN NUMERAL FIFTY THOUSAND";
	case U'\u2188':
		return U"ROMAN NUMERAL ONE HUNDRED THOUSAND";
	case U'\u2189':
		return U"VULGAR FRACTION ZERO THIRDS";
	case U'\u218A':
		return U"TURNED DIGIT TWO";
	case U'\u218B':
		return U"TURNED DIGIT THREE";
	/* MISCELLANEOUS SYMBOLS: */
	case U'\u2630':
		return U"TRIGRAM FOR HEAVEN";
	case U'\u2631':
		return U"TRIGRAM FOR LAKE";
	case U'\u2632':
		return U"TRIGRAM FOR FIRE";
	case U'\u2633':
		return U"TRIGRAM FOR THUNDER";
	case U'\u2634':
		return U"TRIGRAM FOR WIND";
	case U'\u2635':
		return U"TRIGRAM FOR WATER";
	case U'\u2636':
		return U"TRIGRAM FOR MOUNTAIN";
	case U'\u2637':
		return U"TRIGRAM FOR EARTH";
	case U'\u2638':
		return U"WHEEL OF DHARMA";
	case U'\u2639':
		return U"WHITE FROWNING FACE";
	case U'\u263A':
		return U"WHITE SMILING FACE";
	case U'\u263B':
		return U"BLACK SMILING FACE";
	case U'\u263C':
		return U"WHITE SUN WITH RAYS";
	case U'\u263D':
		return U"FIRST QUARTER MOON";
	case U'\u263E':
		return U"LAST QUARTER MOON";
	case U'\u263F':
		return U"MERCURY";
	case U'\u2640':
		return U"FEMALE SIGN";
	case U'\u2641':
		return U"EARTH";
	case U'\u2642':
		return U"MALE SIGN";
	case U'\u2643':
		return U"JUPITER";
	case U'\u2644':
		return U"SATURN";
	case U'\u2645':
		return U"URANUS";
	case U'\u2646':
		return U"NEPTUNE";
	case U'\u2647':
		return U"PLUTO";
	case U'\u2648':
		return U"ARIES";
	case U'\u2649':
		return U"TAURUS";
	case U'\u264A':
		return U"GEMNINI";
	case U'\u264B':
		return U"CANCER";
	case U'\u264C':
		return U"LEO";
	case U'\u264D':
		return U"VIRGO";
	case U'\u264E':
		return U"LIBRA";
	case U'\u264F':
		return U"SCORPIUS";
	case U'\u2650':
		return U"SAGITTARIUS";
	case U'\u2651':
		return U"CAPRICORN";
	case U'\u2652':
		return U"AQUARIUS";
	case U'\u2653':
		return U"PISCES";
	case U'\u2654':
		return U"WHITE CHESS KING";
	case U'\u2655':
		return U"WHITE CHESS QUEEN";
	case U'\u2656':
		return U"WHITE CHESS ROOK";
	case U'\u2657':
		return U"WHITE CHESS BISHOP";
	case U'\u2658':
		return U"WHITE CHESS KNIGHT";
	case U'\u2659':
		return U"WHITE CHESS PAWN";
	case U'\u265A':
		return U"BLACK CHESS KING";
	case U'\u265B':
		return U"BLACK CHESS QUEEN";
	case U'\u265C':
		return U"BLACK CHESS ROOK";
	case U'\u265D':
		return U"BLACK CHESS BISHOP";
	case U'\u265E':
		return U"BLACK CHESS KNIGHT";
	case U'\u265F':
		return U"BLACK CHESS PAWN";
	case U'\u2660':
		return U"BLACK SPADE SUIT";
	case U'\u2661':
		return U"WHITE HEART SUIT";
	case U'\u2662':
		return U"WHITE DIAMOND SUIT";
	case U'\u2663':
		return U"BLACK CLUB SUIT";
	case U'\u2664':
		return U"WHITE SPADE SUIT";
	case U'\u2665':
		return U"BLACK HEART SUIT";
	case U'\u2666':
		return U"BLACK DIAMOND SUIT";
	case U'\u2667':
		return U"WHITE CLUB SUIT";
	case U'\u2668':
		return U"HOT SPRINGS";
	case U'\u2669':
		return U"QUARTER NOTE";
	case U'\u266A':
		return U"EIGHT NOTE";
	case U'\u266B':
		return U"BEAMED EIGTH NOTES";
	case U'\u266C':
		return U"BEAMED SIXTEENTH NOTES";
	case U'\u266D':
		return U"MUSIC FLAT SIGN";
	case U'\u266E':
		return U"MUSIC NEUTRAL SIGN";
	case U'\u266F':
		return U"MUSIC SHARP SIGN";
	case U'\u2670':
		return U"WEST SYRIAC CROSS";
	case U'\u2671':
		return U"EAST SYRIAC CROSS";
	case U'\u2672':
		return U"UNIVERSAL RECYCLING SYMBOL";
	case U'\u2673':
		return U"RECYCLING SYMBOL FOR TYPE-1 PLASTICS";
	case U'\u2674':
		return U"RECYCLING SYMBOL FOR TYPE-2 PLASTICS";
	case U'\u2675':
		return U"RECYCLING SYMBOL FOR TYPE-3 PLASTICS";
	case U'\u2676':
		return U"RECYCLING SYMBOL FOR TYPE-4 PLASTICS";
	case U'\u2677':
		return U"RECYCLING SYMBOL FOR TYPE-5 PLASTICS";
	case U'\u2678':
		return U"RECYCLING SYMBOL FOR TYPE-6 PLASTICS";
	case U'\u2679':
		return U"RECYCLING SYMBOL FOR TYPE-7 PLASTICS";
	case U'\u267A':
		return U"RECYCLING SYMBOL FOR GENERIC MATERIALS";
	case U'\u267B':
		return U"BLACK UNIVERSAL RECYCLING SYMBOL";
	case U'\u267C':
		return U"RECYCLED PAPER SYMBOL";
	case U'\u267D':
		return U"PARTIALLY-RECYCLED PAPER SYMBOL";
	case U'\u267E':
		return U"PERMANENT PAPER SIGN";
	case U'\u267F':
		return U"WHEELCHAIR SYMBOL";
	case U'\u26B9':
		return U"SEXTILE";
	/* DINGBATS: */
	case U'\u271D':
		return U"LATIN CROSS";
	case U'\u2721':
		return U"STAR OF DAVID";
	/* SUPPLEMENTAL PUNCTUATION: */
	case U'\u2E3B':
		return U"THREE-EM DASH";
	/* ARABIC PRESENTATION FORMS-A: */
	case U'\uFDFD':
		return U"ARABIC LIGATURE BISMILLAH AL-RAHMAN AR-RAHEEM";
	/* ANCIENT SYMBOLS: */
	case U'\U00010190':
		return U"ROMAN SEXTANS SIGN";
	case U'\U00010191':
		return U"ROMAN UNCIA SIGN";
	case U'\U00010192':
		return U"ROMAN SEMUNCIA SIGN";
	case U'\U00010193':
		return U"ROMAN SEXTULA SIGN";
	case U'\U00010194':
		return U"ROMAN DIMIDIA SEXTULA SIGN";
	case U'\U00010195':
		return U"ROMAN SILIQUA SIGN";
	case U'\U00010196':
		return U"ROMAN DENARIUS SIGN";
	case U'\U00010197':
		return U"ROMAN QUINARIUS SIGN";
	case U'\U00010198':
		return U"ROMAN SESTERTIUS SIGN";
	case U'\U00010199':
		return U"ROMAN DUPONDIUS SIGN";
	case U'\U0001019A':
		return U"ROMAN AS SIGN";
	case U'\U0001019B':
		return U"ROMAN CENTURIAL SIGN";
	case U'\U0001019C':
		return U"ASCIA SIGN";
	/* BRAHMI: */
	case U'\U00011066':
		return U"BRAHMI DIGIT ZERO";
	case U'\U00011067':
		return U"BRAHMI DIGIT ONE";
	case U'\U00011068':
		return U"BRAHMI DIGIT TWO";
	case U'\U00011069':
		return U"BRAHMI DIGIT THREE";
	case U'\U0001106A':
		return U"BRAHMI DIGIT FOUR";
	case U'\U0001106B':
		return U"BRAHMI DIGIT FIVE";
	case U'\U0001106C':
		return U"BRAHMI DIGIT SIX";
	case U'\U0001106D':
		return U"BRAHMI DIGIT SEVEN";
	case U'\U0001106E':
		return U"BRAHMI DIGIT EIGHT";
	case U'\U0001106F':
		return U"BRAHMI DIGIT NINE";
	/* CUNEIFORM: */
	case U'\U00012031':
		return U"CUNEIFORM SIGN AN PLUS NAGA SQUARED";
	/* CUNEIFORM NUMBERS AND PUNCTUATION: */
	case U'\U0001242B':
		return U"CUNEIFORM NUMERIC SIGN NINE SHAR2";
	/* EGYPTIAN HIEROGLYPHS: */
	case U'\U000130B8':
		return U"EGYPTIAN HIEROGLYPH D052";
	/* COUNTING ROD NUMERALS: */
	case U'\U0001D372':
		return U"IDEOGRAPHIC TALLY MARK ONE";
	case U'\U0001D373':
		return U"IDEOGRAPHIC TALLY MARK TWO";
	case U'\U0001D374':
		return U"IDEOGRAPHIC TALLY MARK THREE";
	case U'\U0001D375':
		return U"IDEOGRAPHIC TALLY MARK FOUR";
	case U'\U0001D376':
		return U"IDEOGRAPHIC TALLY MARK FIVE";
	case U'\U0001D377':
		return U"TALLY MARK ONE";
	case U'\U0001D378':
		return U"TALLY MARK FIVE";
	/* ENCLOSED ALPHANUMERIC SUPPLEMENT: */
	case U'\U0001F10D':
		return U"CIRCLED ZERO WITH SLASH";
	case U'\U0001F10E':
		return U"CIRCLED ANTICKLOCKWISE ARROW";
	case U'\U0001F10F':
		return U"CIRCLED DOLLAR SIGN WITH OVERLAID BACKSLASH";
	case U'\U0001F12F':
		return U"COPYLEFT SYMBOL";
	case U'\U0001F16D':
		return U"CIRCLED CC";
	case U'\U0001F16E':
		return U"CIRCLED C WITH OVERLAID BACKSLASH";
	case U'\U0001F16F':
		return U"CIRCLED HUMAN FIGURE";
	/* EMOTICONS: */
	case U'\U0001F600':
		return U"GRINNING FACE";
	case U'\U0001F601':
		return U"GRINNING FACE WITH SMIRKING EYES";
	case U'\U0001F602':
		return U"FACE WITH TEARS OF JOY";
	case U'\U0001F603':
		return U"SMILING FACE WITH OPEN MOUTH";
	case U'\U0001F604':
		return U"SMILING FACE WITH OPEN MOUTH AND SMILING EYES";
	case U'\U0001F605':
		return U"SMILING FACE WITH OPEN MOUTH AND COULD SWEAT";
	case U'\U0001F606':
		return U"SMILING FACE WITH OPEN MOUTH AND TIGHTLY-CLOSED EYES";
	case U'\U0001F607':
		return U"SMILING FACE WITH HALO";
	case U'\U0001F608':
		return U"SMILING FACE WITH HORNS";
	case U'\U0001F609':
		return U"WINKING FACE";
	case U'\U0001F60A':
		return U"SMILING FACE WITH SMILING EYES";
	case U'\U0001F60B':
		return U"FACE SAVOURING DELICIOUS FOOD";
	case U'\U0001F60C':
		return U"RELIEVED FACE";
	case U'\U0001F60D':
		return U"SMILLING FACE HEART-SHAPED EYES";
	case U'\U0001F60E':
		return U"SMILLING FACE WITH SUNGLASSES";
	case U'\U0001F60F':
		return U"SMIRKING FACE";
	case U'\U0001F610':
		return U"NEUTRAL FACE";
	case U'\U0001F611':
		return U"EXPRESSIONLESS FACE";
	case U'\U0001F612':
		return U"UNAMUSED FACE";
	case U'\U0001F613':
		return U"FACE WITH COLD SWEAT";
	case U'\U0001F614':
		return U"PENSIVE FACE";
	case U'\U0001F615':
		return U"CONFUSED FACE";
	case U'\U0001F616':
		return U"CONFOUNDED FACE";
	case U'\U0001F617':
		return U"KISSING FACE";
	case U'\U0001F618':
		return U"FACE THROWING A KISS";
	case U'\U0001F619':
		return U"KISSING FACE WITH SMILLING EYES";
	case U'\U0001F61A':
		return U"KISSING FACE WITH CLOSED EYES";
	case U'\U0001F61B':
		return U"FACE WITH STUCK-OUT TONGUE";
	case U'\U0001F61C':
		return U"FACE WITH STUCK-OUT TONGUE AND WINKING EYE";
	case U'\U0001F61D':
		return U"FACE WITH STUCK-OUT TONGUE AND TIGHTLY-CLOSED EYES";
	case U'\U0001F61E':
		return U"DISSAPOINTED FACE";
	case U'\U0001F61F':
		return U"WORRIED FACE";
	case U'\U0001F620':
		return U"ANGRY FACE";
	case U'\U0001F621':
		return U"POUTING FACE";
	case U'\U0001F622':
		return U"CRYING FACE";
	case U'\U0001F623':
		return U"PERSEVERING FACE";
	case U'\U0001F624':
		return U"FACE WITH LOOK OF TRIUMPH";
	case U'\U0001F625':
		return U"DISSAPOINTED BUT RELIEVED FACE";
	case U'\U0001F626':
		return U"FROWNING FACE WITH OPEN MOUTH";
	case U'\U0001F627':
		return U"ANGUISHED FACE";
	case U'\U0001F628':
		return U"FEARFUL FACE";
	case U'\U0001F629':
		return U"WEARY FACE";
	case U'\U0001F62A':
		return U"SLEEPY FACE";
	case U'\U0001F62B':
		return U"TIRED FACE";
	case U'\U0001F62C':
		return U"GRIMACING FACE";
	case U'\U0001F62D':
		return U"LOUDLY CRYING FACE";
	case U'\U0001F62E':
		return U"FACE WITH OPEN MOUTH";
	case U'\U0001F62F':
		return U"HUSHED FACE";
	case U'\U0001F630':
		return U"FACE WITH OPEN MOUTH AND COLD SWEAT";
	case U'\U0001F631':
		return U"FACE SCREAMING IN FEAR";
	case U'\U0001F632':
		return U"ASTONISHED FACE";
	case U'\U0001F633':
		return U"FLUSHED FACE";
	case U'\U0001F634':
		return U"SLEEPING FACE";
	case U'\U0001F635':
		return U"DIZZY FACE";
	case U'\U0001F636':
		return U"FACE WITHOUT MOUTH";
	case U'\U0001F637':
		return U"FACE WITH MEDICAL MASK";
	case U'\U0001F641':
		return U"SLIGHTLY FROWNING FACE";
	case U'\U0001F642':
		return U"SLIGHTLY SMILING FACE";
	case U'\U0001F643':
		return U"UPSIDE-DOWN FACE";
	case U'\U0001F644':
		return U"FACE WITH ROLLING EYES";
	/* ORNAMENTAL DINGBATS: */
	case U'\U0001F670':
		return U"SCRIPT LIGATURE ET ORNAMENT";
	case U'\U0001F671':
		return U"HEAVY SCRIPT LIGATURE ET ORNAMENT";
	case U'\U0001F672':
		return U"LIGATURE OPEN ET ORNAMENT";
	case U'\U0001F673':
		return U"HEAVY LIGATURE OPEN ET ORNAMENT";
	case U'\U0001F674':
		return U"HEAVY AMPERSAND ORNAMENT";
	case U'\U0001F675':
		return U"SWASH AMPERSAND ORNAMENT";
	case U'\U0001F676':
		return U"SANS-SERIF HEAVY DOUBLE TURNED COMMA QUOTATION MARK ORNAMENT";
	case U'\U0001F677':
		return U"SANS-SERIF HEAVY DOUBLE COMMA QUOTATION MARK ORNAMENT";
	case U'\U0001F678':
		return U"SANS-SERIF HEAVY LOW DOUBLE QUOTATION MARK ORNAMENT";
	case U'\U0001F679':
		return U"HEAVY INTERROBANG ORNAMENT";
	case U'\U0001F67A':
		return U"SANS-SERIF INTERROBANG ORNAMENT";
	case U'\U0001F67B':
		return U"HEAVY SANS-SERIF INTERROBANG ORNAMENT";
	case U'\U0001F67C':
		return U"VERY HEAVY SOLIDUS";
	case U'\U0001F67D':
		return U"VERY HEAVY REVERSE SOLIDUS";
	case U'\U0001F67E':
		return U"CHECKER BOARD";
	case U'\U0001F67F':
		return U"REVERSE CHECKER BOARD";
	/* CJK UNIFIED IDEOGRAPHS EXTENSION G: */
	case U'\U0003106C':
		return U"CJK UNIFIED IDEOGRAPH-3106C";
	/* TAGS: */
	case U'\U000E0001':
		return U"LANGUAGE TAG";
	case U'\U000E0020':
		return U"TAG SPACE";
	case U'\U000E0021':
		return U"TAG EXCLAMATION MARK";
	case U'\U000E0022':
		return U"TAG QUOTATION MARK";
	case U'\U000E0023':
		return U"TAG NUMBER SIGN";
	case U'\U000E0024':
		return U"TAG DOLLAR SIGN";
	case U'\U000E0025':
		return U"TAG PERCENT SIGN";
	case U'\U000E0026':
		return U"TAG AMPERSAND";
	case U'\U000E0027':
		return U"TAG APOSTROPHE";
	case U'\U000E0028':
		return U"TAG LEFT PARANTHESIS";
	case U'\U000E0029':
		return U"TAG RIGHT PARANTHESIS";
	case U'\U000E002A':
		return U"TAG ASTERISK";
	case U'\U000E002B':
		return U"TAG PLUS SIGN";
	case U'\U000E002C':
		return U"TAG COMMA";
	case U'\U000E002D':
		return U"TAG HYPHEN-MINUS";
	case U'\U000E002E':
		return U"TAG FULL STOP";
	case U'\U000E002F':
		return U"TAG SOLIDUS";
	case U'\U000E0030':
		return U"TAG DIGIT ZERO";
	case U'\U000E0031':
		return U"TAG DIGIT ONE";
	case U'\U000E0032':
		return U"TAG DIGIT TWO";
	case U'\U000E0033':
		return U"TAG DIGIT THREE";
	case U'\U000E0034':
		return U"TAG DIGIT FOUR";
	case U'\U000E0035':
		return U"TAG DIGIT FIVE";
	case U'\U000E0036':
		return U"TAG DIGIT SIX";
	case U'\U000E0037':
		return U"TAG DIGIT SEVEN";
	case U'\U000E0038':
		return U"TAG DIGIT EIGHT";
	case U'\U000E0039':
		return U"TAG DIGIT NINE";
	case U'\U000E003A':
		return U"TAG COLON";
	case U'\U000E003B':
		return U"TAG SEMICOLON";
	case U'\U000E003C':
		return U"TAG LESS-THAN SIGN";
	case U'\U000E003D':
		return U"TAG EQUALS SIGN";
	case U'\U000E003E':
		return U"TAG GREATER-THAN SIGN";
	case U'\U000E003F':
		return U"TAG QUESTION MARK";
	case U'\U000E0040':
		return U"TAG COMMERCIAL AT";
	case U'\U000E0041':
		return U"TAG LATIN CAPITAL LETTER A";
	case U'\U000E0042':
		return U"TAG LATIN CAPITAL LETTER B";
	case U'\U000E0043':
		return U"TAG LATIN CAPITAL LETTER C";
	case U'\U000E0044':
		return U"TAG LATIN CAPITAL LETTER D";
	case U'\U000E0045':
		return U"TAG LATIN CAPITAL LETTER E";
	case U'\U000E0046':
		return U"TAG LATIN CAPITAL LETTER F";
	case U'\U000E0047':
		return U"TAG LATIN CAPITAL LETTER G";
	case U'\U000E0048':
		return U"TAG LATIN CAPITAL LETTER H";
	case U'\U000E0049':
		return U"TAG LATIN CAPITAL LETTER I";
	case U'\U000E004A':
		return U"TAG LATIN CAPITAL LETTER J";
	case U'\U000E004B':
		return U"TAG LATIN CAPITAL LETTER K";
	case U'\U000E004C':
		return U"TAG LATIN CAPITAL LETTER L";
	case U'\U000E004D':
		return U"TAG LATIN CAPITAL LETTER M";
	case U'\U000E004E':
		return U"TAG LATIN CAPITAL LETTER N";
	case U'\U000E004F':
		return U"TAG LATIN CAPITAL LETTER O";
	case U'\U000E0050':
		return U"TAG LATIN CAPITAL LETTER P";
	case U'\U000E0051':
		return U"TAG LATIN CAPITAL LETTER Q";
	case U'\U000E0052':
		return U"TAG LATIN CAPITAL LETTER R";
	case U'\U000E0053':
		return U"TAG LATIN CAPITAL LETTER S";
	case U'\U000E0054':
		return U"TAG LATIN CAPITAL LETTER T";
	case U'\U000E0055':
		return U"TAG LATIN CAPITAL LETTER U";
	case U'\U000E0056':
		return U"TAG LATIN CAPITAL LETTER V";
	case U'\U000E0057':
		return U"TAG LATIN CAPITAL LETTER W";
	case U'\U000E0058':
		return U"TAG LATIN CAPITAL LETTER X";
	case U'\U000E0059':
		return U"TAG LATIN CAPITAL LETTER Y";
	case U'\U000E005A':
		return U"TAG LATIN CAPITAL LETTER Z";
	case U'\U000E005B':
		return U"TAG LEFT SQUARE BRACKET";
	case U'\U000E005C':
		return U"TAG REVERSE SOLIDUS";
	case U'\U000E005D':
		return U"TAG RIGHT SQUARE BRACKET";
	case U'\U000E005E':
		return U"TAG CIRCUMFLEX ACCENT";
	case U'\U000E005F':
		return U"TAG LOW LINE";
	case U'\U000E0060':
		return U"TAG GRAVE ACCENT";
	case U'\U000E0061':
		return U"TAG LATIN SMALL LETTER A";
	case U'\U000E0062':
		return U"TAG LATIN SMALL LETTER B";
	case U'\U000E0063':
		return U"TAG LATIN SMALL LETTER C";
	case U'\U000E0064':
		return U"TAG LATIN SMALL LETTER D";
	case U'\U000E0065':
		return U"TAG LATIN SMALL LETTER E";
	case U'\U000E0066':
		return U"TAG LATIN SMALL LETTER F";
	case U'\U000E0067':
		return U"TAG LATIN SMALL LETTER G";
	case U'\U000E0068':
		return U"TAG LATIN SMALL LETTER H";
	case U'\U000E0069':
		return U"TAG LATIN SMALL LETTER I";
	case U'\U000E006A':
		return U"TAG LATIN SMALL LETTER J";
	case U'\U000E006B':
		return U"TAG LATIN SMALL LETTER K";
	case U'\U000E006C':
		return U"TAG LATIN SMALL LETTER L";
	case U'\U000E006D':
		return U"TAG LATIN SMALL LETTER M";
	case U'\U000E006E':
		return U"TAG LATIN SMALL LETTER N";
	case U'\U000E006F':
		return U"TAG LATIN SMALL LETTER O";
	case U'\U000E0070':
		return U"TAG LATIN SMALL LETTER P";
	case U'\U000E0071':
		return U"TAG LATIN SMALL LETTER Q";
	case U'\U000E0072':
		return U"TAG LATIN SMALL LETTER R";
	case U'\U000E0073':
		return U"TAG LATIN SMALL LETTER S";
	case U'\U000E0074':
		return U"TAG LATIN SMALL LETTER T";
	case U'\U000E0075':
		return U"TAG LATIN SMALL LETTER U";
	case U'\U000E0076':
		return U"TAG LATIN SMALL LETTER V";
	case U'\U000E0077':
		return U"TAG LATIN SMALL LETTER W";
	case U'\U000E0078':
		return U"TAG LATIN SMALL LETTER X";
	case U'\U000E0079':
		return U"TAG LATIN SMALL LETTER Y";
	case U'\U000E007A':
		return U"TAG LATIN SMALL LETTER Z";
	case U'\U000E007B':
		return U"TAG LEFT CURLY BRACKET";
	case U'\U000E007C':
		return U"TAG VERTICAL LINE";
	case U'\U000E007D':
		return U"TAG RIGHT CURLY BRACKET";
	case U'\U000E007E':
		return U"TAG TILDE";
	case U'\U000E007F':
		return U"CANCEL TAG";
	}
}
