#include<iostream>
using namespace std;
#include<map>

class Node
{
    public:
    int data;
    Node* next;

    Node(int data)
    {
        this -> data = data;
        this -> next= NULL;
    }
};

// time: O(N)  bcz search and insert in hash maps take O(1) not log(N) like in the map
// space: O(N)

/*
int lengthLoop(Node* Head)
{
    int temp = 1;
    unordered_map<Node*,int>record;

    while(Head!=NULL)
    {
        if(record.find(Head)!=record.end())
        {
            return temp - record[Head]; // 1 2 3 4 5 3
        }

        record[Head] = temp;
        Head = Head->next;
        temp++;
    }
}
*/

/* optimal way using the slow and fast method
time: O(N)
space: O(1)
*/
int lengthLoop(Node* head)
{
    Node* fast =head;
    Node* slow =head;

    while(fast = NULL && fast->next!=NULL)
    {
        slow= slow->next;
        fast = fast->next->next;
        if(slow==fast)
        {
            int cnt = 1;
            fast = fast->next;
            while(fast!=slow)
            {
                cnt++;
                fast =fast->next;
            }
            return cnt;
        }
        
    }
    return 0;
}