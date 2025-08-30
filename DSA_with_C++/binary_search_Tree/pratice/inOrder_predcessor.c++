/*************************************************************

    Following is the Binary Tree node structure
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

*************************************************************/


//Time: O(H) → where H = height of tree (O(log N) for balanced BST, O(N) for skewed)
//Space: O(1) (iterative, no recursion stack)
pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    // Write your code here.
   
    int pre = -1, suc = -1;
    TreeNode* curr = root;

    // Step 1: Find the key node
    while (curr && curr->data != key) {
        if (key < curr->data) {
            suc = curr->data; // possible successor
            curr = curr->left;
        } else {
            pre = curr->data; // possible predecessor
            curr = curr->right;
        }
    }

    if (!curr) return {pre, suc}; // key not found

    // Step 2: If left subtree exists, find max (predecessor)
    TreeNode* temp = curr->left;
    while (temp) {
        pre = temp->data;
        temp = temp->right;
    }

    // Step 3: If right subtree exists, find min (successor)
    temp = curr->right;
    while (temp) {
        suc = temp->data;
        temp = temp->left;
    }

    return {pre, suc};
}