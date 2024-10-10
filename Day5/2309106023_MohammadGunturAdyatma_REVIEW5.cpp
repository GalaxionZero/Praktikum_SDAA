#include <iostream>
using namespace std;
 
struct Node
{
    int data;
    Node *next;
};
 
int length(Node *head)
{
    int panjang = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        panjang++;
    }
    return panjang;
}
int linkedList2Array(Node *head, int *arr)
{
    int panjang = length(head);
    for (int i = 0; i < panjang; i++)
    {
        arr[i] = head->data;
        head = head->next;
    }
    return panjang;
}
int array2LinkedList(Node *head, int *arr)
{
    int panjang = length(head);
    for (int i = 0; i < panjang; i++)
    {
        head->data = arr[i];
        head = head->next;
    }
    return panjang;
}

int shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] < temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
    return 0;
}
 
void display(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
int main()
{
    Node *node1 = new Node;
    Node *node2 = new Node;
    Node *node3 = new Node;
    Node *node4 = new Node;
    Node *node5 = new Node;
    node1->data = 2;
    node2->data = 1;
    node3->data = 4;
    node4->data = 3;
    node5->data = 5;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = NULL;
    Node *HEAD = node1;
    int arr[length(HEAD)];
    linkedList2Array(HEAD, arr);
    cout << "Sebelum disorting: ";
    display(HEAD);
    shellSort(arr, length(HEAD));
    array2LinkedList(HEAD, arr);
    cout << "Setelah disorting: ";
    display(HEAD);
    return 0;
}