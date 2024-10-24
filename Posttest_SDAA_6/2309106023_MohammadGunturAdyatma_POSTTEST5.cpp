#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;

struct students {
    string name;
    string attackType;
    string defenseType;
    string typeOfStudent;
    string rangeOfWeapon;
    string school;
    string club;
    int age;
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
    cout << "Enter age: ";
    cin >> newStudent->age;
    cin.clear();
    cin.ignore(10000, '\n');
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
    cout << "Enter age: ";
    cin >> newStudent->age;
    cin.clear();
    cin.ignore(10000, '\n');
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
        cout << "Age: " << temp->age << endl;
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
            cout << "Enter new age: ";
            cin >> temp->age;
            cin.clear();
            cin.ignore(10000, '\n');
            cout << endl << "Student updated!" << endl;
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

void push(students *&top) {
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
    cout << "Enter age: ";
    cin >> newStudent->age;
    cin.clear();
    cin.ignore(10000, '\n');
    newStudent->next = top;
    top = newStudent;
    cout << "Student pushed to stack!" << endl;
}

void pop(students *&top) {
    if (top == nullptr) {
        cout << "Stack is empty!" << endl;
        return;
    }
    students *temp = top;
    top = top->next;
    cout << "Popped student: " << temp->name << endl;
    delete temp;
}

void enqueue(students *&front, students *&rear) {
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
    cout << "Enter age: ";
    cin >> newStudent->age;
    cin.clear();
    cin.ignore(10000, '\n');
    newStudent->next = nullptr;

    if (rear == nullptr) {
        front = rear = newStudent;
    } else {
        rear->next = newStudent;
        rear = newStudent;
    }
    cout << "Student added to queue!" << endl;
}

void dequeue(students *&front, students *&rear) {
    if (front == nullptr) {
        cout << "Queue is empty!" << endl;
        return;
    }
    students *temp = front;
    front = front->next;
    if (front == nullptr) {
        rear = nullptr;
    }
    cout << "Dequeued student: " << temp->name << endl;
    delete temp;
}

int getLength(students *head) {
    int length = 0;
    students *temp = head;
    while (temp != nullptr) {
        length++;
        temp = temp->next;
    }
    return length;
}

students** listToArray(students *head, int length) {
    students **arr = new students*[length];
    students *temp = head;
    for (int i = 0; i < length; i++) {
        arr[i] = temp;
        temp = temp->next;
    }
    return arr;
}

void arrayToList(students **arr, students *&head, int length) {
    head = arr[0];
    students *temp = head;
    for (int i = 1; i < length; i++) {
        temp->next = arr[i];
        temp = temp->next;
    }
    temp->next = nullptr;
    delete[] arr;
}

void shellSort(students *&head, bool ascending = true) {
    int n = getLength(head);
    if (n <= 1) return;

    students **arr = listToArray(head, n);

    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            students *temp = arr[i];
            int j;
            if (ascending) {
                for (j = i; j >= gap && arr[j - gap]->age > temp->age; j -= gap) {
                    arr[j] = arr[j - gap];
                }
            } else {
                for (j = i; j >= gap && arr[j - gap]->age < temp->age; j -= gap) {
                    arr[j] = arr[j - gap];
                }
            }
            arr[j] = temp;
        }
    }

    arrayToList(arr, head, n);
}

students* getTail(students* cur) {
    while (cur != nullptr && cur->next != nullptr)
        cur = cur->next;
    return cur;
}

students* partition(students* head, students* end, students** newHead, students** newEnd, bool ascending) {
    students* pivot = end;
    students* prev = nullptr, *cur = head, *tail = pivot;

    while (cur != pivot) {
        if ((ascending && cur->name < pivot->name) || (!ascending && cur->name > pivot->name)) {
            if (*newHead == nullptr)
                *newHead = cur;

            prev = cur;
            cur = cur->next;
        } else {
            if (prev) {
                prev->next = cur->next;
            }
            students* tmp = cur->next;
            cur->next = nullptr;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }

    if (*newHead == nullptr)
        *newHead = pivot;

    *newEnd = tail;

    return pivot;
}

students* quickSortRecur(students* head, students* end, bool ascending) {
    if (!head || head == end)
        return head;

    students* newHead = nullptr, *newEnd = nullptr;

    students* pivot = partition(head, end, &newHead, &newEnd, ascending);

    if (newHead != pivot) {
        students* temp = newHead;
        while (temp->next != pivot)
            temp = temp->next;
        temp->next = nullptr; 

        newHead = quickSortRecur(newHead, temp, ascending);

        temp = getTail(newHead);
        temp->next = pivot;
    }

    pivot->next = quickSortRecur(pivot->next, newEnd, ascending);

    return newHead;
}

void quickSort(students *&head, bool ascending = true) {
    if (!head || head->next == nullptr)
        return;

    head = quickSortRecur(head, getTail(head), ascending);
}

int fibMonaccianSearch(students *head, int x, int n)
{
    students *temp = head;
    int fibMMm2 = 0;
    int fibMMm1 = 1;
    int fibM = fibMMm2 + fibMMm1;
    while (fibM < n)
    {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }
    int offset = -1;
    while (fibM > 1)
    {
        int i = min(offset + fibMMm2, n - 1);
 
        temp = head;
        for (int j = 0; j < i; j++)
        {
            temp = temp->next;
        }
        if (temp->age < x)
        {
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        }
        else if (temp->age > x)
        {
            fibM = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        }
        else
            return i;
    }
    temp = head;
    for (int j = 0; j < offset + 1; j++)
    {
        temp = temp->next;
    }
    if (fibMMm1 && temp->age == x)
        return offset + 1;
    return -1;
}

int findStudents(students *head, int idx)
{
    for (int i = 0; i < idx; i++)
    {
        head = head->next;
    }
    return head->age;
}
 
int jumpSearch(students *head, int x, int n)
{
    int step = sqrt(n);
    int prev = 0;
 
    int idx = min(step, n) - 1;
    while (findStudents(head, idx) < x)
    {
        prev = step;
        step += sqrt(n);
        idx = min(step, n) - 1;
        if (prev >= n)
        {
            return -1;
        }
    }
    while (findStudents(head, prev) < x)
    {
        prev++;
    }
    if (findStudents(head, prev) == x)
    {
        return prev;
    }
    return -1;
}

const int NO_OF_CHARS = 256;
void badCharHeuristic(string str, int size, int badChar[NO_OF_CHARS])
{
    for (int i = 0; i < NO_OF_CHARS; i++)
    {
        badChar[i] = -1;
    }
    for (int i = 0; i < size; i++)
    {
        badChar[(int)str[i]] = i;
    }
}
 
void booyerMooreSearch(students *head, string pat)
{
    int m = pat.size();
    students *temp = head;
    while (temp != NULL)
    {
        int n = temp->name.size();
        int badChar[NO_OF_CHARS];
        badCharHeuristic(pat, m, badChar);
        int s = 0;
 
        while (s <= (n - m))
        {
            int j = m - 1;
            while (j >= 0 && pat[j] == temp->name[s + j])
            {
                j--;
            }
            if (j < 0)
            {
                cout << temp->name << endl;
                cout << temp->attackType << endl;
                cout << temp->defenseType << endl;
                cout << temp->typeOfStudent << endl;
                cout << temp->rangeOfWeapon << endl;
                cout << temp->school << endl;
                cout << temp->club << endl;
                cout << temp->age << endl;
                break;
            }
            else
            {
                s += max(1, j - badChar[temp->name[s + j]]);
            }
        }
        temp = temp->next;
    }
}

int main() {
    int choice;
    string name;
    students *head = nullptr;
    students *stackTop = nullptr; 
    students *queueFront = nullptr, *queueRear = nullptr; 

    while (true) {
        cout << "===== MENU =====" << endl;
        cout << "1. Add Student to List" << endl;
        cout << "2. View Students in List" << endl;
        cout << "3. Update Student" << endl;
        cout << "4. Delete Student" << endl;
        cout << "5. Stack Operations (Push/Pop)" << endl;
        cout << "6. Queue Operations (Enqueue/Dequeue)" << endl;
        cout << "7. Sort Students (Shell Sort / Quick Sort)" << endl;
        cout << "8. Search Functions" << endl;
        cout << "9. Exit" << endl;
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
                cout << "1. Push to Stack" << endl;
                cout << "2. Pop from Stack" << endl;
                cout << "3. View Stack" << endl;
                cout << "Choose: ";
                cin >> choice;
                cin.clear();
                cin.ignore(10000, '\n');
                if (choice == 1)
                    push(stackTop);
                else if (choice == 2)
                    pop(stackTop);
                else if (choice == 3)
                    listStudents(stackTop);
                break;
            case 6:
                cout << "1. Enqueue (Add to Queue)" << endl;
                cout << "2. Dequeue (Remove from Queue)" << endl;
                cout << "3. View Queue" << endl;
                cout << "Choose: ";
                cin >> choice;
                cin.clear();
                cin.ignore(10000, '\n');
                if (choice == 1)
                    enqueue(queueFront, queueRear);
                else if (choice == 2)
                    dequeue(queueFront, queueRear);
                else if (choice == 3)
                    listStudents(queueFront);
                break;
            case 7:
                cout << "1. Shell Sort Ascending" << endl;
                cout << "2. Shell Sort Descending" << endl;
                cout << "3. Quick Sort Ascending" << endl;
                cout << "4. Quick Sort Descending" << endl;
                cout << "Choose: ";
                cin >> choice;
                cin.clear();
                cin.ignore(10000, '\n');
                if (choice == 1)
                    shellSort(head, true);
                else if (choice == 2)
                    shellSort(head, false);
                else if (choice == 3)
                    quickSort(head, true);
                else if (choice == 4)
                    quickSort(head, false);

                listStudents(head);
                break;
            case 8:
                cout << "1. Fibbonaci Search" << endl;
                cout << "2. Jump Search" << endl;
                cout << "3. Booyer-Moore Search" << endl;
                cout << "Choose: ";
                cin >> choice;
                cin.clear();
                cin.ignore(10000, '\n');

                if (choice == 1) {
                    cout << "Fibbonaci Search" << endl;
                    int x;
                    cout << "Enter age to search: ";
                    cin >> x;
                    cin.clear();
                    cin.ignore(10000, '\n');
                    shellSort(head, true);
                    int result = fibMonaccianSearch(head, x, getLength(head));
                    if (result == -1) {
                        cout << "Student not found!" << endl;
                    } else {
                        cout << "Student found at index " << result << endl;
                    }
                } else if (choice == 2) {
                    cout << "Jump Search" << endl;
                    int x;
                    cout << "Enter age to search: ";
                    cin >> x;
                    cin.clear();
                    cin.ignore(10000, '\n');
                    shellSort(head, true);
                    int result = jumpSearch(head, x, getLength(head));
                    if (result == -1) {
                        cout << "Student not found!" << endl;
                    } else {
                        cout << "Student found at index " << result << endl;
                    }
                } else if (choice == 3) {
                    cout << "Booyer-Moore Search" << endl;
                    string name;
                    cout << "Enter name to search: ";
                    getline(cin, name);
                    booyerMooreSearch(head, name);
                }
                break;
            default:
                cout << "Invalid choice!" << endl;
                break;
        }
    }
    return 0;
}
