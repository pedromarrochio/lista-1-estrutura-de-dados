#include "ReservationSystem.hpp"
#include <iostream>

using namespace std;


Room :: Room(int capacity){

    this -> capacity = capacity;
    this -> quant_res = 0;
    this -> horarios_res = 0;

    reservas = new Reserve*[this -> res_max];

};

Room :: ~Room(){

    for(int i = 0; i < quant_res; i++)
        delete this -> reservas[i] ;

    delete [] this -> reservas;
    this -> quant_res = 0;
    
};

int Room :: getCapacity(){

    return this -> capacity;

};
    
int Room :: getQuantRes(){

    return this -> quant_res;

};

int Room :: getHoraRes(){

    return this -> horarios_res;

}

int Room :: getResMax(){

    return 65;

};


Reserve ** Room :: getReserves(){

    return this ->  reservas;

};

void Room :: DoReserve(string course_name, string weekday, int start_hour, int end_hour){

    this -> horarios_res += end_hour - start_hour;

    this -> reservas[this -> quant_res] = new Reserve(course_name,weekday,start_hour, end_hour);
    
    this -> quant_res++;

};

void Room :: CancelReserve(int index){

    delete this -> reservas[index];

    for(int i = index; i < (this -> quant_res) - 1; i++)
        reservas[i] = reservas[i+1];

    this -> quant_res--;

    reservas[this -> quant_res] = nullptr;

};



ReservationSystem :: ReservationSystem(int room_count, int* room_capacities){
    this -> room_count = room_count;
    this -> room_capacities = room_capacities;
    string days[] = {"seg", "ter", "qua", "qui", "sex"};
    this -> working_days = days;  
    this -> working_days_size = 5;
    salas = new Room*[room_count];

    for(int i = 0; i < room_count; i++)
        salas[i] = new Room(room_capacities[i]);
};

ReservationSystem :: ~ReservationSystem(){

    for(int i = 0; i < this -> room_count; i++){
        this -> salas[i]->~Room();

        delete this -> salas[i];
    };

    delete[] this -> salas;
};

bool ReservationSystem :: is_working_day(string day){
    for(int i = 0; i < this -> working_days_size; i++){
        if(day == this -> working_days[i]){
            return true; 
        }
    } 
    return false;
}


bool ReservationSystem :: is_overlaping(int request_start, int request_end, int scheduled_start, int scheduled_end){
    if(request_start < scheduled_end && request_start > scheduled_start){
       return true;
    } 
    if(request_end < scheduled_end && request_end > scheduled_start){
        return true;
    }
    return false;
}
bool ReservationSystem :: reserve(ReservationRequest request){
    Room* sala_escolhida;
    if(!this -> is_working_day(request.getWeekday())){
        return false;
    }
    for(int i = 0; i < this -> room_count; i++){
        Room* sala = salas[i];

        if((sala->getCapacity() < request.getStudentCount()) || (sala->getHoraRes() >= sala->getResMax())){
            continue;
        }

        Reserve** reservas = sala->getReserves();

        bool disponivel = true;
        for(int j = 0; j < sala->getQuantRes(); j++){
            Reserve* reserva = reservas[j];
            bool overlaping = is_overlaping(request.getStartHour(), request.getEndHour(), reserva->getStartHour(), reserva->getEndHour());
            if(reserva->getWeekday() == request.getWeekday() && overlaping){
                disponivel = false;
                break;
            }
        };
        if (disponivel){
            sala->DoReserve(request.getCourseName(), request.getWeekday(), request.getStartHour(), request.getEndHour());
            return true;
        }
    
    };

    return false;

};

bool ReservationSystem :: cancel(string course_name){

    for(int i = 0; i < this -> room_count; i++){

        Reserve ** reservas = salas[i]->getReserves();

        for(int j = 0; j < salas[i]->getQuantRes(); j++){

            if(course_name == reservas[j]->getCourseName()){
                salas[i]->CancelReserve(j);
                return true;
            };
        };
    };

    return false;

};



