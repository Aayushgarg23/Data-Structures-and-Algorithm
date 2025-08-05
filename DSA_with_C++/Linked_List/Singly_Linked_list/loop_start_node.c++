/* Using the Brute Force 
time: 
space:
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

