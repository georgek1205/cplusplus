#include <iostream>
#include <fstream>

using namespace std;

struct Node 
{
    int info;
    Node* next;
};

void append(Node*& head, int x);
Node* initialize_list(string s);
void print(Node* head);
Node* merge(Node* head1, Node* head2);

void append(Node*& head, int x)
{
    Node* p = new Node;
    p->info = x;
    p->next = NULL;

    if (head == NULL) {
        p->next = head;
        head = p;
    }
    else
    {
        Node* prev = head;
        Node* cur = head->next;

        while (cur != NULL)
        {
            prev = cur;
            cur = cur->next;
        }

        p->next = prev->next;
        prev->next = p;
    }
}


Node* initialize_list(string s)
{
    Node* head = NULL;
    ifstream inFile(s);

    if (!inFile.is_open()) {
        cout << "Error: cannot open data file" << endl;
        exit(0);
    }

    while (!inFile.eof())
    {
        int i;
        inFile >> i;

        if (!inFile.fail())
            append(head, i);
        else
            break;
    }

    inFile.close();
    return head;
}


void print(Node* head)
{
    Node* cur = head;
    while (cur != NULL) {
        cout << cur->info << " ";
        cur = cur->next;
    }
    cout << endl;
}

Node* merge(Node* head1, Node* head2)
{
    Node* new_head = NULL;
    Node* new_head_cur = NULL;
    Node* curnode1 = head1;
    Node* curnode2 = head2;
    while(curnode1->next!=NULL && curnode2->next!=NULL)
    {
        if(new_head == NULL)
        {
            if(curnode1->info < curnode2->info)
            {
                new_head = curnode1;
                curnode1 = curnode1->next;
            }
            else
            {
                new_head = curnode2;
                curnode2 = curnode2->next;
            }
            new_head_cur = new_head;
        }
        else
        {
            if(curnode1->info < curnode2->info)
            {
                new_head_cur->next = curnode1;
                curnode1 = curnode1->next;
            }
            else
            {
                new_head_cur->next = curnode2;
                curnode2 = curnode2->next;
            }
            new_head_cur = new_head_cur->next;
        }
    }
    if(curnode1->next == NULL)
    {
        new_head_cur->next = curnode2;
        curnode2 = curnode2->next;
    }
    else if(curnode2->next == NULL)
    {
        new_head_cur->next = curnode1;
        curnode1 = curnode1->next;
    }
    return new_head;

    
}

int main() {
    Node* head1 = NULL;
    Node* head2 = NULL;

    head1 = initialize_list("sortA.txt");
    head2 = initialize_list("sortB.txt");

    cout << "Contents of the list A: ";
    print(head1);
    cout << "Contents of the list B: ";
    print(head2);

    Node* new_head = NULL;

    new_head = merge(head1, head2);

    cout << "This is the output of the new list after merging:" << endl;
    print(new_head);
    
    return 0;
}




