#include <iostream>
#include <vector>
#include <memory>
#include "User.h"
#include "Passenger.h"
#include "Admin.h"
#include "Flight.h"
#include "Booking.h"
#include "Payment.h"
#include "Validation.h" 
#include "FileHandler.h"
//#include "FileHandling.h"
using namespace std;

int main() {
    // Initialize lists for users and flights
    vector<unique_ptr<User>> users;
    vector<unique_ptr<Flight>> flights;
    vector<unique_ptr<Booking>> bookings;

    // Load existing data
    loadUsersFromFile(users);
    loadFlightsFromFile(flights);
    loadBookingsFromFile(bookings, flights, users);

    // Create a sample admin and a passenger
    unique_ptr<Admin> admin = make_unique<Admin>("admin", "admin@nafs.com", "Admin@1234", "12345-1234567-1", "admin01");
    unique_ptr<Passenger> passenger = make_unique<Passenger>("John Doe", "john.doe@email.com", "Password123!", "23456-2345678-9", "AB123456");

    users.push_back(move(admin));
    users.push_back(move(passenger));

    // Create some sample flights
    unique_ptr<Flight> flight1 = make_unique<Flight>("FL123", "Islamabad", "Lahore", "10:00 AM", "12:00 PM", 2, 5, 2);
    unique_ptr<Flight> flight2 = make_unique<Flight>("FL124", "Lahore", "Karachi", "01:00 PM", "03:00 PM", 3, 5, 2);
    flights.push_back(move(flight1));
    flights.push_back(move(flight2));

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

                        // Admin Actions
                        int adminChoice;
                        while (true) {
                            cout << "\nAdmin Menu:" << endl;
                            cout << "1. Add Flight" << endl;
                            cout << "2. Edit Flight Schedule" << endl;
                            cout << "3. Block Flight" << endl;
                            cout << "4. View Bookings" << endl;
                            cout << "5. Logout" << endl;
                            cout << "Enter your choice: ";
                            cin >> adminChoice;

                            if (adminChoice == 1) {
                                adminPtr->addFlight();
                            }
                            else if (adminChoice == 2) {
                                adminPtr->editFlightSchedule();
                            }
                            else if (adminChoice == 3) {
                                adminPtr->blockFlight();
                            }
                            else if (adminChoice == 4) {
                                adminPtr->manageFlightBookings();
                            }
                            else if (adminChoice == 5) {
                                cout << "Logging out..." << endl;
                                break;  // Exit the admin menu and return to main menu
                            }
                            else {
                                cout << "Invalid choice, try again!" << endl;
                            }
                        }
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

                        // Passenger Actions
                        int passengerChoice;
                        while (true) {
                            cout << "\nPassenger Menu:" << endl;
                            cout << "1. Book Flight" << endl;
                            cout << "2. View Booking" << endl;
                            cout << "3. Cancel Booking" << endl;
                            cout << "4. Update Travel Profile" << endl;
                            cout << "5. Logout" << endl;
                            cout << "Enter your choice: ";
                            cin >> passengerChoice;

                            if (passengerChoice == 1) {
                                passengerPtr->bookFlight(flights, bookings);
                            }
                            else if (passengerChoice == 2) {
                                passengerPtr->viewBooking(bookings);
                            }
                            else if (passengerChoice == 3) {
                                passengerPtr->cancelBooking(bookings);
                            }
                            else if (passengerChoice == 4) {
                                passengerPtr->updateTravelProfile();
                            }
                            else if (passengerChoice == 5) {
                                cout << "Logging out..." << endl;
                                break;  // Exit the passenger menu and return to main menu
                            }
                            else {
                                cout << "Invalid choice, try again!" << endl;
                            }
                        }
                        break;
                    }
                }
            }
            if (!loggedIn) {
                cout << "Invalid CNIC!" << endl;
            }
        }
        else if (choice == 3) {
            // Write data back to files when exiting
            writeUsersToFile(users);
            writeFlightsToFile(flights);
            writeBookingsToFile(bookings);
            break;  // Exit the program
        }
        else {
            cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
