/*myData_CS2001 name of file*/
#include "BST.cpp"


void searchOccurence(Node* root) {
    int number; //User input Number
    cout << "Enter the number you want to find occurences of: ";
    cin >> number;

    int firstOccurrence = getFirstOccurrence(number, root); //getting first occurrence
    int lastOccurrence = getLastOccurrence(number, root);   //getting last occurence
    int* occurrences = new int[lastOccurrence - firstOccurrence + 1];
    int numOccurrences = 0;
    getAllOccurrences(number, root, occurrences, numOccurrences);   //getting all occurences
    
    //if no occurence
    if (firstOccurrence == -1) {
        cout << "Number " << number << " not found" << endl;
    }
    //if number is present
    else {
        cout << "First Occurrence of " << number << ": " << firstOccurrence << endl;
        cout << "Last Occurrence of " << number << ": " << lastOccurrence << endl;
        cout << "All Occurrences of " << number << ": ";
        for (int i = 0; i < numOccurrences; ++i) {
            cout << occurrences[i] << " ";
        }
        cout << endl;
    }
}

void searchOccurence(Node* root, int number) {
    int firstOccurrence = getFirstOccurrence(number, root); //getting first occurrence
    int lastOccurrence = getLastOccurrence(number, root);   //getting last occurence
    int* occurrences = new int[lastOccurrence - firstOccurrence + 1];
    int numOccurrences = 0;
    getAllOccurrences(number, root, occurrences, numOccurrences);   //getting all occurences

    //if no occurence
    if (firstOccurrence == -1) {
        cout << "Number " << number << " not found" << endl;
    }
    //if number is present
    else {
        cout << "First Occurrence of " << number << ": " << firstOccurrence << endl;
        cout << "Last Occurrence of " << number << ": " << lastOccurrence << endl;
        cout << "All Occurrences of " << number << ": ";
        for (int i = 0; i < numOccurrences; ++i) {
            cout << occurrences[i] << " ";
        }
        cout << endl;
    }
}

void mainMenu(Node* root) {
    int input = 0;  //User input for MainMenu
    while (true) {
        cout << "\n---------MainMenu---------\n";
        cout << "1. Occurences of 232\n";
        cout << "2. Occurences of 649\n";
        cout << "3. Occurences of 989\n";
        cout << "4. Occurences of 1447\n";
        cout << "5. Occurences of 1909\n";
        cout << "6. Check Occurence Of Your Input Number\n";
        cout << "7. Exit\n";
        cout << "Enter Your Choice: ";
        cin >> input;

        switch (input) {
        case 1:
            system("cls");
            searchOccurence(root, 232);
            break;
        case 2:
            system("cls");
            searchOccurence(root, 649);
            break;
        case 3:
            system("cls");
            searchOccurence(root, 989);
            break;
        case 4:
            system("cls");
            searchOccurence(root, 1447);
            break;
        case 5:
            system("cls");
            searchOccurence(root, 1909);
            break;
        case 6:
            system("cls");
            searchOccurence(root);
            break;
        case 7:
            system("cls");
            cout << "Exiting the program.\n";
            exit(0);
        default:
            system("cls");
            cout << "Invalid input, try again\n";
        }
    }
}


int main() {

    const string inputFilename = "myData_CS2001.csv";
    Node* root = getData(inputFilename);

    if (root == nullptr) {
        cout << "Failed to read data from file." << endl;
        return 1;
    }

    if (validateTree(root)) {
        cout << "Tree is a valid BST." << endl;
    }
    else {
        cout << "Tree is not a valid BST." << endl;
    }

    mainMenu(root);

    return 0;
}