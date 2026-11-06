cmake_minimum_required(VERSION 4.3)
project(Projeto_Final_de_Estrutura_de_Dados)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(Projeto_Final_de_Estrutura_de_Dados
        include/chamado.hpp
        include/cliente.hpp
        src/chamados.cpp
        src/clientes.cpp
        src/main.cpp
        include/chamado.hpp
        include/chamado.hpp 

)
