// formatxx - C++ string formatting library.
//
// This is free and unencumbered software released into the public domain.
// 
// Anyone is free to copy, modify, publish, use, compile, sell, or
// distribute this software, either in source code form or as a compiled
// binary, for any purpose, commercial or non - commercial, and by any
// means.
// 
// In jurisdictions that recognize copyright laws, the author or authors
// of this software dedicate any and all copyright interest in the
// software to the public domain. We make this dedication for the benefit
// of the public at large and to the detriment of our heirs and
// successors. We intend this dedication to be an overt act of
// relinquishment in perpetuity of all present and future rights to this
// software under copyright law.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
// IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
// OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
// OTHER DEALINGS IN THE SOFTWARE.
// 
// For more information, please refer to <http://unlicense.org/>
//
// Authors:
//   Sean Middleditch <sean@middleditch.us>

#if !defined(_guard_FORMATXX_DETAIL_FORMAT_TRAITS_H)
#define _guard_FORMATXX_DETAIL_FORMAT_TRAITS_H
#pragma once

namespace formatxx {
namespace _detail {
namespace {

template <typename CharT> struct FormatTraits;

template <> struct FormatTraits<char>
{
	static constexpr char cFormatBegin = '{';
	static constexpr char cFormatEnd = '}';
	static constexpr char cFormatSep = ':';

	static constexpr char cPlus = '+';
	static constexpr char cMinus = '-';
	static constexpr char cSpace = ' ';
	static constexpr char cHash = '#';
	static constexpr char cDot = '.';

	static constexpr char to_digit(char c) { return c + '0'; }

	static constexpr char cPrintfSpec = '%';
	static constexpr char cPrintfIndex = '$';

	static constexpr string_view sTrue{"true", 4};
	static constexpr string_view sFalse{"false", 5};

	static constexpr string_view sPrintfSpecifiers{"bcCsSdioxXufFeEaAgGp", 20};
	static constexpr string_view sPrintfModifiers{"hljztL", 6};

	static constexpr char const sDecimalPairs[] =
		"00010203040506070809"
		"10111213141516171819"
		"20212223242526272829"
		"30313233343536373839"
		"40414243444546474849"
		"50515253545556575859"
		"60616263646566676869"
		"70717273747576777879"
		"80818283848586878889"
		"90919293949596979899";
	static constexpr char const sHexadecimalLower[] = "0123456789abcdef";
	static constexpr char const sHexadecimalUpper[] = "0123456789ABCDEF";
};

constexpr string_view FormatTraits<char>::sTrue;
constexpr string_view FormatTraits<char>::sFalse;
constexpr string_view FormatTraits<char>::sPrintfSpecifiers;
constexpr string_view FormatTraits<char>::sPrintfModifiers;
constexpr char const FormatTraits<char>::sDecimalPairs[];
constexpr char const FormatTraits<char>::sHexadecimalLower[];
constexpr char const FormatTraits<char>::sHexadecimalUpper[];

template <> struct FormatTraits<wchar_t>
{
	static constexpr wchar_t cFormatBegin = L'{';
	static constexpr wchar_t cFormatEnd = L'}';
	static constexpr wchar_t cFormatSep = L':';

	static constexpr wchar_t cPlus = L'+';
	static constexpr wchar_t cMinus = L'-';
	static constexpr wchar_t cSpace = L' ';
	static constexpr wchar_t cHash = L'#';
	static constexpr wchar_t cDot = L'.';

	static constexpr wchar_t to_digit(wchar_t c) { return c + L'0'; }

	static constexpr wchar_t cPrintfSpec = L'%';
	static constexpr wchar_t cPrintfIndex = L'$';

	static constexpr wstring_view sTrue{L"true", 4};
	static constexpr wstring_view sFalse{L"false", 5};

	static constexpr wstring_view sPrintfSpecifiers{L"bcCsSdioxXufFeEaAgGp", 20};
	static constexpr wstring_view sPrintfModifiers{L"hljztL", 6};

	static constexpr wchar_t const sDecimalPairs[] =
		L"00010203040506070809"
		L"10111213141516171819"
		L"20212223242526272829"
		L"30313233343536373839"
		L"40414243444546474849"
		L"50515253545556575859"
		L"60616263646566676869"
		L"70717273747576777879"
		L"80818283848586878889"
		L"90919293949596979899";
	static constexpr wchar_t const sHexadecimalLower[] = L"0123456789abcdef";
	static constexpr wchar_t const sHexadecimalUpper[] = L"0123456789ABCDEF";
};

constexpr wstring_view FormatTraits<wchar_t>::sTrue;
constexpr wstring_view FormatTraits<wchar_t>::sFalse;
constexpr wstring_view FormatTraits<wchar_t>::sPrintfSpecifiers;
constexpr wstring_view FormatTraits<wchar_t>::sPrintfModifiers;
constexpr wchar_t const FormatTraits<wchar_t>::sDecimalPairs[];
constexpr wchar_t const FormatTraits<wchar_t>::sHexadecimalLower[];
constexpr wchar_t const FormatTraits<wchar_t>::sHexadecimalUpper[];

} // anonymous namespace
} // namespace _detail
} // namespace formatxx

#endif // _guard_FORMATXX_DETAIL_FORMAT_TRAITS_H
