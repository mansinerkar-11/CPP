#include <iostream>
using namespace std;
#define size 20

class Stack {
	int top;
	int arr[size];
	public:
		Stack() {
			top = -1;
		}
		inline bool full() {
			return (top == size-1);
		}
		// ====================
		inline bool empty() {
			return (top == -1);
		}
		// ====================
		void push(int s) {
			if (full()) {
				//cout << "Stack is full!\n";
				return;
			}
			arr[++top] = s;
		}
		// ====================
		void pop() {
			if (empty()) {
				//cout << "Stack is empty!\n";
				return;
			}
			top--;
		}
		// ====================
		/*void displayStack() {
			while (!empty()) {
				cout << getTop() << "\n";
				pop();
			}
		}*/
		// ====================	
		inline int getTop() {
			return arr[top];
		}
};
// ============================
class Queue {
	int front, rear;
	int queue[size];
	string blocks[5] = {"Entrance", "Block A", "Block B", "Block D", "Block E"};
	public:
		Queue() {
			front = rear = -1;
		}
		// ====================
		inline bool full() {
			return (rear == size-1);
		}
		// ====================
		inline bool empty() {
			return (front == -1 || front > rear);
		}
		// ====================
		void enqueue(int s) {
			if (full()) {
				// cout << "Queue is full!";
				return;
			}
			if (front == -1) {
				front = rear = 0;
				queue[rear] = s;
				return;
			}
			queue[++rear] = s;
		}
		// ====================
		void dequeue() {
			if (empty()) {
				// cout << "Queue is empty!\n";
				return;
			}
			front++;
		}
		// ====================
		void displayQueue() {
			for (int i = front; i <= rear; i++) {
				cout << blocks[queue[i]] << " ";
			}
		}
		// ====================
		int getFront() {
			return queue[front];
		}
};
// ===================================
class Graph {
	public:
	string blockNames[5] = {"Entrance", "Block A", "Block B", "Block D", "Block E"};
	int graph[5][5], startBlock, endBlock;
	bool visited[5];
	
		Graph() {
			for (int i = 0; i < 5; i++) {
				// visited[i] = false;
				for (int j = 0; j < 5; j++) {
					graph[i][j] = 0;
				}
			}
		}
		// ===========================
		void insertPath() {
			cout << "(1) Entrance\n(2) Block A\n(3) Block B\n(4) Block D\n(5) Block E\n\n";
			cout << "Enter start block (1-5): ";
			cin >> startBlock;
			cout << "Enter end block (1-5): ";
			cin >> endBlock;
			if (graph[startBlock-1][endBlock-1] == 1) {
				cout << "A path already exists from " << blockNames[startBlock-1] << " to " << blockNames[endBlock-1] << "\n\n";
				return;
			}
			graph[startBlock-1][endBlock-1] = 1;
			// graph[endBlock-1][startBlock-1] = 1;
			cout << "Path successfully inserted from " << blockNames[startBlock-1] << " to " << blockNames[endBlock-1] << endl;
		}
		// ===========================
		void removePath() {
			cout << "(1) Entrance\n(2) Block A\n (3) Block B\n(4) Block D\n(5) Block E\n\n";
			cout << "Enter start block (1-5): ";
			cin >> startBlock;
			cout << "Enter end block (1-5): ";
			cin >> endBlock;
			if (graph[startBlock-1][endBlock-1] == 0) {
				cout << "No path exists from " << blockNames[startBlock-1] << " to " << blockNames[endBlock-1] << endl;
				return;
			} 
			graph[startBlock-1][endBlock-1] = 0;
			// graph[endBlock-1][startBlock-1] = 0;
			cout << "Path " << blockNames[startBlock-1] << " to " << blockNames[endBlock-1] << " removed!\n";
 		}
		// ===========================
		void searchPath() {
			cout << "(1) Entrance\n(2) Block A\n (3) Block B\n(4) Block D\n(5) Block E\n\n";
			cout << "Enter start block (1-5): ";
			cin >> startBlock;
			cout << "Enter end block (1-5): ";
			cin >> endBlock;
			if (graph[startBlock-1][endBlock-1] == 0) {
				cout << "No path present!\n";
			}
			else {
				cout << "Path present from " << blockNames[startBlock-1] << " to " << blockNames[endBlock-1] << endl;
			}
		}
		// ===========================
		void depthFirstSearch(int j) {
			Stack s;
			
			for (int i = 0; i < 5; i++) {
				visited[i] = false;
			}
			s.push(j);
			visited[j] = true;

			while (!s.empty()) {
				int v = s.getTop();
				s.pop();
				cout << blockNames[v] << " ";
				for (int i = 0; i < 5; i++) {
					if (graph[v][i] == 1 && !visited[i]) {
						s.push(i);
						visited[i] = true;
					}
				}
			}
			cout << endl;
		}
		// ===========================
		void breadthFirstSearch(int j) {
			Queue q;
			for (int i = 0; i < 5; i++) {
				visited[i] = false;
			}
			
			// q.displayQueue();
			
			visited[j] = true;
			q.enqueue(j);
			cout << "Breadth-first Search:\n\n";
			cout << blockNames[j] << " ";
			while (!q.empty()) {
				int v = q.getFront();
				q.dequeue();
				cout << blockNames[v] << " ";

				for (int i = 0; i < 5; i++) {
					if (graph[v][i] == 1 && !visited[i]) {
						q.enqueue(i);
						visited[i] = true;
					}
				}
				// cout << "\nQueue Contents: ";
				// q.displayQueue();
				// cout << endl;
			}
			cout << endl;
		}
};
// ===================================
int main(int argc, char const *argv[])
{
	Graph g;
	int ch, vertex;
	// char opt;
	do {
		cout << "(1) Insert Path\n";
		cout << "(2) Remove Path\n";
		cout << "(3) Search Path\n";
		cout << "(4) Depth-first Search\n";
		cout << "(5) Breadth-first Search\n";
		cout << "(6) Exit\n\n";
		cout << "Enter choice: ";
		cin >> ch;

		switch (ch) {
			case 1:
				g.insertPath();
				break;
			
			case 2:
				g.removePath();
				break;
			
			case 3:
				g.searchPath();
				break;
			
			case 4:
				cout << "(1) Entrance\n(2) Block A\n(3) Block B\n(4) Block D\n(5) Block E\n\n";
				cout << "Enter the vertex from which you want to start: ";
				cin >> vertex;
				g.depthFirstSearch(vertex-1);
				break;
			
			case 5:
				cout << "(1) Entrance\n(2) Block A\n(3) Block B\n(4) Block D\n(5) Block E\n\n";
				cout << "Enter the vertex from which you want to start: ";
				cin >> vertex;
				g.breadthFirstSearch(vertex-1);
				break;
			
			case 6:
				cout << "\nExiting...\n";
				break;
			
			default:
				cout << "\nInvalid Choice\n";
				break;
		}
	} while (ch != 6);
	return 0;
}