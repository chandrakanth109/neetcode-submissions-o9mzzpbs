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
    int maxi=INT_MIN;
    int solve(TreeNode* root) {
        if(root==NULL){
            return 0;
        }

        int leftMax=solve(root->left);
        int rightMax=solve(root->right);

        maxi=max(maxi,leftMax+rightMax);

        return max(leftMax,rightMax)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        solve(root);

        return maxi;
    }
};
