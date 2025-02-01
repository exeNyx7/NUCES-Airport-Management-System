#include "FlightSchedule.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Constructor for initializing flight schedule
FlightSchedule::FlightSchedule(string scheduleID, Flight* flight, string departureTime, string arrivalTime)
    : scheduleID(scheduleID), flight(flight), departureTime(departureTime), arrivalTime(arrivalTime) {}

// View schedule details
void FlightSchedule::viewSchedule() const {
    cout << "Flight Schedule ID: " << scheduleID << endl;
    cout << "Flight ID: " << flight->getFlightID() << endl;
    cout << "Departure Time: " << departureTime << endl;
    cout << "Arrival Time: " << arrivalTime << endl;
}

// Edit flight schedule
void FlightSchedule::editSchedule() {
    cout << "Editing schedule for Flight ID: " << flight->getFlightID() << endl;
    cout << "Enter new Departure Time (HH:MM): ";
    cin >> departureTime;
    cout << "Enter new Arrival Time (HH:MM): ";
    cin >> arrivalTime;
    cout << "Schedule updated!" << endl;
}

// Cancel the flight schedule
void FlightSchedule::cancelSchedule() {
    cout << "Canceling schedule for Flight ID: " << flight->getFlightID() << endl;
    // Logic for canceling the schedule
    // You can add functionality to remove this schedule from a global schedule list
    cout << "Schedule canceled!" << endl;
}

// Check if the schedule conflicts with another schedule
bool FlightSchedule::isScheduleConflict(const vector<FlightSchedule*>& allSchedules) const {
    for (const auto& schedule : allSchedules) {
        if (schedule->getFlight() == this->flight) {
            // Check if departure times or arrival times overlap with any existing schedule
            if (schedule->getDepartureTime() == this->departureTime || schedule->getArrivalTime() == this->arrivalTime) {
                return true; // Conflict found
            }
        }
    }
    return false; // No conflict
}
