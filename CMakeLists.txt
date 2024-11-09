cmake_minimum_required(VERSION 3.16)
project(CMakeSFMLProject LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_executable(CMakeSFMLProject
    ECS/src/main.cpp
    ECS/src/ECS/Components/RT_Drawable.cpp
    ECS/src/ECS/Components/RT_Enemy.cpp
    ECS/src/ECS/Components/RT_ShootsMulti.cpp
    ECS/src/ECS/Components/RT_CollisionMulti.cpp
    ECS/src/ECS/Loader.cpp
    ECS/src/ECS/Systems/MovementSystem.cpp
    ECS/src/ECS/Systems/PositionSystem.cpp
    ECS/src/ECS/Systems/DrawableSystem.cpp
    ECS/src/ECS/Systems/ControllableSystem.cpp
    ECS/src/ECS/Systems/shootsMultiplayeur.cpp
    ECS/src/ECS/Systems/MusicSystem.cpp
    ECS/include/ECS/Component/RT_Music.hpp
    ECS/src/ECS/Gameplay/parallax.cpp
    ECS/src/utils/createEntity.cpp
    ECS/src/utils/initRegistry.cpp
    Server/src/updates.cpp
    Server/src/makeSpecialEntity.cpp
    Server/src/computeGameplay.cpp
    Server/src/SFserveur.cpp
    Server/src/packetManage.cpp
    Server/src/commandForServer/move.cpp
    Server/src/commandForServer/shot.cpp
    Server/src/entytiFromServeur/sendNewPoseProjectil.cpp
    Server/src/entytiFromServeur/sendNewPoseEnemy.cpp
    Server/src/enemyShoot.cpp
    Server/src/makeEnemyFromFile.cpp
    client/src/getInfo.cpp
    client/src/entityForclient/pickEnemyArgv.cpp
    client/src/entityForclient/pickProjectilArgv.cpp
    client/src/commandeToServeur/shot.cpp
    client/src/commandeToServeur/move.cpp
    client/src/commandeToServeur/clear.cpp
    client/src/SFclientTCP.cpp
    client/src/showGameplay.cpp
)
target_link_libraries(CMakeSFMLProject PUBLIC  sfml-audio sfml-graphics sfml-network)
target_compile_features(CMakeSFMLProject PUBLIC cxx_std_17)
target_include_directories(CMakeSFMLProject PUBLIC 
    ECS/include 
    ECS/include/ECS 
    ECS/include/ECS/Architecture 
    ECS/include/ECS/Component
    ECS/include/Exception
    include
    Server/include
    client/include
)

if (UNIX) 
    include_directories (/usr/include/freetype2)
endif()

if (WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(TARGET CMakeSFMLProject POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:CMakeSFMLProject> $<TARGET_FILE_DIR:CMakeSFMLProject> COMMAND_EXPAND_LISTS)
endif()


file(COPY Assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY map DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

# ---------------------------------UNIT TESTS-------------------------------- #

# if (UNIX) 
#     add_subdirectory(ECS/tests)
# endif()



# ---------------------------------INSTALL-----------------------------------#

# Binaries
install(TARGETS CMakeSFMLProject)
install(DIRECTORY Assets DESTINATION bin)
install(DIRECTORY map DESTINATION bin)
install (TARGETS CMakeSFMLProject DESTINATION bin)


# ----------------------------------PACKAGE--------------------------------- #
set(CPACK_DEBIAN_PACKAGE_NAME "r-type")
set(CPACK_DEBIAN_PACKAGE_VERSION "1.0")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "HEYYYYYY")
set(CPACK_DEBIAN_PACKAGE_CONTACT "dede.dudu@epitech.eu")
set(CPACK_DEBIAN_PACKAGE_DEPENDS "libsfml-dev")


include (CPack)
# set(CPACK_PACKAGE_DESCRIPTION "Just another CPacke example")
# set(CPACK_PACKAGE_VENDOR "ACME")
# set(CPACK_PACKAGE_CONTACT "support@acme.corp")
# set(CPACK_PACKAGE_FILE_NAME "${CMAKE_PROJECT_NAME}...")