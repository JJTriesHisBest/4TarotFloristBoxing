cmake_minimum_required (VERSION 2.6)
project (TarotFloristBoxing)

set (CMAKE_CXX_FLAGS "-std=c++11 -g")
set (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake_modules/")

find_Package (SDL2 REQUIRED)
find_Package (SDL2_image REQUIRED)

link_libraries(
    ${SDL2_LIBRARY}
    ${SDL2_IMAGE_LIBRARY}
)

include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${SDL2_INCLUDE_DIR}
)

add_subdirectory (lib)

include_directories ("${PROJECT_SOURCE_DIR}")

add_executable(tfb app/main.cpp)

target_link_libraries(tfb libtfb)

