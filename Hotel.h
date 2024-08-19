#pragma once
#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "Accomodation.h"
using namespace std;

class Hotel : public Accomodation {
public:
    static vector<Hotel> hotels;
    int rooms;

    Hotel(string name, string city, double price, int rooms);

    void get_info() const;

    void get_registered() const;
    static void display_hotels();
      

    static Hotel* find_hotel_by_name(const string& name);

    bool book_rooms(int num_rooms);
};


