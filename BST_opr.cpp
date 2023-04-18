/*Practical 04

Problem statement :
Beginning with an empty binary search tree, Construct binary search tree by inserting
the values in the order given. After constructing a binary tree -
i. Insert new node
ii. Find number of nodes in longest path from root
iii. Minimum data
value found in the tree
iv. Change a tree so that the roles of the left and right pointers are swapped at every node
v. Search a value
*/
#include<iostream>
#include<vector>
using namespace std;

struct node {
	int data;
	node* left;
	node* right;
};
class BinaryTree {
public:
	node* root;
	BinaryTree() {
		root=NULL;
	}
	void create(int);
	void inorder(node*);
	void minimum();
	void search(int);
	int max_depth(node*);
	void swapTree(node*);
};
void BinaryTree::create(int value) {
	node* curr = new node;
	curr->data = value;
	curr->left = NULL;
	curr->right = NULL;
	node* temp;
		if(root==NULL) {
			root = curr;
		}
		else {
		temp = root;
		while(1) {
			if(curr->data < temp->data) {
				if(temp->left == NULL) {
					temp->left = curr;
					break;
				}
				else
					temp = temp->left;

			}
			else {
				if(temp->right == NULL) {
					temp->right = curr;
					break;
				}
				else
					temp = temp->right;
			}
		}
	}
}
void BinaryTree::inorder(node* root) {

	if(root!=NULL) {
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}

}
void BinaryTree::search(int key) {
	node*temp = root;
	while(temp!=NULL) {
		if(temp->data == key) {
			cout<<endl<<key<<" found!";
			return;
		}
		else {
			if(key<temp->data)
				temp = temp->left;
			else
				temp = temp->right;
			}
	}
	cout<<endl<<key<<" not found!";
}
void BinaryTree::minimum() {
	node* temp = root;
	while(temp->left!=NULL)
		temp = temp->left;
	cout<<"Minimum Value = "<<temp->data;
}
int BinaryTree::max_depth(node* root) {
	if(root == NULL) return 0;
	int leftDepth = max_depth(root->left);
	int rightDepth = max_depth(root->right);
	return max(leftDepth,rightDepth)+1;
}
void swapTree(node* root)  {			//or I should say mirroring

if(root==NULL) return;
swapTree(root->left);
swapTree(root->right);
node* temp= root->right;
root->right = root->left;
root->left = temp;
}
int main()
{
	BinaryTree BST;
	int choice,value;
	do {
		cout<<"\n----------Binary Tree----------"
			<<"\n1.Insert Nodes"	//done
			<<"\n2.Display(Inorder)"	//done
			<<"\n3.Find Number of nodes in longest path from root"	//done
			<<"\n4.Minimum Value in Binary Search Tree "	//done
			<<"\n5.Swap Binary Search Tree "		//done
			<<"\n6.Search a Value "	//done
			<<"\n7.Exit"
			<<"\nEnter Choice : ";
		cin>>choice;
		switch(choice) {
			case 1: cout<<"\nEnter Value : ";
					cin>>value;
					BST.create(value);
					break;
			case 2: cout<<"\nInorder : ";
					BST.inorder(BST.root);
					break;
			case 3:
					cout<<"\nNumber of Nodes in longest path = "<<BST.max_depth(BST.root);
					break;
			case 4: BST.minimum();
					break;
			case 5:
					swapTree(BST.root);
					break;
			case 6: cout<<"\nEnter value to be searched : ";
					cin>>value;
					BST.search(value);
					break;
			case 7:
					break;
			default:
				cout<<"\nInvalid Choice";
		}
	}while(choice!=7);
	return 0;
}
