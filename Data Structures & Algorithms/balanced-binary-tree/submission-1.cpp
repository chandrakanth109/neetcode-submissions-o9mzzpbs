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
    bool ans=true;
    int solve(TreeNode* root) {
        if(root==NULL){
            return 0;
        }

        int maxLeft = solve(root->left);
        int maxRight = solve(root->right);

        if(abs(maxLeft-maxRight) > 1){
            ans=false;
        }

        return max(maxLeft,maxRight)+1;

    }
    bool isBalanced(TreeNode* root) {
        solve(root);
        return ans;
    }
};
