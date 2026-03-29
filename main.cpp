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
//  - consertar destrutor
//  - print de reservas 

int main(){
  int capacities[] = {90};
  // Possível problema no destrutor
  ReservationSystem system(1, capacities); // checar para passagem de menos capacidades do que de quartos

  ReservationRequest request_1("Ed", "seg", 11, 13, 11);
  ReservationRequest request_2("Paa", "seg", 12, 14, 11);
  ReservationRequest request_3("Aln", "seg", 7, 12, 11);
  ReservationRequest request_4("Prob", "ter", 16, 18, 50);

  cout << "Esperado: 1" << endl;
  cout << "Resultado 1a reserva: " << system.reserve(request_1) << endl; 

  cout << "Esperado: 0" << endl;
  cout << "Resultado 2a reserva: " << system.reserve(request_2) << endl;

  cout << "Esperado: 0" << endl;
  cout << "Resultado 3a reserva: " << system.reserve(request_3) << endl;

  cout << "Esperado: 1" << endl;
  cout << "Resultado 4a reserva: " << system.reserve(request_4) << endl;

  system.cancel("Ed");

  system.printSchedule();
 
  cout << "teste insano" << endl;
  return 0;
}
