#include "Admin.h"
#include "Flight.h"
#include "Airport.h"
#include "Booking.h"
#include <iostream>
#include <vector>
#include <memory>
using namespace std;

// Constructor to initialize admin details
Admin::Admin(string name, string email, string password, string CNIC, string adminID)
    : User(name, email, password, CNIC), adminID(adminID) {}

// Implement login for Admin
void Admin::login() {
    cout << "Enter Admin ID: ";
    string inputID;
    cin >> inputID;

    if (inputID == adminID) {
        cout << "Admin login successful!" << endl;
    }
    else {
        cout << "Invalid Admin ID!" << endl;
    }
}

// Implement logout for Admin
void Admin::logout() {
    cout << "Admin logging out..." << endl;
}

// View profile for Admin (override)
void Admin::viewProfile() {
    User::viewProfile();  // Call the base class function to display common user info
    cout << "Admin ID: " << adminID << endl;
    cout << "Permissions: ";
    for (const auto& perm : permissions) {
        cout << perm << " ";
    }
    cout << endl;
}

// Update profile for Admin (override)
void Admin::updateProfile() {
    cout << "Updating admin profile..." << endl;
    cout << "Enter new Admin ID: ";
    cin >> adminID;
    cout << "Profile updated!" << endl;
}

// Add flight for Admin
void Admin::addFlight() {
    string flightID, departureCity, arrivalCity, departureTime, arrivalTime;
    int duration, availableSeatsEconomy, availableSeatsBusiness;

    cout << "Enter Flight ID: ";
    cin >> flightID;
    cout << "Enter Departure City: ";
    cin >> departureCity;
    cout << "Enter Arrival City: ";
    cin >> arrivalCity;
    cout << "Enter Departure Time (HH:MM format): ";
    cin >> departureTime;
    cout << "Enter Arrival Time (HH:MM format): ";
    cin >> arrivalTime;
    cout << "Enter Duration (in hours): ";
    cin >> duration;
    cout << "Enter Available Economy Seats: ";
    cin >> availableSeatsEconomy;
    cout << "Enter Available Business Seats: ";
    cin >> availableSeatsBusiness;

    // Create a new flight and add it to the system
    unique_ptr<Flight> newFlight = make_unique<Flight>(flightID, departureCity, arrivalCity, departureTime, arrivalTime,
        duration, availableSeatsEconomy, availableSeatsBusiness);
    cout << "Flight " << flightID << " added successfully!" << endl;
    // You can add the flight to a global flight list here (assuming you have a system-wide flight collection)
    // flights.push_back(move(newFlight)); // If you have a flight vector
}

// Edit flight schedule for Admin
void Admin::editFlightSchedule() {
    string flightID;
    cout << "Enter Flight ID to edit: ";
    cin >> flightID;

    // Logic to find the flight by ID and allow edits
    // For example, we can change the departure and arrival times
    string newDepartureTime, newArrivalTime;
    cout << "Enter new Departure Time (HH:MM format): ";
    cin >> newDepartureTime;
    cout << "Enter new Arrival Time (HH:MM format): ";
    cin >> newArrivalTime;

    // Assuming you have a method to search for the flight by ID, and modify it.
    // For now, we'll just print the new times
    cout << "Flight " << flightID << " schedule updated!" << endl;
    cout << "New Departure Time: " << newDepartureTime << endl;
    cout << "New Arrival Time: " << newArrivalTime << endl;
}

// Block flight for Admin (COVID-related restriction)
void Admin::blockFlight() {
    string flightID;
    cout << "Enter Flight ID to block: ";
    cin >> flightID;

    // Logic to block the flight due to COVID or other reasons
    // In reality, this could update the flight status to 'Blocked'
    cout << "Flight " << flightID << " has been blocked due to restrictions." << endl;

    // For example, update the flight status in the system (assuming a Flight object has a status property)
    // flight.setStatus("Blocked");
}

// Manage flight bookings for Admin
void Admin::manageFlightBookings() {
    // Manage flight bookings by listing all bookings and offering options to modify or cancel them
    cout << "Managing flight bookings..." << endl;

    // Let's assume you have a global list of bookings to manage.
    // For now, we'll simulate by prompting the user to view or cancel a booking.

    int bookingChoice;
    cout << "1. View Bookings" << endl;
    cout << "2. Cancel Booking" << endl;
    cout << "Enter your choice: ";
    cin >> bookingChoice;

    if (bookingChoice == 1) {
        // List all bookings (for now, simulate by showing a sample message)
        cout << "Displaying all bookings..." << endl;
    }
    else if (bookingChoice == 2) {
        string bookingID;
        cout << "Enter Booking ID to cancel: ";
        cin >> bookingID;

        // Simulate canceling a booking
        cout << "Booking " << bookingID << " has been canceled." << endl;

        // You could add actual booking cancellation logic here, where the system updates the flight's seat availability.
    }
    else {
        cout << "Invalid option." << endl;
    }
}
