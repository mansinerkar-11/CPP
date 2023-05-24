// Chaining


#include <iostream>
#include <string>
#include <limits>
using namespace std;


class node {
    public:
    string key, meaning;
    node *next;
};
class dictionary {
    node **arr; // always make a double pointer for an array of pointers or just assigning some pointer to some other variable
    node *newnode, *q, *temp;
    int size, count, i;
    public:
        dictionary(int s) {
            size = s;
            arr = new node*[size];
            for (int i = 0; i < size; i++) {
                arr[i] = new(node);
                arr[i]->next = NULL;
            }
        }
        // =======================================
        void insertData(string s, string m) {
            int ascii = arrayToInt(s);
            // For finding duplicates
            q = arr[ascii]->next;
            while (q != NULL) {
                if (q->key == s) {
                    cout << "Key already present!\n";
                    return;
                }
                q = q->next;
            }
            if (arr[ascii]->next == NULL) { // the list at the index is empty
                newnode = new(node);
                newnode->key = s;
                newnode->meaning = m;
                newnode->next = NULL;
                arr[ascii]->next = newnode;
            }
            else if (arr[ascii]->next != NULL) {
                newnode = new(node);
                newnode->key = s;
                newnode->meaning = m;
                newnode->next = NULL;
                q = arr[ascii];
                while (q->next != NULL) {
                    q = q->next;
                }
                q->next = newnode;
            }
        }
        // =======================================
        void retrieveData(string s) {
            int index = arrayToInt(s);
            if (arr[index] == NULL) {
                cout << "No data present!\n";
                return;
            }
            q = arr[index]->next;
            while (q != NULL) {
                
                if (q->key == s) {
                    cout << "Word\t:\tMeaning\n";
                    cout << q->key << "\t:\t" << q->meaning << "\n";
                    return;
                }
                q = q->next;
            }
            cout << "Could not retrieve data/ Data not present!\n\n";
        }
        // =======================================
        int arrayToInt(string s = "") {
            int sum = 0;
            for (int i = 0; i < s.length(); i++) {
                if (s[i] >= 65 && s[i] <= 90) {
                    sum += s[i] + 32;
                }
                else {
                    sum += s[i];
                }
            }
            cout << "\nSum = " << sum;
            return sum % 10;
        }
        // =======================================
        string deleteData(string s) {
            int index = arrayToInt(s);
            if (arr[index] == NULL) {
                cout << "No data present!\n";
                return "";
            }
            for (q = arr[index]; q->next != NULL; q = q->next) {
                if (q->next->key == s) {
                    temp = q->next;
                    q->next = temp->next;
                    return temp->key;
                    delete(temp);
                }
            }
            return "";
        }
        // =======================================
        void displayAll() {
           
            for (int i = 0; i < size; i++) {
                if (arr[i]->next == NULL) {
                    cout << i << " -> NULL\n";
                }
                else {
                    cout << i << ":\n";
                    for (q = arr[i]->next; q != NULL; q = q->next) {    // loops from the next of the actual index node to the last node
                        cout << " -> " << q->key << " : " << q->meaning << "\n";
                    }
                    cout << endl;
                }
            }
        }
// ===============================================
};
int main(int argc, char const *argv[])
{
    dictionary d1(10);
    string word, meaning, result;
    int ch;
    char opt;
    do {
        cout << "(1) Insert Data\n";
        cout << "(2) Retrieve Data\n";
        cout << "(3) Delete Data\n";
        cout << "(4) Display All\n";
        cout << "\nEnter choice: ";
        cin >> ch;
        cin.ignore();
        switch (ch) {
            case 1:
                cout << "Enter the word: ";
                getline(cin, word);
                
                // cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Enter the meaning: ";
                getline(cin, meaning);
                
                // cin.ignore(numeric_limits<streamsize>::max(), '\n');
                d1.insertData(word, meaning);
                break;


            case 2:
                cout << "Enter the word whose meaning is to retrieved: ";
                // cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, word);
                d1.retrieveData(word);
                break;
           
            case 3:
                cout << "Enter the key to be deleted: ";
                // cin.ignore(numeric_limits<streamsize>::max(), '\n');    // include the <limits> header file for the parameter
                getline(cin, word);
                result = d1.deleteData(word);
                if (result == "") {
                    cout << "Key not found!";
                }
                else {
                    cout << "\n" << result << " deleted successfully!";
                }
                break;
           
            case 4:
                d1.displayAll();
                break;
           
            default:
                cout << "\nInvalid Choice!\n";
                break;
        }
        cout << "\nContinue? (Y/N): ";
        cin >> opt;
        cin.ignore();
    }
    while (opt == 'y' || opt == 'Y');
    return 0;
}
