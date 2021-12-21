cmake_minimum_required(VERSION 3.12)

set(SOURCE_FILES hello.cpp RendererConsole.cpp)
set(HEADER_FILES RendererConsole.hpp rlutil.h)
set(PROJECTNAME helloworld)

project(${PROJECTNAME})
add_executable(${PROJECTNAME} ${SOURCE_FILES} ${HEADER_FILES})
set_property(TARGET ${PROJECTNAME} PROPERTY CXX_STANDARD 20)

if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  target_compile_options(${PROJECTNAME} PRIVATE /W4 /permissive-)  
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  target_compile_options(${PROJECTNAME} PRIVATE)
elseif (CMAKE_CXX_COMPILER_ID MATCHES "CLANG")
  target_compile_options(${PROJECTNAME} PRIVATE)
endif()

find_program(CLANG_FORMAT "clang-format")
if (CLANG_FORMAT)
  unset(SOURCE_FILES_PATHS)
  foreach(SOURCE_FILE ${SOURCE_FILES} ${GTEST} ${HEADER_FILES})
    get_source_file_property(WHERE ${SOURCE_FILE} LOCATION)
    set(SOURCE_FILES_PATHS ${SOURCE_FILES_PATHS} ${WHERE})
  endforeach()
  add_custom_target(ClangFormat 
    COMMAND 
    ${CLANG_FORMAT}
    -i
    -style=file
    ${SOURCE_FILES_PATHS}
    )
  add_dependencies(${PROJECTNAME} ClangFormat)
else()
  message("unable to find clang-format")
endif()
