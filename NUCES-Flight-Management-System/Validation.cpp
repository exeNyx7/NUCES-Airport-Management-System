#include "Validation.h"
#include <iostream>
#include <regex>
using namespace std;

// Validate CNIC (13 digits)
bool Validation::validateCNIC(const string& CNIC) {
    regex cnicRegex("^[0-9]{5}-[0-9]{7}-[0-9]{1}$");  // CNIC pattern like 12345-1234567-1
    if (regex_match(CNIC, cnicRegex)) {
        return true;
    }
    else {
        cout << "Invalid CNIC format. Please use the format XXXXX-XXXXXXX-X." << endl;
        return false;
    }
}

// Validate password (at least 8 characters, 1 uppercase, 1 lowercase, 1 digit, 1 special character)
bool Validation::validatePassword(const string& password) {
    if (password.length() < 8) {
        cout << "Password must be at least 8 characters long." << endl;
        return false;
    }

    // Password strength regex (minimum 1 lowercase, 1 uppercase, 1 digit, and 1 special character)
    regex passwordRegex("^(?=.*[a-z])(?=.*[A-Z])(?=.*[0-9])(?=.*[!@#$%^&*])[A-Za-z0-9!@#$%^&*]{8,}$");
    if (!regex_match(password, passwordRegex)) {
        cout << "Password must contain at least one lowercase letter, one uppercase letter, one digit, and one special character." << endl;
        return false;
    }

    // Additional password complexity check (e.g., enforcing at least 2 digits or 2 special characters)
    if (count(password.begin(), password.end(), '@') + count(password.begin(), password.end(), '#') < 2) {
        cout << "Password must contain at least two special characters like '@' or '#'. Please choose a stronger password." << endl;
        return false;
    }

    return true;
}

// Validate email format
bool Validation::validateEmail(const string& email) {
    // Simple regex for validating emails
    regex emailRegex("^[a-zA-Z0-9_+&*-]+(?:\\.[a-zA-Z0-9_+&*-]+)*@(?:[a-zA-Z0-9-]+\\.)+[a-zA-Z]{2,7}$");
    if (regex_match(email, emailRegex)) {
        return true;
    }
    else {
        cout << "Invalid email format." << endl;
        return false;
    }
}
