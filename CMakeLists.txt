cmake_minimum_required(VERSION 3.5)
set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")


project(ButtonGame)

add_executable(ButtonGame

src/main.cpp

src/ButtonGame/ButtonGame.h
src/ButtonGame/ButtonGame.cpp

src/GameEngine/GameEngine.cpp
src/GameEngine/GameEngine.h
src/GameEngine/Renderer.cpp
src/GameEngine/Renderer.h
src/GameEngine/InputManager.cpp
src/GameEngine/InputManager.h


src/Utils/Vector2d.cpp
src/Utils/Vector2d.h
src/Utils/Matrix.h
src/Utils/Matrix.cpp
src/Utils/Mouse.h
src/Utils/Texture.h
src/Utils/Texture.cpp
src/Utils/Rect.h
src/Utils/Rect.cpp
)

set_target_properties(ButtonGame PROPERTIES
    CXX_STANDARD 20
    CXX_EXTENSIONS OFF
)

find_package(SDL2 CONFIG REQUIRED)
find_package(SDL2_image CONFIG REQUIRED)
find_package(SDL2_mixer CONFIG REQUIRED)
find_package(SDL2_ttf CONFIG REQUIRED)
find_package(OpenGL REQUIRED COMPONENTS OpenGL)

target_link_libraries(ButtonGame PRIVATE $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main> $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>)
target_link_libraries(ButtonGame PRIVATE $<IF:$<TARGET_EXISTS:SDL2_image::SDL2_image>,SDL2_image::SDL2_image,SDL2_image::SDL2_image-static>)
target_link_libraries(ButtonGame PRIVATE $<IF:$<TARGET_EXISTS:SDL2_ttf::SDL2_ttf>,SDL2_ttf::SDL2_ttf,SDL2_ttf::SDL2_ttf-static>)
target_link_libraries(ButtonGame PRIVATE $<IF:$<TARGET_EXISTS:SDL2_mixer::SDL2_mixer>,SDL2_mixer::SDL2_mixer,SDL2_mixer::SDL2_mixer-static>)
target_link_libraries(ButtonGame PRIVATE ${OPENGL_LIBRARIES})

# Please please turn me on. (I cry)
target_compile_options(ButtonGame PRIVATE -Wall -Wextra -pedantic)
set_target_properties(ButtonGame PROPERTIES COMPILE_WARNING_AS_ERROR ON)
