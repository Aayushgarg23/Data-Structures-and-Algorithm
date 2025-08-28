#include<iostream>
#include<queue>
using namespace std;
 

/*
recursive approach
Time: O(N) where N = min(size of tree1, size of tree2)
Space: O(H) recursion stack (worst case H = N for skewed tree, best H = logN for balanced).
*/

class Solution {
  public:
    bool isIdentical(Node* root1, Node* root2) {
        // code here
        if(root1==NULL && root2==NULL)return true;
        if(root1==NULL || root2==NULL)return false;
        if(root1->data != root2->data) return false;
        return (isIdentical(root1->left,root2->left)&&
        isIdentical(root1->right,root2->right));
    }
};

/*
with the help of the level order
Time: O(N) same as recursion
Space: O(W) where W = max width of tree (at worst O(N) for a complete tree)
*/
 bool isIdentical(Node* p, Node* q) {
        queue<Node*> q1, q2;
        q1.push(p);
        q2.push(q);

        while (!q1.empty() && !q2.empty()) {
            Node* n1 = q1.front(); q1.pop();
            Node* n2 = q2.front(); q2.pop();

            if (!n1 && !n2) continue;      // both NULL -> ok
            if (!n1 || !n2) return false;  // mismatch
            if (n1->data != n2->data) return false;

            q1.push(n1->left);
            q1.push(n1->right);
            q2.push(n2->left);
            q2.push(n2->right);
        }

        return q1.empty() && q2.empty();  // both processed
    }