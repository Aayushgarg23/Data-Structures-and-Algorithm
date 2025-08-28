class Solution {
    int check(Node* root) {
        if (!root) return 0;

        int left = check(root->left);
        if (left == -1) return -1; // already unbalanced

        int right = check(root->right);
        if (right == -1) return -1;

        if (left - right > 1 || right-left >1) return -1; // imbalance

        return 1 + max(left, right);
    }

public:
    bool isBalanced(Node* root) {
        return check(root) != -1;
    }
};
