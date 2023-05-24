/*
Assignment 8: There are flight paths between cities. If there is a flight between city A and city B then there is an edge between the cities.
The cost of the edge can be the time that flight take to reach city B from A, or the amount of fuel used for the journey. Represent this as a 
graph. The node can be represented by airport name or name of the city. Use adjacency list representation of the graph or use adjacency matrix 
representation of the graph. Check whether the graph is connected or not. Justify the storage representation used.
*/

#include <iostream>
#include <stdexcept>	// for stack pop operation

using namespace std;
#define size 10

class node {
	public:
		float time;
		int fuel;
};
// ======================
class Stack {
	private:
		int top, *arr;
	public:
		Stack() {
			top = -1;
			arr = new int[size];;
		}
		void push(int i) {
			if (full()) {
				cout << "\nStack is full\n";
				return;
			}
			arr[++top] = i;
		}
		inline int getTop() {
			return arr[top];
		}
		void pop() {
			if (empty()) {
				cout << "\nStack is empty\n";
				return;
			}
			top--;
		}
		inline bool full() {
			return (top == size-1);
		}
		inline bool empty() {
			return (top == -1);
		}
		inline int peek() {
			return top;
		}
};
// ======================
class flightGraph {
	int startCity, endCity;
	node *table[5][5];
	const char* cityNames[5] = {"Mumbai", "Nashik", "Pune", "Delhi", "Chennai"};
	
	public:
		flightGraph() {
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {
					table[i][j] = NULL;
				}
			}
		}
		// ==============================================
		void insertFlightPath() {
			cout << "Choose the cities to insert a flight path:\n";
			cout << "(1) Mumbai\n(2) Nashik\n(3) Pune\n(4) Delhi\n(5) Chennai\n";

			cout << "\nEnter Origin City (1-5): ";
			cin >> startCity;
			cout << "Enter Destination City (1-5): ";
			cin >> endCity;

			if (table[startCity-1][endCity-1] == NULL) {
			table[startCity-1][endCity-1] = new(node);
				
				cout << "Enter time taken for flight: ";
				cin >> table[startCity-1][endCity-1]->time;

				cout << "Enter the flight fuel comsumption: ";
				cin >> table[startCity-1][endCity-1]->fuel;

				cout << "\nFlight successfully inserted!\n\"" << cityNames[startCity-1] << "\" to \"" << cityNames[endCity-1] << "\"";
				cout << "\nFlight Time: " << table[startCity-1][endCity-1]->time;
				cout << "\nFuel Comsumption: " << table[startCity-1][endCity-1]->fuel << endl;
			}
			else {
				cout << "\n\nA flight path already exists from -\n\"" << cityNames[startCity-1] << "\" to \"" << cityNames[endCity-1] << "\"\n";
			}
		}
		// ==============================================
		void removeFlightPath() {
			cout << "Enter the flight path you want to remove:\n";
			cout << "(1) Mumbai\n(2) Nashik\n(3) Pune\n(4) Delhi\n(5) Chennai\n";
			cout << "Enter origin city (1-5): ";
			cin >> startCity;
			cout << "Enter destination city (1-5): ";
			cin >> endCity;

			if (table[startCity-1][endCity-1] != NULL) {
				
				table[startCity-1][endCity-1]->fuel = 0;
				table[startCity-1][endCity-1]->time = 0.0;
				table[startCity-1][endCity-1] = NULL;
			}
			else {
				cout << "\nNo flight path exists from " <<cityNames[startCity-1] << " to " << cityNames[endCity-1] << "\n\n";
			}
		}
		// ==============================================
		void connectedFlight() {
			cout << "Choose cities:\n";
			cout << "(1) Mumbai\n(2) Nashik\n(3) Pune\n(4) Delhi\n(5) Chennai\n";
			// int startCity, endCity;
			cout << "Enter Start City (1-5): ";
			cin >> startCity;
			cout << "Enter End City (1-5): ";
			cin >> endCity;

			if (table[startCity-1][endCity-1] != NULL) {	// checks for direct flight path

				cout << "Direct Flight exists from \"" << cityNames[startCity-1] << "\" to \"" << cityNames[endCity-1] << "\"" << endl;
				cout << "Time taken: " << table[startCity-1][endCity-1]->time;
				cout << "\nFuel Consumption: " << table[startCity-1][endCity-1]->fuel;
				return;
			}
			Stack s;
			bool visited[5] = {false};
			// Push nodes with destination city matching user input endCity in the stack
			for (int i = 0; i < 5; i++) {
				if (table[i][endCity-1] != NULL) {
					s.push(endCity-1);	// pushing the destination city
					s.push(i);	// pushing city which has a flight path to the endCity
				}
			}
			// =================loops until startCity is found OR until the stack is empty=================
			while (!s.empty()) {
				int currCity;

				int index = s.getTop();
				if (index != startCity-1) {
					currCity = s.getTop();
					s.pop();
				}
				visited[currCity] = true;

				if (index == startCity-1) {	// when finally the start city is found & pushed into the stack, the loop breaks
					break; 
				}
				// Check for nodes whose destination city matches the start city of the last pushed node
				for (int i = 0; i < 5; i++) {
					if (table[i][currCity] != NULL && !visited[i]) {
						s.push(currCity);
						s.push(i);
					}
				}
			}
			// =====While loop ends=====

			// No connected flight path found
			if (s.empty()) {
				cout << "No connected flight path exists from \"" << cityNames[startCity-1] << "\" to \"" << cityNames[endCity-1] << "\"" << endl;
				return;
			}

			// Pop the nodes from the stack & display their city names
			cout << "The connected flight paths/layovers are as follows:\n\n";
			while (!s.empty()) {
				cout << cityNames[s.getTop()];
				s.pop();
				if (s.peek() != -1) {
					cout << " -> ";
				}
			}
			cout << endl;
		}
};
// ==============================
int main(int argc, char const *argv[]) {
	flightGraph fg1;
	int ch;
	char opt;
	do {
		cout << "(1) Insert Flight Path\n";
		cout << "(2) Remove Flight Path\n";
		cout << "(3) Search Flight Path\n";
		cout << "\nEnter choice: ";
		cin >> ch;
		switch(ch) {
			case 1:
				fg1.insertFlightPath();
				break;
			
			case 2:
				fg1.removeFlightPath();
				break;
			
			case 3:
				fg1.connectedFlight();
				break;

			default:
				cout << "\nInvalid Choice!";
				break;
		}
		cout << "\nContinue? (Y/N): ";
		cin >> opt;
		cout << "\n---------------------------\n";
	} while (opt == 'y' || opt == 'Y');
	return 0;
}