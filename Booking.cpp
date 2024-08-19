#include "Booking.h"
#include <iostream>
using namespace std;

Booking::Booking(string customer_name, Accomodation& accomodation, int nights, int num_units)
    : customer_name(customer_name), accomodation(accomodation), nights(nights), num_units(num_units) {}

void Booking::display_booking(string unit) const {
    cout << endl << "== Booking for " << customer_name << " at " << accomodation.get_name()
        << " for " << nights << " nights, " << num_units << " " << unit << ". Total price: $"
        << accomodation.get_price() * nights * num_units << " ==" << endl << endl;
}
