#include <iostream>
#include <stack>
using namespace std;

class node {
	public:
		char data;
		node *left, *right;
};
class ExpressionTree {
	public:
		bool isOperator(char c) {
			return c == '+' || c == '-' || c == '*' || c == '/';
		}
		// ======================================
		node *constructTree(string s) {
			stack <node*> s1;
			for (int i = s.length() - 1; i >= 0; i--) {
				char c = s[i];
				if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) {	// alpha-numeric
				// If the character is an operand, create a node and push it to the stack
					node *newnode = new(node);
					newnode->data = c;
					newnode->left = NULL;
					newnode->right = NULL;
					s1.push(newnode);
				}
				// ==============================
				else if (isOperator(c)) {
					// If the character is an operator, pop two nodes from stack and create a new node
					node *newnode = new(node);
					newnode->data = c;
					newnode->left = s1.top();
					s1.pop();
					newnode->right = s1.top();
					s1.pop();
					s1.push(newnode);
				}
			}
			return s1.top();
		}
		// ======================================
		node *constructTreeNoOperator(string s) {
			stack <node*> s1;
			for (int i = 0; i < s.length(); i++) {
				char c = s[i];
				node *newnode = new(node);
				newnode->data = c;
				if (s1.empty()) {
					newnode->left = NULL;
					newnode->right = NULL;
					s1.push(newnode);
				}
				else {
					newnode->left = s1.top();
					newnode->right = NULL;
					s1.push(newnode);
				}
			}
			return s1.top();
		}
		/*
		void prefixEvaluate(string s) {

		}*/
		// ======================================
		void postOrderTraversal(node *root) {
			if (root == NULL) {
				return;
			}
			stack <node*> s1, s2;
			s1.push(root);

			while (!s1.empty()) {
				node *q = s1.top();
				s1.pop();
				s2.push(q);
				cout << "q = " << q->data << endl;
				// Push the left child first
				if (q->left != NULL) {
					s1.push(q->left);
					cout << "q->left = " << q->left << endl;
				}
				// Push the right child next
				if (q->right != NULL) {
					s1.push(q->right);
					cout << "q->right = " << q->right << endl;
				}
			}
			cout << "Postfix Expression: ";
			while (!s2.empty()) {
				cout << s2.top()->data;
				s2.pop();
			}
		}
		// ======================================
		void deleteExpressionTree(node *root) {
			if (root != NULL) {
				deleteExpressionTree(root->left);
				deleteExpressionTree(root->right);
				delete(root);
			}
		}
		// ======================================
};
int main(int argc, char const *argv[])
{
	int ch, flag = 0;
	char opt;
	string s;
	ExpressionTree t;
	node *root;

	do {
		cout << "(1) Enter Expression\n";
		cout << "(2) Post-Order Traversal\n";
		cout << "(3) Evaluate Prefix Expression\n";	// make a different construction expression (maybe) and also an evaluate function
		cout << "\n\nEnter prefix expression: ";
		getline(cin, s);
		for (int i = 0; i < s.length(); i++) {
			if (!((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))) {
				flag = 1;	// flag = 1 indicates that an operator is present in the expression
				break;
			}
		}
		if (flag == 1) {
			root = t.constructTree(s);
		}
		else {
			root = t.constructTreeNoOperator(s);
		}
		// cout << "Root->Data = " << root->data << endl;
		t.postOrderTraversal(root);
		cout << endl;
		t.deleteExpressionTree(root);
		cout << "\nContinue? (Y/N): ";
		cin >> opt;
		cin.ignore();
	}
	while (opt == 'y' || opt == 'Y');
	return 0;
}