struct Node {
    int val;
    Node *next;
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
    Node(int x, Node *next) : val(x), next(next) {}
};

/* using the brute force method
Time Complexity: O(L)+O(L-N), We are calculating the length of the linked list and then 
iterating up to the (L-N)th node of the linked list, where L is the total length of the list.

Space Complexity:  O(1), as we have not used any extra space.
*/

/*
class Solution {
public:
    Node* removeNthFromEnd(Node* head, int n) {
       int cnt = 0;
        Node* temp = head;
        while (temp != NULL) {
            cnt++;
            temp = temp->next;
        }

        // If removing head
        if (n == cnt) {
            Node* newHead = head->next;
            delete head;
            return newHead;
        }

        // Second pass: go to node before the one to delete
        temp = head;
        int start =1;
        while(start!=cnt-n){
        temp=temp->next;
        start++;
        }

        // Remove nth node from end
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;

        return head;
    }
};
*/

/* more optimal way to do this is using two pointer approach slow and fast
take two pointer and move first further the end node no. times and after that move both together so that it will be more optimal

time: O(N)
space: O(1)
*/

Node* DeleteNthNodefromEnd(Node* head, int N) {
    // Create two pointers, fastp and slowp
    Node* fastp = head;
    Node* slowp = head;

    // Move the fastp pointer N nodes ahead
    for (int i = 0; i < N; i++)
        fastp = fastp->next;

    // If fastp becomes NULL,
    // the Nth node from the end is the head
    if (fastp == NULL)
        return head->next;

    // Move both pointers until fastp reaches the end
    while (fastp->next != NULL) {
        fastp = fastp->next;
        slowp = slowp->next;
    }

    // Delete the Nth node from the end
    Node* delNode = slowp->next;
    slowp->next = slowp->next->next;
    delete delNode;
    return head;
}
