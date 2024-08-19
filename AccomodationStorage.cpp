#include "AccomodationStorage.h"
#include <iostream>
using namespace std;

void AccomodationStorage::add_hotel(const Hotel& hotel) {
    hotels.push_back(hotel);
}

void AccomodationStorage::add_guesthouse(const GuestHouse& guestHouse) {
    guestHouses.push_back(guestHouse);
}

bool AccomodationStorage::find_hotel_by_name(const string& name, Hotel*& result) {
    for (auto& hotel : hotels) {
      //  cout << "Aici";
        if (hotel.get_name() == name) {
            result = &hotel;
          //  cout << "Aici1";
            return true;
        }
    }
   // cout << "Aici2";
    return false;
}

bool AccomodationStorage::find_guesthouse_by_name(const string& name, GuestHouse*& result) {
    for (auto& guesthouse : guestHouses) {
        if (guesthouse.get_name() == name) {
            result = &guesthouse;
            return true;
        }
    }
    return false;
}


void AccomodationStorage::display_hotels() const {
    if (hotels.empty()) {
        cout << "No hotels registered yet." << endl;
    }
    else {
        cout << "List of Hotels:" << endl;
        for (const auto& hotel : hotels) {
            hotel.get_registered();
        }
    }
}

void AccomodationStorage::display_guesthouses() const {
    if (guestHouses.empty()) {
        cout << "No guesthouses registered yet." << endl;
    }
    else {
        cout << "List of Guesthouses:" << endl;
        for (const auto& guestHouse : guestHouses) {
            guestHouse.get_registered();
        }
    }
}
