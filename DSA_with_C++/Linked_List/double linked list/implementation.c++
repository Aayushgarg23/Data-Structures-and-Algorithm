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

void print(Node* Head)
{
    while(Head!=NULL)
    {
        cout << Head->data;
        Head = Head->next;
    }
    cout << endl;
}

int main()
{
    Node* node1 = new Node(10);
    print(node1);

}