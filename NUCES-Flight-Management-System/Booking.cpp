#include "Booking.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// Constructor for initializing booking details
Booking::Booking(string bookingID, Flight* flight, Passenger* passenger, string seatClass)
    : bookingID(bookingID), flight(flight), passenger(passenger), seatClass(seatClass), paymentStatus("Pending"), bookingStatus("Pending") {}

// Setter methods for booking status and payment status
void Booking::setBookingStatus(const string& status) {
    bookingStatus = status;
}

void Booking::setPaymentStatus(const string& status) {
    paymentStatus = status;
}

// Get and display booking details
void Booking::getBookingDetails() const {
    cout << "Booking ID: " << bookingID << endl;
    cout << "Flight ID: " << flight->getFlightID() << endl;
    cout << "From: " << flight->getDepartureCity() << " to " << flight->getArrivalCity() << endl;
    cout << "Departure: " << flight->getDepartureTime() << " Arrival: " << flight->getArrivalTime() << endl;
    cout << "Seat Class: " << seatClass << endl;
    cout << "Payment Status: " << paymentStatus << endl;
    cout << "Booking Status: " << bookingStatus << endl;
}

// Create a new booking
void Booking::createBooking() {
    if (seatClass == "Economy") {
        if (flight->bookEconomySeat()) {
            bookingStatus = "Confirmed";
            paymentStatus = "Pending";
            cout << "Booking created successfully in Economy class! Awaiting payment..." << endl;
        }
        else {
            cout << "No economy seats available. Booking failed." << endl;
        }
    }
    else if (seatClass == "Business") {
        if (flight->bookBusinessSeat()) {
            bookingStatus = "Confirmed";
            paymentStatus = "Pending";
            cout << "Booking created successfully in Business class! Awaiting payment..." << endl;
        }
        else {
            cout << "No business seats available. Booking failed." << endl;
        }
    }
    else {
        cout << "Invalid seat class!" << endl;
    }
}

// Modify booking (allow changing seat class or flight)
void Booking::modifyBooking() {
    cout << "Modifying booking with ID: " << bookingID << endl;
    if (bookingStatus != "Confirmed") {
        cout << "Booking is not confirmed, cannot modify." << endl;
        return;
    }

    string newSeatClass;
    cout << "Enter new seat class (Economy/Business): ";
    cin >> newSeatClass;

    if (newSeatClass == "Economy" && flight->bookEconomySeat()) {
        seatClass = newSeatClass;
        cout << "Booking updated to Economy class." << endl;
    }
    else if (newSeatClass == "Business" && flight->bookBusinessSeat()) {
        seatClass = newSeatClass;
        cout << "Booking updated to Business class." << endl;
    }
    else {
        cout << "Unable to modify seat class. No available seats." << endl;
    }
}

// Cancel the booking with 25% penalty
void Booking::cancelBooking() {
    if (bookingStatus == "Confirmed") {
        if (paymentStatus == "Paid") {
            bookingStatus = "Cancelled";
            paymentStatus = "Refunded";
            cout << "Booking canceled. A 25% cancellation fee applied. Amount refunded." << endl;
        }
        else {
            bookingStatus = "Cancelled";
            cout << "Booking canceled. No payment made, no penalty." << endl;
        }
    }
    else {
        cout << "Cannot cancel a booking that is not confirmed!" << endl;
    }
}

// Process payment
bool Booking::processPayment() {
    if (bookingStatus == "Confirmed") {
        paymentStatus = "Paid";
        cout << "Payment processed successfully!" << endl;
        return true;
    }
    else {
        cout << "Booking not confirmed. Payment cannot be processed." << endl;
        return false;
    }
}

// Refund payment
void Booking::refundPayment() {
    if (paymentStatus == "Paid") {
        paymentStatus = "Refunded";
        cout << "Payment refunded successfully!" << endl;
    }
    else {
        cout << "No payment has been made, so no refund is needed." << endl;
    }
}


