#include "chamado.hpp"
#include <iostream>

int gerarIdChamado() {
    static int proximoId = 1;
    return proximoId++;
}

bool clienteExiste(NoCliente* inicio, int id) {
    NoCliente* atual = inicio;

    while (atual != nullptr) {
        if (atual->dados.id == id) {
            return true;
        }

        atual = atual->proximo;
    }

    return false;
}

void abrirChamado(NoCliente* inicioClientes, NoChamado*& inicioChamados) {
    NoChamado* novo = new NoChamado;

    std::cout << "\nDigite o ID do cliente: ";
    std::cin >> novo->dados.clienteId;
    std::cin.ignore();

    if (!clienteExiste(inicioClientes, novo->dados.clienteId)) {
        std::cout << "Cliente nao encontrado! Chamado nao aberto.\n";
        delete novo;
        return;
    }

    novo->dados.id = gerarIdChamado();

    std::cout << "Data de abertura: ";
    std::getline(std::cin, novo->dados.dataAbertura);

    std::cout << "Descricao: ";
    std::getline(std::cin, novo->dados.descricao);

    std::cout << "Categoria: ";
    std::getline(std::cin, novo->dados.categoria);

    std::cout << "Prioridade: ";
    std::getline(std::cin, novo->dados.prioridade);

    novo->dados.tecnicoResponsavel = "Nao atribuido";
    novo->dados.situacao = "Pendente";

    novo->proximo = nullptr;

    if (inicioChamados == nullptr) {
        inicioChamados = novo;
    } else {
        NoChamado* atual = inicioChamados;

        while (atual->proximo != nullptr) {
            atual = atual->proximo;
        }

        atual->proximo = novo;
    }

    std::cout << "\nChamado aberto com sucesso!\n";
    std::cout << "ID do chamado: " << novo->dados.id << '\n';
}