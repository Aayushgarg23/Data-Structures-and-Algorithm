/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    vector<vector<int>> verticalOrder(Node *root) {
        // Your code here
        map<int,map<int,vector<int>>> temp;
        vector<vector<int>>ans;
        queue<pair<Node*,pair<int,int>>>q; // we need to store the node and it's grid dimension
        if(root == NULL)
            return ans;
            
        q.push(make_pair(root, make_pair(0,0)));
        
        while(!q.empty())
        {
            pair<Node*,pair<int,int>> front = q.front();
            q.pop();
            
            Node* head = front.first;
            int hor = front.second.first;
            int lev = front.second.second;
            
            temp[hor][lev].push_back(head->data);
            
            if(head->left)q.push(make_pair(head->left,make_pair(hor-1,lev+1)));
            if(head->right)q.push(make_pair(head->right,make_pair(hor+1,lev+1)));
        }
        for(auto i : temp)
        {
            vector<int> collect;
            for(auto j : i.second)
            {
                for(auto k: j.second)
                {
                    collect.push_back(k);
                }
            }
            ans.push_back(collect);
        }
        return ans;
    }
};

/*
Time Complexity:𝑂(𝑁log⁡𝑁) + O(N){extra for traversal} = O(NlogN)
Space Complexity: 𝑂(𝑁)

Building the structure: O(N log N)
Traversal (your code): O(N)
Space Complexity: O(N) (maps + vectors to store nodes)
*/