cmake_minimum_required(VERSION 3.28)
project(CraftedGame LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(ASSETS_SOURCE_DIR ${CMAKE_SOURCE_DIR}/assets)
set(ASSETS_DESTINATION_DIR ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/assets)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.1
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(CraftedGame 
    src/main.cpp 
    ./src/models/Terrain/Terrain.cpp 
    ./src/models/Unwalkable/Unwalkable.cpp 
    ./src/models/Map/Map.cpp
    ./src/models/Tile/Tile.cpp
    ./src/models/Player/Player.cpp
    ./src/models/Walkable/Walkable.cpp
    ./src/models/Ground/Ground.cpp
    ./src/models/Wall/Wall.cpp
    ./src/models/Drawable/Drawable.cpp
    ./src/models/Item/Item.cpp
)
target_compile_features(CraftedGame PRIVATE cxx_std_17)
target_link_libraries(CraftedGame PRIVATE SFML::Graphics)
