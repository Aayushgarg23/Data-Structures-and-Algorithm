/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        // code here
        vector<int>ans;
        queue<pair<Node*,int>>q;
        map<int,int> m;
        if(root==NULL)return ans;
        q.push(make_pair(root,0));
        
        while(!q.empty())
        {
            auto temp = q.front();
            q.pop();
            
            Node* front = temp.first;
            int a = temp.second;
            if(!(m.find(a)!=m.end())){
            m[a] = front->data;}
            
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