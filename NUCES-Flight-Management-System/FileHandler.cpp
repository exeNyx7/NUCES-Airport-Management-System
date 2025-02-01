#include "FileHandler.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

// Function to save user data to a file
void writeUsersToFile(const vector<unique_ptr<User>>& users) {
    ofstream file("data/users.txt");

    for (const auto& user : users) {
        file << user->getName() << ","
            << user->getEmail() << ","
            << user->getPassword() << ","
            << user->getCNIC() << endl;
    }

    file.close();
}

// Function to save flight data to a file
void writeFlightsToFile(const vector<unique_ptr<Flight>>& flights) {
    ofstream file("data/flights.txt");

    for (const auto& flight : flights) {
        file << flight->getFlightID() << ","
            << flight->getDepartureCity() << ","
            << flight->getArrivalCity() << ","
            << flight->getDepartureTime() << ","
            << flight->getArrivalTime() << ","
            << flight->getDuration() << ","
            << flight->getAvailableSeatsEconomy() << ","
            << flight->getAvailableSeatsBusiness() << endl;
    }

    file.close();
}

// Function to save booking data to a file
void writeBookingsToFile(const vector<unique_ptr<Booking>>& bookings) {
    ofstream file("data/bookings.txt");

    for (const auto& booking : bookings) {
        file << booking->getBookingID() << ","
            << booking->getFlight()->getFlightID() << ","
            << booking->getPassenger()->getCNIC() << ","
            << booking->getSeatClass() << ","
            << booking->getPaymentStatus() << ","
            << booking->getBookingStatus() << endl;
    }

    file.close();
}

// Function to load user data from a file
void loadUsersFromFile(vector<unique_ptr<User>>& users) {
    ifstream file("data/users.txt");
    string name, email, password, CNIC;

    while (getline(file, name, ',') &&
        getline(file, email, ',') &&
        getline(file, password, ',') &&
        getline(file, CNIC)) {
        unique_ptr<User> user = make_unique<Passenger>(name, email, password, CNIC, "");
        users.push_back(move(user));
    }

    file.close();
}

// Function to load flight data from a file
void loadFlightsFromFile(vector<unique_ptr<Flight>>& flights) {
    ifstream file("data/flights.txt");
    string flightID, departureCity, arrivalCity, departureTime, arrivalTime;
    int duration, availableSeatsEconomy, availableSeatsBusiness;

    while (getline(file, flightID, ',') &&
        getline(file, departureCity, ',') &&
        getline(file, arrivalCity, ',') &&
        getline(file, departureTime, ',') &&
        getline(file, arrivalTime, ',') &&
        file >> duration && file.ignore() &&
        file >> availableSeatsEconomy && file.ignore() &&
        file >> availableSeatsBusiness) {
        unique_ptr<Flight> flight = make_unique<Flight>(flightID, departureCity, arrivalCity,
            departureTime, arrivalTime, duration, availableSeatsEconomy, availableSeatsBusiness);
        flights.push_back(move(flight));
    }

    file.close();
}

// Function to load booking data from a file
void loadBookingsFromFile(vector<unique_ptr<Booking>>& bookings,
    const vector<unique_ptr<Flight>>& flights,
    const vector<unique_ptr<User>>& users) {
    ifstream file("data/bookings.txt");
    string bookingID, flightID, passengerCNIC, seatClass, paymentStatus, bookingStatus;

    while (getline(file, bookingID, ',') &&
        getline(file, flightID, ',') &&
        getline(file, passengerCNIC, ',') &&
        getline(file, seatClass, ',') &&
        getline(file, paymentStatus, ',') &&
        getline(file, bookingStatus)) {

        Flight* flight = nullptr;
        for (const auto& f : flights) {
            if (f->getFlightID() == flightID) {
                flight = f.get();
                break;
            }
        }

        User* passenger = nullptr;
        for (const auto& u : users) {
            if (u->getCNIC() == passengerCNIC) {
                passenger = u.get();
                break;
            }
        }

        if (flight && passenger) {
            unique_ptr<Booking> booking = make_unique<Booking>(bookingID, flight, static_cast<Passenger*>(passenger), seatClass);
            booking->setPaymentStatus(paymentStatus);
            booking->setBookingStatus(bookingStatus);
            bookings.push_back(move(booking));
        }
    }

    file.close();
}
