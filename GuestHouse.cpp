#include "GuestHouse.h"
using namespace std;

vector<GuestHouse> GuestHouse::guestHouses;

GuestHouse::GuestHouse(string name, string city, double price, int beds, string owner)
    : Accomodation(name, city, price), beds(beds), owner(owner) {
    guestHouses.push_back(*this);
}

void GuestHouse::get_info() const {
    Accomodation::get_info();
    cout << " available units: " << beds << " beds, Owner name: " << owner << " ==" << endl << endl;
}

void GuestHouse::get_registered() const {
    Accomodation::get_registered();
    cout << " | Beds: " << beds << " | Owner name: " << owner << endl;
}

void GuestHouse::display_guestHouses() {
    if (guestHouses.empty()) {
        cout << endl << "No GuestHouses registered yet." << endl << endl;
    }
    else {
        cout << endl << "List of GuestHouses:" << endl;
        for (const auto& guestHouse : guestHouses) {
            guestHouse.get_registered();
        }
    }
}

GuestHouse* GuestHouse::find_guesthouse_by_name(const string& name) {
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
