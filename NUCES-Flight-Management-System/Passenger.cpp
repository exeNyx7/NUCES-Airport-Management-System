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

// Book a flight for Passenger
void Passenger::bookFlight(vector<unique_ptr<Flight>>& availableFlights, vector<unique_ptr<Booking>>& bookings) {
    cout << "Available Flights: " << endl;
    for (int i = 0; i < availableFlights.size(); i++) {
        cout << i + 1 << ". Flight ID: " << availableFlights[i]->getFlightID() << " from " << availableFlights[i]->getDepartureCity()
            << " to " << availableFlights[i]->getArrivalCity() << " (" << availableFlights[i]->getDuration() << " hours)" << endl;
    }

    int flightChoice;
    cout << "Enter the number of the flight you wish to book: ";
    cin >> flightChoice;

    if (flightChoice < 1 || flightChoice > availableFlights.size()) {
        cout << "Invalid flight choice!" << endl;
        return;
    }

    unique_ptr<Flight>& selectedFlight = availableFlights[flightChoice - 1];

    // Ask for seat class choice
    string seatClass;
    cout << "Choose seat class (Economy/Business): ";
    cin >> seatClass;

    if (seatClass != "Economy" && seatClass != "Business") {
        cout << "Invalid seat class!" << endl;
        return;
    }

    bool seatBooked = false;
    if (seatClass == "Economy") {
        seatBooked = selectedFlight->bookEconomySeat();
    }
    else {
        seatBooked = selectedFlight->bookBusinessSeat();
    }

    if (!seatBooked) {
        cout << "No available seats in " << seatClass << " class." << endl;
        return;
    }

    // Create booking and associate it with the passenger
    string bookingID = "B" + to_string(bookings.size() + 1);  // Simple ID generation
    unique_ptr<Booking> newBooking = make_unique<Booking>(bookingID, selectedFlight.get(), this, seatClass);
    bookings.push_back(move(newBooking));

    cout << "Booking confirmed!" << endl;

    // Now, we need to process payment (Payment is linked to booking)
    Payment payment("P" + bookingID, selectedFlight->getDuration() * (seatClass == "Economy" ? 10000 : 20000), "Credit Card", "2025-02-01", bookings.back().get());
    payment.processPayment();
}

// View booking for Passenger
void Passenger::viewBooking(const vector<unique_ptr<Booking>>& bookings) {
    if (bookings.empty()) {
        cout << "No bookings found!" << endl;
        return;
    }

    cout << "Your bookings: " << endl;
    for (const auto& booking : bookings) {
        cout << "Booking ID: " << booking->getBookingID() << ", Flight ID: " << booking->getFlight()->getFlightID()
            << ", Seat Class: " << booking->getSeatClass() << ", Payment Status: " << booking->getPaymentStatus() << endl;
    }

    int bookingChoice;
    cout << "Enter the number of the booking you want to view: ";
    cin >> bookingChoice;

    if (bookingChoice < 1 || bookingChoice > bookings.size()) {
        cout << "Invalid booking choice!" << endl;
        return;
    }

    // Display booking details
    const unique_ptr<Booking>& selectedBooking = bookings[bookingChoice - 1];
    selectedBooking->getFlight()->getFlightDetails();
    cout << "Seat Class: " << selectedBooking->getSeatClass() << endl;
    cout << "Payment Status: " << selectedBooking->getPaymentStatus() << endl;
}

// Cancel a booking for Passenger
void Passenger::cancelBooking(vector<unique_ptr<Booking>>& bookings) {
    if (bookings.empty()) {
        cout << "No bookings found!" << endl;
        return;
    }

    cout << "Your bookings: " << endl;
    for (int i = 0; i < bookings.size(); ++i) {
        cout << i + 1 << ". Booking ID: " << bookings[i]->getBookingID() << " | Flight: " << bookings[i]->getFlight()->getFlightID()
            << " | Seat Class: " << bookings[i]->getSeatClass() << endl;
    }

    int bookingChoice;
    cout << "Enter the number of the booking you want to cancel: ";
    cin >> bookingChoice;

    if (bookingChoice < 1 || bookingChoice > bookings.size()) {
        cout << "Invalid booking choice!" << endl;
        return;
    }

    unique_ptr<Booking>& selectedBooking = bookings[bookingChoice - 1];

    if (selectedBooking->getPaymentStatus() == "Paid") {
        selectedBooking->setBookingStatus("Cancelled");
        selectedBooking->setPaymentStatus("Refunded");
        cout << "Booking cancelled. 25% cancellation fee applied. Amount refunded." << endl;
    }
    else {
        selectedBooking->setBookingStatus("Cancelled");
        cout << "Booking cancelled. No payment made, no penalty." << endl;
    }

    // Remove booking from list (simulating removal from system)
    bookings.erase(bookings.begin() + (bookingChoice - 1));
}
