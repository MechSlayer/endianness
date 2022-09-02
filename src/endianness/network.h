/*
* Converts between the network endianness and the host endianness
 * - ntoh8(value) is a no-op.
 * - hton8(value) is a no-op.
 * - ntoh16(value) converts a 16-bit value from network to host endianness.
 * - hton16(value) converts a 16-bit value from host to network endianness.
 * - ntoh32(value) converts a 32-bit value from network to host endianness.
 * - hton32(value) converts a 32-bit value from host to network endianness.
 * - ntoh64(value) converts a 64-bit value from network to host endianness.
 * - hton64(value) converts a 64-bit value from host to network endianness.
 * - ntohf(value) converts a 32-bit float value from network to host endianness.
 * - htonf(value) converts a 32-bit float value from host to network endianness.
 * - ntohd(value) converts a 64-bit double value from network to host
endianness.
 * - htond(value) converts a 64-bit double value from host to network
endianness.
*/

#ifndef ENDIANNESS_NETWORK_H
#define ENDIANNESS_NETWORK_H
#include "byte_swap.h"
#include "detection.h"

#if defined(__LITTLE_ENDIAN__)
#    define ntoh8(x) bswap8((x))
#    define hton8(x) bswap8((x))
#    define ntoh16(x) bswap16((x))
#    define hton16(x) bswap16((x))
#    define ntoh32(x) bswap32((x))
#    define hton32(x) bswap32((x))
#    define ntoh64(x) bswap64((x))
#    define hton64(x) bswap64((x))
#    define ntohf(x) bswapf((x))
#    define htonf(x) bswapf((x))
#    define ntohd(x) bswapd((x))
#    define htond(x) bswapd((x))
#elif defined(__BIG_ENDIAN__)
#    define ntoh8(x) (x)
#    define hton8(x) (x)
#    define ntoh16(x) (x)
#    define hton16(x) (x)
#    define ntoh32(x) (x)
#    define hton32(x) (x)
#    define ntoh64(x) (x)
#    define hton64(x) (x)
#    define ntohf(x) (x)
#    define htonf(x) (x)
#    define ntohd(x) (x)
#    define htond(x) (x)
#endif

#endif // ENDIANNESS_NETWORK_H
