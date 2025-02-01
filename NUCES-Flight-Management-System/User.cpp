#include "User.h"
#include <iostream>
#include <regex>
using namespace std;

// Constructor to initialize user details
User::User(string name, string email, string password, string CNIC)
    : name(name), email(email), password(password), CNIC(CNIC) {}

// Virtual destructor for proper cleanup
User::~User() {}

// Sample login method for the User class (abstract)
void User::login() {
    cout << "Login functionality needs to be implemented in derived classes." << endl;
}

// Sample logout method for the User class (abstract)
void User::logout() {
    cout << "Logout functionality needs to be implemented in derived classes." << endl;
}

// View profile method (virtual, will be overridden)
void User::viewProfile() {
    cout << "User Profile: " << endl;
    cout << "Name: " << name << endl;
    cout << "Email: " << email << endl;
    cout << "CNIC: " << CNIC << endl;
}

// Update profile method (virtual, will be overridden)
void User::updateProfile() {
    cout << "Update your details here." << endl;
}
