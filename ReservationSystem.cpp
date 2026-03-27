#include "ReservationSystem.hpp"

using namespace std;

ReservationSystem :: ReservationSystem(int room_count, int* room_capacities){
    this -> room_count = room_count;
    this -> room_capacities = room_capacities;

    salas = new Room*[room_count];

    for(int i = 0; i < room_count; i++)
        salas[i] = new Room(room_capacities[i]);
};

ReservationSystem :: ~ReservationSystem(){

    for(int i = 0; i < this -> room_count; i++)
        delete this -> salas[i];

    delete[] this -> salas;
};



