#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
struct Node {
    long int data; // Data stored in the node
    int index; // Index of the node in the original dataset
    Node* left; // Pointer to the left subtree
    Node* right; // Pointer to the right subtree
};

// Define the struct for Stack
struct Stack {
    int top; // Index of the top element in the stack
    Node* head; // Pointer to the head of the stack
};

// Function prototypes

/*
Function: createTree
Process: Creates an empty binary search tree
Input data (parameter): None
Output data(parameter): None
Output data (return): Pointer to the root of the created tree
Dependencies: None
Complexity: O(1)
*/
Node* createTree();

/*
Function: printTree
Process: Prints the elements of the binary search tree in preorder traversal
Input data (parameter): Pointer to the root of the tree
Output data(parameter): None
Output data (return): None
Dependencies: Recursive call to itself
Complexity: O(n)
*/
void printTree(Node* root);

/*
Function: addNode
Process: Adds a new node with given data and index to the binary search tree
Input data (parameter): Pointer to the root of the tree, data to be inserted, index of the data
Output data(parameter): None
Output data (return): Pointer to the root of the modified tree
Dependencies: None
Complexity: O(log n) on average (assuming balanced tree)
*/
Node* addNode(Node* root, long int data, int index);

/*
Function: getData
Process: Reads data from a .csv file and populates a binary search tree
Input data (parameter): Filename of the .csv file
Output data(parameter): None
Output data (return): Pointer to the root of the created tree
Dependencies: None
Complexity: O(n log n) on average (assuming balanced tree and reading all data)
*/
Node* getData(const string& filename);

/*
Function: saveData
Process: Saves data from the binary search tree to a .csv file in preorder traversal
Input data (parameter): Filename of the .csv file, Pointer to the root of the tree
Output data(parameter): None
Output data (return): None
Dependencies: None
Complexity: O(n) (assuming all elements are written to file)
*/
void saveData(const string& filename, Node* root);

/*
Function: getFirstOccurrence
Process: Finds the index of the first occurrence of a given element in the BST
Input data (parameter): Element to search for, Pointer to the root of the tree
Output data(parameter): None
Output data (return): Index of the first occurrence (-1 if not found)
Dependencies: None
Complexity: O(log n) on average (assuming balanced tree)
*/
int getFirstOccurrence(long int element, Node* root);

/*
Function: getLastOccurrence
Process: Finds the index of the last occurrence of a given element in the BST
Input data (parameter): Element to search for, Pointer to the root of the tree
Output data(parameter): None
Output data (return): Index of the last occurrence (-1 if not found)
Dependencies: None
Complexity: O(log n) on average (assuming balanced tree)
*/
int getLastOccurrence(long int element, Node* root);

/*
Function: getAllOccurrences
Process: Finds all occurrences of a given element in the BST
Input data (parameter): Element to search for, Pointer to the root of the tree, Output array for occurrences, Output variable for number of occurrences
Output data(parameter): Array of occurrences, Number of occurrences
Output data (return): None
Dependencies: Recursive call to itself
Complexity: O(n) in the worst case (if all elements are same)
*/
void getAllOccurrences(long int element, Node* root, int*& occurrences, int& numOccurrences);

/*
Function: validateTree
Process: Validates if the binary search tree is properly structured
Input data (parameter): Pointer to the root of the tree
Output data(parameter): None
Output data (return): True if the tree is a valid binary search tree, False otherwise
Dependencies: None
Complexity: O(n) (assuming traversal of all nodes)
*/
bool validateTree(Node* root);

/*
Function: createStack
Process: Creates an empty stack
Input data (parameter): None
Output data(parameter): None
Output data (return): Pointer to the created stack
Dependencies: None
Complexity: O(1)
*/
Stack* createStack();

/*
Function: push
Process: Pushes a node onto the stack
Input data (parameter): Pointer to the stack, Pointer to the node to push
Output data(parameter): None
Output data (return): None
Dependencies: None
Complexity: O(1)
*/
void push(Stack* s, Node* node);

/*
Function: pop
Process: Pops a node from the stack
Input data (parameter): Pointer to the stack
Output data(parameter): None
Output data (return): Pointer to the popped node
Dependencies: None
Complexity: O(1)
*/
Node* pop(Stack* s);

/*
Function: isEmptyStack
Process: Checks if the stack is empty
Input data (parameter): Pointer to the stack
Output data(parameter): None
Output data (return): True if the stack is empty, False otherwise
Dependencies: None
Complexity: O(1)
*/
bool isEmptyStack(Stack* s);