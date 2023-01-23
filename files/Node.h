#pragma once
#include"Flight.h"

using namespace std;

class Node {								// a node  
	string name_of_location;				// represents a landing location
	Flight* flights;						// and has/receives many flights from source/departing locations
	int no_of_flights;
	Node* next;

public:
	Node() {
		name_of_location = "";
		no_of_flights = 0;
		flights = NULL;
		next = NULL;
	}

	void setLocationName(string name) {
		name_of_location = name;
	}

	string getLocationName() {
		return name_of_location;
	}

	int getNumFlights() {
		return no_of_flights;
	}

	Flight* getFlights() {
		return flights;
	}

	Flight getFlight(int index) {
		return flights[index];
	}

	void addFlight(Flight flt) {

		no_of_flights++;
		Flight* newFlightsArray = createNewFlightArray();

		copyFlights(newFlightsArray, no_of_flights - 1);		// copy all flights into new array
		newFlightsArray[no_of_flights - 1].setFlight(flt);			// add the new flight at last index 
		
		if (flights != NULL) {
			delete[] flights;											// free the previous memory
		}

		flights = newFlightsArray;						// point to new flights array
//		}
	}

	void addFlights(Node* node) {
		int flt_count = node->getNumFlights();
		no_of_flights += flt_count;

		Flight* newFlightsArray = createNewFlightArray();

		copyFlights(newFlightsArray, no_of_flights - flt_count);
		
		for (int i = no_of_flights - flt_count, j=0; i < no_of_flights; i++,j++) {
			newFlightsArray[i].setFlight(node->getFlight(j));
		}

		if (flights != NULL) {
			delete[] flights;
		}

		flights = newFlightsArray;
	}

	Flight* createNewFlightArray() {
		return new Flight[no_of_flights];
	}

	void copyFlights(Flight* newFlightsArray, int num_flts) {
		for (int i = 0; i < num_flts; i++) {
			newFlightsArray[i].setFlight(flights[i]);			// copy all flights into new array
		}
	}

	void setNext(Node* newNode) {
		next = newNode;
	}

	Node* getNext() {
		return next;
	}

	void displayNode() {
		cout << "Name of location: " << name_of_location << endl;
		cout << "No. of flights: " << no_of_flights << endl << endl;
		
		for (int i = 0; i < no_of_flights; i++) {
			cout<< "Flight " << i + 1 << ":" <<endl;
			flights[i].displayFlight();
			cout << endl;
		}
	}
};