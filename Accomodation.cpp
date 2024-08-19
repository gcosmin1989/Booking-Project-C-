#include "Accomodation.h"
#include <iostream>;
using namespace std;

Accomodation::Accomodation(string name, string city, double price)
    : name(name), city(city), price(price) {}

string Accomodation::get_name() const { return name; }
double Accomodation::get_price() const { return price; }

void Accomodation::get_info() const {
    cout << "== Registration successfully for: " << name << " in " << city << " with price of: $" << price << " per night";
}

void Accomodation::get_registered() const {
    cout << "Name: " << name << " | City: " << city << " | Price per night: $" << price;
}
