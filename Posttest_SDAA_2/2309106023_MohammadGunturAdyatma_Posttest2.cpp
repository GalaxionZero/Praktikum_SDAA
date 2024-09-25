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


int addStudents(students student[], int *numberOfStudents)
{
    students newStudent;
    cout << "Enter Student's Name: ";
    getline (cin, newStudent.name);
    cout << "Enter Student's Attack Type: ";
    getline(cin, newStudent.attackType);
    cout << "Enter Student's Defense Type: ";
    getline(cin, newStudent.defenseType);
    cout << "Enter Student's Type of Student: ";
    getline(cin, newStudent.typeOfStudent);
    cout << "Enter Student's Range of Weapon: ";
    getline(cin, newStudent.rangeOfWeapon);
    cout << "Enter Student's School: ";
    getline(cin, newStudent.school);
    cout << "Enter Student's Club: ";
    getline(cin, newStudent.club);

    student[*numberOfStudents] = newStudent;
    student[*numberOfStudents - 1].next = &student[*numberOfStudents];
    student[*numberOfStudents].next = nullptr;
    *numberOfStudents += 1;

    return 0;
}

void listStudents(students student[], int numberOfStudents)
{
    students *head = &student[0];
    while (head != nullptr)
    {
        cout << "Student's Name: " << head->name << endl;
        cout << "Student's Attack Type: " << head->attackType << endl;
        cout << "Student's Defense Type: " << head->defenseType << endl;
        cout << "Student's Type of Student: " << head->typeOfStudent << endl;
        cout << "Student's Range of Weapon: " << head->rangeOfWeapon << endl;
        cout << "Student's School: " << head->school << endl;
        cout << "Student's Club: " << head->club << endl;
        head = head->next;
    }
}


void updateStudents(students student[], int numberOfStudents)
{
    string name;
    cout << "Enter Student's Name: ";
    getline(cin, name);

    for (int i = 0; i < numberOfStudents; i++)
    {
        if (student[i].name == name)
        {
            cout << "Enter Student's Attack Type: ";
            getline(cin, student[i].attackType);
            cout << "Enter Student's Defense Type: ";
            getline(cin, student[i].defenseType);
            cout << "Enter Student's Type of Student: ";
            getline(cin, student[i].typeOfStudent);
            cout << "Enter Student's Range of Weapon: ";
            getline(cin, student[i].rangeOfWeapon);
            cout << "Enter Student's School: ";
            getline(cin, student[i].school);
            cout << "Enter Student's Club: ";
            getline(cin, student[i].club);
        }
    }
}


void deleteStudents(students student[], int *numberOfStudents)
{
    string name;
    cout << "Enter Student's Name: ";
    getline(cin, name);

    for (int i = 0; i < *numberOfStudents; i++)
    {
        if (student[i].name == name)
        {
            if (i < *numberOfStudents - 1)
            {
                student[i] = student[*numberOfStudents - 1];
                student[*numberOfStudents - 1].next = nullptr;
            }
            else
            {
                student[i].name = "";
                student[i].attackType = "";
                student[i].defenseType = "";
                student[i].typeOfStudent = "";
                student[i].rangeOfWeapon = "";
                student[i].school = "";
                student[i].club = "";
                student[i].next = nullptr;
            }
        }
    }

    *numberOfStudents -= 1;
}

int main()
{
    int numberOfStudents = 1, choice;
    students student[10];

    student[0].name = "Misono Mika";
    student[0].attackType = "Piercing";
    student[0].defenseType = "Heavy";
    student[0].typeOfStudent = "Striker";
    student[0].rangeOfWeapon = "Short";
    student[0].school = "Trinity";
    student[0].club = "Tea Party";
    student[0].next = nullptr;

    while (true)
    {
        cout << "===== MENU =====" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. View Student" << endl;
        cout << "3. Update Student" << endl;
        cout << "4. Delete Student" << endl;
        cout << "5. Exit" << endl;
        cout << "Choose:" ;
        cin >> choice;
        cin.clear();
        cin.ignore(10000, '\n');

        switch (choice)
        {
        case 1:
            addStudents(student, &numberOfStudents);
            break;
        case 2:
            listStudents(student, numberOfStudents);
            break;
        case 3:
            updateStudents(student, numberOfStudents);
            break;
        case 4:
            deleteStudents(student, &numberOfStudents);
            break;
        case 5:
            return 0;
        default:
            break;
        }
    }
    return 0;
}