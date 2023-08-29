cmake_minimum_required(VERSION 3.23)
project(3DSDL1)

set(CMAKE_CXX_STANDARD 14)
set(SDL2_INCLUDE_DIR "C:/Users/klara/Downloads/SDL2-2.28.2/i686-w64-mingw32/include")
set(SDL2_LIBRARY_DIR "C:/Users/klara/Downloads/SDL2-2.28.2/i686-w64-mingw32/lib")
include_directories(${SDL2_INCLUDE_DIR})
add_executable(3DSDL1 main.cpp Screen.cpp Screen.h Matrix.cpp Matrix.h Camera.cpp Camera.h Point.cpp Point.h Controls.cpp Controls.h)
target_link_libraries(3DSDL1 -lmingw32 ${SDL2_LIBRARY_DIR}/libSDL2main.a ${SDL2_LIBRARY_DIR}/libSDL2.dll.a -mwindows)
