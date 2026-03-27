#include "ReservationRequest.hpp"
#include <string>

using namespace std;

ReservationRequest :: ReservationRequest(string course_name, string weekday, int start_hour, int end_hour, int student_count){

        this -> course_name = course_name;
        this -> weekday = weekday;
        this -> start_hour = start_hour;
        this -> end_hour = end_hour;
        this -> student_count = student_count;

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


