cmake_minimum_required(VERSION 3.8)
project(my-p6-project)

add_executable(${PROJECT_NAME})
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

# Set the folder where the executable is created
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE})

# Add all the files
file(GLOB_RECURSE MY_SOURCES CONFIGURE_DEPENDS src/* include/*)
target_sources(${PROJECT_NAME} PRIVATE ${MY_SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE src include)

# ---Add p6---
add_subdirectory(p6)
target_link_libraries(${PROJECT_NAME} p6::p6)