#include "ReservationRequest.hpp"
#include "ReservationSystem.hpp"
#include <iostream>

using namespace std;

// Eu quero testar:
// - menos capacidades que salas 
// - várias salas com sucesso na reserva
// - sala com falha por:
//  - começo conflitante
//  - fim conflitante
//  - numero de alunos excedente as capacidades
//  - dia lotado
//  - horário fora do funcionamento (fora do intervalo [7, 21])
//  - dia inválido (precisamos definir um array com os dias úteis


// TODO:
//  - Tratamento de erro para quando não há salas com capacidade suficiente
//   - Atualmente ele dá seg_fault quando eu tento reservar:
        // int capacities[] = {2, 11 , 4}; não há 2 salas com 
        // ReservationRequest request_1("Ed", "seg", 7, 8, 5);
        // ReservationRequest request_2("Paa", "ter", 9, 10, 5);
//  - Basicamente qualquer falha em reserva resulta em um seg_fault
//  - Esta dando erro para dias diferentes da semana com mesmo horário

int main(){
  int capacities[] = {2, 11 , 4};
  // Possível problema no destrutor
  ReservationSystem system(3, capacities); // checar para passagem de menos capacidades do que de quartos

  ReservationRequest request_1("Ed", "seg", 7, 8, 1);
  ReservationRequest request_2("Paa", "seg", 10, 11, 1);
  // ReservationRequest request_3("Aln", "terca", 7, 8, 1);

  cout << "Esperado: 1" << endl;
  cout << "Resultado 1a reserva: " << system.reserve(request_1) << endl; 

  cout << "Esperado: 1" << endl;
  cout << "Resultado 2a reserva: " << system.reserve(request_2) << endl;

  // cout << "Esperado: 1" << endl;
  // cout << "Resultado 3a reserva: " << system.reserve(request_3) << endl;
 
  cout << "teste insano" << endl;
  return 0;
}
