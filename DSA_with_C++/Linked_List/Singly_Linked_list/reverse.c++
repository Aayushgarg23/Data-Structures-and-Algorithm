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

/* cab be done using brute force method as well by using a stack which will keep inserting element of the linked list at the last of stack
and then when I will keep traversing again until it's Linked list NULL and replace data value and

time: 2O(N)---------it will use two time traversal
space: O(N)---------a stack memory
*/


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