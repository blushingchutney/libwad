add_executable(
    test
    test.cxx
)
target_include_directories(test PRIVATE ..)
target_link_libraries(test PRIVATE wad)
