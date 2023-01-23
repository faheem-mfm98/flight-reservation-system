#include<iostream>
#include<string>
#include<fstream>
#include"Departure.h"
#include"Adjlist.h"
#include"Flight.h"
#include"Date.h"
#include"Node.h"
#include"AirlineSystem.h"

using namespace std;

string readInputString(ifstream& input) {
	string str;
	input >> str;
	return str;
}

void ignoreCharacter(ifstream& input) {
	char ch;
	input >> ch;
}

int main() {
	string str = "hello";
	cout << "Welcome to Airline Reservation System" << endl;

	ifstream input;
	input.open("../flights.txt", ios::in);

	string source, dest, airline;
	int day, month, year, fly_hour, fly_min, land_hour, land_min, price;

	Adjlist graph(20);

	char ch;
	while (input >> source) {
		input >> dest;
		input >> day;
		input >> ch;
		input >> month;
		input >> ch;
		input >> year;
		input >> fly_hour;
		input >> ch;
		input >> fly_min;
		input >> land_hour;
		input >> ch;
		input >> land_min;
		input >> price;
		input >> airline;

		Node* node3 = new Node;
		node3->setLocationName(dest);

		Flight flt3;
		flt3.setFlightPrice(price);
		flt3.setDate(day, month, year);
		flt3.setAirlineName(airline);

		node3->addFlight(flt3);

		graph.addDeparture(source, node3);
	}

	graph.displayAllDepartures();
	
//	AirlineSystem system;
//	system.userInput("Lahore","Finland", graph);

/*
	Node* node = new Node;
	node->setLocationName("Paris");

	Flight flt;
	flt.setFlightPrice(10000);
	flt.setDate(2, 2, 2000);
	//	flt2.date_of_flight.setMonth(2);
	//	flt2.date_of_flight.setYear(2000);
	flt.setAirlineName("PIA");

	node->addFlight(flt);

//	node->displayNode();

	Node* node2 = new Node;
	node2->setLocationName("Toronto");

	Flight flt2;
	flt2.setFlightPrice(10000);
	flt2.setDate(2,2,2000);
//	flt2.date_of_flight.setMonth(2);
//	flt2.date_of_flight.setYear(2000);
	flt2.setAirlineName("New AirLines");

	node2->addFlight(flt);
	node2->addFlight(flt2);

//	node2->displayNode();

//	cout << "Success" << endl;
	
	Departure list;

//	cout << "List" << endl << endl;
	list.setDepartingName("Islamabad");

	list.addNode(node);
	list.addNode(node2);

//	list.displayList();

	cout << "Graph" << endl << endl;
	
	Adjlist graph(2);
	cout << graph.getNumDeparts();
	graph.addDeparture("Islamabad", node);
//	graph.displayDepartsFrom("Islamabad");
	graph.addDeparture("New York", node);
	graph.addDeparture("New York", node2);
	graph.addDeparture("New York", node2);
*/
//	graph.displayAllDepartures();

	return 0;
}
