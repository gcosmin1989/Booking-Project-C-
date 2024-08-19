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

    static void display_guestHouses();

    static GuestHouse* find_guesthouse_by_name(const string& name);

    bool book_beds(int num_beds);
};

