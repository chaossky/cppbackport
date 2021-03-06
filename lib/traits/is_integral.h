/* Copyright (c) 2016, Pollard Banknote Limited
   All rights reserved.

   Redistribution and use in source and binary forms, with or without modification,
   are permitted provided that the following conditions are met:

   1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.

   2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation and/or
   other materials provided with the distribution.

   3. Neither the name of the copyright holder nor the names of its contributors
   may be used to endorse or promote products derived from this software without
   specific prior written permission.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
   ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
   WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
   DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
   FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
   DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
   SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
   CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
   OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef PBL_CPP_TRAITS_IS_INTEGRAL_H
#define PBL_CPP_TRAITS_IS_INTEGRAL_H

#ifndef CPP11
#include "integral_constant.h"
#include "config/arch.h"
#include "is_same.h"
#include "remove_cv.h"

namespace cpp11
{
template< class T >
struct is_integral
	: cpp17::bool_constant<
		is_same< bool, typename remove_cv< T >::type >::value
		|| is_same< char, typename remove_cv< T >::type >::value
		|| is_same< signed char, typename remove_cv< T >::type >::value
		|| is_same< unsigned char, typename remove_cv< T >::type >::value
		|| is_same< wchar_t, typename remove_cv< T >::type >::value
		|| is_same< short, typename remove_cv< T >::type >::value
		|| is_same< unsigned short, typename remove_cv< T >::type >::value
		|| is_same< int, typename remove_cv< T >::type >::value
		|| is_same< unsigned int, typename remove_cv< T >::type >::value
		|| is_same< long, typename remove_cv< T >::type >::value
		|| is_same< unsigned long, typename remove_cv< T >::type >::value
		#ifdef HAS_LONG_LONG
		|| is_same< long long, typename remove_cv< T >::type >::value
		|| is_same< unsigned long long, typename remove_cv< T >::type >::value
		#endif
	>
{};
}

#else
#ifndef CPP17
#ifdef CPP14
namespace cpp17
{
template< class T >
constexpr bool is_integral_v = std::is_integral< T >::value;
}
#endif
#endif
#endif // ifndef CPP11
#endif // PBL_CPP_TRAITS_IS_INTEGRAL_H
