#pragma once
#include <string>
#include <iostream>

class Accomodation
{
private:
    std::string name ;
    std::string city = "";
    double price = {};
public:
    Accomodation(std::string name_val, std::string city_val, double price_val) {
        name = name_val;
        city = city_val;
        price = price_val;
    }
    void get_info() {
        std::cout << "=============================" << std::endl 
            << "Registration successfully for: " << std::endl 
            << "Name: " << name << std::endl 
            << "City:" << city << std::endl 
            << "Price per night: " << price << std::endl;
    }
};


