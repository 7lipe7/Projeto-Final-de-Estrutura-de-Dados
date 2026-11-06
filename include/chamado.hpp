#ifndef CHAMADO_HPP
#define CHAMADO_HPP

#include <string>

using namespace std;

struct Chamado {
    int id;
    int clienteId;
    string dataAbertura;
    string descricao;
    string categoria;
    string prioridade;
    string tecnicoResponsavel;
    string situacao;
};
int gerarIdChamado();
#endif