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
#    ifndef ntoh8
#        define ntoh8(x) bswap8((x))
#    endif

#    ifndef hton8
#        define hton8(x) bswap8((x))
#    endif

#    ifndef letoh8
#        define letoh8(x) (x)
#    endif

#    ifndef htole8
#        define htole8(x) (x)
#    endif

#    ifndef betoh8
#        define betoh8(x) bswap8((x))
#    endif

#    ifndef htobe8
#        define htobe8(x) bswap8((x))
#    endif

#    ifndef ntoh16
#        define ntoh16(x) bswap16((x))
#    endif

#    ifndef hton16
#        define hton16(x) bswap16((x))
#    endif

#    ifndef letoh16
#        define letoh16(x) (x)
#    endif

#    ifndef htole16
#        define htole16(x) (x)
#    endif

#    ifndef betoh16
#        define betoh16(x) bswap16((x))
#    endif

#    ifndef htobe16
#        define htobe16(x) bswap16((x))
#    endif

#    ifndef ntoh32
#        define ntoh32(x) bswap32((x))
#    endif

#    ifndef hton32
#        define hton32(x) bswap32((x))
#    endif

#    ifndef letoh32
#        define letoh32(x) (x)
#    endif

#    ifndef htole32
#        define htole32(x) (x)
#    endif

#    ifndef betoh32
#        define betoh32(x) bswap32((x))
#    endif

#    ifndef htobe32
#        define htobe32(x) bswap32((x))
#    endif

#    ifndef ntoh64
#        define ntoh64(x) bswap64((x))
#    endif

#    ifndef hton64
#        define hton64(x) bswap64((x))
#    endif

#    ifndef letoh64
#        define letoh64(x) (x)
#    endif

#    ifndef htole64
#        define htole64(x) (x)
#    endif

#    ifndef betoh64
#        define betoh64(x) bswap64((x))
#    endif

#    ifndef htobe64
#        define htobe64(x) bswap64((x))
#    endif

#    ifndef ntohf
#        define ntohf(x) bswapf((x))
#    endif

#    ifndef htonf
#        define htonf(x) bswapf((x))
#    endif

#    ifndef letohf
#        define letohf(x) (x)
#    endif

#    ifndef htolef
#        define htolef(x) (x)
#    endif

#    ifndef betohf
#        define betohf(x) bswapf((x))
#    endif

#    ifndef htobef
#        define htobef(x) bswapf((x))
#    endif

#    ifndef ntohd
#        define ntohd(x) bswapd((x))
#    endif

#    ifndef htond
#        define htond(x) bswapd((x))
#    endif

#    ifndef letohd
#        define letohd(x) (x)
#    endif

#    ifndef htoled
#        define htoled(x) (x)
#    endif

#    ifndef betohd
#        define betohd(x) bswapd((x))
#    endif

#    ifndef htobed
#        define htobed(x) bswapd((x))
#    endif

#elif defined(__BIG_ENDIAN__)
#    ifndef ntoh8
#        define ntoh8(x) (x)
#    endif

#    ifndef hton8
#        define hton8(x) (x)
#    endif

#    ifndef letoh8
#        define letoh8(x) bswap8((x))
#    endif

#    ifndef htole8
#        define htole8(x) bswap8((x))
#    endif

#    ifndef betoh8
#        define betoh8(x) (x)
#    endif

#    ifndef htobe8
#        define htobe8(x) (x)
#    endif

#    ifndef ntoh16
#        define ntoh16(x) (x)
#    endif

#    ifndef hton16
#        define hton16(x) (x)
#    endif

#    ifndef letoh16
#        define letoh16(x) bswap16((x))
#    endif

#    ifndef htole16
#        define htole16(x) bswap16((x))
#    endif

#    ifndef betoh16
#        define betoh16(x) (x)
#    endif

#    ifndef htobe16
#        define htobe16(x) (x)
#    endif

#    ifndef ntoh32
#        define ntoh32(x) (x)
#    endif

#    ifndef hton32
#        define hton32(x) (x)
#    endif

#    ifndef letoh32
#        define letoh32(x) bswap32((x))
#    endif

#    ifndef htole32
#        define htole32(x) bswap32((x))
#    endif

#    ifndef betoh32
#        define betoh32(x) (x)
#    endif

#    ifndef htobe32
#        define htobe32(x) (x)
#    endif

#    ifndef ntoh64
#        define ntoh64(x) (x)
#    endif

#    ifndef hton64
#        define hton64(x) (x)
#    endif

#    ifndef letoh64
#        define letoh64(x) bswap64((x))
#    endif

#    ifndef htole64
#        define htole64(x) bswap64((x))
#    endif

#    ifndef betoh64
#        define betoh64(x) (x)
#    endif

#    ifndef htobe64
#        define htobe64(x) (x)
#    endif

#    ifndef ntohf
#        define ntohf(x) (x)
#    endif

#    ifndef htonf
#        define htonf(x) (x)
#    endif

#    ifndef letohf
#        define letohf(x) bswapf((x))
#    endif

#    ifndef htolef
#        define htolef(x) bswapf((x))
#    endif

#    ifndef betohf
#        define betohf(x) (x)
#    endif

#    ifndef htobef
#        define htobef(x) (x)
#    endif

#    ifndef ntohd
#        define ntohd(x) (x)
#    endif

#    ifndef htond
#        define htond(x) (x)
#    endif

#    ifndef letohd
#        define letohd(x) bswapd((x))
#    endif

#    ifndef htoled
#        define htoled(x) bswapd((x))
#    endif

#    ifndef betohd
#        define betohd(x) (x)
#    endif

#    ifndef htobed
#        define htobed(x) (x)
#    endif
#endif

#endif // ENDIANNESS_NETWORK_H
