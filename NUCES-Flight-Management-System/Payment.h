#ifndef PAYMENT_H
#define PAYMENT_H

#include <string>
using namespace std;

class Payment {
private:
    string paymentID;      // Unique identifier for the payment
    double amount;         // Amount to be paid
    string paymentMethod;  // Method of payment (e.g., Credit Card, PayPal)
    string paymentDate;    // Date of the payment
    string paymentStatus;  // Status of the payment (Pending, Completed, Failed)

public:
    // Constructor for initializing payment details
    Payment(string paymentID, double amount, string paymentMethod, string paymentDate);

    // Getter methods for payment details
    string getPaymentID() const { return paymentID; }
    double getAmount() const { return amount; }
    string getPaymentMethod() const { return paymentMethod; }
    string getPaymentDate() const { return paymentDate; }
    string getPaymentStatus() const { return paymentStatus; }

    // Setter methods for payment details
    void setPaymentStatus(const string& status) { paymentStatus = status; }

    // Method to process the payment
    bool processPayment();

    // Method to validate the payment (e.g., check the payment method and amount)
    bool validatePayment();

    // Refund the payment
    void refundPayment();

    // Method to display payment details
    void displayPaymentDetails() const;
};

#endif // PAYMENT_H
