#set text(size: 11pt)
#set page(margin: 1.5cm)

= Relatório — Sistema de Reserva de Salas

== Introdução

Este trabalho apresenta a implementação de um sistema de reserva de salas para alocação de disciplinas ao longo da semana.
O sistema permite criar, cancelar e visualizar reservas, garantindo que não haja conflitos de horário em uma mesma sala.

== Estruturas de Dados Utilizadas

As principais entidades foram representadas por meio de objetos com atributos relevantes e métodos auxiliares.
A estrutura principal do sistema consiste em uma classe que armazena as Salas em um array e essas por sua vez armazenam suas
reservas também em um array.
== Decisões de Implementação

Para cada solicitação de reserva, o sistema percorre sequencialmente as salas e verifica:

1. Se a capacidade é suficiente;
2. Se não há conflito de horário no mesmo dia.

A primeira sala que satisfaz ambas as condições é selecionada.

As reservas são ordenadas por hora de início somente para serem exibidas.
Isso facilita inserção de dados.

== Alternativas Consideradas

Uma alternativa seria utilizar matrizes 2D (salas x horários), representando ocupação por hora.
Essa abordagem simplificaria a verificação de conflitos,
e melhora o uso de memória mas reduz a flexibilidade do sistema como um todo.

Outra opção seria o uso de árvores balanceadas para manter ordenação automática, porém isso foi descartado devido à complexidade de implementação sem STL.

== Trade-offs

O principal trade-off a se considerar é a facilidade de implementação e flexibilidade do código versus a eficiência na busca de dados.
Ademais, é notável a maior eficiência em inserir dados do que resgatá-los, em um caso onde buscar dados fosse
o mais importante, como um hospital com muitos pacientes, as decisões deveriam ser reconsideradas para simplificar esse
processo. Porém, vale destacar que o método utilizado facilita a expansão de funcionalidade e manutenção geral já
que utiliza de programação orientada a objetos. 

= Análise de Complexidade

== 1. Verificações de Conflito (`is_overlaping`)

Esta função realiza apenas comparações matemáticas simples entre quatro números inteiros.

- *Custo:* $O(1)$ (Tempo Constante).
- *Explicação:* O tempo de execução não depende do tamanho do sistema; é uma operação imediata de lógica booleana.

---

== 2. Método `reserve`

O custo depende de quantas salas existem ($N$) e de quantas reservas cada sala já possui ($M$).

- *Custo:* $O(N times M)$.
- *Explicação:*
  - O sistema percorre cada sala disponível ($N$).
  - Para cada sala, ele percorre a lista de reservas existentes ($M$) para verificar conflitos de horário usando `is_overlaping`.
  - No pior caso (sala lotada ou última sala da lista), o custo é o produto dessas duas variáveis.

---

== 3. Método `cancel`

Este método busca uma disciplina específica em todo o sistema para removê-la.

- *Custo:* $O(N times M)$.
- *Explicação:*
  - O sistema itera por todas as salas ($N$) e, dentro de cada uma, varre o array de reservas ($M$) procurando o nome do curso.
  - Quando encontra, a função `CancelReserve` da classe `Room` reorganiza o array (deslocando os elementos para preencher o buraco), o que também custa $O(M)$, mantendo a complexidade geral na mesma ordem.

---

== 4. Método `printSchedule`

Este é o método mais custoso do sistema atual devido à lógica de ordenação e aos loops aninhados.

- *Custo:* $O(N times (M^2 + D times M))$.
- *Explicação:*
  - *Ordenação:* Para cada sala ($N$), *Bubble Sort* é executado no array de reservas ($M$). O custo do Bubble Sort é $O(M^2)$.
  - *Impressão por dia:* Após ordenar, os dias úteis ($D = 5$) são percorridos e, para cada dia, percorre novamente todas as reservas ($M$) para filtrar o que imprimir.
  - Como $M^2$ geralmente cresce mais rápido que $5M$, o custo dominante por sala é a ordenação.

---

== Resumo de Complexidade

#table(
  columns: 3,
  [*Método*], [*Complexidade*], [*Fator Limitante*],
  [`is_overlaping`], [$O(1)$], [Operação atômica.],
  [`reserve`], [$O(N times M)$], [Busca de horários vagos em todas as salas.],
  [`cancel`], [$O(N times M)$], [Busca por nome e reorganização do array.],
  [`printSchedule`], [$O(N times M^2)$], [Ordenação das reservas por sala antes da impressão.]
)

---

*Onde:*
- $N$ = Número de salas.
- $M$ = Quantidade de reservas em uma sala.

== Conclusão

A solução apresentada atende aos requisitos do problema, garantindo consistência das reservas e organização eficiente dos dados. Apesar de simples, a abordagem permite fácil manutenção e pode ser expandida para cenários mais complexos.
