#pragma once

#include <string>
#include <iostream>

class Accomodation {
protected:
    std::string name;
    std::string city;
    double price;

public:
    Accomodation(std::string name, std::string city, double price);

    std::string get_name() const;
    double get_price() const;

    void get_info() const;
    void get_registered() const;
};

