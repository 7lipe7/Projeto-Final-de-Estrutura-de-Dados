#include "cliente.hpp"
#include "chamado.hpp"
#include <iostream>

int main() {
    NoCliente* inicio = nullptr;
    NoChamado* inicioChamados = nullptr;

    cadastrarCliente(inicio);
    cadastrarCliente(inicio);

    int id;

    std::cout << "\nDigite o ID para consultar: ";
    std::cin >> id;

    consultarCliente(inicio, id);

    abrirChamado(inicio, inicioChamados);

    // Liberar memoria dos chamados
    while (inicioChamados != nullptr) {
        NoChamado* temporario = inicioChamados;
        inicioChamados = inicioChamados->proximo;
        delete temporario;
    }

    // Liberar memoria dos clientes
    liberarClientes(inicio);

    return 0;
}