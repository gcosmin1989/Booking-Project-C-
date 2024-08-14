#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
using namespace std;
//De verificat de ce intra in loop cand introduc string la input la rooms si price

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
		cout << "== "
			<< "Registration succesfuly for: " << this->name << " in " << this->city << " with price of: $" << this->price<<" per night";
	}
	void get_registered() const {
			cout << "Name: " << this->name << "| City: " << this->city  << "| Price per night: " << this->price;
	}

};

class Hotel :Accommodation {
public:
	static vector<Hotel> hotels;
	string guesthouse_name;
public:
	int rooms;
	
	Hotel( string name, string city, double price, int rooms)
		: Accommodation(name, city, price) {
		this->rooms = rooms;
		hotels.push_back(*this);
	}
	
	void get_info() const { 
		Accommodation::get_info();
		cout << " with: " << this->rooms << " rooms" << " ==" << endl << endl;
	}

	void get_registered() const {
		Accommodation::get_registered();
		cout << "| Rooms: " <<this->rooms<< endl;
	}

	static void display_hotels() {
		if (hotels.empty()) {
			cout << endl << "No hotels registered yet." << endl << endl;
		}
		else {
			cout << "List of Hotels:" << endl;
			for (const auto& hotel : hotels) {
				hotel.get_registered();
			}
			cout << "Choose a hotel you want to stay(Enter the name): " << endl;

		}
	}

	 static void book() {
            cout << "Hotel not found." << endl;
        }
};

vector<Hotel> Hotel::hotels;

class GuestHouse :Accommodation {
public:
	static vector<GuestHouse> guestHouses;

public:
	int beds;
	string owner;

	GuestHouse(string name, string city, double price, int beds, string owner)
		: Accommodation(name, city, price) {
		this->beds = beds;
		this->owner = owner;
		guestHouses.push_back(*this);
	}

	void get_info() const {
		Accommodation::get_info();
		cout << " with " << this->beds<<" beds, "  << "Owner name: " << this->owner  <<" ==" << endl;;
	}

	void get_registered() const {
		Accommodation::get_registered();
		cout << "| Beds: " << this->beds << endl;
		cout << "| Owner name: " << this->owner << endl;
	}

	static void display_guestHouses() {
		if (guestHouses.empty()) {
			cout <<endl<< "No GuestHouses registered yet." << endl << endl;
		}
		else {
			
			for (const auto& guestHouse : guestHouses) {
				guestHouse.get_registered();
			}

		}
	}

};
vector<GuestHouse> GuestHouse::guestHouses;

int main()
{
	while (true)
	{
		string user_choise;
		int booking_choise;
		int register_choise;
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
		cin >> user_choise;

		if (user_choise == "Booking") {
			cout << "Please choose what accommodation you want:" << endl
				<< "1 for Hotels" << endl
				<< "2 for GuestHouses" << endl
				<< "3 go Back" << endl;
			cin >> booking_choise;

			if (booking_choise == 1) {
				Hotel::display_hotels();
				if (!Hotel::hotels.empty()) {
					cout << "Choose Accommodation Hotel" << endl;
					Hotel::book();
				}
			}
			else if (booking_choise == 2) {
				GuestHouse::display_guestHouses();
				if (!GuestHouse::guestHouses.empty()) {
					cout << "List of Hotels:" << endl;
				}
			}
		}
		else if (user_choise == "Register") {
			cout << "Please choose what accommodation you want to Register:" << endl
				<< "1 for Hotels" << endl
				<< "2 for GuestHouses" << endl
				<< "3 go Back" << endl;
			cin >> register_choise;

			if (register_choise == 1) {
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
			else if (register_choise == 2) {
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
		else if (user_choise == "Exit") {
			cout << "Exit Selected" << endl;
			break;
		}
		else {
			cout << "Invalid selection" << endl;
		}
	}

	return 0;
}

