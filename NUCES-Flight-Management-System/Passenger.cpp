#include "Passenger.h"
#include "Validation.h"
#include <iostream>
using namespace std;

// Constructor to initialize passenger details
Passenger::Passenger(string name, string email, string password, string CNIC, string passportDetails)
    : User(name, email, password, CNIC), passportDetails(passportDetails) {}

// Implement login for Passenger
void Passenger::login() {
    cout << "Enter CNIC: ";
    string inputCNIC;
    cin >> inputCNIC;

    if (inputCNIC == CNIC) {
        cout << "Login successful!" << endl;
    }
    else {
        cout << "Invalid CNIC!" << endl;
    }
}

// Implement logout for Passenger
void Passenger::logout() {
    cout << "Logging out..." << endl;
}

// View profile for Passenger
void Passenger::viewProfile() {
    User::viewProfile();  // Call the base class function
    cout << "Passport Details: " << passportDetails << endl;
    cout << "Travel History: ";
    for (const auto& country : travelHistory) {
        cout << country << " ";
    }
    cout << endl;
}

// Update profile for Passenger
void Passenger::updateProfile() {
    cout << "Updating profile..." << endl;
    cout << "Enter new Passport Details: ";
    cin >> passportDetails;
    cout << "Profile updated!" << endl;
}

// Book a flight for Passenger (simplified)
void Passenger::bookFlight() {
    cout << "Booking flight..." << endl;
    // Assume flight and booking logic here
    cout << "
