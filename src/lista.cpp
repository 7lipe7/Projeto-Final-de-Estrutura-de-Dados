#include "lista.hpp"

#include <iostream>

namespace {
    // Verifica se um ID ja existe na lista.
    bool existeId(const NoChamado* inicio, int id) {
        const NoChamado* atual = inicio;

        while (atual != nullptr) {
            if (atual->dados.id == id) {
                return true;
            }
            atual = atual->proximo;
        }

        return false;
    }

    // Desvincula um no da lista sem liberar sua memoria.
    NoChamado* extrairChamado(NoChamado*& inicio, int id) {
        NoChamado* atual = inicio;
        NoChamado* anterior = nullptr;

        while (atual != nullptr && atual->dados.id != id) {
            anterior = atual;
            atual = atual->proximo;
        }

        if (atual == nullptr) {
            return nullptr;
        }

        if (anterior == nullptr) {
            inicio = atual->proximo;
        } else {
            anterior->proximo = atual->proximo;
        }

        atual->proximo = nullptr;
        return atual;
    }

    // Anexa um no ja existente ao final da lista.
    void anexarNo(NoChamado*& inicio, NoChamado* no) {
        no->proximo = nullptr;

        if (inicio == nullptr) {
            inicio = no;
            return;
        }

        NoChamado* atual = inicio;
        while (atual->proximo != nullptr) {
            atual = atual->proximo;
        }

        atual->proximo = no;
    }
}

bool inserirChamado(NoChamado*& inicio, const Chamado& chamado) {
    if (existeId(inicio, chamado.id)) {
        return false;
    }

    NoChamado* novo = new NoChamado;
    novo->dados = chamado;
    novo->proximo = nullptr;

    anexarNo(inicio, novo);
    return true;
}

void listarChamados(const NoChamado* inicio) {
    if (inicio == nullptr) {
        std::cout << "Nenhum chamado nesta lista.\n";
        return;
    }

    const NoChamado* atual = inicio;

    while (atual != nullptr) {
        std::cout << "\n----------------------------------------\n";
        std::cout << "ID: " << atual->dados.id << '\n';
        std::cout << "ID do cliente: " << atual->dados.clienteId << '\n';
        std::cout << "Data de abertura: " << atual->dados.dataAbertura << '\n';
        std::cout << "Descricao: " << atual->dados.descricao << '\n';
        std::cout << "Categoria: " << atual->dados.categoria << '\n';
        std::cout << "Prioridade: " << atual->dados.prioridade << '\n';
        std::cout << "Tecnico: " << atual->dados.tecnicoResponsavel << '\n';
        std::cout << "Situacao: " << atual->dados.situacao << '\n';

        atual = atual->proximo;
    }

    std::cout << "----------------------------------------\n";
}

NoChamado* consultarChamado(NoChamado* inicio, int id) {
    NoChamado* atual = inicio;

    while (atual != nullptr) {
        if (atual->dados.id == id) {
            return atual;
        }

        atual = atual->proximo;
    }

    return nullptr;
}

bool removerChamado(NoChamado*& inicio, int id) {
    NoChamado* removido = extrairChamado(inicio, id);

    if (removido == nullptr) {
        return false;
    }

    delete removido;
    return true;
}

bool encaminharChamado(
    NoChamado*& pendentes,
    NoChamado*& emAtendimento,
    int id
) {
    // Evita inserir o mesmo ID duas vezes na lista de atendimento.
    if (existeId(emAtendimento, id)) {
        return false;
    }

    NoChamado* transferido = extrairChamado(pendentes, id);

    if (transferido == nullptr) {
        return false;
    }

    transferido->dados.situacao = "Em atendimento";
    anexarNo(emAtendimento, transferido);

    return true;
}

bool concluirChamado(
    NoChamado*& emAtendimento,
    NoChamado*& concluidos,
    int id
) {
    if (existeId(concluidos, id)) {
        return false;
    }

    NoChamado* transferido = extrairChamado(emAtendimento, id);

    if (transferido == nullptr) {
        return false;
    }

    transferido->dados.situacao = "Concluido";
    anexarNo(concluidos, transferido);

    return true;
}

void liberarChamados(NoChamado*& inicio) {
    while (inicio != nullptr) {
        NoChamado* temporario = inicio;
        inicio = inicio->proximo;
        delete temporario;
    }
}
