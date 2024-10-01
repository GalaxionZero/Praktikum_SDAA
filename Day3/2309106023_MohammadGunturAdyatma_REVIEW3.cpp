#include <iostream>
using namespace std;
 
struct Node {
    int data;
    Node* next;
};
 
void tambahDepan(Node** head, int dataBaru) {
    Node* nodeBaru = new Node();
 
    // Lengkapi di bawah comment ini

    head = &nodeBaru;
    nodeBaru->data = dataBaru;
    nodeBaru->next = *head;
    
    // Lengkapi di atas comment ini
}
 
void tambahTengah(Node* head, int dataBaru, int posisi) {
    Node* nodeBaru = new Node();
    nodeBaru->data = dataBaru;
    Node* temp = head;
 
    for (int i = 1; temp != nullptr && i < posisi - 1; i++) {
        temp = temp->next;
    }
 
    if (temp == nullptr || temp->next == nullptr) {
        cout << "Posisi tidak valid atau diluar jangkauan" << endl;
        return;
    }
 
    // Lengkapi di bawah comment ini

    nodeBaru->next = temp->next;
    
    // Lengkapi di atas comment ini
}
 
void hapusAkhir(Node** head) {
    if (*head == nullptr) {
        cout << "List kosong, tidak ada yang dihapus" << endl;
        return;
    }
 
    if ((*head)->next == nullptr) {
        delete *head;
        *head = nullptr;
        return;
    }
 
    Node* temp = *head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
 
    // Lengkapi di bawah comment ini

    delete temp->next;
    
    // Lengkapi di atas comment ini
}
 
void tampilkan(Node* head) {
    if (head == nullptr) {
        cout << "List kosong" << endl;
        return;
    }
    
    // Lengkapi di bawah comment ini

    else {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
    
    // Lengkapi di atas comment ini
 
    cout << endl;
}
 
int main() {
    Node* head = nullptr;
 
    tambahDepan(&head, 10);
    tambahDepan(&head, 20);
    tambahDepan(&head, 30);
 
    cout << "Linked list setelah tambah depan: ";
    tampilkan(head);
 
    tambahTengah(head, 25, 2);
    cout << "Linked list setelah tambah tengah di posisi 2: ";
    tampilkan(head);
 
    hapusAkhir(&head);
    cout << "Linked list setelah hapus akhir: ";
    tampilkan(head);
 
    return 0;
}