#ifndef LISTA_HPP
#define LISTA_HPP

#include "chamado.hpp"

// Insere uma copia dos dados no final da lista.
// Retorna false se o ID ja estiver cadastrado nessa lista.
bool inserirChamado(NoChamado *&inicio, const Chamado &chamado);

// Percorre e exibe todos os chamados da lista.s
void listarChamados(const NoChamado *inicio);

// Pesquisa por ID. Retorna o endereco do no ou nullptr.
NoChamado *consultarChamado(NoChamado *inicio, int id);

// Remove e desaloca o no com o ID informado.
// Retorna false se o ID nao for encontrado.
bool removerChamado(NoChamado *&inicio, int id);

// Transfere o no de pendentes para atendimento, sem recria-lo.
bool encaminharChamado(
    NoChamado *&pendentes,
    NoChamado *&emAtendimento,
    int id
);

// Transfere o no de atendimento para concluidos.
bool concluirChamado(
    NoChamado *&emAtendimento,
    NoChamado *&concluidos,
    int id
);

// Libera todos os nos de uma lista.
void liberarChamados(NoChamado *&inicio);

#endif
