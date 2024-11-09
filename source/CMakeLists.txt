set(
    LIBWAD_SOURCE_FILES
    wad.cxx
    wad.hxx
)

add_library(
    wad_static STATIC
    ${LIBWAD_SOURCE_FILES}
)

add_library(
    wad_shared SHARED
    ${LIBWAD_SOURCE_FILES}
)

install(
    TARGETS wad_static wad_shared
    DESTINATION lib
)

install(
    FILES wad.hxx
    DESTINATION include
)

add_subdirectory(test)
