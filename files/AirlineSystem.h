#pragma once

#include"AdjList.h"
#include<stack>
#include<list>
#include<iterator>



class AirlineSystem {

public:
	void userInput(string source, string dest, Adjlist graph) {
		int size = graph.getNumDeparts();
		int** all_paths;

		bool* visited = new bool[size];
		all_paths = new int*[size];

		for (int i = 0; i < size; i++) {
			all_paths[i] = new int[size];
			visited[i] = false;

			for (int j = 0; j < size; j++) {
				all_paths[i][j] = -1;
			}
		}

		
		Node* ptr = graph.getDeparturesFor(source);
		stack<Node*> st;
//		stack<bool*> visit_stack;

		string str = "" + graph.departLocExist(ptr->getLocationName());
		
		st.push(ptr);

		all_paths[0][graph.departLocExist(ptr->getLocationName())] = 1;
		int i = 0, j=2;

		while (!st.empty()) {
			
			ptr = graph.getDeparturesFor(st.top()->getLocationName());
			if (ptr->getLocationName() == dest) {
				printStack(st);
			}
//			bool* visited = new bool[size];
//			visit_stack.push(visited);

			ptr->displayNode();
			if (ptr != NULL) {
				while (ptr != NULL) {//visited[graph.departLocExist(ptr->getLocationName())]
					if (!visited[graph.departLocExist(ptr->getLocationName())]) {
						st.push(ptr);
						cout << "Push: " << ptr->getLocationName() << endl;
//						all_paths[i][graph.departLocExist(ptr->getLocationName())] = j;
//						j++;
						break;
					}
					ptr = ptr->getNext();
				}

				if (ptr == NULL) {
					cout << "pop: " << st.top()->getLocationName() << endl;
					visited[graph.departLocExist(st.top()->getLocationName())] = true;
					st.pop();
					//i--;
				}
			}
			else {
				cout << "pop: " << st.top()->getLocationName() << endl;
				visited[graph.departLocExist(st.top()->getLocationName())] = true;
				st.pop();
			}
		}
	}

	void printStack(stack<Node*> st) {
		list<Node*> ls;
		int size = 0;
		list<Node*>::iterator it;

		while (!st.empty()) {
			ls.push_front(st.top());
			st.pop();
			size++;
		}



		for (it = ls.begin(); it != ls.end();it++) {
			cout << *it << " ";
		}
		cout <<endl;
	}

	void operator <<(Node* &item)
	{
		item->displayNode();
	}
};