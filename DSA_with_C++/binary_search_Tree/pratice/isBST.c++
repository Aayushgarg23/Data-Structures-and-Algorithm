/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


class Solution {
public:
    bool isBST(TreeNode* root,long long min, long long max)
    {
        if(!root) return true;

        if(root->val > min && root->val < max)
        {
            bool left=isBST(root->left,min,root->val);
            bool right =isBST(root->right,root->val,max);
            return left && right;
        }
        else return false;
        
    }
    bool isValidBST(TreeNode* root) {
        return isBST(root,LLONG_MIN,LLONG_MAX); // as it can be equal to int_max or min as well and equal not allowed
    }
};



bool inorderCheck(Node* root, long long &prev) {
    if (!root) return true;

    if (!inorderCheck(root->left, prev)) return false;

    if (root->val <= prev) return false;  // not strictly increasing
    prev = root->val;

    return inorderCheck(root->right, prev);
}

bool isValidBST(Node* root) {
    long long prev = LLONG_MIN;
    return inorderCheck(root, prev);
}


// both will take same complexity
//time: O(N)
//space: O(H) {H = height of tree}