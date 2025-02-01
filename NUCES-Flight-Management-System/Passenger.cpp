#include "Passenger.h"
#include "Booking.h"
#include "Flight.h"
#include "Payment.h"
#include <iostream>
#include <vector>
using namespace std;

// Constructor to initialize passenger details
Passenger::Passenger(string name, string email, string password, string CNIC, string passportDetails)
    : User(name, email, password, CNIC), passportDetails(passportDetails) {}

// Implement login for Passenger with password check
void Passenger::login() {
    cout << "Enter CNIC: ";
    string inputCNIC;
    cin >> inputCNIC;

    cout << "Enter Password: ";
    string inputPassword;
    cin >> inputPassword;

    if (inputCNIC == CNIC && inputPassword == password) {
        cout << "Login successful!" << endl;
    }
    else {
        cout << "Invalid CNIC or Password!" << endl;
    }
}

void Passenger::bookFlight(vector<unique_ptr<Flight>>& flights, vector<unique_ptr<Booking>>& bookings) {
    cout << "Available Flights:" << endl;
    for (int i = 0; i < flights.size(); i++) {
        flights[i]->getFlightDetails();  // Display available flights
    }

    string flightID;
    cout << "Enter the Flight ID to book: ";
    cin >> flightID;

    string seatClass;
    cout << "Enter seat class (Economy/Business): ";
    cin >> seatClass;

    // Find the selected flight
    Flight* selectedFlight = nullptr;
    for (auto& flight : flights) {
        if (flight->getFlightID() == flightID) {
            selectedFlight = flight.get();
            break;
        }
    }

    if (selectedFlight) {
        // Create a booking
        string bookingID = "BKG" + to_string(bookings.size() + 1); // Simple booking ID generation
        unique_ptr<Booking> newBooking = make_unique<Booking>(bookingID, selectedFlight, this, seatClass);
        newBooking->createBooking();
        bookings.push_back(move(newBooking));  // Add the booking to the list
    }
    else {
        cout << "Flight not found!" << endl;
    }
}

void Passenger::viewBooking(const vector<unique_ptr<Booking>>& bookings) {
    if (bookings.empty()) {
        cout << "No bookings found!" << endl;
        return;
    }

    cout << "Your bookings:" << endl;
    for (int i = 0; i < bookings.size(); ++i) {
        cout << i + 1 << ". " << endl;
        bookings[i]->getBookingDetails();  // Display the booking details
    }

    int bookingChoice;
    cout << "Enter the number of the booking you want to view: ";
    cin >> bookingChoice;

    if (bookingChoice < 1 || bookingChoice > bookings.size()) {
        cout << "Invalid booking choice!" << endl;
        return;
    }

    // Display selected booking details
    const unique_ptr<Booking>& selectedBooking = bookings[bookingChoice - 1];
    selectedBooking->getBookingDetails();
}


void Passenger::cancelBooking(vector<unique_ptr<Booking>>& bookings) {
    string bookingID;
    cout << "Enter Booking ID to cancel: ";
    cin >> bookingID;

    auto it = find_if(bookings.begin(), bookings.end(), [&](const unique_ptr<Booking>& booking) {
        return booking->getBookingID() == bookingID;
        });

    if (it != bookings.end()) {
        (*it)->cancelBooking();
        bookings.erase(it);  // Remove the canceled booking from the list
    }
    else {
        cout << "Booking not found!" << endl;
    }
}
void Passenger::updateTravelProfile() {
    string country;
    cout << "Enter visited country to add to travel history: ";
    cin >> country;
    travelHistory.push_back(country);
    cout << "Travel profile updated!" << endl;
}

// Implement logout for Passenger
void Passenger::logout() {
    cout << "Logging out..." << endl;
}

// View profile for Passenger
void Passenger::viewProfile() {
    User::viewProfile();  // Call the base class function to display common user info
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