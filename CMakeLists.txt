cmake_minimum_required(VERSION 3.13)

project(
    black_hole
    VERSION 1.0
    LANGUAGES CXX
)

find_package(r_log REQUIRED)

add_executable(black_hole
    src/main.cpp
)
target_include_directories(black_hole PRIVATE include)
target_link_libraries( black_hole
    PRIVATE r_log::r_log
)

target_compile_features(black_hole PUBLIC cxx_std_14)
set_target_properties(black_hole PROPERTIES CXX_EXTENSIONS OFF)

# install
#set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_BINARY_DIR}/install)
install(TARGETS
    black_hole
    DESTINATION bin/
)
