
#include "cliente.hpp"
#include "lista.hpp"

#include <iostream>
#include <limits>

// Leitura segura de numeros inteiros
bool lerInteiro(const char* mensagem, int& valor) {
    std::cout << mensagem;

    if (std::cin >> valor) {
        std::cin.ignore(
            std::numeric_limits<std::streamsize>::max(), '\n'
        );
        return true;
    }

    std::cout << "Entrada invalida!\n";

    std::cin.clear();
    std::cin.ignore(
        std::numeric_limits<std::streamsize>::max(), '\n'
    );

    return false;
}

// Exibe os dados de um chamado
void exibirChamado(const Chamado& chamado) {
    std::cout << "\n----------------------------------------\n";
    std::cout << "ID: " << chamado.id << '\n';
    std::cout << "ID do cliente: " << chamado.clienteId << '\n';
    std::cout << "Data de abertura: " << chamado.dataAbertura << '\n';
    std::cout << "Descricao: " << chamado.descricao << '\n';
    std::cout << "Categoria: " << chamado.categoria << '\n';
    std::cout << "Prioridade: " << chamado.prioridade << '\n';
    std::cout << "Tecnico: " << chamado.tecnicoResponsavel << '\n';
    std::cout << "Situacao: " << chamado.situacao << '\n';
    std::cout << "----------------------------------------\n";
}

int main() {

    // Lista de clientes
    NoCliente* inicio = nullptr;

    // Listas de chamados
    NoChamado* pendentes = nullptr;
    NoChamado* emAtendimento = nullptr;
    NoChamado* concluidos = nullptr;

    int opcao;
    int id;

    do {
        std::cout << "\n========== SISTEMA DE SUPORTE ==========\n";
        std::cout << "1  - Cadastrar cliente\n";
        std::cout << "2  - Consultar cliente\n";
        std::cout << "3  - Abrir chamado\n";
        std::cout << "4  - Listar chamados pendentes\n";
        std::cout << "5  - Listar chamados em atendimento\n";
        std::cout << "6  - Listar chamados concluidos\n";
        std::cout << "7  - Consultar chamado por ID\n";
        std::cout << "8  - Encaminhar chamado\n";
        std::cout << "9  - Concluir chamado\n";
        std::cout << "0  - Sair\n";
        std::cout << "========================================\n";

        if (!lerInteiro("Escolha uma opcao: ", opcao)) {
            continue;
        }

        switch (opcao) {

            case 1:
                std::cout << "\n--- CADASTRO DE CLIENTE ---\n";
                cadastrarCliente(inicio);
                break;

            case 2:
                if (lerInteiro("\nDigite o ID do cliente: ", id)) {
                    consultarCliente(inicio, id);
                }
                break;

            case 3:
                std::cout << "\n--- ABERTURA DE CHAMADO ---\n";

                // Novos chamados entram na lista de pendentes
                abrirChamado(inicio, pendentes);
                break;

            case 4:
                std::cout << "\n--- CHAMADOS PENDENTES ---\n";
                listarChamados(pendentes);
                break;

            case 5:
                std::cout << "\n--- CHAMADOS EM ATENDIMENTO ---\n";
                listarChamados(emAtendimento);
                break;

            case 6:
                std::cout << "\n--- CHAMADOS CONCLUIDOS ---\n";
                listarChamados(concluidos);
                break;

            case 7: {
                if (!lerInteiro("\nDigite o ID do chamado: ", id)) {
                    break;
                }

                NoChamado* encontrado = consultarChamado(pendentes, id);

                if (encontrado != nullptr) {
                    std::cout << "\nChamado encontrado: PENDENTE\n";
                    exibirChamado(encontrado->dados);
                    break;
                }

                encontrado = consultarChamado(emAtendimento, id);

                if (encontrado != nullptr) {
                    std::cout << "\nChamado encontrado: EM ATENDIMENTO\n";
                    exibirChamado(encontrado->dados);
                    break;
                }

                encontrado = consultarChamado(concluidos, id);

                if (encontrado != nullptr) {
                    std::cout << "\nChamado encontrado: CONCLUIDO\n";
                    exibirChamado(encontrado->dados);
                    break;
                }

                std::cout << "\nChamado nao encontrado!\n";
                break;
            }

            case 8:
                if (!lerInteiro("\nID do chamado para encaminhar: ", id)) {
                    break;
                }

                if (encaminharChamado(pendentes, emAtendimento, id)) {
                    std::cout << "\nChamado encaminhado com sucesso!\n";
                } else {
                    std::cout << "\nNao foi possivel encaminhar o chamado.\n";
                    std::cout << "Verifique se o ID existe nos pendentes.\n";
                }
                break;

            case 9:
                if (!lerInteiro("\nID do chamado para concluir: ", id)) {
                    break;
                }

                if (concluirChamado(emAtendimento, concluidos, id)) {
                    std::cout << "\nChamado concluido com sucesso!\n";
                } else {
                    std::cout << "\nNao foi possivel concluir o chamado.\n";
                    std::cout << "Verifique se o ID esta em atendimento.\n";
                }
                break;

            case 0:
                std::cout << "\nEncerrando sistema...\n";
                break;

            default:
                std::cout << "\nOpcao invalida!\n";
                break;
        }

    } while (opcao != 0);

    // Liberacao das tres listas de chamados
    liberarChamados(pendentes);
    liberarChamados(emAtendimento);
    liberarChamados(concluidos);

    // Liberacao da lista de clientes
    liberarClientes(inicio);

    std::cout << "\nMemoria liberada com sucesso!\n";

    return 0;
}
