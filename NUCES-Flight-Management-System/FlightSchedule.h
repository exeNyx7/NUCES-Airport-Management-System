#ifndef FLIGHTSCHEDULE_H
#define FLIGHTSCHEDULE_H

#include <string>
#include <vector>
using namespace std;

class FlightSchedule {
private:
    string scheduleID;
    Flight* flight;
    string departureTime;
    string arrivalTime;

public:
    // Constructor for initializing flight schedule
    FlightSchedule(string scheduleID, Flight* flight, string departureTime, string arrivalTime)
        : scheduleID(scheduleID), flight(flight), departureTime(departureTime), arrivalTime(arrivalTime) {}

    // Getter and setter methods for schedule details
    string getScheduleID() const { return scheduleID; }
    void setScheduleID(const string& scheduleID) { this->scheduleID = scheduleID; }

    string getDepartureTime() const { return departureTime; }
    void setDepartureTime(const string& departureTime) { this->departureTime = departureTime; }

    string getArrivalTime() const { return arrivalTime; }
    void setArrivalTime(const string& arrivalTime) { this->arrivalTime = arrivalTime; }

    // Methods to view and edit schedule
    void viewSchedule();
    void editSchedule();
};

#endif // FLIGHTSCHEDULE_H
