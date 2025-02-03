add_library(
    wad SHARED
    wad.cxx
    wad.hxx
)

install(
    FILES wad.hxx
    DESTINATION include
)

install(
    TARGETS wad
    DESTINATION lib
)

add_subdirectory(test)
