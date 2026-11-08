
#include "cliente.hpp"
#include "chamado.hpp"
#include <iostream>
#include <limits>

int main() {
    NoCliente* inicio = nullptr;
    NoChamado* inicioChamados = nullptr;

    int opcao;
    int id;

    do {
        std::cout << "\n========== SISTEMA DE SUPORTE ==========\n";
        std::cout << "1 - Cadastrar cliente\n";
        std::cout << "2 - Consultar cliente\n";
        std::cout << "3 - Abrir chamado\n";
        std::cout << "0 - Sair\n";
        std::cout << "========================================\n";
        std::cout << "Escolha uma opcao: ";

        if (!(std::cin >> opcao)) {
            std::cout << "\nEntrada invalida!\n";
            std::cin.clear();
            std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(), '\n'
            );
            continue;
        }

        std::cin.ignore(
            std::numeric_limits<std::streamsize>::max(), '\n'
        );

        switch (opcao) {

            case 1:
                std::cout << "\n--- CADASTRO DE CLIENTE ---\n";
                cadastrarCliente(inicio);
                std::cout << "\nCliente cadastrado!\n";
                break;

            case 2:
                std::cout << "\nDigite o ID do cliente: ";
                if (std::cin >> id) {
                    consultarCliente(inicio, id);
                } else {
                    std::cout << "ID invalido!\n";
                    std::cin.clear();
                }
                std::cin.ignore(
                    std::numeric_limits<std::streamsize>::max(), '\n'
                );
                break;

            case 3:
                std::cout << "\n--- ABERTURA DE CHAMADO ---\n";
                abrirChamado(inicio, inicioChamados);
                break;

            case 0:
                std::cout << "\nEncerrando sistema...\n";
                break;

            default:
                std::cout << "\nOpcao invalida!\n";
                break;
        }

    } while (opcao != 0);

    // Liberar memoria dos chamados
    while (inicioChamados != nullptr) {
        NoChamado* temporario = inicioChamados;
        inicioChamados = inicioChamados->proximo;
        delete temporario;
    }

    // Liberar memoria dos clientes
    liberarClientes(inicio);

    std::cout << "Memoria liberada com sucesso!\n";

    return 0;
}
