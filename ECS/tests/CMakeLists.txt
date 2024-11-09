if (WIN32)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif()

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)
FetchContent_MakeAvailable(googletest)

add_executable(unit_tests 
    ECS/Architecture/testEntity.cpp
    ECS/Architecture/testSparseArray.cpp
)

target_include_directories(unit_tests PRIVATE ${CMAKE_SOURCE_DIR}ECS/include/ECS/Architecture)
target_link_libraries(unit_tests GTest::gtest_main)


include(CTest)
add_test(NAME unit_tests COMMAND unit_tests)