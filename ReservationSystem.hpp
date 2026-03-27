#ifndef RESERVATIONSISTEM_HPP
#define RESERVATIONSISTEM_HPP

using namespace std;
#include <string>
#include "ReservationRequest.hpp"




class Room{

private:

    int capacity;
    int quant_res;
    Reserve ** reservas;
    static const int cap_max = 65;

public:

    Room(int capacity);
    ~Room();

    void DoReserve();

    int getCapacity();
    int getQuantRes();

};

class ReservationSystem {

private:
    int room_count;
    int* room_capacities;
    Room **salas;

    // Estruturas internas escolhidas pelos alunos
    // para armazenar e gerenciar as reservas, os horários, ...

public:

    ReservationSystem(int room_count, int* room_capacities);
    ~ReservationSystem();

    bool reserve(ReservationRequest request);
    bool cancel(string course_name);

    void printSchedule();

    // Outros métodos utilitários necessários
    // para auxiliar nas funções requisitadas
};

#endif