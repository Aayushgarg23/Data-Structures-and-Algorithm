#include<iostream>
using namespace std;


class Node
{
    public:
    
    Node* previous;
    int data;
    Node* next;
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
        this->previous = NULL;
    }
};

void insertAtHead(Node* &Head, int d)
{
    Node* temp = new Node(d);
    temp->next = Head;
    Head->previous = temp;
    Head = temp;
}

void print(Node* Head)
{
    while(Head!=NULL)
    {
        cout << Head->data;
        Head = Head->next;
    }
    cout << endl;
}

int getLength(Node* Head)
{
    int len =0;
    while(Head!=NULL)
    {
        len++;
        Head = Head->next;
    }
    cout << endl;
    return len;
}


int main()
{
    Node* node1 = new Node(10);
    Node* Head = node1;
    print(node1);
    insertAtHead(Head,24);
    insertAtHead(Head,56);
    insertAtHead(Head,13);
    print(node1);
    cout<< getLength(Head);

}