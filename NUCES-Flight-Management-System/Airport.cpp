#include "Airport.h"
#include "Flight.h"
#include <iostream>
#include <vector>
using namespace std;

// Constructor for initializing airport details
Airport::Airport(string airportCode, string city) : airportCode(airportCode), city(city) {}

// Add flight to the airport's available flights list
void Airport::addFlight(Flight* flight) {
    availableFlights.push_back(flight);
    cout << "Flight with ID: " << flight->getFlightID() << " added to airport " << airportCode << endl;
}

// Update flight status (e.g., block due to restrictions)
void Airport::updateFlightStatus(Flight* flight, const string& newStatus) {
    flight->updateFlightStatus(newStatus);
    cout << "Flight with ID: " << flight->getFlightID() << " has been updated to status: " << newStatus << endl;
}

// Manage flight restrictions (e.g., block flights due to COVID)
void Airport::manageRestrictions(Flight* flight, bool isRestricted) {
    if (isRestricted) {
        restrictedFlights.push_back(flight);
        cout << "Flight with ID: " << flight->getFlightID() << " has been restricted due to COVID." << endl;
    }
    else {
        // Remove the flight from restricted flights list
        restrictedFlights.erase(remove(restrictedFlights.begin(), restrictedFlights.end(), flight), restrictedFlights.end());
        cout << "Flight with ID: " << flight->getFlightID() << " is no longer restricted." << endl;
    }
}

// Get all available flights at the airport
void Airport::getAvailableFlights() const {
    cout << "Available flights at airport " << airportCode << " (" << city << "):" << endl;
    if (availableFlights.empty()) {
        cout << "No available flights." << endl;
        return;
    }

    for (const auto& flight : availableFlights) {
        flight->getFlightDetails();
    }
}

// Get the list of restricted flights
void Airport::getRestrictedFlights() const {
    cout << "Restricted flights at airport " << airportCode << " (" << city << "):" << endl;
    if (restrictedFlights.empty()) {
        cout << "No restricted flights." << endl;
        return;
    }

    for (const auto& flight : restrictedFlights) {
        flight->getFlightDetails();
    }
}
