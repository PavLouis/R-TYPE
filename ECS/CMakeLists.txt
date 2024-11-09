cmake_minimum_required(VERSION 3.16)
project(CMakeSFMLProject LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_executable(CMakeSFMLProject
    src/ECS/Components/RT_Drawable.cpp
    src/ECS/Loader.cpp
    src/ECS/Systems/MovementSystem.cpp
    src/ECS/Systems/PositionSystem.cpp
    src/ECS/Systems/DrawableSystem.cpp
    src/ECS/Systems/ControllableSystem.cpp
    src/ECS/Systems/parallaxSystem.cpp
)
target_link_libraries(CMakeSFMLProject PRIVATE sfml-graphics sfml-audio)
target_compile_features(CMakeSFMLProject PRIVATE cxx_std_17)
target_include_directories(CMakeSFMLProject PRIVATE include include/ECS include/ECS/Architecture include/ECS/Component)

if (UNIX) 
    include_directories (/usr/include/freetype2)
endif()

if (WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(TARGET CMakeSFMLProject POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:CMakeSFMLProject> $<TARGET_FILE_DIR:CMakeSFMLProject> COMMAND_EXPAND_LISTS)
endif()

include_directories (/usr/include/freetype2)
install(TARGETS CMakeSFMLProject)

file(COPY sprites DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

# ---------------------------------UNIT TESTS-------------------------------- #

add_subdirectory(tests)

