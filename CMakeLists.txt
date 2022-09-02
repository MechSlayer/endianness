cmake_minimum_required(VERSION 3.4)
project(endianness C CXX)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)

option(ENDIANNESS_CHECK_FLOAT_SIZE "Checks that the size of float/double is the same as uint32_t/uint64_t" ON)
option(ENDIANNESS_DETECT_ON_CONFIGURE "Tries to detect the endianness on configure time" ON)
set(ENDIANNESS_TARGET "LITTLE" CACHE STRING "The target endianness for target.h conversions")

if (${ENDIANNESS_CHECK_FLOAT_SIZE})

    include(CheckTypeSize)

    check_type_size("float" FLOAT_SIZE BUILTIN_TYPES_ONLY LANGUAGE C)
    check_type_size("uint32_t" UINT32_SIZE LANGUAGE C)

    if (NOT ${FLOAT_SIZE} EQUAL ${UINT32_SIZE})
        message(FATAL_ERROR "float and uint32_t are not the same size")
    endif ()

    check_type_size("double" DOUBLE_SIZE BUILTIN_TYPES_ONLY LANGUAGE C)
    check_type_size("uint64_t" UINT64_SIZE LANGUAGE C)

    if (NOT ${DOUBLE_SIZE} EQUAL ${UINT64_SIZE})
        message(FATAL_ERROR "double and uint64_t are not the same size")
    endif ()

endif ()

add_library(${PROJECT_NAME} INTERFACE)
target_include_directories(${PROJECT_NAME} INTERFACE src)

if(ENDIANNESS_TARGET STREQUAL "BIG")
    target_compile_definitions(${PROJECT_NAME} INTERFACE ENDIANNESS_TARGET_BIG)
elseif(ENDIANNESS_TARGET STREQUAL "LITTLE")
    target_compile_definitions(${PROJECT_NAME} INTERFACE ENDIANNESS_TARGET_LITTLE)
endif()


if (${ENDIANNESS_DETECT_ON_CONFIGURE})
    if (${CMAKE_MAJOR_VERSION} GREATER 3 AND ${CMAKE_MINOR_VERSION} GREATER 19)
        if (${CMAKE_C_BYTE_ORDER} EQUAL BIG_ENDIAN)
            target_compile_definitions(${PROJECT_NAME} INTERFACE __BIG_ENDIAN__)
        elseif (${CMAKE_C_BYTE_ORDER} EQUAL LITTLE_ENDIAN)
            target_compile_definitions(${PROJECT_NAME} INTERFACE __LITTLE_ENDIAN__)
        endif ()
    else ()
        include(TestBigEndian)
        test_big_endian(IS_BIG_ENDIAN)
        if (IS_BIG_ENDIAN)
            target_compile_definitions(${PROJECT_NAME} INTERFACE __BIG_ENDIAN__)
        else ()
            target_compile_definitions(${PROJECT_NAME} INTERFACE __LITTLE_ENDIAN__)
        endif ()
    endif ()
endif ()