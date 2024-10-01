#include <iostream>
using namespace std;

struct students {
    string name;
    string attackType;
    string defenseType;
    string typeOfStudent;
    string rangeOfWeapon;
    string school;
    string club;
    students *next;
};

void addStudentsFront(students *&head) {
    students *newStudent = new students;
    cout << "Enter name: ";
    getline(cin, newStudent->name);
    cout << "Enter attack type: ";
    getline(cin, newStudent->attackType);
    cout << "Enter defense type: ";
    getline(cin, newStudent->defenseType);
    cout << "Enter type of student: ";
    getline(cin, newStudent->typeOfStudent);
    cout << "Enter range of weapon: ";
    getline(cin, newStudent->rangeOfWeapon);
    cout << "Enter school: ";
    getline(cin, newStudent->school);
    cout << "Enter club: ";
    getline(cin, newStudent->club);
    newStudent->next = head;
    head = newStudent;
}

void addStudentsBack(students *&head) {
    students *newStudent = new students;
    cout << "Enter name: ";
    getline(cin, newStudent->name);
    cout << "Enter attack type: ";
    getline(cin, newStudent->attackType);
    cout << "Enter defense type: ";
    getline(cin, newStudent->defenseType);
    cout << "Enter type of student: ";
    getline(cin, newStudent->typeOfStudent);
    cout << "Enter range of weapon: ";
    getline(cin, newStudent->rangeOfWeapon);
    cout << "Enter school: ";
    getline(cin, newStudent->school);
    cout << "Enter club: ";
    getline(cin, newStudent->club);
    newStudent->next = nullptr;

    if (head == nullptr) {
        head = newStudent;
    } else {
        students *temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newStudent;
    }
}

void listStudents(students *head) {
    students *temp = head;
    while (temp != nullptr) {
        cout << "Name: " << temp->name << endl;
        cout << "Attack Type: " << temp->attackType << endl;
        cout << "Defense Type: " << temp->defenseType << endl;
        cout << "Type of Student: " << temp->typeOfStudent << endl;
        cout << "Range of Weapon: " << temp->rangeOfWeapon << endl;
        cout << "School: " << temp->school << endl;
        cout << "Club: " << temp->club << endl;
        temp = temp->next;
    }
}

void updateStudent(students *head, string name) {
    students *temp = head;
    while (temp != nullptr) {
        if (temp->name == name) {
            cout << "Enter new name: ";
            getline(cin, temp->name);
            cout << "Enter new attack type: ";
            getline(cin, temp->attackType);
            cout << "Enter new defense type: ";
            getline(cin, temp->defenseType);
            cout << "Enter new type of student: ";
            getline(cin, temp->typeOfStudent);
            cout << "Enter new range of weapon: ";
            getline(cin, temp->rangeOfWeapon);
            cout << "Enter new school: ";
            getline(cin, temp->school);
            cout << "Enter new club: ";
            getline(cin, temp->club);
            return;
        }
        temp = temp->next;
    }
    cout << "Student not found!" << endl;
}

void deleteStudent(students *&head, string name) {
    students *temp = head;
    students *prev = nullptr;

    while (temp != nullptr) {
        if (temp->name == name) {
            if (prev == nullptr) {
                head = temp->next;
            } else {
                prev->next = temp->next;
            }
            delete temp;
            cout << "Student deleted!" << endl;
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    cout << "Student not found!" << endl;
}

int main() {
    int choice;
    string name;
    students *head = nullptr;

    while (true) {
        cout << "===== MENU =====" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. View Student" << endl;
        cout << "3. Update Student" << endl;
        cout << "4. Delete Student" << endl;
        cout << "5. Exit" << endl;
        cout << "Choose: ";
        cin >> choice;
        cin.clear();
        cin.ignore(10000, '\n');

        switch (choice) {
            case 1:
                cout << "1. Add Student to Front" << endl;
                cout << "2. Add Student to Back" << endl;
                cout << "Choose: ";
                cin >> choice;
                cin.clear();
                cin.ignore(10000, '\n');
                if (choice == 1)
                    addStudentsFront(head);
                else if (choice == 2)
                    addStudentsBack(head);
                break;
            case 2:
                listStudents(head);
                break;
            case 3:
                cout << "Enter student name to update: ";
                getline(cin, name);
                updateStudent(head, name);
                break;
            case 4:
                cout << "Enter student name to delete: ";
                getline(cin, name);
                deleteStudent(head, name);
                break;
            case 5:
                return 0;
            default:
                break;
        }
    }
    return 0;
}