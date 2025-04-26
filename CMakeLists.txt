cmake_minimum_required(VERSION 3.16)
project(REPLACE_WITH_YOUR_PROJECT_NAME)

set(CMAKE_CXX_STANDARD 17)

cmake_policy(SET CMP0135 NEW)

include(FetchContent)
set(FETCHCONTENT_QUIET FALSE)

FetchContent_Declare(
    ptsd

    URL         https://github.com/ntut-open-source-club/practical-tools-for-simple-design/archive/refs/tags/v0.2.zip

    # Or alternatively if you want to use a specific git commit instead of a release:
    # GIT_REPOSITORY  https://github.com/ntut-open-source-club/practical-tools-for-simple-design.git
    # GIT_TAG         <git_tag>

    SOURCE_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/PTSD
)

FetchContent_MakeAvailable(ptsd)

include(files.cmake)
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
list(TRANSFORM SRC_FILES PREPEND ${SRC_DIR}/)
list(TRANSFORM INCLUDE_FILES PREPEND ${INCLUDE_DIR}/)

# file(GLOB_RECURSE SRC_FILES src/*)
# file(GLOB_RECURSE HEADER_FILES include/*)

add_executable(${PROJECT_NAME}
        App/main.cpp

        # Header files
        include/Object/Object.hpp
        include/Object/IGravityObject.hpp
        include/Object/ICollisionObject.hpp

        include/Mario/Mario.hpp

        include/Monsters/Monster.hpp
        include/Monsters/Mushroom.hpp
        include/Monsters/Turtle.hpp
        include/Monsters/BlackTurtle.hpp
        include/Monsters/FlyTurtle.hpp
        include/Monsters/EatFlower.hpp
        include/Monsters/Kooper.hpp
        include/Monsters/JumpTurtle.hpp

        include/Blocks/Block.hpp
        include/Blocks/LuckyBlock.hpp
        include/Blocks/FootBlock.hpp
        include/Blocks/PipeBlock.hpp
        include/Blocks/AirBlock.hpp
        include/Blocks/OriginalBlock.hpp

        include/Items/ItemObject.hpp
        include/Items/CoinItem.hpp
        include/Items/MushroomItem.hpp
        include/Items/FireFlowerItem.hpp
        include/Items/Fireball.hpp

        include/Managers/SceneManager.hpp
        include/Managers/GravityManager.hpp
        include/Managers/CollisionManager.hpp
        include/Managers/BlockManager.hpp
        include/Managers/MonsterManager.hpp
        include/Managers/ItemManager.hpp
        include/Managers/MarioManager.hpp

        include/Flags/Flag.hpp

        include/Enums/ObjectType.hpp
        include/Enums/MonsterType.hpp
        include/Enums/BlockType.hpp
        include/Enums/ItemType.hpp
        include/Enums/MarioState.hpp
        include/Enums/WayType.hpp

        # Source files (.cpp)
        src/Object/Object.cpp
        src/Object/IGravityObject.cpp
        src/Object/ICollisionObject.cpp

        src/Mario/Mario.cpp

        src/Monsters/Monster.cpp
        src/Monsters/Mushroom.cpp
        src/Monsters/Turtle.cpp
        src/Monsters/BlackTurtle.cpp
        src/Monsters/FlyTurtle.cpp
        src/Monsters/EatFlower.cpp
        src/Monsters/Kooper.cpp
        src/Monsters/JumpTurtle.cpp

        src/Blocks/Block.cpp
        src/Blocks/LuckyBlock.cpp
        src/Blocks/FootBlock.cpp
        src/Blocks/PipeBlock.cpp
        src/Blocks/AirBlock.cpp
        src/Blocks/OriginalBlock.cpp

        src/Items/ItemObject.cpp
        src/Items/CoinItem.cpp
        src/Items/MushroomItem.cpp
        src/Items/FireFlowerItem.cpp
        src/Items/Fireball.cpp

        src/Managers/SceneManager.cpp
        src/Managers/GravityManager.cpp
        src/Managers/CollisionManager.cpp
        src/Managers/BlockManager.cpp
        src/Managers/MonsterManager.cpp
        src/Managers/ItemManager.cpp
        src/Managers/MarioManager.cpp

        src/Flags/Flag.cpp

        src/Enums/ObjectType.cpp
        src/Enums/MonsterType.cpp
        src/Enums/BlockType.cpp
        src/Enums/ItemType.cpp
        src/Enums/MarioState.cpp
        src/Enums/WayType.cpp
)



if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic)
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(${PROJECT_NAME} PRIVATE RESOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}/Resources")
else()
    message(FATAL_ERROR "relative RESOURCE_DIR is WIP, Please use `-DCMAKE_BUILD_TYPE=Debug` build for now.")
    # target_compile_definitions(${PROJECT_NAME} PRIVATE RESOURCE_DIR="${CMAKE_INSTALL_PREFIX}/Resources")
endif()

target_include_directories(${PROJECT_NAME} SYSTEM PRIVATE ${DEPENDENCY_INCLUDE_DIRS})
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/PTSD/include)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(${PROJECT_NAME}
    SDL2::SDL2main
    PTSD
)
