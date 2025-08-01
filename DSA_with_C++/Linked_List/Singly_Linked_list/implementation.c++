#include<iostream>
using namespace std;


class Node
{
    public:
    int data;
    Node* next;

    Node(int data)
    {
        this -> data = data;
        this -> next= NULL;
    }
};


void insertAtHead(Node* &Head, int d)
{
    Node* temp= new Node(d);
    temp ->next = Head;
    Head = temp;
}

void print(Node* Head)
{
    while(head!=NULL)
    {
        cout << Head;
        Head= Head->next;
    }
}

int main()
{
    Node* node1 = new Node(10);
    cout << node1 -> data;
}