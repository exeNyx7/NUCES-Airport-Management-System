#ifndef FLIGHT_H
#define FLIGHT_H

#include <string>
#include <vector>
#include <memory>  // Include this for using unique_ptr
using namespace std;

class Flight {
private:
    string flightID;
    string departureCity;
    string arrivalCity;
    string departureTime;
    string arrivalTime;
    int duration;  // Duration in hours
    int availableSeatsEconomy;  // Number of available economy seats
    int availableSeatsBusiness;  // Number of available business seats
    string status;  // Flight status: On-time, Delayed, Canceled

public:
    // Constructor for initializing a flight object
    Flight(string flightID, string departureCity, string arrivalCity,
        string departureTime, string arrivalTime, int duration,
        int availableSeatsEconomy, int availableSeatsBusiness);

    // Getter methods for flight details
    string getFlightID() const { return flightID; }
    string getDepartureCity() const { return departureCity; }
    string getArrivalCity() const { return arrivalCity; }
    string getDepartureTime() const { return departureTime; }
    string getArrivalTime() const { return arrivalTime; }
    int getDuration() const { return duration; }
    int getAvailableSeatsEconomy() const { return availableSeatsEconomy; }
    int getAvailableSeatsBusiness() const { return availableSeatsBusiness; }
    string getStatus() const { return status; }

    // Method to get flight details
    void getFlightDetails();

    // Method to update the flight status
    void updateFlightStatus(string newStatus);

    // Method to check if the flight is available
    bool isAvailable();

    // Methods to book economy and business class seats
    bool bookEconomySeat();
    bool bookBusinessSeat();

};

#endif // FLIGHT_H
