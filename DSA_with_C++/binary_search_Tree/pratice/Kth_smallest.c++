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

 //---------------------there are many others ways(including optimised) to solve this----------------------- */

 //time: O(N) or min(O(N), O(H+k))
 // sace: O(H) due to recursion
class Solution {
public:
     int inOrder(TreeNode* root, int &count, int k) {
        if (!root) return -1;  // base case
        // Traverse left
        int left = inOrder(root->left, count, k);
        if (left != -1) return left; // if answer already found in left subtree
        // Process current node
        count++;
        if (count == k) return root->val;
        // Traverse right
        return inOrder(root->right, count, k);
    }
 
    int kthSmallest(TreeNode* root, int k) {
        int count =0;
        return inOrder(root,count,k);
    }
};