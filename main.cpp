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
  int capacities[] = {10, 20, 30, 40};

  ReservationSystem system(4, capacities); 

  ReservationRequest request_1("E.D.", "segunda", 7, 13, 40);
  ReservationRequest request_2("P.A.A", "segunda", 13, 21, 40);
  ReservationRequest request_3("A.L.N.", "segunda", 7, 12, 40);
  ReservationRequest request_4("Prob.", "terca", 16, 18, 50);
  ReservationRequest request_5("E.D.O.", "segunda", 11, 11, 15);
  ReservationRequest request_6("Calculo 1", "quinta", 12, 14, 30);
  ReservationRequest request_7("Intro. Comp.", "sexta", 7, 12, 10);
  ReservationRequest request_8("G.A.", "quarta", 16, 18, 20);
  
  system.reserve(request_1); 

  system.reserve(request_2);

   system.reserve(request_3);

  system.reserve(request_4);
  
  system.reserve(request_5); 

  system.reserve(request_6);

   system.reserve(request_7);

  system.reserve(request_8);

  system.cancel("E.D.");

  system.printSchedule();

  return 0;

}
