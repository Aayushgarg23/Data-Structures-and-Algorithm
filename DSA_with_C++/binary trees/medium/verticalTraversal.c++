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
        vector<vector<int>> ans;
        queue<pair<TreeNode*,pair<int,int>>> q;
        if(!root) return ans;
            
        q.push({root, {0,0}});
        
        while(!q.empty()) {
            auto front = q.front();
            q.pop();
            
            TreeNode* head = front.first;
            int hor = front.second.first;
            int lev = front.second.second;
            
            temp[hor][lev].push_back(head->val);
            
            if(head->left)  q.push({head->left,  {hor-1, lev+1}});
            if(head->right) q.push({head->right, {hor+1, lev+1}});
        }
        
        for(auto &i : temp) {
            vector<int> collect;
            for(auto &j : i.second) {
                auto &nodes = j.second;
                sort(nodes.begin(), nodes.end()); // ✅ sort same level nodes
                // sorting is necessary bcz at some platform it will give error due to value position change
                for(auto k: nodes) {
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