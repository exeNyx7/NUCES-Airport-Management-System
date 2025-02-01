#pragma once
#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <vector>
#include <memory>
#include "User.h"
#include "Flight.h"
#include "Booking.h"
using namespace std;

// Function prototypes for file handling operations
void writeUsersToFile(const vector<::unique_ptr<User>>& users);
void writeFlightsToFile(const vector<::unique_ptr<Flight>>& flights);
void writeBookingsToFile(const vector<::unique_ptr<Booking>>& bookings);

void loadUsersFromFile(::vector<std::unique_ptr<User>>& users);
void loadFlightsFromFile(::vector<std::unique_ptr<Flight>>& flights);
void loadBookingsFromFile(::vector<std::unique_ptr<Booking>>& bookings,
    const std::vector<std::unique_ptr<Flight>>& flights,
    const std::vector<std::unique_ptr<User>>& users);

#endif // FILEHANDLER_H
