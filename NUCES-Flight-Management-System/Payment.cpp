#include "Payment.h"
#include <iostream>
#include <regex> // For validating payment method (optional)
using namespace std;

// Constructor for initializing payment details
Payment::Payment(string paymentID, double amount, string paymentMethod, string paymentDate)
    : paymentID(paymentID), amount(amount), paymentMethod(paymentMethod), paymentDate(paymentDate), paymentStatus("Pending") {}

// Process the payment (simplified)
bool Payment::processPayment() {
    // Validate payment before processing
    if (!validatePayment()) {
        cout << "Payment failed due to invalid details." << endl;
        return false;  // Return false if validation fails
    }

    // Simulate payment processing
    cout << "Processing payment of " << amount << " via " << paymentMethod << " on " << paymentDate << endl;

    // Assuming payment is successful
    paymentStatus = "Completed";
    cout << "Payment completed successfully!" << endl;
    return true;
}

// Validate the payment (check if amount is valid and payment method is supported)
bool Payment::validatePayment() {
    // Check if the amount is greater than zero
    if (amount <= 0) {
        cout << "Invalid payment amount!" << endl;
        return false;
    }

    // Check if payment method is valid (for example, only Credit Card and PayPal are allowed)
    if (paymentMethod != "Credit Card" && paymentMethod != "PayPal") {
        cout << "Invalid payment method! Only Credit Card or PayPal are accepted." << endl;
        return false;
    }

    return true;
}

// Refund the payment
void Payment::refundPayment() {
    if (paymentStatus == "Completed") {
        paymentStatus = "Refunded";
        cout << "Payment of " << amount << " refunded successfully!" << endl;
    }
    else {
        cout << "No payment to refund." << endl;
    }
}

// Display payment details
void Payment::displayPaymentDetails() const {
    cout << "Payment ID: " << paymentID << endl;
    cout << "Amount: " << amount << endl;
    cout << "Payment Method: " << paymentMethod << endl;
    cout << "Payment Date: " << paymentDate << endl;
    cout << "Payment Status: " << paymentStatus << endl;
}
