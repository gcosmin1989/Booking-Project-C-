#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "Hotel.h"
#include "GuestHouse.h"
#include "Booking.h"

int main() {
    while (true) {
        string user_choice;
        int booking_choice;
        int register_choice;
        string hotel_name;
        string hotel_city;
        int hotel_rooms;
        double hotel_price;
        string guesthouse_name;
        string guesthouse_city;
        int guesthouse_beds;
        double guesthouse_price;
        string guesthouse_owner;

        cout << "Would you like to register your Accomodation or make a Booking? (Register/Booking/Exit)" << endl;
        cin >> user_choice;

        if (user_choice == "Booking") {
            cout << "Please choose what Accomodation you want:" << endl
                << "1 for Hotels" << endl
                << "2 for GuestHouses" << endl
                << "3 go Back" << endl;
            cin >> booking_choice;

            if (booking_choice == 1) {
                Hotel::display_hotels();
                if (!Hotel::hotels.empty()) {
                    cout << "Enter the hotel name you want to book: ";
                    cin.ignore();
                    getline(cin, hotel_name);
                    Hotel* hotel = Hotel::find_hotel_by_name(hotel_name);
                    if (hotel != nullptr && hotel->rooms > 0) {
                        string customer_name;
                        int nights;
                        int num_rooms;
                        cout << "Enter your name: ";
                        getline(cin, customer_name);
                        cout << "Enter the number of nights: ";
                        cin >> nights;
                        cout << "Enter the number of rooms: ";
                        cin >> num_rooms;
                        if (hotel->book_rooms(num_rooms)) {
                            Booking booking(customer_name, *hotel, nights, num_rooms);
                            booking.display_booking("rooms");
                        }
                        else {
                            cout << "Not enought rooms availbe" << endl;
                        }
                    }
                    else if(hotel->rooms == 0) {
                        cout << "Rooms not available" << endl;
                        
                    }else{ 
                        cout << "Hotel not found." << endl; 
                    }
                }
            }
            else if (booking_choice == 2) {
                GuestHouse::display_guestHouses();
                if (!GuestHouse::guestHouses.empty()) {
                    cout << "Enter the guesthouse name you want to book: ";
                    cin.ignore();
                    getline(cin, guesthouse_name);
                    GuestHouse* guestHouse = GuestHouse::find_guesthouse_by_name(guesthouse_name);
                    if (guestHouse != nullptr && guestHouse->beds>0) {
                        string customer_name;
                        int nights;
                        int num_beds;
                        cout << "Enter your name: ";
                        getline(cin, customer_name);
                        cout << "Enter the number of nights: ";
                        cin >> nights;
                        cout << "Enter the number of beds: ";
                        cin >> num_beds;
                        
                        if (guestHouse->book_beds(num_beds)) {
                            Booking booking(customer_name, *guestHouse, nights, num_beds);
                            booking.display_booking("beds");
                        }
                        
                        else {
                            cout << "Not enought beds availabe" << endl;
                        }
                    }
                    else if (guestHouse->beds == 0) {
                        cout << "Beds not available" << endl;

                    }
                    else {
                        cout << "GuestHouse not found." << endl;
                    }
                }
            }
        }
        else if (user_choice == "Register") {
            cout << "Please choose what Accomodation you want to Register:" << endl
                << "1 for Hotels" << endl
                << "2 for GuestHouses" << endl
                << "3 go Back" << endl;
            cin >> register_choice;

            if (register_choice == 1) {
                cout << "Hotel name: ";
                cin.ignore();
                getline(cin, hotel_name);
                cout << "City: ";
                getline(cin, hotel_city);
                cout << "Number of rooms: ";
                while (!(cin >> hotel_rooms)) {
                    cout << "Invalid input. Please enter the number of rooms: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                cout << "Price per room: ";
                while (!(cin >> hotel_price)) {
                    cout << "Invalid input. Please enter the price of a room: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cout << endl;
                Hotel hotel(hotel_name, hotel_city, hotel_price, hotel_rooms);
                hotel.get_info();
            }
            else if (register_choice == 2) {
                cout << "GuestHouse name: ";
                cin.ignore();
                getline(cin, guesthouse_name);
                cout << "City: ";
                getline(cin, guesthouse_city);
                cout << "Number of beds: ";
                while (!(cin >> guesthouse_beds)) {
                    cout << "Invalid input. Please enter the number of beds: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                cout << "Price per bed: ";
                while (!(cin >> guesthouse_price)) {
                    cout << "Invalid input. Please enter the price of a bed: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cin.ignore();
                cout << "GuestHouse owner name: ";
                getline(cin, guesthouse_owner);
                cout << endl;
                GuestHouse guestHouse(guesthouse_name, guesthouse_city, guesthouse_price, guesthouse_beds, guesthouse_owner);
                guestHouse.get_info();
            }
        }
        else if (user_choice == "Exit") {
            cout << "Exit Selected" << endl;
            break;
        }
        else {
            cout << "Invalid selection" << endl;
        }
    }

    return 0;
}
