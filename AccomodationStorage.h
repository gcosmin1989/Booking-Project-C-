#pragma once
#include "Hotel.h"
#include "GuestHouse.h"
#include <vector>
#include <string>
using namespace std;

class AccomodationStorage {
public:
    vector<Hotel> hotels;
    vector<GuestHouse> guestHouses;

public:
    void add_hotel(const Hotel& hotel);
    void add_guesthouse(const GuestHouse& guestHouse);

    bool find_hotel_by_name(const string& name, Hotel*& result);
    bool find_guesthouse_by_name(const string& name, GuestHouse*& result);

    void display_hotels() const;
    void display_guesthouses() const;
};