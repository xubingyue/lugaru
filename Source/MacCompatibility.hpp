/*
Copyright (C) 2003, 2010 - Wolfire Games
Copyright (C) 2010-2016 - Lugaru contributors (see AUTHORS file)

This file is part of Lugaru.

Lugaru is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

Lugaru is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Lugaru.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _MACCOMPATIBLITY_HPP_
#define _MACCOMPATIBLITY_HPP_

#include "Math/Random.hpp"

#include <float.h>
#include <math.h>
#include <stdio.h>

// stuff to make Mac code compatable with Windows/Linux/etc

#if defined(WIN32) && !defined(strcasecmp)
#define strcasecmp(a,b) stricmp(a,b)
#endif

#ifdef _MSC_VER
// disable warnings about double to float conversions
#pragma warning(disable:4305)
#pragma warning(disable:4244)

// disable warnings about boolean to int conversions
#pragma warning(disable:4800)

// disable warning about unreferenced local variables
#pragma warning(disable:4101)
#endif

#ifndef __forceinline
#  ifdef __GNUC__
#    define __forceinline inline __attribute__((always_inline))
#  endif
#endif

struct Point {
    short v;
    short h;
};

typedef signed char SInt8;
typedef unsigned int UInt32;



typedef struct AbsoluteTime {
    unsigned long   hi;
    unsigned long   lo;
} AbsoluteTime;

AbsoluteTime UpTime(); // NOTE: returns time since app started, not system start

typedef long Duration;

enum {
    durationMicrosecond             = -1,
    durationMillisecond             = 1,
    durationSecond                  = 1000,
    durationMinute                  = 1000 * 60,
    durationHour                    = 1000 * 60 * 60,
    durationDay                     = 1000 * 60 * 60 * 24,
    durationForever                 = 0x7FFFFFFF,
    durationImmediate               = 0,
};

Duration AbsoluteDeltaToDuration( AbsoluteTime& a, AbsoluteTime& b);

#ifdef _MSC_VER
inline bool isnormal( double x)
{
    int ret = _fpclass( x);
    return (ret == _FPCLASS_NN || ret == _FPCLASS_PN);
}
#else
#include <stdint.h>
#endif

#endif


