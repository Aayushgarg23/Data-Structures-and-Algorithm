/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

// for more understanding analyze the top view sol file first
// same complexities as top view
class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // Your Code Here
        
        // code here
        vector<int>ans;
        queue<pair<Node*,int>>q;
        map<int,int> m; //can use unordered_map for reducing complexiity form NlogN to N but left->right order
        //will not come
        if(root==NULL)return ans;
        q.push(make_pair(root,0));
        
        while(!q.empty())
        {
            auto temp = q.front();
            q.pop();
            
            Node* front = temp.first;
            int a = temp.second;
            m[a] = front->data;
            
            if(front->left)q.push(make_pair(front->left,a-1));
            if(front->right)q.push(make_pair(front->right,a+1));
            
        }
        for(auto i : m)
        {
            ans.push_back(i.second); //using the map for pushing to ensure the left->right order
            // as map store in sorted order acc to key 
        }
        return ans;
    
    }
};