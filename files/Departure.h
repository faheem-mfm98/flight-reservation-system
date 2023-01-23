#pragma once

#include"Node.h"
using namespace std;

class Departure {								// a departure   
	string departing_location;					// is a location name 
	Node* destination_locations;				// and has direct flights to destination locations  
	int no_of_destinations;						// count of direct locations

public:
	Departure() {
		departing_location = "";
		destination_locations = NULL;
		no_of_destinations = 0;
	}

	void setDepartingName(string name) {
		departing_location = name;
	}

	string getDepartingLocationName() {
		return departing_location;
	}

	Node* getDestinations() {
		return destination_locations;
	}

	void addNode(Node* node) {

		Node* ptr2 = nodeExist(node->getLocationName());
		if (ptr2) {
			ptr2->addFlights(node);
			return;
		}

		Node* newNode = new Node;					// create and copy node's values
		newNode->setNext(NULL);
		newNode->setLocationName(node->getLocationName());

		for (int i = 0; i < node->getNumFlights(); i++) {		// copy all flights details
			newNode->addFlight(node->getFlight(i));
		}

		if (destination_locations == NULL) {		// if no destination exist in the list, make it the initial dest.
			destination_locations = newNode;
		}
		else {
			Node* ptr = destination_locations;
			while (ptr->getNext() != NULL) {		// iterate over the nodeList to last node
				ptr = ptr->getNext();
			}

			ptr->setNext(newNode);					// and append to end of the list
		}

		no_of_destinations++;
	}

	Node* nodeExist(string dest_name) {
		Node* ptr = destination_locations;

		if (ptr == NULL) {
			return NULL;
		}
		else if (ptr->getLocationName() == dest_name) {
			return ptr;
		}

		while (ptr->getNext() != NULL) {
			ptr = ptr->getNext();

			if (ptr->getLocationName() == dest_name) {
				return ptr;
			}
		}

		return NULL;
	}

	void displayList() {
		cout << "Depart from: " << departing_location << endl;
		Node* ptr = destination_locations;

		cout << "No. of destination locations: " << no_of_destinations << endl << endl;
		int i = 1;
		while (ptr != NULL) {
			cout << "Destination " << i << ":" << endl;

			ptr->displayNode();
			ptr = ptr->getNext();
			cout << endl;

			i++;
		}
	}
};