/*Practical 06
Problem statement :

A Dictionary stores keywords and its meanings. Provide facility for adding new keywords, deleting keywords, updating values of any entry. Provide a facility to display whole word sorted in ascending/ Descending order. Also find how many maximum comparisons may require for finding any keyword. Use Binary Search Tree for
Implementation.


*/


#include<iostream>
#include<stack>
using namespace std;

struct tree_node{

    string word,meaning;
    tree_node*left_child;
    tree_node*right_child;

    tree_node(){
        word = "";
        meaning = "";
        left_child = NULL;
        right_child = NULL;
    }
};

class Binary_search_tree{
    tree_node*root_node;
    public:
        int noOfComparisons;
        Binary_search_tree(){
            root_node = NULL;
            noOfComparisons = 0;
        }
        void insert(string,string);
        int search_val(string);
        void ascending_order_display(tree_node*);
        void descending_order_display(tree_node*);
        tree_node* updateMeaning(string);
        tree_node* initialize_to_root_node();
        tree_node* deleteWord(string,tree_node*);
};

void Binary_search_tree::insert(string word,string meaning){
    tree_node*temp;
    tree_node*current;
    if (root_node == NULL){
        root_node = new tree_node;
        this->root_node->word = word;
        this->root_node->meaning = meaning;
        return;
    }

    temp = new tree_node;
    this->root_node->word = word;
    this->root_node->meaning = meaning;
    current = root_node;
    int i=0;

    while(true){
        if(temp->word[i] < current->word[i]){
            if(current->left_child != NULL){
                current = current->left_child;
            }
            else{
                current->left_child = temp;
                return;
            }
        }
        else if(temp->word[i] > current->word[i]){
            if(current->right_child != NULL){
                current = current->right_child;
            }
            else{
                current->right_child = temp;
                return;
            }
        }
        else{
            i++;
        }
    }
};

int Binary_search_tree::search_val(string word){
    if (root_node == NULL){
        return -1;
    }

    tree_node*current;
    current = root_node;
    int i=0;

    while(true){
        if(current->word == word){
            noOfComparisons++;
            return 1;
        }

        else if(word[i] < current->word[i]){
            if(current->left_child != NULL){
                current = current->left_child;
                noOfComparisons++;
            }
            else{
                noOfComparisons++;
                return 0;
            }
        }
        else if(word[i] > current->word[i]){
            if(current->right_child != NULL){
                current = current->right_child;
                noOfComparisons++;
            }
            else{
                noOfComparisons++;
                return 0;
            }
        }
        else{
            i++;
        }
    }
    cout<<"\nWord not found in the Dictionary!\n";
};

tree_node* Binary_search_tree::updateMeaning(string word){
    if (root_node == NULL){
        cout<<"\nBst is empty!\n";
        return root_node;
    }

    tree_node*current;
    current = root_node;
    int i=0;

    while(true){
        if(current->word == word){
            noOfComparisons++;
            return current;
        }

        else if(word[i] < current->word[i]){
            if(current->left_child != NULL){
                current = current->left_child;
                noOfComparisons++;
            }
            else{
                noOfComparisons++;
                return current;
            }
        }
        else if(word[i] > current->word[i]){
            if(current->right_child != NULL){
                current = current->right_child;
                noOfComparisons++;
            }
            else{
                noOfComparisons++;
                return current;
            }
        }
        else{
            i++;
        }
    }
    cout<<"\nWord not found in the Dictionary!\n";
};
void Binary_search_tree::ascending_order_display(tree_node*temp){

    stack<tree_node*>s;
    while(temp != NULL || s.empty() == false){
        while(temp != NULL){
            s.push(temp);
            temp = temp->left_child;
        }

        temp = s.top();
        s.pop();
        cout<<temp->word<<" == "<<temp->meaning<<endl;
        temp = temp->right_child;
    }
};

void Binary_search_tree::descending_order_display(tree_node*temp){

    stack<tree_node*>s;
    while(temp != NULL || s.empty() == false){
        while(temp != NULL){
            s.push(temp);
            temp = temp->right_child;
        }

        temp = s.top();
        s.pop();
        cout<<temp->word<<" == "<<temp->meaning<<endl;
        temp = temp->left_child;
    }
};

tree_node* Binary_search_tree::deleteWord(string s,tree_node* temp){
	if (temp == NULL){
		return temp;
	}
	else if(s >temp->word){
		temp->right_child = deleteWord(s,temp->right_child);
	}
	else if (s<temp->word){
		temp->left_child = deleteWord(s,temp->left_child);
	}

	else{
		if(temp->left_child == NULL && temp->right_child == NULL){
			delete temp;
			return temp;
		}
		else if (temp->left_child == NULL){
			tree_node* curr = temp->right_child;
			delete temp;
			return curr;
		}
		else if (temp->right_child == NULL){
			tree_node* curr = temp->left_child;
			delete temp;
			return curr;
		}

		else{
			tree_node*curr = temp->right_child;

			while(curr->left_child!=NULL){
				curr = curr->left_child;
			}

			temp -> word = curr->word;
			temp->meaning = curr->meaning;

			temp->right_child = deleteWord(curr->word,curr->right_child);
		}
	}
	return temp;
}
tree_node* Binary_search_tree::initialize_to_root_node(){
    if(root_node == NULL){
        cout<<"\nBST is empty\n";
    }
    else{
        return root_node;
    }
};

int main(){
    int choice,returnVal;
    string inputWord,inputMeaning;
    Binary_search_tree BST;
    tree_node*temp;
    do{
        cout<<"\n*******Binary Search Tree Operations*******";
        cout<<"\n1) Insert new word and it's meaning";
        cout<<"\n2) Search a word or it's meaning in the dictionary";
        cout<<"\n3) Ascending order display";
        cout<<"\n4) Descending order display";
        cout<<"\n5) Update Meaning of the word";
        cout<<"\n6) Delete word and meaning in dictionary";
        cout<<"\n7) Exit!";
        cout<<"\nEnter your choice:\n";
        cin>>choice;

        switch(choice){
            case 1:
                cout<<"\nEnter word to be inserted : \n";
                cin.ignore();
                getline(cin,inputWord);
                cout<<"\nEnter meaning of the word : \n";
                getline(cin,inputMeaning);
                BST.insert(inputWord,inputMeaning);
                cout<<"\nNode inserted successfully in Binary Search tree !\n";
                break;

            case 2:
                cout<<"\nEnter word to be searched : \n";
                cin.ignore();
                cin>>inputWord;
                returnVal = BST.search_val(inputWord);
                if(returnVal == 1){
                    cout<<"\nFound !";
                    cout<<"\nNumber of comparisons required == "<<BST.noOfComparisons;
                }
                else if(returnVal == 0){
                    cout<<"\nNot found !";
                    cout<<"\nNumber of comparisons required == "<<BST.noOfComparisons;
                }
                else{
                    cout<<"\nBinary search tree is empty!!";
                }
                break;

            case 3:
                temp = BST.initialize_to_root_node();
                cout<<"\nAscending order display :\n";
                BST.ascending_order_display(temp);
                break;

            case 4:
                temp = BST.initialize_to_root_node();
                cout<<"\nDescending order display :\n";
                BST.descending_order_display(temp);
                break;
                break;
            case 5:
                cout<<"\nEnter the word you want to update :\n";
                cin.ignore();
                getline(cin,inputWord);
                temp = BST.updateMeaning(inputWord);
                cout<<"\nEnter the Updated meaning of the word :\n";
                getline(cin,inputMeaning);
                temp->meaning = inputMeaning;
                break;
            case 6:
            	cout<<"\nEnter the word to be deleted : \n";
            	cin.ignore();
            	getline(cin,inputWord);
            	temp = BST.initialize_to_root_node();
            	temp = BST.deleteWord(inputWord,temp);
            	if(temp == NULL){
            		cout<<"\nWord successfully deleted from dictionary!\n";
            	}
            	break;
            case 7:
                cout<<"\nExiting Program.....\n";
                break;
            default:
                cout<<"\nEnter a valid choice!";
                break;
        }
    }while(choice!=6);
    return 0;
}
