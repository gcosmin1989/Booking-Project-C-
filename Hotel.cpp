#include "Hotel.h"

std::vector<Hotel> Hotel::hotels;

Hotel::Hotel(std::string name, std::string city, double price, int rooms)
    : Accomodation(name, city, price), rooms(rooms) {
    hotels.push_back(*this);
}

void Hotel::get_info() const {
    Accomodation::get_info();
    std::cout << " available rooms: " << rooms << " rooms ==" << std::endl << std::endl;
}

void Hotel::get_registered() const {
    Accomodation::get_registered();
    std::cout << " | Rooms: " << rooms << std::endl;
}

void Hotel::display_hotels() {
    if (hotels.empty()) {
        std::cout << std::endl << "No hotels registered yet." << std::endl << std::endl;
    }
    else {
        std::cout << std::endl << "List of Hotels:" << std::endl;
        for (const auto& hotel : hotels) {
            hotel.get_registered();
        }
    }
}

Hotel* Hotel::find_hotel_by_name(const std::string& name) {
    for (auto& hotel : hotels) {
        if (hotel.get_name() == name) {
            return &hotel;
        }
    }
    return nullptr;
}

bool Hotel::book_rooms(int num_rooms) {
    if (num_rooms <= rooms) {
        rooms -= num_rooms;
        return true;
    }
    else {
        return false;
    }
}
