# NUCES-Flight-Management-System

## Table of Contents

- [Project Overview](#project-overview)
- [Features](#features)
- [Technologies Used](#technologies-used)
- [File Structure](#file-structure)
- [How to Run the Project](#how-to-run-the-project)
- [File Handling](#file-handling)
- [Code Walkthrough](#code-walkthrough)
- [Contributors](#contributors)
- [License](#license)

## Project Overview

The **Flight Management System** is a console-based application designed to manage flights, bookings, users, and payment systems for an airline. The system allows users to manage and book flights, while administrators can manage flights, schedules, and bookings.

This system allows both passengers and administrators to:

- **Passengers**: Book flights, view bookings, cancel bookings, and update profiles.
- **Admins**: Add, edit, and block flights; view and manage bookings; and update flight schedules.

The project uses file handling to save and load data, such as user details, flight information, and bookings.

## Features

### Passengers

- **Login/Logout**: Login using CNIC (for passengers) or Admin ID (for admins).
- **Flight Booking**: Choose and book flights in either Economy or Business class.
- **View Booking**: View details of the booking.
- **Cancel Booking**: Cancel confirmed bookings and handle penalties.
- **Profile Management**: Update user profiles.

### Admins

- **Flight Management**: Admins can add, edit, or block flights.
- **Booking Management**: Admins can view and cancel bookings, handle penalties, and refund payments.
- **Flight Schedule Management**: Update or block flight schedules.
- **Manage Flight Restrictions**: Block flights due to restrictions such as COVID.

## Technologies Used

- **C++**: The core programming language used for building the system.
- **File Handling**: To save/load user, flight, and booking data.
- **Standard C++ Libraries**: `iostream`, `fstream`, `string`, `vector`, `memory`, etc.

## File Structure

```
/Flight-Management-System
├── data/
│   ├── bookings.txt     # Stores all bookings data
│   ├── flights.txt      # Stores all flights data
│   └── users.txt        # Stores all user data
├── Admin.cpp            # Admin class implementation
├── Admin.h              # Admin class header
├── Booking.cpp          # Booking class implementation
├── Booking.h            # Booking class header
├── Flight.cpp           # Flight class implementation
├── Flight.h            # Flight class header
├── FileHandler.cpp      # File handling functions (write and load data)
├── FileHandler.h        # Header for file handling functions
├── Passenger.cpp        # Passenger class implementation
├── Passenger.h          # Passenger class header
├── User.cpp            # User class implementation
├── User.h              # User class header
├── main.cpp            # Main program file
├── Payment.cpp         # Payment class implementation
└── Payment.h           # Payment class header
```

## How to Run the Project

### Prerequisites

- **C++ Compiler**: Any C++ compiler (e.g., GCC, Clang, MSVC).
- **IDE**: You can use any IDE such as Visual Studio, Code::Blocks, or any text editor like VS Code.

### Steps to run

1. **Clone the repository**:

   ```bash
   git clone https://github.com/exeNyx7/NUCES-Airport-Management-System
   cd Flight-Management-System
   ```

2. **Compile the project**:
   Use your IDE's build tools or use the following command (assuming you are using GCC):

   ```bash
   g++ main.cpp Admin.cpp Passenger.cpp Flight.cpp Booking.cpp Payment.cpp User.cpp FileHandler.cpp -o FlightManagement
   ```

3. **Run the executable**:
   On Windows:

   ```bash
   FlightManagement.exe
   ```

   On Linux or macOS:

   ```bash
   ./FlightManagement
   ```

## File Handling

The project uses file handling for storing and loading data to/from text files. These are:

- **users.txt**: Stores user details (name, email, CNIC).
- **flights.txt**: Stores flight details (flight ID, departure, arrival, seat availability).
- **bookings.txt**: Stores booking details (booking ID, flight ID, passenger CNIC, seat class, payment status, booking status).

### Writing to File

- `writeUsersToFile()`: Saves user data to users.txt.
- `writeFlightsToFile()`: Saves flight data to flights.txt.
- `writeBookingsToFile()`: Saves booking data to bookings.txt.

### Reading from File

- `loadUsersFromFile()`: Loads user data from users.txt.
- `loadFlightsFromFile()`: Loads flight data from flights.txt.
- `loadBookingsFromFile()`: Loads booking data from bookings.txt.

## Code Walkthrough

### Main Components

- **User Class**: Base class for both Admin and Passenger. It holds common attributes like name, email, CNIC, etc., and virtual methods like `login()`, `logout()`, `viewProfile()`, and `updateProfile()`.
- **Admin Class**: Derived from User. Manages flight additions, schedule edits, and booking management.
- **Passenger Class**: Derived from User. Manages flight bookings, viewing, and cancellations.
- **Flight Class**: Stores flight-related data, including available seats and flight status.
- **Booking Class**: Handles booking functionality, including booking creation, modification, and cancellation.

## Contributors

exeNyx7: Contributor.
