#ifndef HEADER_HPP
#define HEADER_HPP

#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <ctime>
#include <cstdlib>

using namespace std;

// DVD Class
class DVD {
public:
    string title;
    string genre;
    string year;
    int nostock;

    // Constructor
    DVD() = default; // Let the compiler generate it
};

class Customer {
public:
    string name;
    string customerID;
    string phone;
    string email;

    // Constructor
    Customer() = default; // Let the compiler generate it
};


// Rental Class
class Rental {
public:
    int customerID;
    string DVDTitle;

    time_t now = std::time(0);              
    tm *ltm = std::localtime(&now);         
    
    string dates= to_string(ltm->tm_mday) + "/" + to_string(1 + ltm->tm_mon) + "/" +to_string(1900 + ltm->tm_year);

    // Constructor
    Rental() = default; // Let the compiler generate it
};

extern vector<DVD> dvdCollection;
extern vector<Customer> customers;
extern vector<Rental> rentalHistory;

void displayMenu();
void CheckAvailability();
void AddDVD();
void registerCustomer();
void searchCustomer();
void rentDVD();
void returnDVD();
bool CustomerID(string);
void displayCustomerData();
void displayRentalHistory();

#endif