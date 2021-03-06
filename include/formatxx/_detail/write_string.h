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

#if !defined(_guard_FORMATXX_DETAIL_WRITE_STRING_H)
#define _guard_FORMATXX_DETAIL_WRITE_STRING_H
#pragma once

#include "format_util.h"

namespace formatxx {
namespace _detail {
namespace {

template <typename CharT>
void write_string(basic_format_writer<CharT>& out, basic_string_view<CharT> str, basic_string_view<CharT> spec_string)
{
	auto const spec = parse_format_spec(spec_string);

	if (spec.has_precision)
	{
		str = trim_string(str, spec.precision);
	}

	if (!spec.left_justify)
	{
		write_padded_align_right(out, str, FormatTraits<CharT>::cSpace, spec.width);
	}
	else
	{
		write_padded_align_left(out, str, FormatTraits<CharT>::cSpace, spec.width);
	}
}

template <typename CharT>
void write_char(basic_format_writer<CharT>& out, CharT ch, basic_string_view<CharT> spec)
{
	write_string(out, {&ch, 1}, spec);
}

} // anonymous namespace
} // namespace _detail
} // namespace formatxx

#endif // _guard_FORMATXX_DETAIL_WRITE_STRING_H
