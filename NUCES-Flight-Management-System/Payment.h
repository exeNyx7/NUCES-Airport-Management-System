#ifndef PAYMENT_H
#define PAYMENT_H

#include <string>
using namespace std;

class Booking;  // Forward declaration for Booking class

class Payment {
private:
    string paymentID;      // Unique identifier for the payment
    double amount;         // Amount to be paid
    string paymentMethod;  // Method of payment (e.g., Credit Card, PayPal)
    string paymentDate;    // Date of the payment
    string paymentStatus;  // Status of the payment (Pending, Completed, Failed, Refunded)
    Booking* associatedBooking;  // Link to the associated booking (if any)

public:
    // Constructor for initializing payment details
    Payment(string paymentID, double amount, string paymentMethod, string paymentDate, Booking* booking);

    // Getter methods for payment details
    string getPaymentID() const { return paymentID; }
    double getAmount() const { return amount; }
    string getPaymentMethod() const { return paymentMethod; }
    string getPaymentDate() const { return paymentDate; }
    string getPaymentStatus() const { return paymentStatus; }

    // Methods for processing, validating, and refunding payments
    bool processPayment();
    bool validatePayment();
    void refundPayment();
    void displayPaymentDetails() const;
};

#endif // PAYMENT_H
