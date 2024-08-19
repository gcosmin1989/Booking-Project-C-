#pragma once
using namespace std;
#include <string>
#include <iostream>

class Accomodation {
protected:
    string name;
    string city;
    double price;

public:
    Accomodation(string name, string city, double price);

    string get_name() const;
    double get_price() const;

    void get_info() const;
    void get_registered() const;
};

