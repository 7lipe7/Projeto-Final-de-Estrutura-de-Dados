#include "cliente.hpp"
#include <iostream>
int gerarIdCliente() {
    static int proximoId = 1;
    return proximoId++;
}
void liberarClientes(NoCliente*& inicio) {
    while (inicio != nullptr) {
        NoCliente* temporario = inicio;
        inicio = inicio->proximo;
        delete temporario;
    }
}

void cadastrarCliente(NoCliente*& inicio) {
    NoCliente* novo = new NoCliente;
    
    novo->dados.id = gerarIdCliente();

    std::cout << "Nome: ";
    std::getline(std::cin, novo->dados.nome);

    std::cout << "Telefone: ";
    std::getline(std::cin, novo->dados.telefone);

    std::cout << "Email: ";
    std::getline(std::cin, novo->dados.email);

    std::cout << "Empresa: ";
    std::getline(std::cin, novo->dados.empresa);
    
    novo->proximo = nullptr;
    
    if (inicio == nullptr) {
        inicio = novo;
    } else {
        NoCliente* atual = inicio;

        while (atual->proximo != nullptr) {
            atual = atual->proximo;
        }

        atual->proximo = novo;
    }
}

void consultarCliente(NoCliente* inicio, int id) {
    NoCliente* atual = inicio;

    while (atual != nullptr) {
        if (atual->dados.id == id) {
            std::cout << "Cliente encontrado!\n";
            std::cout << "ID: " << atual->dados.id << '\n';
            std::cout << "Nome: " << atual->dados.nome << '\n';
            std::cout << "Telefone: " << atual->dados.telefone << '\n';
            std::cout << "Email: " << atual->dados.email << '\n';
            std::cout << "Empresa: " << atual->dados.empresa << '\n';
            return;
        }

        atual = atual->proximo;
    }

    std::cout << "Cliente nao encontrado!\n";
    
    
}


