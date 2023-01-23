#pragma once

#include"Departure.h"
#include"Date.h"
using namespace std;

class Flight {								// a flight 
	Date date_of_flight;					// has a date of departure
	int price;								// and ticket price
	string airline;							// and is from an airline

public:
	Flight() {
		date_of_flight.setDay(0);
		date_of_flight.setMonth(0);
		date_of_flight.setYear(0);
		price = 0;								
		airline = "";							
	}

	Date getFlightDate() {
		return date_of_flight;
	}

	void setDate(Date date) {
		date_of_flight.setDay(date.getDay());
		date_of_flight.setMonth(date.getMonth());
		date_of_flight.setYear(date.getYear());
	}

	void setDate(int day, int month, int year) {
		date_of_flight.setDay(day);
		date_of_flight.setMonth(month);
		date_of_flight.setYear(year);
		
	}

	void setFlight(Flight flt) {
		setDate(flt.getFlightDate());
		setFlightPrice(flt.getFlightPrice());
		setAirlineName(flt.getAirlineName());
	}

	int getFlightPrice() {
		return price;
	}

	void setFlightPrice(int p) {
		price = p;
	}

	string getAirlineName() {
		return airline;
	}

	void setAirlineName(string name) {
		airline = name;
	}

	void displayFlight() {
		cout << "date: ";
		date_of_flight.displayDate();
		cout << "Price: " << price << endl;
		cout << "Airline: " << airline << endl;

	}
};
