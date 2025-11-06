#include <iostream>
#include <string>

using namespace std;

struct Student {
    int roll;
    string name;
    int marks;
};

struct Node {
    Student data;
    Node* next;
};

Node* head = nullptr;

void showMenu() {
    cout << "\n--- Student Menu ---" << endl;
    cout << "1. Add Record" << endl;
    cout << "2. Display All" << endl;
    cout << "3. Search by Roll" << endl;
    cout << "4. Delete by Roll" << endl;
    cout << "5. Exit" << endl;
}

void insertRecord() {
    Student s;
    cout << "Enter Roll Number: "; cin >> s.roll;
    cout << "Enter Name (No Spaces): "; cin >> s.name;
    cout << "Enter Marks: "; cin >> s.marks;
    
    Node* newNode = new Node;
    newNode->data = s;
    newNode->next = head;
    head = newNode;
    
    cout << "\nRecord added successfully." << endl;
}

void displayAll() {
    if (!head) {
        cout << "Database is empty." << endl;
        return;
    }
    
    cout << "--- All Student Records ---" << endl;
    cout << "Roll | Name | Marks" << endl;
    cout << "-------------------------" << endl;
    
    Node* current = head;
    while (current) {
        cout << current->data.roll << " | " 
             << current->data.name << " | " 
             << current->data.marks << endl;
        current = current->next;
    }
}

void searchRecord() {
    int roll_to_find;
    cout << "Enter Roll Number to search: ";
    if (!(cin >> roll_to_find)) { cin.clear(); cin.ignore(10000, '\n'); return; }
    
    Node* current = head;
    while (current) {
        if (current->data.roll == roll_to_find) {
            cout << "\nRecord Found: Name: " << current->data.name << ", Marks: " << current->data.marks << endl;
            return;
        }
        current = current->next;
    }
    cout << "\nRoll Number " << roll_to_find << " not found." << endl;
}

void deleteRecord() {
    int roll_to_delete;
    cout << "Enter Roll Number to delete: ";
    if (!(cin >> roll_to_delete)) { cin.clear(); cin.ignore(10000, '\n'); return; }
    
    Node* current = head;
    Node* prev = nullptr;

    while (current && current->data.roll != roll_to_delete) {
        prev = current;
        current = current->next;
    }

    if (!current) {
        cout << "\nRoll Number " << roll_to_delete << " not found." << endl;
        return;
    }

    if (prev == nullptr) {
        head = current->next;
    } else {
        prev->next = current->next;
    }

    delete current;
    cout << "\nRecord for Roll Number " << roll_to_delete << " deleted." << endl;
}

int main() {
    int choice;
    
    do {
        showMenu();
        cout << "Enter choice: ";
        if (!(cin >> choice)) { 
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        
        cout << "----------------------------------------" << endl;

        switch (choice) {
            case 1: insertRecord(); break;
            case 2: displayAll(); break;
            case 3: searchRecord(); break;
            case 4: deleteRecord(); break;
            case 5: cout << "Exiting system. Goodbye! 👋" << endl; break;
            default: cout << "Invalid choice." << endl;
        }
        cout << "----------------------------------------\n" << endl;

    } while (choice != 5);
    
    return 0;
}