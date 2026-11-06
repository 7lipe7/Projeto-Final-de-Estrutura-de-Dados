#include "cliente.hpp"
#include <iostream>
int gerarIdCliente() {
    static int proximoId = 1;
    return proximoId++;
}