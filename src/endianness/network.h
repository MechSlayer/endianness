/*
 * Converts between the network endianness and the host endianness
 * - ntoh8(value) is a no-op.
 * - hton8(value) is a no-op.
 * - letoh8(value) is a no-op.
 * - htole8(value) is a no-op.
 * - betoh8(value) is a no-op.
 * - htobe8(value) is a no-op.
 *
 * - ntoh16(value) converts a 16-bit value from network to host endianness.
 * - hton16(value) converts a 16-bit value from host to network endianness.
 * - letoh16(value) converts a 16-bit value from little-endian to host
 * endianness.
 * - htole16(value) converts a 16-bit value from host endianness to
 * little-endian.
 * - betoh16(value) converts a 16-bit value from big-endian to host endianness.
 * - htobe16(value) converts a 16-bit value from host endianness to big-endian.
 *
 * - ntoh32(value) converts a 32-bit value from network to host endianness.
 * - hton32(value) converts a 32-bit value from host to network endianness.
 * - letoh32(value) converts a 32-bit value from little-endian to host
 * endianness.
 * - htole32(value) converts a 32-bit value from host endianness to
 * little-endian.
 * - betoh32(value) converts a 32-bit value from big-endian to host endianness.
 * - htobe32(value) converts a 32-bit value from host endianness to big-endian.
 *
 * - ntoh64(value) converts a 64-bit value from network to host endianness.
 * - hton64(value) converts a 64-bit value from host to network endianness.
 * - letoh64(value) converts a 64-bit value from little-endian to host
 * endianness.
 * - htole64(value) converts a 64-bit value from host endianness to
 * little-endian.
 * - betoh64(value) converts a 64-bit value from big-endian to host endianness.
 * - htobe64(value) converts a 64-bit value from host endianness to big-endian.
 *
 * - ntohf(value) converts a 32-bit float value from network to host endianness.
 * - htonf(value) converts a 32-bit float value from host to network endianness.
 * - letohf(value) converts a 32-bit float value from little-endian to host
 * endianness.
 * - htolef(value) converts a 32-bit float value from host endianness to
 * little-endian.
 * - betohf(value) converts a 32-bit float value from big-endian to host
 * endianness.
 * - htobef(value) converts a 32-bit float value from host endianness to
 * big-endian.
 *
 * - ntohd(value) converts a 64-bit float value from network to host endianness.
 * - htond(value) converts a 64-bit float value from host to network endianness.
 * - letohd(value) converts a 64-bit float value from little-endian to host
 * endianness.
 * - htoled(value) converts a 64-bit float value from host endianness to
 * little-endian.
 * - betohd(value) converts a 64-bit float value from big-endian to host
 * endianness.
 * - htobed(value) converts a 64-bit float value from host endianness to
 * big-endian.
 */

#ifndef ENDIANNESS_NETWORK_H
#define ENDIANNESS_NETWORK_H
#include "byte_swap.h"
#include "detection.h"

#if defined(__LITTLE_ENDIAN__)
#    define ntoh8(x) bswap8((x))
#    define hton8(x) bswap8((x))
#    define letoh8(x) (x)
#    define htole8(x) (x)
#    define betoh8(x) bswap8((x))
#    define htobe8(x) bswap8((x))

#    define ntoh16(x) bswap16((x))
#    define hton16(x) bswap16((x))
#    define letoh16(x) (x)
#    define htole16(x) (x)
#    define betoh16(x) bswap16((x))
#    define htobe16(x) bswap16((x))

#    define ntoh32(x) bswap32((x))
#    define hton32(x) bswap32((x))
#    define letoh32(x) (x)
#    define htole32(x) (x)
#    define betoh32(x) bswap32((x))
#    define htobe32(x) bswap32((x))

#    define ntoh64(x) bswap64((x))
#    define hton64(x) bswap64((x))
#    define letoh64(x) (x)
#    define htole64(x) (x)
#    define betoh64(x) bswap64((x))
#    define htobe64(x) bswap64((x))

#    define ntohf(x) bswapf((x))
#    define htonf(x) bswapf((x))
#    define letohf(x) (x)
#    define htolef(x) (x)
#    define betohf(x) bswapf((x))
#    define htobef(x) bswapf((x))

#    define ntohd(x) bswapd((x))
#    define htond(x) bswapd((x))
#    define letohd(x) (x)
#    define htoled(x) (x)
#    define betohd(x) bswapd((x))
#    define htobed(x) bswapd((x))

#elif defined(__BIG_ENDIAN__)
#    define ntoh8(x) (x)
#    define hton8(x) (x)
#    define letoh8(x) bswap8((x))
#    define htole8(x) bswap8((x))
#    define betoh8(x) (x)
#    define htobe8(x) (x)

#    define ntoh16(x) (x)
#    define hton16(x) (x)
#    define letoh16(x) bswap16((x))
#    define htole16(x) bswap16((x))
#    define betoh16(x) (x)
#    define htobe16(x) (x)

#    define ntoh32(x) (x)
#    define hton32(x) (x)
#    define letoh32(x) bswap32((x))
#    define htole32(x) bswap32((x))
#    define betoh32(x) (x)
#    define htobe32(x) (x)

#    define ntoh64(x) (x)
#    define hton64(x) (x)
#    define letoh64(x) bswap64((x))
#    define htole64(x) bswap64((x))
#    define betoh64(x) (x)
#    define htobe64(x) (x)

#    define ntohf(x) (x)
#    define htonf(x) (x)
#    define letohf(x) bswapf((x))
#    define htolef(x) bswapf((x))
#    define betohf(x) (x)
#    define htobef(x) (x)

#    define ntohd(x) (x)
#    define htond(x) (x)
#    define letohd(x) bswapd((x))
#    define htoled(x) bswapd((x))
#    define betohd(x) (x)
#    define htobed(x) (x)
#endif

#endif // ENDIANNESS_NETWORK_H
