/*
Asg 4: Binary Search Tree

	1) Insert a new node
	2) Find the no. of nodes from root to leaf node
	3) Minimum data value found in tree
	4) Change a tree so that the left & right pointers are swapped at every node (Mirror the tree)
	5) Search a value
*/

#include <iostream>
using namespace std;
bool flag = 0;

class node {
	public:
		int data;
		node *left;
		node *right;
};
// ====================================
class bst {
	public:
		node *newnode, *q, *temp;
		node *root;
		int leftCount, rightCount;
		bst() {
			root = NULL;
		    leftCount = 0;
		    rightCount = 0;
		}
		// ============================
		void insertData(int x) {
			newnode = new(node);
			newnode->data = x;
			newnode->left = NULL;
			newnode->right = NULL;
			q = root;
			
			if (root == NULL) {
				root = newnode;
				return;
			}
			while (q != NULL) {
				if (q->data > x) {
					if (q->left == NULL) {
						q->left = newnode;
						break;
					}
					else {
						q = q->left;
					}
				}
				// -----------------------
				else if (q->data < x) {
					if (q->right == NULL) {
						q->right = newnode;
						break;
					}
					else {
						q = q->right;
					}
				}
				// -----------------------
				else {
					cout << "\nData already present\n";
					break;
				}
			}
		}
		// ============================
		void searchData(int x) {
			q = root;
			int searchCount = 0;
			if (root == NULL) {
				cout << "Tree does not exist\n";
				return;
			}
			while (q != NULL) {
				if (q->data > x) {
					q = q->left;
					searchCount += 1;
				}
				else if (q->data < x) {
					q = q->right;
					searchCount += 1;
				}
				else {
					cout << "\nData found!\n";
					searchCount += 1;
					cout << "\nNo. of comparisons = " << searchCount << endl;
					return;
				}
			}
			cout << "\nData not found!\n";
		}
		// ============================
		int heightOfTree(node *root) {
			if (root == NULL) {
				return 0;
			}
			else {
				int leftCount = heightOfTree(root->left);
				int rightCount = heightOfTree(root->right);
				if (leftCount > rightCount) {
				    return leftCount + 1;
				}
				else {
				    return rightCount + 1;
				}
			}
		}
		// ============================
		void mirrorTree(node *root) {
			// q = root;
			if (root != NULL) {
				temp = root->left;
				root->left = root->right;
				root->right = temp;

				mirrorTree(root->left);
				mirrorTree(root->right);
			}
		}
		// ============================
		int minElementOfTree() {
			q = root;
			while (q->left != NULL) {
				q = q->left;
			}
			return q->data;
		}
		// ============================
		int maxElementOftree() {
			q = root;
			while (q->right != NULL) {
				q = q->right;
			}
			return q->data;
		}
		// ============================
		void inOrderTraversal(node *root) {
			if (root != NULL) {
				inOrderTraversal(root->left);
				cout << root->data << " ";
				inOrderTraversal(root->right);
			}
		}
};
// ====================================
int main() {
	bst t1;
	int ch, data;
	char opt;
	
	do {
		cout << "(1) Insert a new node\n";
		cout << "(2) Find the height of the tree\n";
		cout << "(3) Minimum & maximum data found in the tree\n";
		cout << "(4) Swap left & right data of a node (Mirror the tree)\n";
		cout << "(5) Search a value\n";
		cout << "(6) Display Data\n";
		cout << "\nEnter choice: ";
		cin >> ch;
		
		switch (ch) {
			case 1:
				cout << "Enter data to be inserted: ";
				cin >> data;
				t1.insertData(data);
				break;
				
			case 2:
				data = t1.heightOfTree(t1.root);
				cout << "Height of the tree = " << data - 1 << endl;
				break;

			case 3:
				if (flag == 0) {
					cout << "Minimum element in the tree = " << t1.minElementOfTree();
					cout << "\nMaximum element of the tree = " << t1.maxElementOftree() << endl;
				}
				else if (flag == 1) {
					cout << "Maximum element in the tree = " << t1.minElementOfTree();
					cout << "\nMinimum element of the tree = " << t1.maxElementOftree() << endl;
				}
				break;

			case 4:
				if (flag == 0) {
					cout << "Tree is now mirrored!\n";
					flag = 1;
				}
				else {
					cout << "Tree is now back to its original form!\n";
					flag = 0;
				}
				t1.mirrorTree(t1.root);
				break;
			
			case 5:
				cout << "Enter the data to be searched: ";
				cin >> data;
				t1.searchData(data);
				break;
			
			case 6:
				cout << "\nIn-order Traversal:\n";
				t1.inOrderTraversal(t1.root);
				cout << endl;
				break;
			
			default:
				cout << "Invalid Choice!\n";
				break;
		}
		cout << "Continue? (Y/N): ";
		cin >> opt;
		cout << "\n=====================\n";
	} while (opt == 'y' || opt == 'Y');
	return 0;
}