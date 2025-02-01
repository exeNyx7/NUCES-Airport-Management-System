#include "FlightSchedule.h"
#include <iostream>
#include <stdexcept>
#include "./FlightSchedule.h"
#include "./Flight.h"
using namespace std;

// Constructor for initializing flight schedule
FlightSchedule::FlightSchedule(string scheduleID, Flight* flight, string departureTime, string arrivalTime)
    : scheduleID(scheduleID), flight(flight), departureTime(departureTime), arrivalTime(arrivalTime) {}

// View schedule details
void FlightSchedule::viewSchedule() {
    cout << "Flight Schedule Details:" << endl;
    cout << "Schedule ID: " << scheduleID << endl;
    cout << "Flight ID: " << flight->getFlightID() << endl;
    cout << "Departure Time: " << departureTime << endl;
    cout << "Arrival Time: " << arrivalTime << endl;
}

// Edit flight schedule
void FlightSchedule::editSchedule() {
    cout << "Editing flight schedule..." << endl;
    cout << "Enter new departure time: ";
    cin >> departureTime;
    cout << "Enter new arrival time: ";
    cin >> arrivalTime;
    cout << "Flight schedule updated!" << endl;
}

// Getters for schedule details
string FlightSchedule::getScheduleID() const {
    return scheduleID;
}

string FlightSchedule::getDepartureTime() const {
    return departureTime;
}

string FlightSchedule::getArrivalTime() const {
    return arrivalTime;
}
