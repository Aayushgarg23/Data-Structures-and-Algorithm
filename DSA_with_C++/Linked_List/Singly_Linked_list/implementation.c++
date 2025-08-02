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
void insertAtPosition(Node* &head, Node* &tail, int position, int d)
{
    if(position==1) {
        
        insertAtHead(head, d);
        return;
    }
    Node* temp = head;

    int cnt =1;  // 1 2 3 4 5
    while(cnt<position-1)
    {
        temp = temp->next;
        cnt++;
    }

    // check for last node if we are adding in last then it require to update the tail as well

    if(temp->next == NULL)
    {
        insertAtTail(tail,d);
        return;
    }
    Node* pos = new Node(d);
    pos->next = temp->next;
    temp->next = pos;
}


void deletenode(Node* &head, int position)
{
    Node* previous = head;
    int cnt = 1;
    if(head==NULL)return;

    if(position==1)
    {
        head = head->next;
        return;
    }
    while(cnt<position-1) // 1 2 3 4 5
    {
        previous = previous->next;
        cnt++;
    }

    if(previous->next == NULL)
    {
        return;
    }
    Node* current = previous->next;
    Node* next1 = current->next;
    previous->next = next1; 
     
    delete current;
}

void print(Node* Head)
{
    while(Head!=NULL)
    {
        cout << Head->data<<" ";
        Head= Head->next;
    }
    cout << endl;
}
 

// reverse the Linked list
void reverse(Node* &head)
{
    if(head==NULL) return;

    Node* prev = NULL;
    Node* current = head;
    Node* upcoming = NULL;
    
    while(current!=NULL)
    {
       upcoming = current->next;
       current->next = prev;
       prev = current;
       current = upcoming;
    }
    head = prev;
}

int main()
{
    Node* node1 = new Node(10);
    Node* Head = node1;
    Node* tail = node1;
    cout << node1;
    insertAtTail(tail,13);
    insertAtTail(tail,50);
    print(Head);
    insertAtPosition(Head,tail, 4, 24);
    print(Head);
    deletenode(Head,2);
    print(Head);
    reverse(Head);
    cout << "Linked List after the reverse: ";
    print(Head);
}