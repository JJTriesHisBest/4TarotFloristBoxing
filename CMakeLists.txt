cmake_minimum_required (VERSION 2.6)
project (TarotFloristBoxing)
add_library (tfb lib/card.cpp lib/player.cpp)
include_directories ("${PROJECT_SOURCE_DIR}")
add_executable(TarotFloristBoxing app/main.cpp)


