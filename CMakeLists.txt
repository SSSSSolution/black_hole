cmake_minimum_required(VERSION 3.13)

project(
    worm_hole
    VERSION 1.0
    LANGUAGES CXX
)

find_package(r_log REQUIRED)

add_executable(worm_hole
    src/worm_hole.cpp
)
target_include_directories(worm_hole PRIVATE include)
target_link_libraries( worm_hole
    PRIVATE r_log::r_log
)

target_compile_features(worm_hole PUBLIC cxx_std_14)
set_target_properties(worm_hole PROPERTIES CXX_EXTENSIONS OFF)

add_executable(galaxy
    src/galaxy.cpp
)
target_include_directories(galaxy PRIVATE include)
target_link_libraries( galaxy
    PRIVATE r_log::r_log
)

target_compile_features(galaxy PUBLIC cxx_std_14)
set_target_properties(galaxy PROPERTIES CXX_EXTENSIONS OFF)

# install
#set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_BINARY_DIR}/install)
install(TARGETS
    worm_hole
    galaxy
    DESTINATION bin/
)
