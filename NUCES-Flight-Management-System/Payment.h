#pragma once
#ifndef PAYMENT_H
#define PAYMENT_H

#include <string>
using namespace std;

// Payment class to handle payment details and operations
class Payment {
private:
    string paymentID;
    double amount;
    string paymentMethod; // Credit card, Debit card, Online
    string paymentDate;

public:
    // Constructor for initializing payment details
    Payment(string paymentID, double amount, string paymentMethod, string paymentDate)
        : paymentID(paymentID), amount(amount), paymentMethod(paymentMethod), paymentDate(paymentDate) {}

    // Methods to process and refund payment
    bool processPayment();
    void refundPayment();
};

#endif // PAYMENT_H
