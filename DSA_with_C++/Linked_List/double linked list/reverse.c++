#include<iostream>
using namespace std;

/*
Ist method(Not optimal): make a stack (LIFO) and then use one traversal to copy all node value into it 
and then make one more traversal and then change the value of each node form the stack but it is not optimal 
it will only chnage the vaues of the node but will not reverse in true as the node next and previous are still
the same not reversed and this method can be bad fpr other complex data 

time: 2N
space: N


2nd Method(optimal): we can use In-Place reversal of linked list in such a way that we will make two nodes current temp
and will jsut traverse and will swap the next and previosu of each node

*/
class Node
{
    int data;
    Node* next;
    Node* previous;
    
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
        this->previous = NULL;
    }
}

void reverse(Node* &Head)
{
    Node* current = Head;
    Node* upcoming = NULL;
    Node* prev = NULL;
    while(current!=NULL)
    {
        prev->
        upcoming = current->next;
        current
        current->next = current->previous;
    }
}

int main()
{
    Node* Head = NULL;
    Node* tail = NULL;
    reverse(&head);
    print(head);
}