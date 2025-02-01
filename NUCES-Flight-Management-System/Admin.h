#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"
#include <vector>
using namespace std;

// Admin class derived from User
class Admin : public User {
private:
    string adminID;
    vector<string> permissions; // Admin permissions

public:
    // Constructor for initializing Admin object
    Admin(string name, string email, string password, string CNIC, string adminID);


    // Getter and setter methods for adminID
    string getAdminID() const { return adminID; }
    void setAdminID(const string& adminID) { this->adminID = adminID; }

    vector<string> getPermissions() const { return permissions; }
    void addPermission(const string& permission) { permissions.push_back(permission); }

    void addFlight();
    void editFlightSchedule();
    void blockFlight();
    void manageFlightBookings();

    // Override methods from User class
    void login() override;
    void logout() override;
    void viewProfile() override;
    void updateProfile() override;
};

#endif // ADMIN_H
