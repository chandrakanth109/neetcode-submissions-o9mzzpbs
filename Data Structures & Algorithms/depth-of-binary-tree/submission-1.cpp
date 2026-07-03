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
    int maxi=0;
    int solve(TreeNode* root) {
        if(root==NULL){
            return 0;
        }

        int leftMax=solve(root->left);
        int rightMax=solve(root->right);

        maxi=max(leftMax,rightMax)+1;

        return max(leftMax,rightMax)+1;
    }
    int maxDepth(TreeNode* root) {
        solve(root);
        return maxi;
    }
};
