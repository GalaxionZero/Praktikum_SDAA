#include <iostream>
#define MAX 100
using namespace std;

int stack[MAX];
int top = -1;

void push(int value) {
    if (top >= MAX - 1) {
        cout << "Stack overflow" << endl;
    } else {
        top++;
        stack[top] = value;
    }
}

int pop() {
    if (top < 0) {
        cout << "Stack underflow" << endl;
        return -1;
    } else {
        int value = stack[top];
        top--;
        return value;
    }
}

bool isEmpty() {
    return (top < 0);
}

int peek() {
    if (top < 0) {
        cout << "Stack is empty" << endl;
        return -1;
    } else {
        return stack[top];
    }
}

void reverseNumbers() {
    int n, num;

    cout << "Masukkan jumlah angka: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Masukkan angka ke-" << i+1 << ": ";
        cin >> num;
        push(num);
    }

    cout << "Angka dalam urutan terbalik: ";
    while (!isEmpty()) {
        cout << pop() << " ";
    }  
}

int main() {
    reverseNumbers();
    return 0;
}
