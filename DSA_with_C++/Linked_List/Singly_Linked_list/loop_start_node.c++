/* Using the Brute Force 
time: O(N)
space: (N)
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
       unordered_map<ListNode*,int> record;
       while(head!=NULL)
       {
        if(record.find(head)!=record.end()) return head;
        record[head]=1;
        head = head->next;
       }
       return NULL;
    }
};
*/


// optimla one using the slow and fast method
// space: O(1)
// TIME: O(N) 

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!= NULL && fast->next!= NULL)
        {
            slow= slow->next;
            fast= fast->next->next;
            if(slow==fast)
            {
                slow = head;
                while(slow!=fast)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
return slow;
            }
        }
        return NULL;
    }
};