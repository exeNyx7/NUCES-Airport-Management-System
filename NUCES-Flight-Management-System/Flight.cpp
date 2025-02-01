#include "Flight.h"
#include <iostream>
using namespace std;

// Constructor for initializing flight details
Flight::Flight(string flightID, string departureCity, string arrivalCity,
    string departureTime, string arrivalTime, int duration,
    int availableSeatsEconomy, int availableSeatsBusiness)
    : flightID(flightID), departureCity(departureCity), arrivalCity(arrivalCity),
    departureTime(departureTime), arrivalTime(arrivalTime), duration(duration),
    availableSeatsEconomy(availableSeatsEconomy), availableSeatsBusiness(availableSeatsBusiness), status("On-time") {}

// Get flight details
void Flight::getFlightDetails() {
    cout << "Flight ID: " << flightID << endl;
    cout << "From: " << departureCity << " To: " << arrivalCity << endl;
    cout << "Departure: " << departureTime << " Arrival: " << arrivalTime << endl;
    cout << "Duration: " << duration << " hours" << endl;
    cout << "Economy seats available: " << availableSeatsEconomy << endl;
    cout << "Business seats available: " << availableSeatsBusiness << endl;
    cout << "Status: " << status << endl;
}

// Update flight status
void Flight::updateFlightStatus(string newStatus) {
    status = newStatus;
    cout << "Flight status updated to: " << status << endl;
}

// Check if the flight has available seats
bool Flight::isAvailable() {
    return (availableSeatsEconomy > 0 || availableSeatsBusiness > 0);
}

// Book an economy seat (simplified)
bool Flight::bookEconomySeat() {
    if (availableSeatsEconomy > 0) {
        availableSeatsEconomy--;
        cout << "Economy seat booked!" << endl;
        return true;
    }
    else {
        cout << "No economy seats available!" << endl;
        return false;
    }
}

// Book a business seat (simplified)
bool Flight::bookBusinessSeat() {
    if (availableSeatsBusiness > 0) {
        availableSeatsBusiness--;
        cout << "Business seat booked!" << endl;
        return true;
    }
    else {
        cout << "No business seats available!" << endl;
        return false;
    }
}
