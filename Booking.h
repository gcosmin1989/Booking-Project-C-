#pragma once
#include <string>
#include "Accomodation.h"
using namespace std;

class Booking {
public:
    string customer_name;
    Accomodation& accomodation;
    int nights;
    int num_units;

    Booking(string customer_name, Accomodation& accomodation, int nights, int num_units);

    void display_booking(string unit) const;
};


