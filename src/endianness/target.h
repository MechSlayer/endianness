/*
 * Converts between the specified target endianness and the host endianness
 */

#ifndef ENDIANNESS_TARGET_H
#define ENDIANNESS_TARGET_H
#include "byte_swap.h"

#if !defined(ENDIANNESS_TARGET_BIG) && !defined(ENDIANNESS_TARGET_LITTLE)
#    warning                                                                   \
        "Neither ENDIANNESS_TARGET_BIG nor ENDIANNESS_TARGET_LITTLE is defined. Assuming little endian."
#    define ENDIANNESS_TARGET_LITTLE
#elif defined(ENDIANNESS_TARGET_BIG) && defined(ENDIANNESS_TARGET_LITTLE)
#    error                                                                     \
        "Both ENDIANNESS_TARGET_BIG and ENDIANNESS_TARGET_LITTLE are defined."
#endif

#define htot8(x) (x)
#define ttoh8(x) (x)

#if defined(ENDIANNESS_TARGET_BIG)
#    if defined(__BIG_ENDIAN__)
#        define ENDIANNESS_IS_TARGET 1
#        define htot16(x) (x)
#        define ttoh16(x) (x)
#        define htot32(x) (x)
#        define ttoh32(x) (x)
#        define htot64(x) (x)
#        define ttoh64(x) (x)
#        define htotf(x) (x)
#        define ttohf(x) (x)
#        define htotd(x) (x)
#        define ttohd(x) (x)
#    elif defined(__LITTLE_ENDIAN__)
#        define ENDIANNESS_IS_TARGET 0
#        define htot16(x) bswap16((x))
#        define ttoh16(x) bswap16((x))
#        define htot32(x) bswap32((x))
#        define ttoh32(x) bswap32((x))
#        define htot64(x) bswap64((x))
#        define ttoh64(x) bswap64((x))
#        define htotf(x) bswapf((x))
#        define ttohf(x) bswapf((x))
#        define htotd(x) bswapd((x))
#        define ttohd(x) bswapd((x))
#    endif
#elif defined(ENDIANNESS_TARGET_LITTLE)
#    if defined(__LITTLE_ENDIAN__)
#        define ENDIANNESS_IS_TARGET 1
#        define htot16(x) (x)
#        define ttoh16(x) (x)
#        define htot32(x) (x)
#        define ttoh32(x) (x)
#        define htot64(x) (x)
#        define ttoh64(x) (x)
#        define htotf(x) (x)
#        define ttohf(x) (x)
#        define htotd(x) (x)
#        define ttohd(x) (x)
#    elif defined(__BIG_ENDIAN__)
#        define ENDIANNESS_IS_TARGET 0
#        define htot16(x) bswap16((x))
#        define ttoh16(x) bswap16((x))
#        define htot32(x) bswap32((x))
#        define ttoh32(x) bswap32((x))
#        define htot64(x) bswap64((x))
#        define ttoh64(x) bswap64((x))
#        define htotf(x) bswapf((x))
#        define ttohf(x) bswapf((x))
#        define htotd(x) bswapd((x))
#        define ttohd(x) bswapd((x))
#    endif
#else
#    error "Unknown target endianness."
#endif

#endif // ENDIANNESS_TARGET_H
