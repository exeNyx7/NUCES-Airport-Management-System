#pragma once
#ifndef VALIDATION_H
#define VALIDATION_H

#include <string>
#include <regex>
using namespace std;

// Validation class to validate CNIC, password, and other inputs.
class Validation {
public:
    // Method to validate CNIC (13 digits)
    static bool validateCNIC(const string& CNIC);

    // Method to validate password (min 8 characters, 1 uppercase, 1 lowercase, 1 digit, 1 special character)
    static bool validatePassword(const string& password);

    // Method to validate email format (basic validation)
    static bool validateEmail(const string& email);
};

#endif // VALIDATION_H
