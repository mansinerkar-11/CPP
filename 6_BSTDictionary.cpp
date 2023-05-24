/*
Assignment 6:
A dictionary stores keywords and its meanings. Provide facility for adding new keywords, deleting keywords,
updating values of any entry. Provide a facility to display whole data sorted in ascending/descending order. Also, find
how many maximum comparisons may require for finding any keyword. Use Binary Search Tree for implementation.
*/
#include <iostream>
using namespace std;

class node {
	public:
		string key;
		string meaning;
		node *left;
		node *right;
};
class tree {
	node *newnode, *temp, *q;
	string newMeaning;
	public:
		node *root;
		tree() {
			root = NULL;
		}
		// ======================================
		void insertKey(string s, string m) {
			// A Do-While Loop can be used to repetitively insert keys
			newnode = new(node);
			newnode->key = s;
			newnode->meaning = m;
			newnode->left = NULL;
			newnode->right= NULL;

			q = root;

			if (root == NULL) {
				root = newnode;
				return;
			}

			while (q != NULL) {
				if (q->key > s) {
					if (q->left == NULL) {
						q->left = newnode;
						break;
					}
					else {
						q = q->left;
					}
				}
				else if (q->key < s) {
					if (q->right == NULL) {
						q->right = newnode;
						break;
					}
					else {
						q = q->right;
					}
				}
				else {
					cout << "\nData already present!\n";
					break;
				}
			}
		}
		// ======================================
		string searchKey (string s) {
			if (root == NULL) {
				cout << "\n";
				return "Tree does not exist!";
			}
			q = root;
			while (q != NULL) {
				if (q->key > s) {
					q = q->left;
				}
				else if (q->key < s) {
					q = q->right;
				}
				else {
					return q->meaning;
				}
			}
			cout << "Not found!\n";
			return "";
		}
		// ======================================
		void updateMeaning(string s) {
			if (root == NULL) {
				cout << "\nTree does not exist!\n";
				return;
			}
			q = root;
			while (q != NULL) {
				if (q->key > s) {
					q = q->left;
				}
				else if (q->key < s) {
					q = q->right;
				}
				else {
					cout << "Old Meaning: " << q->meaning << "\n\n";
					cout << "Enter the new meaning: ";
					getline(cin, newMeaning);
					q->meaning = newMeaning;
					cout << "Meaning changed successfully!\n";
					break;
				}
			}
		}
		// ======================================
		node* inOrderSuccessor(node *root) {
			q = root;
			while (q->left != NULL) {
				q = q->left;
			}
			return q;
		}
		// ======================================
		node* deleteKey(node *root, string s) {
			/*
			3 cases:
			(1) Deletion of a node with no child
			(2) Deletion of a node with 1 child
			(3) Deletion of a node with 2 children
			*/
			if (root == NULL) {
				return root;
			}
			// If key is smaller than the root node, search in the left subtree
			if (s < root->key) {
				root->left = deleteKey(root->left, s);
			}
			// If key is greater than the root node, search in the right subtree
			else if (s > root->key) {
				root->right = deleteKey(root->right, s);
			}
			// When the key is found, delete the node
			else {
				// Case 1: Leaf Node
				if (root->left == NULL && root->right == NULL) {
					delete(root);
					root = NULL;
				}
				// Case (2.a): Node with a right child
				else if (root->left == NULL) {
					node *temp = root;
					root = root->right;
					delete(root);
				}
				// Case (2.b): Node with a left child
				else if (root->right == NULL) {
					node *temp = root;
					root = root->left;
					delete(root);
				}
				// Case 3: Node with both left & right children nodes
				else {
					node *temp = inOrderSuccessor(root->right);
					root->key = temp->key;
					root->right = deleteKey(root->right, temp->key);
				}
			}
			return root;
		}
		// ======================================
		void ascendingTraversal(node *root) {
			if (root == NULL) {
				return;
			}
			ascendingTraversal(root->left);
			cout << root->key << "\t:\t" << root->meaning << endl;
			ascendingTraversal(root->right);
		}
		// ======================================
		void descendingTraversal(node *root) {
			if (root == NULL) {
				return;
			}
			cout << "Word\t:\tMeaning\n\n";
			descendingTraversal(root->right);
			cout << root->key << "\t:\t" << root->meaning << endl;
			descendingTraversal(root->left);
		}
};
// ==============================================
int main(int argc, char const *argv[]) {
	int ch;
	char opt;
	node *returnNode;
	string key, meaning;
	tree t1;
	do {
		cout << "(1) Insert Key & Meaning\n";
		cout << "(2) Update Key & Meaning\n";
		cout << "(3) Search Key\n";
		cout << "(4) Delete Key\n";
		cout << "(5) Display Dictionary (Ascending)\n";
		cout << "(6) Display Dictionary (Descending)\n";
		cout << "\nEnter choice: ";
		cin >> ch;
		cin.ignore();

		switch(ch) {
			case 1:
				cout << "Enter key: ";
				getline(cin, key);
				cout << "Enter meaning: ";
				getline(cin, meaning);
				t1.insertKey(key, meaning);
				break;
			
			case 2:
				cout << "Enter key whose meaning is to be updated: ";
				getline(cin, key);
				t1.updateMeaning(key);
				break;

			case 3:
				cout << "Enter key to search: ";
				getline(cin, key);
				meaning = t1.searchKey(key);
				cout << "\nWord: " << key << "\nMeaning: " << meaning << endl;
				break;

			case 4:
				cout << "Enter the key to be deleted: ";
				getline(cin, key);
				returnNode = t1.deleteKey(t1.root, key);
				cout << "Keyword " << returnNode->key << " deleted!\n";
				break;
			
			case 5:
				cout << "Word\t:\tMeaning\n\n";
				t1.ascendingTraversal(t1.root);
				break;
			
			case 6:
				t1.descendingTraversal(t1.root);
				break;
			
			default:
				cout << "\nInvalid choice!\n";
				break;
		}
		cout << "\nContinue? (Y/N): ";
		cin >> opt;
		cout << "\n--------------------\n";
	}
	while (opt == 'y' || opt == 'Y');
	return 0;
}