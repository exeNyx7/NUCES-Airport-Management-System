#include "Payment.h"
#include <iostream>
using namespace std;

// Constructor for initializing payment details
Payment::Payment(string paymentID, double amount, string paymentMethod, string paymentDate)
    : paymentID(paymentID), amount(amount), paymentMethod(paymentMethod), paymentDate(paymentDate) {}

// Process the payment (simplified)
bool Payment::processPayment() {
    cout << "Processing payment of " << amount << " via " << paymentMethod << endl;
    return true;  // Assume payment is successful
}

// Refund payment
void Payment::refundPayment() {
    cout << "Refunding payment of " << amount << " via " << paymentMethod << endl;
}
