#include "Booking.h"
#include <iostream>

Booking::Booking(std::string customer_name, Accomodation& accomodation, int nights, int num_units)
    : customer_name(customer_name), accomodation(accomodation), nights(nights), num_units(num_units) {}

void Booking::display_booking(std::string unit) const {
    std::cout << std::endl << "== Booking for " << customer_name << " at " << accomodation.get_name()
        << " for " << nights << " nights, " << num_units << " " << unit << ". Total price: $"
        << accomodation.get_price() * nights * num_units << " ==" << std::endl << std::endl;
}
