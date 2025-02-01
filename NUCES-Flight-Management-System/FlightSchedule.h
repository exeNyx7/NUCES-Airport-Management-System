#ifndef FLIGHTSCHEDULE_H
#define FLIGHTSCHEDULE_H

#include <string>
#include <vector>
#include "Flight.h"
using namespace std;

// FlightSchedule class to manage flight schedules
class FlightSchedule {
private:
    string scheduleID;       // Unique identifier for the flight schedule
    Flight* flight;          // The flight associated with this schedule
    string departureTime;    // Departure time for this schedule
    string arrivalTime;      // Arrival time for this schedule

public:
    // Constructor for initializing flight schedule
    FlightSchedule(string scheduleID, Flight* flight, string departureTime, string arrivalTime);

    // Getter methods for schedule details
    string getScheduleID() const { return scheduleID; }
    Flight* getFlight() const { return flight; }
    string getDepartureTime() const { return departureTime; }
    string getArrivalTime() const { return arrivalTime; }

    // Setter methods for schedule details
    void setScheduleID(const string& id) { scheduleID = id; }
    void setDepartureTime(const string& time) { departureTime = time; }
    void setArrivalTime(const string& time) { arrivalTime = time; }

    // Methods to view and edit schedule
    void viewSchedule() const;
    void editSchedule();
    void cancelSchedule();

    // Method to check if the schedule conflicts with another
    bool isScheduleConflict(const vector<FlightSchedule*>& allSchedules) const;
};

#endif // FLIGHTSCHEDULE_H
