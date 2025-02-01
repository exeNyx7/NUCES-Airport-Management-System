#pragma once
#ifndef BOOKING_H
#define BOOKING_H

#include <string>
#include <vector>
#include "Passenger.h"
#include "Flight.h"
using namespace std;

// Booking class to handle flight bookings
class Booking {
private:
    string bookingID;
    Flight* flight;
    Passenger* passenger;
    string seatClass; // Economy or Business
    string paymentStatus; // Paid, Pending, Failed

public:
    // Constructor for initializing booking
    Booking(string bookingID, Flight* flight, Passenger* passenger, string seatClass)
        : bookingID(bookingID), flight(flight), passenger(passenger), seatClass(seatClass), paymentStatus("Pending") {}

    // Methods for booking operations
    void createBooking();
    void modifyBooking();
    void cancelBooking();

    // Methods to check payment status
    bool processPayment();
    void refundPayment();
};

#endif // BOOKING_H
