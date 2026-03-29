# Sistema de Reserva de Salas (Reservation System)

## Descrição do Projeto

Este projeto consiste em um sistema em C++ para o gerenciamento de reservas de salas de aula. O sistema permite cadastrar salas com capacidades específicas, processar solicitações de reserva para disciplinas (verificando disponibilidade de horário, capacidade de alunos e dias úteis) e cancelar reservas existentes. O objetivo principal é garantir que não haja conflitos de horários em uma mesma sala e que a ocupação respeite o limite físico de cada espaço.

## Instruções de Compilação

O projeto é composto por múltiplos arquivos `.cpp` e `.hpp.` Para compilar utilizando o `g++`, utilize o comando abaixo no terminal:

```bash
g++ main.cpp ReservationSystem.cpp ReservationRequest.cpp -o reservation_system
```

## Instruções de Execução

Após a compilação, execute o programa com o seguinte comando:

```bash
./reservation_system
```

## Organização Interna dos Dados

O sistema utiliza uma hierarquia de classes para manter a integridade dos dados e facilitar a busca por disponibilidade:

* ReservationRequest: Atua como um objeto de informação de dados, contendo as informações brutas do pedido (nome da disciplina, dia, horas e quantidade de alunos).

* Reserve: Representa uma reserva confirmada e armazenada. É uma versão simplificada do pedido, focada em armazenar permanentemente os dados.

* Room (Sala): Cada sala possui:

    * Um array dinâmico de ponteiros para objetos Reserve.

    * Sua capacidade máxima de alunos.

    * Um contador de horas totais reservadas para controle interno.

* ReservationSystem: É a classe gestora. Ela contém:

    * Um array de ponteiros para Room.

    * Um array de strings definindo os dias úteis (segunda a sexta).

    * A lógica de negócio para percorrer as salas e encontrar a primeira que satisfaça todos os requisitos de uma ReservationRequest.