#ifndef PASSENGER_H
#define PASSENGER_H

#include "User.h"
#include <vector>
#include <memory>  // Include for unique_ptr
using namespace std;

// Forward declarations of the Flight and Booking classes
class Flight;
class Booking;

// Passenger class derived from User
class Passenger : public User {
private:
    string passportDetails;
    string visaDetails; // Only relevant for international flights
    vector<string> travelHistory; // Travel history of the passenger

public:
    // Constructor for initializing a Passenger object
    Passenger(string name, string email, string password, string CNIC, string passportDetails);

    // Getter and setter methods for passport details, visa details, and travel history
    string getPassportDetails() const { return passportDetails; }
    void setPassportDetails(const string& passportDetails) { this->passportDetails = passportDetails; }

    string getVisaDetails() const { return visaDetails; }
    void setVisaDetails(const string& visaDetails) { this->visaDetails = visaDetails; }

    vector<string> getTravelHistory() const { return travelHistory; }
    void addTravelHistory(const string& country) { travelHistory.push_back(country); }

    // User operations (overridden)
    void login() override;
    void logout() override;
    void viewProfile() override;
    void updateProfile() override;

    // Additional functionality for passengers
    void bookFlight(vector<unique_ptr<Flight>>& availableFlights, vector<unique_ptr<Booking>>& bookings);
    void viewBooking(const vector<unique_ptr<Booking>>& bookings);
    void cancelBooking(vector<unique_ptr<Booking>>& bookings);
    void updateTravelProfile();  // Declare the method
};

#endif // PASSENGER_H
