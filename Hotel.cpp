#include "Hotel.h"
using namespace std;


Hotel::Hotel(string name, string city, double price, int rooms)
    : Accomodation(name, city, price), rooms(rooms) {}

void Hotel::get_info() const {
    Accomodation::get_info();
    cout << " available units: " << rooms << " rooms ==" << endl << endl;
}

void Hotel::get_registered() const {
    Accomodation::get_registered();
    cout << " | Rooms: " << rooms << endl;
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
