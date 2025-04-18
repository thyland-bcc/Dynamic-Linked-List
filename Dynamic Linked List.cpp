#include <iostream>
#include <string>
using namespace std;

struct Node {
    string name;
    int id;
    Node* next;
};

bool isDuplicate(Node* head, int id) {
    while (head) {
        if(head->id == id) return true;
        head = head->next;
    }
    return false;
}

void insertNode(Node*& head) {
    string name;
    int id;

    cout << "Enter the student's name: ";
    getline(cin, name);
    cout << "Enter the student's ID: ";
    cin >> id;
    cin.ignore();
    cout << endl;


    // Check if the ID is already in the linked list
    if(isDuplicate(head, id)) {
        cout << "Error: Student ID already exists";
        return;
    }

    Node* newNode = new Node;
    newNode->name = name;
    newNode->id = id;
    newNode->next = nullptr;

    // Insert at the front if the linked list is empty or if the new node ID is less than the head node ID
    if(head == nullptr || id < head->id) {
        newNode->next = head;
        head = newNode;
        return;
    }

    // Iterate through the linked list as long as the next node isn't the last node or the next node's ID is less than the new node
    Node* current = head;
    while(current->next && current->next->id < id) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;

}

void deleteNode(Node*& head) {
    
    // We can return immediately if the list is empty
    if(head == nullptr) return;

    int id;

    cout << "Enter the student's ID to delete: ";
    cin >> id;
    cin.ignore();
    cout << endl;

    // Check the ID of the head, if it matches delete it and set the next node as the new head
    if(head->id == id) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    // Iterate through the linked list as long as it isn't the last node and the next node doesn't match the ID
    Node* current = head;
    while(current->next && current->next->id != id) {
        current = current->next;
    }

    if(current->next == nullptr) {
        cout << "Error: Can't delete node, student ID not found";
        cout << endl;
        return;
    }

    Node* temp = current->next;
    current->next = temp->next;
    delete temp;

}


void search(Node* head) {
    int id;

    cout << "Enter the student's ID to search: ";
    cin >> id;
    cin.ignore();
    cout << endl;

    Node* current = head;
    while (current) {
        if (current->id == id) {
            cout << "Student Name: " << current->name << endl;
            cout << "Student ID: " << current->id << endl;
        }
        
    current = current->next;
    }
    cout << "Error: Can't print node, student ID not found";
    cout << endl;
}

void modifyNode(Node* head) {

}

void printList(Node*& head) {
    Node* current = head;
    while (current != nullptr) {
        cout << "Student Name: " << current->name << endl;
        cout << "Student ID: " << current->id << endl;

        current = current->next;
    }
}

int main()
{
    Node* head = nullptr;
    insertNode(head);
    insertNode(head);
    insertNode(head);
    insertNode(head);
    deleteNode(head);
    deleteNode(head);
    deleteNode(head);
    printList(head);
}

