#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cstdlib>

using namespace std;

#define CLS() (system("CLS"))
#define PAUSE() (system("PAUSE > NUL"))

struct Flight {
    string flightNumber;
    string aircraftNumber;
    string pilotName;
    string sourceCity;
    string destinationCity;
    string flightDate;
    string passengerName;
    string flightTime;
};

void Menu() {
    cout << "::::::::::::::: MENU :::::::::::::::\n";
    cout << "1. Add a new flight\n";
    cout << "2. Delete a flight by flight number\n";
    cout << "3. Add a new passenger\n";
    cout << "4. Delete a passenger by flight number\n";
    cout << "5. Change the name of the pilot\n";
    cout << "6. Display the list of flights with a specific pilot\n";
    cout << "7. Display the list of flights with a specific date\n";
    cout << "8. Display flights sorted by date\n";
    cout << "9. Display pilots in alphabetical order\n";
    cout << "10. Search flights by flight number\n";
    cout << "11. Display delayed flights (12:00-15:00)\n";
    cout << "12. Display all flights\n";
    cout << "13. Quit\n";
    cout << "Enter your choice: ";
}

// Add a new flight
void NewFlight(vector<Flight> &flights) {
    Flight flight;
    cout << "Enter the following information:\n";
    cout << "Flight number: "; cin >> flight.flightNumber;
    cout << "Aircraft number: "; cin >> flight.aircraftNumber;
    cout << "Pilot name: "; cin >> flight.pilotName;
    cout << "Source city: "; cin >> flight.sourceCity;
    cout << "Destination city: "; cin >> flight.destinationCity;
    cout << "Flight date: "; cin >> flight.flightDate;
    cout << "Passenger name: "; cin >> flight.passengerName;
    cout << "Flight time: "; cin >> flight.flightTime;

    flights.push_back(flight);
    cout << "Flight added successfully.\n";
}

// Delete a flight
void DeleteFlight(vector<Flight> &flights) {
    string flightNumber;
    cout << "Enter flight number to delete: ";
    cin >> flightNumber;

    for (auto it = flights.begin(); it != flights.end(); it++) {
        if (it->flightNumber == flightNumber) {
            flights.erase(it);
            cout << "Flight deleted successfully.\n";
            return;
        }
    }

    cout << "Flight not found.\n";
}



// Add a new passenger
void AddPassenger(vector<Flight> &flights) {
    string flightNumber, passengerName;
    cout << "Enter flight number to add passenger: ";
    cin >> flightNumber;

    for (auto &flight : flights) {
        if (flight.flightNumber == flightNumber) {
            cout << "Enter passenger name: ";
            cin >> passengerName;
            flight.passengerName = passengerName;
            cout << "Passenger added successfully.\n";
            return;
        }
    }

    cout << "Flight not found.\n";
}

// Delete a passenger
void DeletePassenger(vector<Flight> &flights) {
    string flightNumber;
    cout << "Enter flight number to delete passenger: ";
    cin >> flightNumber;

    for (auto &flight : flights) {
        if (flight.flightNumber == flightNumber) {
            flight.passengerName.clear();
            cout << "Passenger deleted successfully.\n";
            return;
        }
    }

    cout << "Flight not found.\n";
}

// Change pilot name
void ChangePilot(vector<Flight> &flights) {
    string flightNumber, pilotName;
    cout << "Enter flight number: ";
    cin >> flightNumber;

    for (auto &flight : flights) {
        if (flight.flightNumber == flightNumber) {
            cout << "Enter new pilot name: ";
            cin >> pilotName;
            flight.pilotName = pilotName;
            cout << "Pilot name changed successfully.\n";
            return;
        }
    }

    cout << "Flight not found.\n";
}

// Display flights by specific pilot
void DisplayByPilot(const vector<Flight> &flights) {
    string pilotName;
    cout << "Enter pilot name: ";
    cin >> pilotName;

    cout << setw(10) << "Flight No" << setw(15) << "Aircraft No" << setw(15) << "Pilot" 
         << setw(15) << "Source" << setw(15) << "Destination" << setw(15) << "Date" 
         << setw(15) << "Passenger" << setw(10) << "Time" << endl;

    for (const auto &flight : flights) {
        if (flight.pilotName == pilotName) {
            cout << setw(10) << flight.flightNumber << setw(15) << flight.aircraftNumber << setw(15) 
                 << flight.pilotName << setw(15) << flight.sourceCity << setw(15) 
                 << flight.destinationCity << setw(15) << flight.flightDate 
                 << setw(15) << flight.passengerName << setw(10) << flight.flightTime << endl;
        }
    }
}

// Display flights by specific date
void DisplayByDate(const vector<Flight> &flights)
{
    string flightDate;
    cout << "Enter flight date: ";
    cin >> flightDate;

    cout << setw(10) << "Flight No" << setw(15) << "Aircraft No" << setw(15) << "Pilot" 
         << setw(15) << "Source" << setw(15) << "Destination" << setw(15) << "Date" 
         << setw(15) << "Passenger" << setw(10) << "Time" << endl;

    for(const auto &flight : flights){
        if(flight.flightDate == flightDate){
            cout << setw(10) << flight.flightNumber << setw(15) << flight.aircraftNumber << setw(15) 
                 << flight.pilotName << setw(15) << flight.sourceCity << setw(15) 
                 << flight.destinationCity << setw(15) << flight.flightDate 
                 << setw(15) << flight.passengerName << setw(10) << flight.flightTime << endl;
        }
    }
}

// Sort flights by date
bool compareByDate(const Flight &f1, const Flight &f2) {
    return f1.flightDate < f2.flightDate;
}

void DisplaySortedByDate(vector<Flight> &flights) {
    sort(flights.begin(), flights.end(), compareByDate);
    cout << "Flights sorted by date:\n";
    cout << setw(10) << "Flight No" << setw(15) << "Aircraft No" << setw(15) << "Pilot"
         << setw(15) << "Source" << setw(15) << "Destination" << setw(15) << "Date"
         << setw(15) << "Passenger" << setw(10) << "Time" << endl;
    
    for (const auto &flight : flights) {
        cout << setw(10) << flight.flightNumber << setw(15) << flight.aircraftNumber << setw(15) 
             << flight.pilotName << setw(15) << flight.sourceCity << setw(15) 
             << flight.destinationCity << setw(15) << flight.flightDate 
             << setw(15) << flight.passengerName << setw(10) << flight.flightTime << endl;
    }
}

// Display pilots in alphabetical order
bool compareByPilotName(const Flight &f1, const Flight &f2) {
    return f1.pilotName < f2.pilotName;
}

void DisplayPilotsInAlphabeticalOrder(vector<Flight> &flights) {
    sort(flights.begin(), flights.end(), compareByPilotName);
    cout << "Flights sorted by pilot names:\n";
    cout << setw(10) << "Flight No" << setw(15) << "Aircraft No" << setw(15) << "Pilot"
         << setw(15) << "Source" << setw(15) << "Destination" << setw(15) << "Date"
         << setw(15) << "Passenger" << setw(10) << "Time" << endl;

    for (const auto &flight : flights) {
        cout << setw(10) << flight.flightNumber << setw(15) << flight.aircraftNumber << setw(15)
             << flight.pilotName << setw(15) << flight.sourceCity << setw(15) 
             << flight.destinationCity << setw(15) << flight.flightDate 
             << setw(15) << flight.passengerName << setw(10) << flight.flightTime << endl;
    }
}

// Search flights by flight number
void SearchByFlightNumber(const vector<Flight> &flights) {
    string flightNumber;
    cout << "Enter flight number to search: ";
    cin >> flightNumber;

    for (const auto &flight : flights) {
        if (flight.flightNumber == flightNumber) {
            cout << "Flight found:\n";
            cout << setw(10) << "Flight No" << setw(15) << "Aircraft No" << setw(15) << "Pilot"
                 << setw(15) << "Source" << setw(15) << "Destination" << setw(15) << "Date"
                 << setw(15) << "Passenger" << setw(10) << "Time" << endl;
            cout << setw(10) << flight.flightNumber << setw(15) << flight.aircraftNumber << setw(15)
                 << flight.pilotName << setw(15) << flight.sourceCity << setw(15) 
                 << flight.destinationCity << setw(15) << flight.flightDate 
                 << setw(15) << flight.passengerName << setw(10) << flight.flightTime << endl;
            return;
        }
    }

    cout << "Flight not found.\n";
}

// Display delayed flights (12:00-15:00)
void DisplayDelayedFlights(const vector<Flight> &flights) {
    cout << "Displaying delayed flights (12:00-15:00):\n";
    cout << setw(10) << "Flight No" << setw(15) << "Aircraft No" << setw(15) << "Pilot"
         << setw(15) << "Source" << setw(15) << "Destination" << setw(15) << "Date"
         << setw(15) << "Passenger" << setw(10) << "Time" << endl;

    for (const auto &flight : flights) {
        if (flight.flightTime >= "12:00" && flight.flightTime <= "15:00") {
            cout << setw(10) << flight.flightNumber << setw(15) << flight.aircraftNumber << setw(15)
                 << flight.pilotName << setw(15) << flight.sourceCity << setw(15) 
                 << flight.destinationCity << setw(15) << flight.flightDate 
                 << setw(15) << flight.passengerName << setw(10) << flight.flightTime << endl;
        }
    }
}

// Display all flights
void DisplayAllFlights(const vector<Flight> &flights) {
    cout << "Displaying all flights:\n";
    cout << setw(10) << "Flight No" << setw(15) << "Aircraft No" << setw(15) << "Pilot"
         << setw(15) << "Source" << setw(15) << "Destination" << setw(15) << "Date"
         << setw(15) << "Passenger" << setw(10) << "Time" << endl;

    for (const auto &flight : flights) {
        cout << setw(10) << flight.flightNumber << setw(15) << flight.aircraftNumber << setw(15)
             << flight.pilotName << setw(15) << flight.sourceCity << setw(15) 
             << flight.destinationCity << setw(15) << flight.flightDate 
             << setw(15) << flight.passengerName << setw(10) << flight.flightTime << endl;
    }
}

// Main function
int main() {
    vector<Flight> flights;
    int choice;

    while (true) {
        CLS();
        Menu();
        cin >> choice;

        switch (choice) {
            case 1: CLS(); NewFlight(flights); PAUSE(); break;
            case 2: CLS(); DeleteFlight(flights); PAUSE(); break;
            case 3: CLS(); AddPassenger(flights); PAUSE(); break;
            case 4: CLS(); DeletePassenger(flights); PAUSE(); break;
            case 5: CLS(); ChangePilot(flights); PAUSE(); break;
            case 6: CLS(); DisplayByPilot(flights); PAUSE(); break;
            case 7: CLS(); DisplayByDate(flights); PAUSE(); break;
            case 8: CLS(); DisplaySortedByDate(flights); PAUSE(); break;
            case 9: CLS(); DisplayPilotsInAlphabeticalOrder(flights); PAUSE(); break;
            case 10: CLS(); SearchByFlightNumber(flights); PAUSE(); break;
            case 11: CLS(); DisplayDelayedFlights(flights); PAUSE(); break;
            case 12: CLS(); DisplayAllFlights(flights); PAUSE(); break;
            case 13: exit(0); break;
            default: PAUSE(); break;
        }
    }

    return 0;
}
