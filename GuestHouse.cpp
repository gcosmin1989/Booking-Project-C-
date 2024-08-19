#include "GuestHouse.h"

std::vector<GuestHouse> GuestHouse::guestHouses;

GuestHouse::GuestHouse(std::string name, std::string city, double price, int beds, std::string owner)
    : Accomodation(name, city, price), beds(beds), owner(owner) {
    guestHouses.push_back(*this);
}

void GuestHouse::get_info() const {
    Accomodation::get_info();
    std::cout << " available units: " << beds << " beds, Owner name: " << owner << " ==" << std::endl << std::endl;
}

void GuestHouse::get_registered() const {
    Accomodation::get_registered();
    std::cout << " | Beds: " << beds << " | Owner name: " << owner << std::endl;
}

void GuestHouse::display_guestHouses() {
    if (guestHouses.empty()) {
        std::cout << std::endl << "No GuestHouses registered yet." << std::endl << std::endl;
    }
    else {
        std::cout << std::endl << "List of GuestHouses:" << std::endl;
        for (const auto& guestHouse : guestHouses) {
            guestHouse.get_registered();
        }
    }
}

GuestHouse* GuestHouse::find_guesthouse_by_name(const std::string& name) {
    for (auto& guestHouse : guestHouses) {
        if (guestHouse.get_name() == name) {
            return &guestHouse;
        }
    }
    return nullptr;
}

bool GuestHouse::book_beds(int num_beds) {
    if (num_beds <= beds) {
        beds -= num_beds;
        return true;
    }
    else {
        return false;
    }
}
