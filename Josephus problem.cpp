#include <iostream>
using namespace std;

struct Node
{
    int info;
    Node* next;
    Node* prev;
};

Node* head = NULL;

void insert_sort(int i, int max);
void erase(int size, int k);

void insert_sort(int i, int max)
{
    Node* newNode = new Node{i, NULL, NULL};
    Node* curNode;

    if(head == NULL)
    {
        head = newNode;
        return;
    }

    curNode = head;
    while(curNode->next != NULL)
    {
        curNode = curNode->next;
    }
    curNode->next = newNode;
    newNode->prev = curNode;
    if(newNode->info == max)
    {
        newNode->next = head;
        head->prev = newNode;
    }
}

void erase(int size, int k)
{
    Node* delNode = head;
    Node* curNode = head;
    static int index = 0;
    
    index = (index + k) % size;
    for(int i = 0; i < index; i++)
    {
        delNode = delNode->next;
        curNode = curNode->next;
    }
    delNode->prev->next = delNode->next;
    delNode->next->prev = delNode->prev;
    cout << "Erased " << delNode->info << " from linked list" << endl;
    
    if(delNode == head)
        head = delNode->next;
    delete delNode;
    
    if(head->next == head)
        cout << "The last node is " << head->info << "." << endl;

}

int main()
{
    int n, k, size;
    cout << "Please input n: ";
    cin >> n;
    for(int i = 1; i <= n; i++)
        insert_sort(i, n);
    size = n;

    cout << "Please input k: ";
    cin >> k;
    for(int i = 0; i < size - 1; i++)
    {
        erase(n, k);
        n--;
    }
    return 0;
}


