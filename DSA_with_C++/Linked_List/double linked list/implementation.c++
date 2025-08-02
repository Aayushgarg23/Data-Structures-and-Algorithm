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


// Insert new node at Head
void insertAtHead(Node* &Head, int d)
{
    Node* temp = new Node(d);
    temp->next = Head;
    Head->previous = temp;
    Head = temp;
}

//Insert new Node at tail

void insertAtTail(Node* &tail, int d)
{
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}


// Insert at any position

void insertAtPosition(Node* Head, int position, int d)
{
    Node* temp = new Node(d);
    
}
//traversing a linked list
void print(Node* Head)
{
    while(Head!=NULL)
    {
        cout << Head->data << " ";
        Head = Head->next;
    }
    cout << endl;
}

// getting length of the linked list 
int getLength(Node* Head)
{
    int len =0;
    while(Head!=NULL)
    {
        len++;
        Head = Head->next;
    }
    return len;
}


int main()
{
    Node* node1 = new Node(10);
    Node* Head = node1;
    Node* tail = node1;
    cout << "First Node created: ";
    print(Head);
    insertAtHead(Head,24);
    insertAtHead(Head,56);
    insertAtHead(Head,13);
    cout << "After adding elements on head: ";
    print(Head);
    cout << "Length after adding some new elements on head: "<<  getLength(Head);

    insertAtTail(tail,23);
    insertAtTail(tail,45);
    insertAtTail(tail,89);
    cout << "After adding elements on tail: ";
    print(Head);
}