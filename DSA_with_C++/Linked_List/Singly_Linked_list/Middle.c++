
 #include<iostream>
 using namespace std;


 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
/* 
Time: O(N+N/2) ~ O(N)
Space: O(1)
*/

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int cnt = 0;
        ListNode* temp = head;
        while(Head!=NUll) // 1 2 3 4 
        {
            cnt++;
            head = head->next;
        }
        int mid = cnt/2 + 1;
        ListNode* temp = head;
        while(mid!=0)
        {
            mid--;
            if(mid==0) break;  // try to understand via if there only one element then it should 
                               //print head->val but if it will go to temp->next it will return NULL
            temp = temp->next;
        }
        return temp->val;
    }
};

/*
optimal approach by the tortosie and the Hare Algorithm
time: O(N/2)
space: O(1)
*/

void middleOptimal(Node* Head)
{
    if(Head->next==NULL)
    {
         cout<< Head->data;
    }
    Node* slow = Head;
    Node* fast = Head;

    while(fast!= NULL && fast->next!=NULL  )
    {
        
        slow= slow->next;
        fast = fast->next->next;
        
    }
    cout<< slow->data;
}