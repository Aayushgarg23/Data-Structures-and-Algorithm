#include<bits/stdc++.h>
using namespace std;



// leetcode 95. Unique Binary Trees I
class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    map<pair<int,int>, vector<TreeNode*>> dp;

    vector<TreeNode*> build(int start, int end){

        if(start > end) return {NULL};

        if(dp.count({start,end}))
            return dp[{start,end}];

        vector<TreeNode*> trees;

        for(int root=start; root<=end; root++){

            auto leftTrees = build(start, root-1);
            auto rightTrees = build(root+1, end);

            for(auto left : leftTrees){
                for(auto right : rightTrees){
                    TreeNode* node = new TreeNode(root);
                    node->left = left;
                    node->right = right;
                    trees.push_back(node);
                }
            }
        }

        return dp[{start,end}] = trees;
    }

    vector<TreeNode*> generateTrees(int n) {
        return build(1,n);
    }
};
