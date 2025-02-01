#include "Booking.h"
#include <iostream>
using namespace std;

// Constructor for initializing booking details
Booking::Booking(string bookingID, Flight* flight, Passenger* passenger, string seatClass)
    : bookingID(bookingID), flight(flight), passenger(passenger), seatClass(seatClass), paymentStatus("Pending") {}

// Create a new booking
void Booking::createBooking() {
    if (seatClass == "Economy") {
        if (flight->bookEconomySeat()) {
            paymentStatus = "Pending";
            cout << "Booking created! Awaiting payment..." << endl;
        }
    }
    else if (seatClass == "Business") {
        if (flight->bookBusinessSeat()) {
            paymentStatus = "Pending";
            cout << "Booking created! Awaiting payment..." << endl;
        }
    }
    else {
        cout << "Invalid seat class!" << endl;
    }
}

// Modify booking (simplified)
void Booking::modifyBooking() {
    cout << "Modifying booking..." << endl;
    // Implementation of booking modification logic (e.g., change seat class, flight)
}

// Cancel the booking with 25% penalty
void Booking::cancelBooking() {
    if (paymentStatus == "Paid") {
        cout << "Booking canceled. 25% cancellation fee applied." << endl;
    }
    else {
        cout << "Booking not paid yet. Cannot cancel." << endl;
    }
}

// Process payment
bool Booking::processPayment() {
    paymentStatus = "Paid";
    cout << "Payment processed successfully!" << endl;
    return true;
}

// Refund payment
void Booking::refundPayment() {
    paymentStatus = "Refunded";
    cout << "Payment refunded successfully!" << endl;
}
