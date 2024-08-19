#include "Accomodation.h"
#include <iostream>;


Accomodation::Accomodation(std::string name, std::string city, double price)
    : name(name), city(city), price(price) {}

std::string Accomodation::get_name() const { return name; }
double Accomodation::get_price() const { return price; }

void Accomodation::get_info() const {
    std::cout << "== Registration successfully for: " << name << " in " << city << " with price of: $" << price << " per night";
}

void Accomodation::get_registered() const {
    std::cout << "Name: " << name << " | City: " << city << " | Price per night: $" << price;
}
