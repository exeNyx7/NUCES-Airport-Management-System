#ifndef BOOKING_H
#define BOOKING_H

#include <string>
#include "Flight.h"
#include "Passenger.h"
using namespace std;

class Booking {
private:
    string bookingID;       // Unique identifier for the booking
    Flight* flight;         // The flight associated with the booking
    Passenger* passenger;   // The passenger who made the booking
    string seatClass;       // Seat class (Economy or Business)
    string paymentStatus;   // Payment status (Pending, Paid, Refunded)
    string bookingStatus;   // Booking status (Pending, Confirmed, Canceled)

public:
    // Constructor for initializing booking details
    Booking(string bookingID, Flight* flight, Passenger* passenger, string seatClass);

    // Getter methods for accessing booking details
    string getBookingID() const { return bookingID; }
    Flight* getFlight() const { return flight; }
    Passenger* getPassenger() const { return passenger; }
    string getSeatClass() const { return seatClass; }
    string getPaymentStatus() const { return paymentStatus; }
    string getBookingStatus() const { return bookingStatus; }

    // Setter methods for updating booking details
    void setBookingID(const string& id) { bookingID = id; }
    void setSeatClass(const string& seat) { seatClass = seat; }
    void setPaymentStatus(const string& status) { paymentStatus = status; }
    void setBookingStatus(const string& status) { bookingStatus = status; }

    // Create a new booking
    void createBooking();

    // Modify the booking (e.g., change seat class)
    void modifyBooking();

    // Cancel the booking with 25% penalty
    void cancelBooking();

    // Process payment for the booking
    bool processPayment();

    // Refund payment for the booking
    void refundPayment();
};

#endif // BOOKING_H
