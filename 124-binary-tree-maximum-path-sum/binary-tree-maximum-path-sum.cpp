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
private:
    int res;
    int find(TreeNode *root){
        if(!root)   return 0;
        int left=find(root->left);
        int right=find(root->right);
        res=max(res,left+right+root->val);
        if(max(left,right)+root->val < 0)
            return 0;
        return max(left,right)+root->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        res=INT_MIN;
        find(root);
        return res;
    }
};