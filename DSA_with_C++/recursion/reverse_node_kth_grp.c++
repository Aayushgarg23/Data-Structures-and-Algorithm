#include<bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// https://leetcode.com/problems/reverse-nodes-in-k-group/description/

/*
I use a dummy node and process the list in groups of k. 
For each group, I first verify that k nodes exist, then reverse the pointers
in-place and reconnect the group with the rest of the list. 
This achieves O(n) time and O(1) space
*/

// iterative solution
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
       
        if(!head || k<=1) return head;

        ListNode dummy(0);

        ListNode *prevgrp = &dummy;
        dummy.next = head;

        while(true)
        {
            ListNode* kth = prevgrp;

            for(int i=0;i<k;i++)
            {
                if(kth)kth = kth->next;
            }
            if(!kth) break;


            ListNode* grpnext = kth->next;
            ListNode* prev = grpnext;
            ListNode* curr = prevgrp->next;

            while(curr!= grpnext)
            {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev =curr;
                curr = temp;
            }

            ListNode* temp  = prevgrp->next;
            prevgrp-> next = kth; // to coneect the dummy with the new starting node of the group
            prevgrp = temp;

        }
    }
};


// Recursive solution
// time complexity: O(n) where n is the number of nodes in the list

ListNode* reverseKGroup(ListNode* head, int k) {
        // 1️⃣ Check if k nodes exist
        ListNode* temp = head;
        for (int i = 0; i < k; i++) {
            if (temp == NULL) return head;
            temp = temp->next;
        }

        // 2️⃣ Reverse first k nodes
        ListNode* prev = NULL;
        ListNode* curr = head;

        for (int i = 0; i < k; i++) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // 3️⃣ Recursive call for remaining list
        head->next = reverseKGroup(curr, k);

        // 4️⃣ New head of this group
        return prev;
    }


int main()
{
    int n, k;
    cin >> n >> k;
    ListNode* head = new ListNode(1);
    ListNode* current = head;
    for (int i = 2; i <= n; i++) {
        current->next = new ListNode(i);
        current = current->next;
    }
    Solution s;
    head = s.reverseKGroup(head, k);
    current = head;
    while (current) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;

}

