#ifndef AIRPORT_H
#define AIRPORT_H

#include <string>
#include <vector>
#include "Flight.h"
using namespace std;

// Airport class for storing airport-related details
class Airport {
private:
    string airportCode;
    string city;
    vector<Flight*> availableFlights;  // Flights available at this airport
    vector<Flight*> restrictedFlights; // Flights restricted due to various reasons (e.g., COVID)

public:
    // Constructor for initializing airport details
    Airport(string airportCode, string city);

    // Getter and setter methods for airport details
    string getAirportCode() const { return airportCode; }
    void setAirportCode(const string& code) { airportCode = code; }

    string getCity() const { return city; }
    void setCity(const string& cityName) { city = cityName; }

    // Add a flight to the available flights list
    void addFlight(Flight* flight);

    // Update the status of a flight (e.g., block or unblock)
    void updateFlightStatus(Flight* flight, const string& newStatus);

    // Manage flight restrictions (e.g., block/unblock due to COVID)
    void manageRestrictions(Flight* flight, bool isRestricted);

    // Get the list of available flights at the airport
    void getAvailableFlights() const;

    // Get the list of restricted flights at the airport
    void getRestrictedFlights() const;
};

#endif // AIRPORT_H
