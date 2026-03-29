#include "ReservationRequest.hpp"
#include <string>
#include <iostream>

using namespace std;

ReservationRequest :: ReservationRequest(string course_name, string weekday, int start_hour, int end_hour, int student_count){

        this -> course_name = course_name;
        this -> weekday = weekday;
        this -> student_count = student_count;
        this -> end_hour = 0;
        this -> start_hour = 0;

        if((start_hour < end_hour) && ( 7 <= start_hour) && (end_hour <= 21)){

            this -> end_hour = end_hour;
            this -> start_hour = start_hour;
            
        };
};

ReservationRequest :: ~ReservationRequest(){
};

string ReservationRequest :: getCourseName(){

    return this -> course_name;

};  

string ReservationRequest :: getWeekday(){

    return this -> weekday;

};

int ReservationRequest :: getEndHour(){

    return this -> end_hour;

};

int ReservationRequest :: getStartHour(){

    return this -> start_hour;

};

int ReservationRequest :: getStudentCount(){

    return this -> student_count;

};

Reserve :: Reserve(string course_name, string weekday, int start_hour, int end_hour){

        this -> course_name = course_name;
        this -> weekday = weekday;
        this -> start_hour = start_hour;
        this -> end_hour = end_hour;    

};


string Reserve :: getWeekday(){

    return this -> weekday;

};

int Reserve :: getEndHour(){

    return this -> end_hour;

};

int Reserve :: getStartHour(){

    return this -> start_hour;

};

string Reserve :: getCourseName(){

    return this -> course_name;

};  


