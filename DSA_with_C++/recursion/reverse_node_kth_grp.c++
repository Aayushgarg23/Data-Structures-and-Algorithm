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

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k <= 1) return head;

        ListNode dummy(0);
        dummy.next = head;

        ListNode* groupPrev = &dummy;

        while (true) {
            // Find the k-th node
            ListNode* kth = groupPrev;
            for (int i = 0; i < k && kth; i++) {
                kth = kth->next;
            }
            if (!kth) break;

            // Reverse the group
            ListNode* groupNext = kth->next;
            ListNode* prev = groupNext;
            ListNode* curr = groupPrev->next;

            while (curr != groupNext) {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            // Connect with previous part
            ListNode* temp = groupPrev->next;
            groupPrev->next = kth;
            groupPrev = temp;
        }

        return dummy.next;
    }
};



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

