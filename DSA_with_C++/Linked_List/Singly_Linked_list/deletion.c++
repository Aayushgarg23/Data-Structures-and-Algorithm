/*

Node is given in input 

class Solution {
public:
    void deleteNode(ListNode* node) {
        // Overwrite data of next node on current node.
        node->val = node->next->val;
        // Make current node point to next of next node.
        node->next = node->next->next;
    }
};
*/


/*
position is given in input
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

*/


/*
val of a node is given 
void deleteByValue(Node* &head, int value) {
    if (head == NULL) return;

    // If head itself needs to be deleted
    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* current = head;
    Node* previous = NULL;

    while (current != NULL && current->data != value) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) return; // value not found

    previous->next = current->next;
    delete current;
}


*/