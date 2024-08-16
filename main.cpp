#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Accommodation {
protected:
    string name;
    string city;
    double price;
public:
    Accommodation(string name, string city, double price) {
        this->name = name;
        this->city = city;
        this->price = price;
    }

    string get_name() const { return name; }
    double get_price() const { return price; }

    void get_info() const {
        cout << "== Registration successfully for: " << this->name << " in " << this->city << " with price of: $" << this->price<< " per night";
    }

    void get_registered() const {
        cout << "Name: " << this->name << " | City: " << this->city
            << " | Price per night: $" << this->price;
    }
};

class Hotel : public Accommodation {
public:
    static vector<Hotel> hotels;
    int rooms;

    Hotel(string name, string city, double price, int rooms)
        : Accommodation(name, city, price), rooms(rooms) {
        hotels.push_back(*this);
    }

    void get_info() const {
        Accommodation::get_info();
        cout << " available units: " << this->rooms << " rooms ==" << endl << endl;
    }

    void get_registered() const {
        Accommodation::get_registered();
        cout << " | Rooms: " << this->rooms << endl;
    }

    static void display_hotels() {
        if (hotels.empty()) {
            cout << endl << "No hotels registered yet." << endl << endl;
        }
        else {
            cout <<endl << "List of Hotels:" << endl;
            for (const auto& hotel : hotels) {
                hotel.get_registered();
            }
        }
    }

    static bool find_hotel_by_name(const string& name, Hotel*& result) {
        for (auto& hotel : hotels) {
            if (hotel.get_name() == name) {
                result = &hotel;  
                return true;
            }
        }
        return false;  
    }

    bool book_rooms(int num_rooms) {
        if (num_rooms <= rooms) {
            rooms -= num_rooms;
            return true;
        }
        else {
            return false;
        }
    }
};

vector<Hotel> Hotel::hotels;

class GuestHouse : public Accommodation {
public:
    static vector<GuestHouse> guestHouses;
    int beds;
    string owner;

    GuestHouse(string name, string city, double price, int beds, string owner)
        : Accommodation(name, city, price), beds(beds), owner(owner) {
        guestHouses.push_back(*this);
    }

    void get_info() const {
        Accommodation::get_info();
        cout << " available units :  " << this->beds << " beds, Owner name: " << this->owner << " ==" << endl<<endl;
    }

    void get_registered() const {
        Accommodation::get_registered();
        cout << " | Beds: " << this->beds << " | Owner name: " << this->owner << endl;
    }

    static void display_guestHouses() {

        if (guestHouses.empty()) {
            cout << endl << "No GuestHouses registered yet." << endl << endl;
        }
        else {
            cout << endl << "List of GuestHouses:" << endl;
            for (const auto& guestHouse : guestHouses) {
                guestHouse.get_registered();
            }
        }
    }

    static GuestHouse* find_guesthouse_by_name(const string& name) {
        for (auto& guestHouse : guestHouses) {
            if (guestHouse.get_name() == name) {
                return &guestHouse;
            }
        }
        return nullptr;  
    }

    bool book_beds(int num_beds) {
        if (num_beds <= beds) {
            beds -= num_beds;
            return true;
        }
        else {
            return false;
        }
    }
};

vector<GuestHouse> GuestHouse::guestHouses;

class Booking {
public:
    string customer_name;
    Accommodation& accommodation;
    int nights;
    int num_units; 

    Booking(string customer_name, Accommodation& accommodation, int nights, int num_units)
        : customer_name(customer_name), accommodation(accommodation), nights(nights), num_units(num_units) {}

    void display_booking(string unit) const {
        cout << endl<< "== Booking for " << customer_name << " at " << accommodation.get_name()
            << " for " << nights << " nights, " << num_units <<" "<< unit << ".Total price : $"
            << accommodation.get_price() * nights * num_units <<" =="<< endl<<endl;
    }
};

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

        cout << "Would you like to register your Accommodation or make a Booking? (Register/Booking/Exit)" << endl;
        cin >> user_choice;

        if (user_choice == "Booking") {
            cout << "Please choose what accommodation you want:" << endl
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
                    Hotel* hotel_ptr;
                    if (Hotel::find_hotel_by_name(hotel_name, hotel_ptr) && hotel_ptr->rooms > 0) {
                        string customer_name;
                        int nights;
                        int num_rooms;
                        cout << "Enter your name: ";
                        getline(cin, customer_name);
                        cout << "Enter the number of nights: ";
                        cin >> nights;
                        cout << "Enter the number of rooms: ";
                        cin >> num_rooms;
                        if (hotel_ptr->book_rooms(num_rooms)) {
                            Booking booking(customer_name, *hotel_ptr, nights, num_rooms);
                            booking.display_booking("rooms");
                        }
                        else {
                            cout << "Not enought rooms availbe" << endl;
                        }
                    }
                    else if(hotel_ptr->rooms == 0) {
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
                            cout << "Not enought beds availbe" << endl;
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
            cout << "Please choose what accommodation you want to Register:" << endl
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
