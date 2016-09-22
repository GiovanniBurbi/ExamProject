cmake_minimum_required(VERSION 3.5)

add_subdirectory(./lib/googletest)
set(gtest_SOURCE_DIR, ./lib/googletest/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

find_package(wxWidgets REQUIRED net gl core base)
include(${wxWidgets_USE_FILE})

set(TEST_SOURCE_FILES runAllTests.cpp DownloaderTest.cpp)
add_executable(runGameCharacterTests ${TEST_SOURCE_FILES})
target_link_libraries(runGameCharacterTests gtest gtest_main ${wxWidgets_LIBRARIES} core)


