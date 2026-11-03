#ifndef CLIENTES_HPP
#define CLIENTES_HPP

#include <string>

struct Cliente {
    int id;
    std::string nome;
    std::string telefone;
    std::string email;
    std::string empresa;
};

#endif