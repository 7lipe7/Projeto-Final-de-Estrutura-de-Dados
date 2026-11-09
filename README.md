# Projeto-Final-de-Estrutura-de-Dados

## Status das Atividades de Felipe

### ✅ Concluídas:

1. **Estruturas (struct) de Cliente e Chamado**
   - `cliente.hpp`: struct Cliente (id, nome, telefone, email, empresa) e NoCliente
   - `chamado.hpp`: struct Chamado (id, clienteId, dataAbertura, descricao, categoria, prioridade, tecnicoResponsavel, situacao) e NoChamado

2. **Cadastro de clientes**
   - `clientes.cpp`: função `cadastrarCliente(NoCliente*& inicio)` com IDs únicos auto-gerados

3. **Abertura de chamados**
   - `chamados.cpp`: função `abrirChamado(NoCliente* inicioClientes, NoChamado*& inicioChamados)` com validação de cliente

4. **Consulta de clientes**
   - `clientes.cpp`: função `consultarCliente(NoCliente* inicio, int id)` que pesquisa e exibe dados do cliente

5. **Identificadores únicos**
   - `gerarIdCliente()` e `gerarIdChamado()` usam contadores estáticos starting em 1

### ❌ Pendente:

6. **Desenvolver diagrama de classes ou modelo de domínio**
   - Não existe diagrama ou modelo formal no projeto
   - Seria o próximo item a ser desenvolvido