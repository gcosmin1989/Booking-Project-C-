#include "Hotel.h"
using namespace std;
vector<Hotel> Hotel::hotels;

Hotel::Hotel(string name, string city, double price, int rooms)
    : Accomodation(name, city, price), rooms(rooms) {
    hotels.push_back(*this);
}

void Hotel::get_info() const {
    Accomodation::get_info();
    cout << " available units: " << rooms << " rooms ==" << endl << endl;
}

void Hotel::get_registered() const {
    Accomodation::get_registered();
    cout << " | Rooms: " << rooms << endl;
}

void Hotel::display_hotels() {
    if (hotels.empty()) {
        cout << endl << "No hotels registered yet." << endl << endl;
    }
    else {
        cout << endl << "List of Hotels:" << endl;
        for (const auto& hotel : hotels) {
            hotel.get_registered();
        }
    }
}

Hotel* Hotel::find_hotel_by_name(const string& name) {
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
