#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

vector<vector<int>> zigZagLevelTraversal(TreeNode* root)
{
    if(root==NULL) return {};

    queue<TreeNode*>q;

    vector<vector<int>> ans;

    q.push(root);
    
    int rightleft =-1;

    while(!q.empty())
    {
        int n = q.size();

        vector<int> temp(n);

        for(int i=0;i<n;i++)
        {

            TreeNode* front = q.front();
            q.pop();

            int index = rightleft == -1 ? i : n-1-i;
            temp[index] = front->val;
            if(front->left)q.push(front->left);
            if(front->right)q.push(front->right);
        }
            rightleft*= -1;
            ans.push_back(temp);
        
    }

}