#ifndef USER_H
#define USER_H

#include <string>
#include <iostream>
using namespace std;

// Base class for common user attributes and methods
class User {
protected:
    string name;
    string email;
    string password;
    string CNIC; // CNIC is unique identifier for users (passenger/admin)

public:
    // Constructor for initializing the User object
    User(string name, string email, string password, string CNIC)
        : name(name), email(email), password(password), CNIC(CNIC) {}

    // Getter and setter methods for name, email, password, and CNIC
    string getName() const { return name; }
    void setName(const string& name) { this->name = name; }

    string getEmail() const { return email; }
    void setEmail(const string& email) { this->email = email; }

    string getPassword() const { return password; }
    void setPassword(const string& password) { this->password = password; }

    string getCNIC() const { return CNIC; }
    void setCNIC(const string& CNIC) { this->CNIC = CNIC; }

    virtual void login() = 0;
    virtual void logout() = 0;
    virtual void viewProfile() = 0;
    virtual void updateProfile() = 0;

    virtual ~User() {}
};

#endif // USER_H
