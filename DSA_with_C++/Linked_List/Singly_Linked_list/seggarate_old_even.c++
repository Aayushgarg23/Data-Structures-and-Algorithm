
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/* using the brute force method
time: O(2N) ~ O(N)
space: O(N)
*/

/*
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* temp = head;
        vector<int> store;
        while(temp!=NULL && temp->next!=NULL)
        {
            store.push_back(temp->val);
            temp= temp->next->next;
        }
        if(temp!=NULL) store.push_back(temp->val);
        temp = head->next;
        while(temp!=NULL && temp->next!=NULL)
        {
            store.push_back(temp->val);
            temp= temp->next->next;
        }
        if(temp!=NULL) store.push_back(temp->val);
        temp=head;
int i =0;
        while(temp!=NULL)
        {
    temp->val = store[i];
    i++;
    temp = temp->next;
        }
        return head;
    }
};
*/

/*  optimal method using the in place approach
time: O(N)
space: O(1)
*/


class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
       ListNode* odd = head;
       ListNode* even = head->next;
       ListNode* memo = head->next;
       while(even!=NULL && even->next!=NULL)
       {
        odd->next = odd->next->next;
        even->next= even->next->next;
        odd = odd->next;
        even = even->next;
       }
       odd->next = memo;
       return head;
    }
};