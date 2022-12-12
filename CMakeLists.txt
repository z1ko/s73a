cmake_minimum_required (VERSION 3.10)
project(S73A
    DESCRIPTION "A tiny digital synthetizer"
    LANGUAGES CXX
)

# Find project files
file(GLOB_RECURSE SRCS "${PROJECT_SOURCE_DIR}/src/*.cpp")

add_executable(S73A)
target_sources(S73A PRIVATE ${SRCS})
target_include_directories(S73A PRIVATE ${PROJECT_SOURCE_DIR}/src)

find_package(ALSA REQUIRED)
include_directories(${ALSA_INCLUDE_DIRS})
target_link_libraries (S73A ${ALSA_LIBRARIES})