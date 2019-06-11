cmake_minimum_required(VERSION 3.14)
project(prueba)

set(CMAKE_CXX_STANDARD 14)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
add_executable(SFMLTest main.cpp Juego.cpp Dado.cpp Ludo.cpp Tablero.cpp Jugador.cpp Ficha.cpp Recorrido.cpp)
target_link_libraries(SFMLTest sfml-graphics sfml-audio)

