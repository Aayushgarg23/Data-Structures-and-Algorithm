/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

/*
Time Complexity: O(N) + O(N log N) = O(N log N)

Traversal → Each node is processed once ⇒ O(N)
Map operations → map is balanced BST → insert/find = O(logM) :-> {M = number of unique HDs ≤ N}
So total map operations = O(N logN)

Space Complexity: O(N)

Queue (for BFS) → O(N) in worst case (skewed tree).
Map → Stores at most N HDs ⇒ O(N).
Answer vector → Stores at most N nodes ⇒ O(N).
*/
class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
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