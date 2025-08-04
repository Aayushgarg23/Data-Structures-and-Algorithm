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
void insertAtHead(Node* &Head, Node* &tail, int d)
{
    if(Head==NULL) // in case there is no first node and then we are doing this
    {
        Node* temp = new Node(d);
        Head = temp;
        tail = temp;
    }
    else
    {    Node* temp = new Node(d);
    temp->next = Head;
    Head->previous = temp;
    Head = temp;
}}

//Insert new Node at tail

void insertAtTail(Node* &head,Node* &tail, int d)
{
    if(tail==NULL)
    {
         Node* temp = new Node(d);
         tail = temp;
         head = temp;
    }
    else
    {Node* temp = new Node(d);
    tail->next = temp;
    temp->previous = tail;
    tail = temp;}
}


// Insert at any position

void insertAtPosition(Node* &Head, Node* &tail, int position, int d)
{
    if(position==1)
    {
        insertAtHead(Head,tail,d);
        return;
    }
    Node* temp = Head;
    int cnt=1;
    while(cnt< position-1) // 1 2 3 4 5 
    {
        temp = temp->next;
        cnt++;
    }
    if(temp->next == NULL)
    {
        insertAtTail(Head,tail,d);
        return;
    }

    Node* pos = new Node(d);
    pos->next = temp->next;
    pos->previous = temp;
    temp->next->previous = pos;
    temp->next = pos;
    
}

// Deleting a Node according to the position
void deleteNode(Node* &head, int position) {
    if (head == NULL) return;

    // Case 1: Deleting head
    if (position == 1) {
        Node* temp = head;
        head = head->next;
        if (head != NULL) {
            head->previous = NULL;
        }
        delete temp;
        return;
    }

    // Traverse to position-1
    Node* prev = head;
    int cnt = 1;
    while (cnt < position - 1 && prev->next != NULL) {
        prev = prev->next;
        cnt++;
    }

    // Edge case: Invalid position
    if (prev->next == NULL) return;

    Node* current = prev->next;
    prev->next = current->next;
    if (current->next != NULL) {
        current->next->previous = prev;
    }
    delete current;
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

void reverse(Node* &Head)
{
    Node* current = Head;
    //Node* upcoming = NULL;
    Node* prev = NULL;
    while(current!=NULL)
    {
        prev = current->previous;
        current->previous = current->next;
        current->next = prev;
        current = current->previous;
    }
    Head = prev->previous; // as current will become null after last iteration of while loop and then for goign back we will need to go to the 
    // last node wiht the help of the prev.back which will pint to the last node
}
int main()
{
    Node* Head = NULL;
    Node* tail = NULL;
    cout << "First Node created: ";
    print(Head);
    insertAtHead(Head,tail,24);
    insertAtHead(Head,tail,56);
    insertAtHead(Head,tail,13);
    cout << "After adding elements on head: ";
    print(Head);
    cout << "Length after adding some new elements on head: "<<  getLength(Head);

    insertAtTail(Head,tail,23);
    insertAtTail(Head,tail,45);
    insertAtTail(Head,tail,89);
    cout << "After adding elements on tail: ";
    print(Head);

    insertAtPosition(Head,tail,2,48);
    insertAtPosition(Head,tail,1,31);
    insertAtPosition(Head,tail,getLength(Head),43);
    cout << "Printing after some middle implementation case I: ";
    print(Head);
    insertAtPosition(Head,tail,5,27);
    insertAtPosition(Head,tail,getLength(Head)+1,94); // use +1 if want to print in the last ot the insertAtTail
    cout << "After adding elemtnets at middle positions: ";
    print(Head);

    deleteNode(Head,1);
    deleteNode(Head,2);
    deleteNode(Head,getLength(Head));
    deleteNode(Head,2);
    cout << "List After Deletion: ";
    print(Head);
    cout << "Trying to Delete the size+1th element: ";
    deleteNode(Head,getLength(Head)+1); // notihng will happen
    print(Head);
    reverse(Head);
    cout << "Linked List after the reverse: ";
    print(Head);

}