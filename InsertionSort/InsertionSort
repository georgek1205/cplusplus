#include <iostream>
#include <fstream>
using namespace std;

struct Node
{
    int info;
    Node* link;
};

Node* head = NULL;

void insertion_Sort(int x);
void print();

void insertion_Sort(int x)
{
    Node* newNode = new Node{x, NULL};
    Node* curNode;
    Node* preNode;
    
    if(head == NULL)
    {
        head = newNode;
        return;
    }
    
    if(head->info > newNode->info)
    {
        newNode->link = head;
        head = newNode;
        return;
    }
    
    curNode = preNode = head;
    while(curNode->link != NULL)
    {
        curNode = curNode->link;
        if (curNode->info > newNode->info)
        {
            newNode->link = curNode;
            preNode->link = newNode;
            return;
        }
        preNode = preNode -> link;
    }
    curNode->link = newNode;
}

void print()
{
    Node* cur = head;
    while (cur->link != NULL)
    {
        cout << cur->info << " ";
        cur = cur->link;
    }
    cout << cur->info;
    cout << endl;
}
int main()
{
    ifstream file("testdata.txt");
    if (!file.is_open())
    {
        cout << "Cannot read data from the file" << endl;
        exit(0);
    }
    cout << "Unsorted contents of the list before insertion: ";
    while (!file.eof())
    {
        int i;
        file >> i;
        if (!file.fail())
        {
            cout << i << " ";
            insertion_Sort(i);
        }
        else
        {
            cout << "=====break here=====" << endl;
            break;
        }
    }
    cout << endl;
    file.close();
    cout << "Sorted contents of the list before insertion: ";
    print();
    cout << "Please insert the element you want to insert: ";
    int x;
    cin >> x;
    insertion_Sort(x);
    cout << "This is the output of the final list after insertion:";
    print();
    
    
    return 0;
}

