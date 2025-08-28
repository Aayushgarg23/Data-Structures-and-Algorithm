/* I can do it in two ways first by taking the height function and then use that for diameter
Time Complexity = O(N²)
Because for every node (N), we call height() (which is O(N) in skewed tree)

Space Complexity = O(H) (recursion stack, where H = tree height)
*/

/*  Not a good approach and can give error sometimes
class Solution {
  public:
    int height(Node* node) {
        // code here
        queue<Node*> q;
        if(node==NULL) return -1;
        q.push(node);
        int height = 0;
        while(!q.empty())
        {
            height++;
            int level = int(q.size());
            for(int i=0;i<level;i++)
            {
                Node* front = q.front();
                q.pop();
                
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
                
            }
        }
        return height;
        
    }
    int diameter(Node* root) {
    if (!root) return 0;

    // Diameter through root
    int throughRoot = height(root->left) + height(root->right) + 1;

    // Diameter in left subtree
    int leftDia = diameter(root->left);

    // Diameter in right subtree
    int rightDia = diameter(root->right);

    return max(throughRoot, max(leftDia, rightDia));
}
    
};

*/


//optimised one y calculating height and diameter in single recursive call instead of Cal. height separatly
//Time = O(N)
//Space = O(H) where H is tree height (worst case O(N))

class Solution {
    int diameterVal = -1;  // member variable instead of passing as argument

    int solve(Node* root) {
        if (!root) return 0;

        int leftHeight = solve(root->left);
        int rightHeight = solve(root->right);

        diameterVal = max(diameterVal, leftHeight + rightHeight); // use left+right+1 for node based

        return 1 + max(leftHeight, rightHeight);
    }

public:
    int diameter(Node* root) {
        solve(root);
        return diameterVal;
    }
};

