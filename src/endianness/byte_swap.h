/*
 *  Performs byte-swap operations.
 *  - bswap8(value) is a no-op.
 *  - bswap16(value) swaps the bytes of a 16-bit value.
 *  - bswap32(value) swaps the bytes of a 32-bit value.
 *  - bswap64(value) swaps the bytes of a 64-bit value.
 *  - bswapf(value) swaps the bytes of a 32-bit float value.
 *  - bswapd(value) swaps the bytes of a 64-bit double value.
 */

#ifndef ENDIANNESS_BYTE_SWAP_H
#define ENDIANNESS_BYTE_SWAP_H
#ifdef __cplusplus
#    include <cstdint>
#    include <cstring>
#else
#    include <assert.h>
#    include <stdint.h>
#endif

#ifndef bswap8
#    define bswap8(x) (x)
#endif

#if defined(_MSC_VER)
#    ifdef __cplusplus
#        include <cstdlib>
#    else
#        include <stdlib.h>
#    endif
#    ifndef bswap16
#        define bswap16(x) _byteswap_ushort((x))
#    endif

#    ifndef bswap32
#        define bswap32(x) _byteswap_ulong((x))
#    endif

#    ifndef bswap64
#        define bswap64(x) _byteswap_uint64((x))
#    endif
#elif (__GNUC__ > 4) || (__GNUC__ == 4 && __GNUC_MINOR__ >= 8)
#    ifndef bswap16
#        define bswap16(x) __builtin_bswap16((x))
#    endif

#    ifndef bswap32
#        define bswap32(x) __builtin_bswap32((x))
#    endif

#    ifndef bswap64
#        define bswap64(x) __builtin_bswap64((x))
#    endif
#elif defined(__has_builtin) && __has_builtin(__builtin_bswap64)
#    ifndef bswap16
#        define bswap16(x) __builtin_bswap16((x))
#    endif

#    ifndef bswap32
#        define bswap32(x) __builtin_bswap32((x))
#    endif

#    ifndef bswap64
#        define bswap64(x) __builtin_bswap64((x))
#    endif
#else
#    ifndef bswap16
static inline uint16_t bswap16(const uint16_t x) {
    return (((x >> 8) & 0xFFu) | ((x & 0xFFu) << 8));
}
#    endif

#    ifndef bswap32
static inline uint32_t bswap32(const uint32_t x) {
    return (((x & 0xFF000000u) >> 24) | ((x & 0x00FF0000u) >> 8) |
            ((x & 0x0000FF00u) << 8) | ((x & 0x000000FFu) << 24));
}
#    endif

#    ifndef bswap64
static inline uint64_t bswap64(const uint64_t x) {
    return (((x & 0xFF00000000000000ull) >> 56) |
            ((x & 0x00FF000000000000ull) >> 40) |
            ((x & 0x0000FF0000000000ull) >> 24) |
            ((x & 0x000000FF00000000ull) >> 8) |
            ((x & 0x00000000FF000000ull) << 8) |
            ((x & 0x0000000000FF0000ull) << 24) |
            ((x & 0x000000000000FF00ull) << 40) |
            ((x & 0x00000000000000FFull) << 56));
}
#    endif
#endif

#ifndef bswapf
static inline float bswapf(float f) {
#    ifdef __cplusplus
    static_assert(sizeof(float) == sizeof(std::uint32_t),
                  "float is not 32 bits");
    std::uint32_t bits;
    std::memcpy(&bits, reinterpret_cast<const void *>(&f),
                sizeof(std::uint32_t));
    bits = bswap32(bits);
    std::memcpy(&f, reinterpret_cast<const void *>(&bits),
                sizeof(std::uint32_t));
    return f;
#    else
#        if defined(static_assert)
    static_assert(sizeof(float) == sizeof(uint32_t), "float is not 32 bits");
#        elif __STDC_VERSION__ >= 201112L
    _Static_assert(sizeof(float) == sizeof(uint32_t), "float is not 32 bits");
#        endif
    union {
        uint32_t bits;
        float value;
    } conversion;
    conversion.value = f;
    conversion.bits = bswap32(conversion.bits);
    return conversion.value;
#    endif
}
#endif

#ifndef bswapd
static inline double bswapd(double d) {
#    ifdef __cplusplus
    static_assert(sizeof(double) == sizeof(std::uint64_t),
                  "double is not 64 bits");
    std::uint64_t bits;
    std::memcpy(&bits, reinterpret_cast<const void *>(&d),
                sizeof(std::uint64_t));
    bits = bswap64(bits);
    std::memcpy(&d, reinterpret_cast<const void *>(&bits),
                sizeof(std::uint64_t));
    return d;
#    else
#        if defined(static_assert)
    static_assert(sizeof(double) == sizeof(uint64_t), "double is not 64 bits");
#        elif __STDC_VERSION__ >= 201112L
    _Static_assert(sizeof(double) == sizeof(uint64_t), "double is not 64 bits");
#        endif
    union {
        uint64_t bits;
        double value;
    } conversion;
    conversion.value = d;
    conversion.bits = bswap64(conversion.bits);
    return conversion.value;
#    endif
}
#endif

#endif // ENDIANNESS_BYTE_SWAP_H
