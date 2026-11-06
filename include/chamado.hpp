#ifndef CHAMADO_HPP
#define CHAMADO_HPP
#include "cliente.hpp"
#include <string>

struct Chamado {
    int id;
    int clienteId;
    std::string dataAbertura;
    std::string descricao;
    std::string categoria;
    std::string prioridade;
    std::string tecnicoResponsavel;
    std::string situacao;
};

struct NoChamado {
    Chamado dados;
    NoChamado* proximo;
    
};

int gerarIdChamado();
void abrirChamado(NoCliente* inicioClientes, NoChamado*& inicioChamados);
#endif