#ifndef FLIGHT_H
#define FLIGHT_H

#include <string>
#include <vector>
using namespace std;

class Flight {
private:
    string flightID;
    string departureCity;
    string arrivalCity;
    string departureTime;
    string arrivalTime;
    int duration; // Duration in hours
    int availableSeatsEconomy;
    int availableSeatsBusiness;
    string status; // On-time, delayed, canceled

public:
    // Constructor for initializing a flight object
    Flight(string flightID, string departureCity, string arrivalCity,
        string departureTime, string arrivalTime, int duration,
        int availableSeatsEconomy, int availableSeatsBusiness)
        : flightID(flightID), departureCity(departureCity), arrivalCity(arrivalCity),
        departureTime(departureTime), arrivalTime(arrivalTime), duration(duration),
        availableSeatsEconomy(availableSeatsEconomy), availableSeatsBusiness(availableSeatsBusiness), status("On-time") {}

    // Getter and setter methods for flight details
    string getFlightID() const { return flightID; }
    void setFlightID(const string& flightID) { this->flightID = flightID; }

    string getDepartureCity() const { return departureCity; }
    void setDepartureCity(const string& departureCity) { this->departureCity = departureCity; }

    string getArrivalCity() const { return arrivalCity; }
    void setArrivalCity(const string& arrivalCity) { this->arrivalCity = arrivalCity; }

    string getDepartureTime() const { return departureTime; }
    void setDepartureTime(const string& departureTime) { this->departureTime = departureTime; }

    string getArrivalTime() const { return arrivalTime; }
    void setArrivalTime(const string& arrivalTime) { this->arrivalTime = arrivalTime; }

    int getDuration() const { return duration; }
    void setDuration(int duration) { this->duration = duration; }

    int getAvailableSeatsEconomy() const { return availableSeatsEconomy; }
    void setAvailableSeatsEconomy(int seats) { availableSeatsEconomy = seats; }

    int getAvailableSeatsBusiness() const { return availableSeatsBusiness; }
    void setAvailableSeatsBusiness(int seats) { availableSeatsBusiness = seats; }

    string getStatus() const { return status; }
    void setStatus(const string& status) { this->status = status; }

    // Methods to update flight status and get flight details
    void updateFlightStatus(const string& newStatus) {
        status = newStatus;
    }

    void getFlightDetails() const {
        cout << "Flight ID: " << flightID << endl;
        cout << "Departure City: " << departureCity << endl;
        cout << "Arrival City: " << arrivalCity << endl;
        cout << "Departure Time: " << departureTime << endl;
        cout << "Arrival Time: " << arrivalTime << endl;
        cout << "Duration: " << duration << " hours" << endl;
        cout << "Economy Seats Available: " << availableSeatsEconomy << endl;
        cout << "Business Seats Available: " << availableSeatsBusiness << endl;
        cout << "Flight Status: " << status << endl;
    }

    // Methods to book seats
    bool bookEconomySeat() {
        if (availableSeatsEconomy > 0) {
            availableSeatsEconomy--;
            cout << "Economy seat booked!" << endl;
            return true;
        }
        return false;
    }

    bool bookBusinessSeat() {
        if (availableSeatsBusiness > 0) {
            availableSeatsBusiness--;
            cout << "Business seat booked!" << endl;
            return true;
        }
        return false;
    }
};

#endif // FLIGHT_H
