#include "ReservationSystem.hpp"

using namespace std;


Room :: Room(int capacity){

    this -> capacity = capacity;
    this -> quant_res = 0;

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

int Room :: getResMax(){

    return 65;

};


Reserve ** Room :: getReserves(){

    return this ->  reservas;

};

void Room :: DoReserve(string course_name, string weekday, int start_hour, int end_hour){

    this -> quant_res += end_hour - start_hour;

    this -> reservas[this -> quant_res] = new Reserve(course_name,weekday,start_hour, end_hour);

};



ReservationSystem :: ReservationSystem(int room_count, int* room_capacities){
    this -> room_count = room_count;
    this -> room_capacities = room_capacities;

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


bool ReservationSystem :: reserve(ReservationRequest request){

    for(int i = 0; i < this -> room_count; i++){

        if((salas[i]->getCapacity() >= request.getStudentCount()) && (salas[i]->getQuantRes() < salas[i]->getResMax())){
  
            for(int j = 0; j < salas[i]->getQuantRes(); j++){

                Reserve** reservas = salas[i]->getReserves();

                if(reservas[j]->getWeekday() == request.getWeekday()){

                    if(!((request.getStartHour() >= reservas[j]->getEndHour()) || (request.getEndHour() <= reservas[j]->getStartHour()))){
                        break;

                    };
                };
            };

            salas[i]->DoReserve(request.getCourseName(), request.getWeekday(), request.getStartHour(), request.getEndHour());
            return true;
        
        };
    };

    return false;

};




