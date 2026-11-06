#include "chamado.hpp"

int gerarIdChamado() {
    static int proximoId = 1;
    return proximoId++;
}