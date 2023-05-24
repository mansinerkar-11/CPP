//ASSIGNMENT 02
#include <iostream>
#include <stddef.h>
#include <string>
using namespace std;


class Phonebook {
    public:
        string name;
        unsigned long int teleno;
};


class hashing {
    Phonebook **arr;    // pointer to an array of pointers hence the double asterisk
    int size, count, i;
    public:
        hashing(int s) {
            size = s;
            count = 0;
            arr = new Phonebook*[size]; // Array of Pointers (Dynamic Memory Allocation)
            for (i = 0; i < size; i++) {
                arr[i] = NULL;   // to fill the array with null pointers
            }
        }
        // =============================================
        inline int hashFunction(int n) {
            return (n % 23);
        }
        // =============================================
        void insertData(string s, unsigned long int no) {
            if (count == size) {
                cout << "Hash Table is full!\n";
                return;
            }
            int hashIndex = hashFunction(no);
            while (arr[hashIndex] != NULL) {
                hashIndex = (hashIndex + 1) % size;
            }
            arr[hashIndex] = new(Phonebook);
            arr[hashIndex]->name = s;
            arr[hashIndex]->teleno = no;
            count++;
        }
        // =============================================
        string retrieveData(unsigned long int no) {
            if (count == 0) {
                return "Empty";
            }
            int hashIndex = hashFunction(no);
            int temp = hashIndex;   // stored for comparing later

            while (true) {
                if (arr[hashIndex] == NULL || arr[hashIndex]->teleno != no) {
                    hashIndex = (hashIndex + 1) % size;
                }
                else {
                    break;
                }

                if ( hashIndex == temp) {
                    temp = -1;
                    break;
                }
            }
            if (temp == -1) {
                return ("\nNot Found!\n");
            }
            else {
                return arr[hashIndex]->name;
            }
        }
        // =============================================
        void deleteData(unsigned long int no) {
            if (count == 0) {
                cout << "Hash Table is empty!\n";
                return;
            }
            int hashIndex = hashFunction(no);
            int temp = hashIndex;


            while (true) {
                if (arr[hashIndex] == NULL) {
                    hashIndex = (hashIndex + 1) % size;
                }
                else if (arr[hashIndex]->teleno != no) {
                    hashIndex = (hashIndex + 1) % size;
                }
                else {
                    break;
                }

                if (hashIndex == temp) {    // it came full circle from the hash index to the last element and then from the first element to the hash index again
                    temp = -1;
                    break;
                }
            }
            if (temp == -1) {
                cout << "\nNot Found!\n";
                return;
            }
            else {
                delete arr[hashIndex];
                arr[hashIndex] = NULL;
                count--;
            }
        }
        // =============================================
        void displayAll() {
            if (count == 0) {
                cout << "Hash Table is empty!\n";
                return;
            }
            cout << "---Hash Table of Phonebook Records---\n\n";
            cout << "Name\t\tTelephone No.\n";
            for (int i = 0; i < size; i++) {
                if (arr[i] != NULL) {
                    cout << arr[i]->name << "\t\t" << arr[i]->teleno << endl;
                }
            }
        }
// =====================================================
};
int main(int argc, char const *argv[])
{
    cout << "---Linear Probing in Hash Table---\n\n";
    int ch, n;
    string name, result;
    unsigned long int number;
    cout << "Enter size/length of the hash table: ";
    cin >> n;
    hashing h1(n);
    char opt;
    do {
        cout << "(1) Insert Data\n";
        cout << "(2) Delete Data\n";
        cout << "(3) Retrieve Data\n";
        cout << "(4) Display Hash Table\n";
        cout << "\nEnter choice: ";
        cin >> ch;
        switch(ch) {
            case 1:
                cout << "Enter Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Telephone No.: ";
                cin >> number;
                h1.insertData(name, number);
                break;
           
            case 2:
                cout << "Enter the number to be deleted: ";
                cin >> number;
                h1.deleteData(number);
                break;
           
            case 3:
                cout << "Enter the number whose data is to be retrieved: ";
                cin >> number;
                result = h1.retrieveData(number);
                cout << result;
                break;
                
            case 4:
            	h1.displayAll();
            	break;
           
            default:
                cout << "\nInvalid Choice!\n";
                break;
        }
        cout << "\nContinue? (Y/N): ";
        cin >> opt;


    } while (opt == 'y' || opt == 'Y');
    return 0;
}


