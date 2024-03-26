cmake_minimum_required(VERSION 3.26)

project(alg)

set(CMAKE_CXX_STANDARD          20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS        OFF)

set(CMAKE_CXX_FLAGS_DEBUG "-g -fsanitize=address,alignment,bool,bounds,enum,float-cast-overflow,float-divide-by-zero,integer-divide-by-zero,nonnull-attribute,null,object-size,return,returns-nonnull-attribute,shift,signed-integer-overflow,undefined,unreachable,vla-bound,vptr")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG")

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

find_package(GTest REQUIRED)
enable_testing()

add_executable(arrays_test ${CMAKE_CURRENT_SOURCE_DIR}/lesson1/arrays_test.cpp
                           ${CMAKE_CURRENT_SOURCE_DIR}/lesson1/arrays.cpp)

add_executable(list_test ${CMAKE_CURRENT_SOURCE_DIR}/lesson2/list_test.cpp)

add_executable(search_test ${CMAKE_CURRENT_SOURCE_DIR}/lesson3/search_test.cpp)

target_link_libraries(arrays_test PRIVATE ${GTEST_LIBRARIES})
target_link_libraries(list_test   PRIVATE ${GTEST_LIBRARIES})
target_link_libraries(search_test   PRIVATE ${GTEST_LIBRARIES})


target_include_directories(arrays_test   PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/lesson1)
target_include_directories(list_test     PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/lesson2)
target_include_directories(search_test   PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/lesson3)


