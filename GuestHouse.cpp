#include "GuestHouse.h"
using namespace std;


GuestHouse::GuestHouse(string name, string city, double price, int beds, string owner)
    : Accomodation(name, city, price), beds(beds), owner(owner) {}

void GuestHouse::get_info() const {
    Accomodation::get_info();
    cout << " available units: " << beds << " beds, Owner name: " << owner << " ==" << endl << endl;
}

void GuestHouse::get_registered() const {
    Accomodation::get_registered();
    cout << " | Beds: " << beds << " | Owner name: " << owner << endl;
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
