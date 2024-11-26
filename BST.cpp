#include "search_lib_BST.h"

// Creates an empty binary search tree
Node* createTree() {
    return nullptr;
}

// Recursively prints tree nodes in a preorder traversal
void printTree(Node* root) {
    if (root) {
        cout << root->data << " ";
        printTree(root->left);
        printTree(root->right);
    }
}

// Inserts a new node with the given data and index into the BST
Node* addNode(Node* root, long int data, int index) {
    if (root == nullptr) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->index = index;
        newNode->left = nullptr;
        newNode->right = nullptr;
        return newNode;
    }

    if (data <= root->data) {
        root->left = addNode(root->left, data, index);
    }
    else {
        root->right = addNode(root->right, data, index);
    }

    return root;
}

// Reads and loads data from a CSV file into the BST
Node* getData(const string& filename) {
    // Create an empty tree
    Node* root = nullptr;

    // Open the file
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return nullptr;
    }

    // Read data from the file and populate the BST
    string line;
    int index = 0;
    while (getline(file, line)) {
        istringstream iss(line);
        long int data;
        if (!(iss >> data)) {
            cerr << "Invalid data format in file: " << filename << endl;
            return nullptr;
        }
        root = addNode(root, data, index++);
    }

    // Close the file
    file.close();

    return root;
}

// Saves the BST data into a CSV file using preorder traversal
void saveData(const string& filename, Node* root) {
    // Open the file
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    // Save data from the BST to file in preorder traversal
    if (root != nullptr) {
        file << root->data << endl;
        saveData(filename, root->left);
        saveData(filename, root->right);
    }

    // Close the file
    file.close();
}

// Finds the index of the first occurrence of the specified element in the BST
int getFirstOccurrence(long int element, Node* root) {
    if (root == nullptr)
        return -1;
    if (root->data == element) {
        //int right = getFirstOccurrence(element, root->right);
        //if (right == -1)
            return root->index;
        //else
           // return right;
    }
    if (element < root->data)
        return getFirstOccurrence(element, root->left);
    else
        return getFirstOccurrence(element, root->right);
}

// Finds the index of the last occurrence of the specified element in the BST
int getLastOccurrence(long int element, Node* root) {
    if (root == nullptr)
        return -1;
    if (root->data == element) {
        int left = getLastOccurrence(element, root->left);
        if (left == -1)
            return root->index;
        else
            return left;
    }
    if (element < root->data)
        return getLastOccurrence(element, root->left);
    else
        return getLastOccurrence(element, root->right);
}

// get index of all element and its duplicates
void getAllOccurrences(long int element, Node* root, int*& occurrences, int& numOccurrences) {
    if (root == nullptr)
        return;

    if (root->data == element) {
        occurrences[numOccurrences++] = root->index;
    }

    getAllOccurrences(element, root->left, occurrences, numOccurrences);
    getAllOccurrences(element, root->right, occurrences, numOccurrences);
}

//Stack creation
Stack* createStack() {
    Stack* stack = new Stack;
    stack->top = -1;
    stack->head = nullptr;
    return stack;
}

//Pushing element onto stack
void push(Stack* s, Node* node) {
    if (s == nullptr)
        return;
    if (s->head == nullptr) {
        s->head = node;
    }
    else {
        node->left = s->head;
        s->head = node;
    }
    s->top++;
}

//Taking top element off the stack
Node* pop(Stack* s) {
    if (s == nullptr || s->head == nullptr)
        return nullptr;
    Node* temp = s->head;
    s->head = s->head->left;
    s->top--;
    return temp;
}

//check if stack is empty
bool isEmptyStack(Stack* s) {
    return s == nullptr || s->head == nullptr;
}


//validating tree if it is a bst
bool validateTree(Node* root) {
    if (root == nullptr) {
        cout << "1 " << endl;
    }
    return true;

    Stack* stack = createStack();
    Node* prev = nullptr;
    Node* curr = root;

    while (curr != nullptr || !isEmptyStack(stack)) {
        while (curr != nullptr) {
            push(stack, curr);
            curr = curr->left;
        }
        curr = pop(stack);
        if (prev != nullptr && prev->data >= curr->data) {
            return false;
        }
        prev = curr;
        curr = curr->right;
    }
    return true;
}
