//
// NumberFormatter.cpp
//
// $Id: //poco/1.4/Foundation/src/NumberFormatter.cpp#4 $
//
// Library: Foundation
// Package: Core
// Module:  NumberFormatter
//
// Copyright (c) 2004-2008, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
// 
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//


#include "Poco/NumberFormatter.h"
#include "Poco/MemoryStream.h"
#include <iomanip>
#if !defined(POCO_NO_LOCALE)
#include <locale>
#endif
#include <cstdio>


#if defined(_MSC_VER) || defined(__MINGW32__)
	#define I64_FMT "I64"
#elif defined(__APPLE__) 
	#define I64_FMT "q"
#else
	#define I64_FMT "ll"
#endif


namespace Poco {


std::string NumberFormatter::format(bool value, BoolFormat format)
{
	switch(format)
	{
		default:
		case FMT_TRUE_FALSE:
			if (value == true)
				return "true";
			return "false";
		case FMT_YES_NO:
			if (value == true)
				return "yes";
			return "no";
		case FMT_ON_OFF:
			if (value == true)
				return "on";
			return "off";
	}
}


void NumberFormatter::append(std::string& str, int value)
{
	char buffer[64];
	std::sprintf(buffer, "%d", value);
	str.append(buffer);
}


void NumberFormatter::append(std::string& str, int value, int width)
{
	poco_assert (width > 0 && width < 64);

	char buffer[64];
	std::sprintf(buffer, "%*d", width, value);
	str.append(buffer);
}


void NumberFormatter::append0(std::string& str, int value, int width)
{
	poco_assert (width > 0 && width < 64);

	char buffer[64];
	std::sprintf(buffer, "%0*d", width, value);
	str.append(buffer);
}


void NumberFormatter::appendHex(std::string& str, int value)
{
	char buffer[64];
	std::sprintf(buffer, "%X", value);
	str.append(buffer);
}


void NumberFormatter::appendHex(std::string& str, int value, int width)
{
	poco_assert (width > 0 && width < 64);

	char buffer[64];
	std::sprintf(buffer, "%0*X", width, value);
	str.append(buffer);
}


void NumberFormatter::append(std::string& str, unsigned value)
{
	char buffer[64];
	std::sprintf(buffer, "%u", value);
	str.append(buffer);
}


void NumberFormatter::append(std::string& str, unsigned value, int width)
{
	poco_assert (width > 0 && width < 64);

	char buffer[64];
	std::sprintf(buffer, "%*u", width, value);
	str.append(buffer);
}


void NumberFormatter::append0(std::string& str, unsigned int value, int width)
{
	poco_assert (width > 0 && width < 64);

	char buffer[64];
	std::sprintf(buffer, "%0*u", width, value);
	str.append(buffer);
}


void NumberFormatter::appendHex(std::string& str, unsigned value)
{
	char buffer[64];
	std::sprintf(buffer, "%X", value);
	str.append(buffer);
}


void NumberFormatter::appendHex(std::string& str, unsigned value, int width)
{
	poco_assert (width > 0 && width < 64);

	char buffer[64];
	std::sprintf(buffer, "%0*X", width, value);
	str.append(buffer);
}


void NumberFormatter::append(std::string& str, long value)
{
	char buffer[64];
	std::sprintf(buffer, "%ld", value);
	str.append(buffer);
}


void NumberFormatter::append(std::string& str, long value, int width)
{
	poco_assert (width > 0 && width < 64);

	char buffer[64];
	std::sprintf(buffer, "%*ld", width, value);
	str.append(buffer);
}


void NumberFormatter::append0(std::string& str, long value, int width)
{
	poco_assert (width > 0 && width < 64);

	char buffer[64];
	std::sprintf(buffer, "%0*ld", width, value);
	str.append(buffer);
}


void NumberFormatter::appendHex(std::string& str, long value)
{
	char buffer[64];
	std::sprintf(buffer, "%lX", value);
	str.append(buffer);
}


void NumberFormatter::appendHex(std::string& str, long value, int width)
{
	poco_assert (width > 0 && width < 64);

	char buffer[64];
	std::sprintf(buffer, "%0*lX", width, value);
	str.append(buffer);
}


void NumberFormatter::append(std::string& str, unsigned long value)
{
	char buffer[64];
	std::sprintf(buffer, "%lu", value);
	str.append(buffer);
}


void NumberFormatter::append(std::string& str, unsigned long value, int width)
{
	poco_assert (width > 0 && width < 64);

	char buffer[64];
	std::sprintf(buffer, "%*lu", width, value);
	str.append(buffer);
}


void NumberFormatter::append0(std::string& str, unsigned long value, int width)
{
	poco_assert (width > 0 && width < 64);

	char buffer[64];
	std::sprintf(buffer, "%0*lu", width, value);
	str.append(buffer);
}


void NumberFormatter::appendHex(std::string& str, unsigned long value)
{
	char buffer[64];
	std::sprintf(buffer, "%lX", value);
	str.append(buffer);
}


void NumberFormatter::appendHex(std::string& str, unsigned long value, int width)
{
	poco_assert (width > 0 && width < 64);

	char buffer[64];
	std::sprintf(buffer, "%0*lX", width, value);
	str.append(buffer);
}


#if defined(POCO_HAVE_INT64) && !defined(POCO_LONG_IS_64_BIT)


void NumberFormatter::append(std::string& str, Int64 value)
{
	char buffer[64];
	std::sprintf(buffer, "%"I64_FMT"d", value);
	str.append(buffer);
}


void NumberFormatter::append(std::string& str, Int64 value, int width)
{
	poco_assert (width > 0 && width < 64);

	char buffer[64];
	std::sprintf(buffer, "%*"I64_FMT"d", width, value);
	str.append(buffer);
}


void NumberFormatter::append0(std::string& str, Int64 value, int width)
{
	poco_assert (width > 0 && width < 64);

	char buffer[64];
	std::sprintf(buffer, "%0*"I64_FMT"d", width, value);
	str.append(buffer);
}


void NumberFormatter::appendHex(std::string& str, Int64 value)
{
	char buffer[64];
	std::sprintf(buffer, "%"I64_FMT"X", value);
	str.append(buffer);
}


void NumberFormatter::appendHex(std::string& str, Int64 value, int width)
{
	poco_assert (width > 0 && width < 64);

	char buffer[64];
	std::sprintf(buffer, "%0*"I64_FMT"X", width, value);
	str.append(buffer);
}


void NumberFormatter::append(std::string& str, UInt64 value)
{
	char buffer[64];
	std::sprintf(buffer, "%"I64_FMT"u", value);
	str.append(buffer);
}


void NumberFormatter::append(std::string& str, UInt64 value, int width)
{
	poco_assert (width > 0 && width < 64);

	char buffer[64];
	std::sprintf(buffer, "%*"I64_FMT"u", width, value);
	str.append(buffer);
}


void NumberFormatter::append0(std::string& str, UInt64 value, int width)
{
	poco_assert (width > 0 && width < 64);

	char buffer[64];
	std::sprintf(buffer, "%0*"I64_FMT"u", width, value);
	str.append(buffer);
}


void NumberFormatter::appendHex(std::string& str, UInt64 value)
{
	char buffer[64];
	std::sprintf(buffer, "%"I64_FMT"X", value);
	str.append(buffer);
}


void NumberFormatter::appendHex(std::string& str, UInt64 value, int width)
{
	poco_assert (width > 0 && width < 64);

	char buffer[64];
	std::sprintf(buffer, "%0*"I64_FMT"X", width, value);
	str.append(buffer);
}


#endif // defined(POCO_HAVE_INT64) && !defined(POCO_LONG_IS_64_BIT)


void NumberFormatter::append(std::string& str, float value)
{
	char buffer[64];
	Poco::MemoryOutputStream ostr(buffer, sizeof(buffer));
#if !defined(POCO_NO_LOCALE)
	ostr.imbue(std::locale::classic());
#endif
	ostr << std::setprecision(8) << value;
	str.append(buffer, static_cast<std::string::size_type>(ostr.charsWritten()));
}


void NumberFormatter::append(std::string& str, double value)
{
	char buffer[64];
	Poco::MemoryOutputStream ostr(buffer, sizeof(buffer));
#if !defined(POCO_NO_LOCALE)
	ostr.imbue(std::locale::classic());
#endif
	ostr << std::setprecision(16) << value;
	str.append(buffer, static_cast<std::string::size_type>(ostr.charsWritten()));
}


void NumberFormatter::append(std::string& str, double value, int precision)
{
	poco_assert (precision >= 0 && precision < 32);

	char buffer[64];
	Poco::MemoryOutputStream ostr(buffer, sizeof(buffer));
#if !defined(POCO_NO_LOCALE)
	ostr.imbue(std::locale::classic());
#endif
	ostr << std::fixed << std::showpoint << std::setprecision(precision) << value;
	str.append(buffer, static_cast<std::string::size_type>(ostr.charsWritten()));
}


void NumberFormatter::append(std::string& str, double value, int width, int precision)
{
	poco_assert (width > 0 && width < 64 && precision >= 0 && precision < width);

	char buffer[64];
	Poco::MemoryOutputStream ostr(buffer, sizeof(buffer));
#if !defined(POCO_NO_LOCALE)
	ostr.imbue(std::locale::classic());
#endif
	ostr << std::fixed << std::showpoint << std::setw(width) << std::setprecision(precision) << value;
	str.append(buffer, static_cast<std::string::size_type>(ostr.charsWritten()));
}


void NumberFormatter::append(std::string& str, const void* ptr)
{
	char buffer[24];
#if defined(POCO_PTR_IS_64_BIT)
	#if defined(POCO_LONG_IS_64_BIT)
		std::sprintf(buffer, "%016lX", (UIntPtr) ptr);
	#else
		std::sprintf(buffer, "%016"I64_FMT"X", (UIntPtr) ptr);
	#endif
#else
	std::sprintf(buffer, "%08lX", (UIntPtr) ptr);
#endif
	str.append(buffer);
}


} // namespace Poco
