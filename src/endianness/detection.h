/*
 * Detects the current endianness and defines __BIG_ENDIAN__ or __LITTLE_ENDIAN__
 */

#ifndef ENDIANNESS_DETECTION_H
#define ENDIANNESS_DETECTION_H

#if !defined(__BIG_ENDIAN__) && !defined(__LITTLE_ENDIAN__)
#    ifdef __has_include
#        if __has_include(<endian.h>)
#            include <endian.h> // gnu libc normally provides, linux
#        elif __has_include(<machine/endian.h>)
#            include <machine/endian.h> //open bsd, macos
#        elif __has_include(<sys/param.h>)
#            include <sys/param.h> // mingw, some bsd (not open/macos)
#        elif __has_include(<sys/isadefs.h>)
#            include <sys/isadefs.h> // solaris
#        endif
#    endif
#endif

#if !defined(__BIG_ENDIAN__) && !defined(__LITTLE_ENDIAN__)
#    if (defined(__BYTE_ORDER__) && __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__) || \
        (defined(__BYTE_ORDER) && __BYTE_ORDER == __BIG_ENDIAN) ||             \
        (defined(_BYTE_ORDER) && _BYTE_ORDER == _BIG_ENDIAN) ||                \
        (defined(BYTE_ORDER) && BYTE_ORDER == BIG_ENDIAN) ||                   \
        (defined(__sun) && defined(__SVR4) && defined(_BIG_ENDIAN)) ||         \
        defined(__ARMEB__) || defined(__THUMBEB__) ||                          \
        defined(__AARCH64EB__) || defined(_MIBSEB) || defined(__MIBSEB) ||     \
        defined(__MIBSEB__) || defined(_M_PPC)
#        define __BIG_ENDIAN__
#    elif (defined(__BYTE_ORDER__) &&                                          \
           __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__) || /* gcc */             \
        (defined(__BYTE_ORDER) &&                                              \
         __BYTE_ORDER == __LITTLE_ENDIAN) /* linux header */                   \
        || (defined(_BYTE_ORDER) && _BYTE_ORDER == _LITTLE_ENDIAN) ||          \
        (defined(BYTE_ORDER) &&                                                \
         BYTE_ORDER == LITTLE_ENDIAN) /* mingw header */                       \
        || (defined(__sun) && defined(__SVR4) &&                               \
            defined(_LITTLE_ENDIAN)) || /* solaris */                          \
        defined(__ARMEL__) ||                                                  \
        defined(__THUMBEL__) || defined(__AARCH64EL__) || defined(_MIPSEL) ||  \
        defined(__MIPSEL) || defined(__MIPSEL__) || defined(_M_IX86) ||        \
        defined(_M_X64) || defined(_M_IA64) || /* msvc for intel processors */ \
        defined(_M_ARM) /* msvc code on arm executes in little endian mode */
#        define __LITTLE_ENDIAN__
#    endif
#endif

#if !defined(__BIG_ENDIAN__) && !defined(__LITTLE_ENDIAN__)
#    error "Unknown endianness"
#endif

#endif // ENDIANNESS_DETECTION_H
