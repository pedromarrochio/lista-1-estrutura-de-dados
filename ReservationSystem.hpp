#ifndef RESERVATIONSISTEM_HPP
#define RESERVATIONSISTEM_HPP

using namespace std;
#include <string>
#include "ReservationRequest.hpp"




class Room{

private:

    int capacity;
    int quant_res;
    int horarios_res;
    Reserve ** reservas;
    static const int res_max = 65;

public:

    Room(int capacity);
    ~Room();

    int getCapacity();
    int getQuantRes();
    int getHoraRes();
    int getResMax();
    Reserve ** getReserves();

    void DoReserve(string course_name, string weekday, int start_hour, int end_hour);
    void CancelReserve(int index);

};

class ReservationSystem {

private:
    int room_count;
    int* room_capacities;
    Room **salas;
    string* working_days;
    int working_days_size;


public:

    ReservationSystem(int room_count, int* room_capacities);
    ~ReservationSystem();

    bool reserve(ReservationRequest request);
    bool cancel(string course_name);

    void printSchedule();
    bool is_working_day(string day);
    bool is_overlaping(int request_start, int request_end, int scheduled_start, int scheduled_end);

};

#endif
