
#ifndef ENDIANNESS_ENDIANNESS_HPP
#define ENDIANNESS_ENDIANNESS_HPP
#include "byte_swap.h"
#include "target.h"

#include <type_traits>

namespace endianness {
    static inline uint8_t swap(const uint8_t x) { return bswap8(x); }

    static inline int8_t swap(const int8_t x) { return bswap8(x); }

    static inline uint16_t swap(const uint16_t x) { return bswap16(x); }

    static inline int16_t swap(const int16_t x) { return bswap16(x); }

    static inline uint32_t swap(const uint32_t x) { return bswap32(x); }

    static inline int32_t swap(const int32_t x) { return bswap32(x); }

    static inline uint64_t swap(const uint64_t x) { return bswap64(x); }

    static inline int64_t swap(const int64_t x) { return bswap64(x); }

    static inline float swap(const float x) { return bswapf(x); }

    static inline double swap(const double x) { return bswapd(x); }

    template <typename T> static inline T host_to_network(const T x) {
#if __cplusplus >= 201103L
        static_assert(std::is_integral<T>::value ||
                          std::is_floating_point<T>::value,
                      "T must be an integral or floating point type");
#endif
#if defined(__LITTLE_ENDIAN__)
        return swap(x);
#elif defined(__BIG_ENDIAN__)
        return x;
#else
        return x;
#endif
    }

    template <typename T> static inline T network_to_host(const T x) {
#if __cplusplus >= 201103L
        static_assert(std::is_integral<T>::value ||
                          std::is_floating_point<T>::value,
                      "T must be an integral or floating point type");
#endif

#if defined(__LITTLE_ENDIAN__)
        return swap(x);
#elif defined(__BIG_ENDIAN__)
        return x;
#else
        return x;
#endif
    }

    static inline uint8_t host_to_target(const uint8_t x) { return htot8(x); }
    static inline uint8_t target_to_host(const uint8_t x) { return ttoh8(x); }
    static inline uint16_t host_to_target(const uint16_t x) {
        return htot16(x);
    }
    static inline uint16_t target_to_host(const uint16_t x) {
        return ttoh16(x);
    }
    static inline uint32_t host_to_target(const uint32_t x) {
        return htot32(x);
    }
    static inline uint32_t target_to_host(const uint32_t x) {
        return ttoh32(x);
    }
    static inline uint64_t host_to_target(const uint64_t x) {
        return htot64(x);
    }
    static inline uint64_t target_to_host(const uint64_t x) {
        return ttoh64(x);
    }
    static inline float host_to_target(const float x) { return htof(x); }
    static inline float target_to_host(const float x) { return ftoh(x); }
    static inline double host_to_target(const double x) { return htod(x); }
    static inline double target_to_host(const double x) { return dtoh(x); }
} // namespace endianness

#endif // ENDIANNESS_ENDIANNESS_HPP
