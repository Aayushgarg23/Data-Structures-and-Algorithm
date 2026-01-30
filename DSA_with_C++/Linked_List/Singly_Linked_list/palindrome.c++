/* using the brute force method by using aa stack (LIFO) by storing last element to the top and then compare
time: 2*O(N)
space: O(N)

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> record;
        ListNode* temp =head;
        while(temp!=NULL)
        {
            record.push(temp->val);
            temp = temp->next;
        }
        temp = head;
        while(temp!=NULL)
        {
            if(temp->val!=record.top()) return false;
             record.pop();
             temp= temp->next;
        }
        return true;
    }
};



/*
can do by slow and fast method also so that we can save the time
1 2 3 3 2 1 

1. here find mid or the first mid (in even istead of second like mod element ques)
2.reverse the second half and make a new node
3 thn traverse again form starting to end and then keep matching first half with second half 
4. if there is any unmatched then it will return false else return true
5. after matching again reverse the original list so that the bonds will not get effected

*/
class Solution {
    private:
    ListNode* isPalindromeSlowFast(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow= slow->next;
            fast= fast->next->next;
        }
        return slow;
        
    }
}