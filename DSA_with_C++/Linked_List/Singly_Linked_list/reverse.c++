#include<iostream>
using namespace std;

class Node
{
    int data;
    Node* next;

    Node(int d)
    {
        this-> data = d;
        this->next = NULL;
    }
};

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
    Node* Head = NULL;
    Node* tail = NULL;
    reverse(&head);
    print(head);
}