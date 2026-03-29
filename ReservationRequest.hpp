#ifndef RESERVATIONREQUEST_HPP
#define RESERVATIONREQUEST_HPP
using   namespace std;
#include <string>

class Reserve{

private: 
    string course_name;
    string weekday;
    int start_hour;
    int end_hour;

public:

    Reserve(string course_name, string weekday, int start_hour, int end_hour);
    int getStartHour();
    int getEndHour();
    string getCourseName();
    string getWeekday();

};


class ReservationRequest {

private:
    string course_name;
    string weekday;
    int start_hour;
    int end_hour;
    int student_count;

public:

    ReservationRequest(string course_name, string weekday, int start_hour, int end_hour, int student_count);
    ~ReservationRequest();

    int getStartHour();
    int getEndHour();
    string getCourseName();
    string getWeekday();
    int getStudentCount();
};

#endif
