#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "Accomodation.h"
using namespace std;

class GuestHouse : public Accomodation {
public:
    static vector<GuestHouse> guestHouses;
    int beds;
    string owner;

    GuestHouse(string name, string city, double price, int beds, string owner);
  

    void get_info() const;

    void get_registered() const;

    bool book_beds(int num_beds);
};

