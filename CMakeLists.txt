cmake_minimum_required(VERSION 3.7)

project(SDL2Test)

FIND_LIBRARY(SDL2_LIB SDL2)
FIND_LIBRARY(SDL2_I SDL2_IMAGE)

set(GRAPHICS inferno/graphics/Texture.cpp inferno/graphics/Sprite.cpp inferno/graphics/TextureManager.cpp)

set(CMAKE_CXX_FLAGS  "-std=c++14 -F/Library/Frameworks -framework SDL2 -framework SDL2_image")
include_directories("/Library/Frameworks/SDL2.framework" "/Library/Frameworks/SDL2_Image.framework" "/usr/local/include")

add_executable(SDLtest main.cpp ${GRAPHICS})
