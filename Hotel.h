#pragma once
#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "Accomodation.h"
using namespace std;

class Hotel : public Accomodation {
public:
    int rooms;

    Hotel(string name, string city, double price, int rooms);

    void get_info() const;

    void get_registered() const;
      
    bool book_rooms(int num_rooms);
};


