#include <iostream>
#include <string>
using namespace std;

struct Node {
    string name;
    int id;
    Node* next;
};

void insertFront(Node*& head) {
    Node* newNode = new Node;
    string name;
    int id;

    cout << "Enter the student's name: ";
    getline(cin, name);
    cout << "Enter the student's ID: ";
    cin >> id;
    cin.ignore();
    cout << endl;

    newNode->name = name;
    newNode->id = id;
    newNode->next = head;
    head = newNode;
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
    insertFront(head);
    insertFront(head);
    insertFront(head);
    printList(head);
}

