#pragma once
#include <string>
#include "Accomodation.h"

class Booking {
public:
    std::string customer_name;
    Accomodation& accomodation;
    int nights;
    int num_units;

    Booking(std::string customer_name, Accomodation& accomodation, int nights, int num_units);

    void display_booking(std::string unit) const;
};


