cmake_minimum_required(VERSION 3.5)
project(autocompletar VERSION 0.1 LANGUAGES CXX )


### Executável
# Diretório contendo os .hpp
include_directories( include )

add_executable( main
                src/main.cpp
                src/dados.cpp
                src/interface.cpp
                src/perfil.cpp)

# The end