/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
}; */

// for more understanding analyze the top view sol file first
// same complexities as top view

class Solution {
  public:
    vector<int> rightView(Node *root) {
        //  Code here
        vector<int>ans;
        queue<pair<Node*,int>>q;
        map<int,int>m;
        
        if(!root)return ans;
        q.push(make_pair(root,0));
        
        while(!q.empty())
        {
            auto temp = q.front();
            q.pop();
            
            Node* head = temp.first;
            int level = temp.second;
            
            m[level] = head->data;
            
            if(head->left)q.push(make_pair(head->left,level+1));
            if(head->right)q.push(make_pair(head->right,level+1));
        }
        for(auto i:m)
        {
            ans.push_back(i.second);
        }
        return ans;
    }
};