#include <iostream>
#include <vector>
#include <memory>
#include "User.h"
#include "Passenger.h"
#include "Admin.h"
#include "Flight.h"
#include "Airport.h"
#include "Booking.h"
#include "Validation.h"
using namespace std;

int main() {
    vector<unique_ptr<User>> users;  // Store users (admin and passenger)
    vector<unique_ptr<Flight>> flights;  // Store flights

    // Create a sample admin and a passenger
    unique_ptr<Admin> admin = make_unique<Admin>("admin", "admin@nafs.com", "Admin@1234", "12345-1234567-1", "admin01");
    unique_ptr<Passenger> passenger = make_unique<Passenger>("John Doe", "john.doe@email.com", "Password123!", "23456-2345678-9", "AB123456");

    users.push_back(move(admin));
    users.push_back(move(passenger));

    // Create a sample flight
    unique_ptr<Flight> flight1 = make_unique<Flight>("FL123", "Islamabad", "Lahore", "10:00 AM", "12:00 PM", 2, 5, 2);
    flights.push_back(move(flight1));

    // Sample main menu for the system
    int choice;
    while (true) {
        cout << "\nMain Menu:" << endl;
        cout << "1. Login as Admin" << endl;
        cout << "2. Login as Passenger" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            // Admin login
            string adminID;
            cout << "Enter Admin ID: ";
            cin >> adminID;
            bool loggedIn = false;
            for (auto& user : users) {
                if (auto adminPtr = dynamic_cast<Admin*>(user.get())) {
                    if (adminPtr->getAdminID() == adminID) {
                        loggedIn = true;
                        adminPtr->login();
                        break;
                    }
                }
            }
            if (!loggedIn) {
                cout << "Invalid Admin ID!" << endl;
            }
        }
        else if (choice == 2) {
            // Passenger login
            string CNIC;
            cout << "Enter your CNIC: ";
            cin >> CNIC;
            bool loggedIn = false;
            for (auto& user : users) {
                if (auto passengerPtr = dynamic_cast<Passenger*>(user.get())) {
                    if (passengerPtr->getCNIC() == CNIC) {
                        loggedIn = true;
                        passengerPtr->login();
                        break;
                    }
                }
            }
            if (!loggedIn) {
                cout << "Invalid CNIC!" << endl;
            }
        }
        else if (choice == 3) {
            break;  // Exit the system
        }
        else {
            cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
