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
	void get_info() const {
		cout << "============================" << endl
			<< "Registration succesfuly for:" << endl
			<< "Name: " << this->name << endl
			<< "City: " << this->city << endl
			<< "Price per night: " << this->price << endl;
	}
	void get_registered() const {
			cout << "Name: " << this->name << "| City: " << this->city  << "| Price per night: " << this->price;
	}
};

class Hotel :Accommodation {
public:
	static vector<Hotel> hotels;
	
public:
	int rooms;
	
	Hotel( string name, string city, double price, int rooms)
		: Accommodation(name, city, price) {
		this->rooms = rooms;
		hotels.push_back(*this);
	}
	
	void get_info() const { 
		Accommodation::get_info();
		cout << "Rooms: " << this->rooms << endl;
	}

	void get_registered() const {
		Accommodation::get_registered();
		cout << "| Rooms: " <<this->rooms<< endl;
	}

	static void display_hotels() {
		if (hotels.empty()) {
			cout << "No hotels registered yet." << endl;
		}
		else {
			for (const auto& hotel : hotels) {
				hotel.get_registered();
			}
		}
	}
};

vector<Hotel> Hotel::hotels;

int main()
{
	while (true)
	{
		string user_choise;
		int booking_choise;
		string hotel_name;
		string hotel_city;
		int hotel_rooms;
		double hotel_price;

		cout << "Would you like to register your Hotel or make a Booking? (Register/Booking/Exit)" << endl;
		cin >> user_choise;
		if (user_choise == "Booking") {
			cout << "Please choose what acomodation you want:" << endl
				<< "1 for Hotels" << endl
				<< "2 for GuestHouses" << endl
				<< "3 go Back" << endl;
			cin >> booking_choise;
			if (booking_choise == 1) {
				Hotel::display_hotels();
			}
			else if (booking_choise == 2) {
				cout << "Booking guestHouse Selected";
			}
			else if (booking_choise == 3) {
				main();
			}
		}
		else if (user_choise == "Register") {
			cout << "Hotel name: ";
			cin >> hotel_name ;
			cout << "City: ";
			cin >> hotel_city;
			cout << "Number of rooms: ";
			cin >> hotel_rooms;
			cout << "Price per room: ";
			cin >> hotel_price;
			Hotel hotel(hotel_name, hotel_city, hotel_price, hotel_rooms);
			hotel.get_info();
		}
		else if (user_choise == "Exit") {
			cout << "Exit Selected" << endl;
			
		}
		else {
			cout << "Invalid selection"<<endl;
			main();
		}
	}

    return 0;
}

