#ifndef PASSENGER_H
#define PASSENGER_H

#include "User.h"
#include <vector>
using namespace std;

// Passenger class derived from User
class Passenger : public User {
private:
    string passportDetails;
    string visaDetails; // Only relevant for international flights
    vector<string> travelHistory; // Travel history of the passenger

public:
    // Constructor for initializing a Passenger object
    Passenger(string name, string email, string password, string CNIC, string passportDetails)
        : User(name, email, password, CNIC), passportDetails(passportDetails) {}

    // Getter and setter methods for passport details, visa details, and travel history
    string getPassportDetails() const { return passportDetails; }
    void setPassportDetails(const string& passportDetails) { this->passportDetails = passportDetails; }

    string getVisaDetails() const { return visaDetails; }
    void setVisaDetails(const string& visaDetails) { this->visaDetails = visaDetails; }

    vector<string> getTravelHistory() const { return travelHistory; }
    void addTravelHistory(const string& country) { travelHistory.push_back(country); }

    void bookFlight();
    void viewBooking();
    void cancelBooking();
    void updateTravelProfile();

    // Override methods from User class
    void login() override;
    void logout() override;
    void viewProfile() override;
    void updateProfile() override;
};

#endif // PASSENGER_H
