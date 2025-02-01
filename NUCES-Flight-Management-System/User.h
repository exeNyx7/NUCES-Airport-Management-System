#ifndef USER_H
#define USER_H

#include <string>
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
    User(string name, string email, string password, string CNIC);

    // Virtual destructor for proper cleanup
    virtual ~User();

    // Virtual login and logout methods (to be implemented in derived classes)
    virtual void login() = 0;
    virtual void logout() = 0;

    // View and update user profile
    virtual void viewProfile();
    virtual void updateProfile();

    // Getters and setters
    string getName() const { return name; }
    void setName(const string& name) { this->name = name; }

    string getEmail() const { return email; }
    void setEmail(const string& email) { this->email = email; }

    string getPassword() const { return password; }
    void setPassword(const string& password) { this->password = password; }

    string getCNIC() const { return CNIC; }
    void setCNIC(const string& CNIC) { this->CNIC = CNIC; }
};

#endif // USER_H
