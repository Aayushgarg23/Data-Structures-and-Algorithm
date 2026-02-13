#include<bits/stdc++.h>
using namespace std;


// leetcode 109. Convert Sorted List to Binary Search Tree

class ListNode {
  public:
    int val;
    ListNode* next;

    ListNode(int val) {
        val = val;
        next = NULL;
    }
};

class TreeNode {
  public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        val = val;
        left = NULL;
        right = NULL;
    }
};

// convert LL->vector->BT
// Time Complexity: O(N) + O(N) = O(N)
// Space Complexity: O(N) + O(N) = O(N)

class Solution {
private:
    TreeNode* solve(vector<int> arr, int s, int e)
    {
        if(s>e) return NULL;

        int mid = s + (e-s)/2;

        TreeNode* root = new TreeNode(arr[mid]);

        root->left = solve(arr,s,mid-1);

        root->right = solve(arr,mid+1,e);

        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return nullptr;
        vector<int>arr;
        ListNode* temp = head;
        while(temp)
        {
            arr.push_back(temp->val);
            temp = temp->next;
        }

       return solve(arr,0,arr.size()-1);
    }
};


// optimla approach
// using the property of in-order traversal of BST is sorted order as we are given sorted LL so we can directly use the LL to construct the BST
// Time Complexity: O(N) {for traversal of LL and constructing the BST}
// Space Complexity: O(logN) {for recursion stack}

class Solution {
ListNode* curr;
TreeNode* solve(int start, int end)
{
    if(start>end) return NULL;

    int mid = start+ (end-start)/2;

    TreeNode* left = solve(start,mid-1);

    TreeNode* root = new TreeNode(curr->val);

    curr = curr->next;

   root->left = left;

   root->right = solve(mid+1,end);

   return root; 

}
public:
    TreeNode* sortedListToBST(ListNode* head) {
     curr = head;
    int n = 0;
    while(head)
    {
        n++;
        head= head->next;
    }

    return solve(0,n-1);
    }
};

// better than the slow-fast approach
// complxity in slow-fast:
// Time Complexity: O(NlogN) {for finding the mid element and constructing the BST}
// Space Complexity: O(logN) {for recursion stack}
