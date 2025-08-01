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

void insertAtTail(Node* &tail,int d)
{
    Node* temp = new Node( d);
    tail->next = temp;
    tail = tail->next;
}


void print(Node* &Head)
{
    while(Head!=NULL)
    {
        cout << Head->data<<" ";
        Head= Head->next;
    }
}
 
int main()
{
    Node* node1 = new Node(10);
    Node* Head = node1;
    Node* tail = node1;
    insertAtTail(tail,13);
    insertAtTail(tail,50);
    print(Head);
}