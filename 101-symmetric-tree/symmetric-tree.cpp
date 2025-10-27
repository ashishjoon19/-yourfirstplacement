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
    bool res;
    void find(TreeNode* root1,TreeNode* root2){
        if(!res)    return;
        if(root1 && root2){
            if(root1->val!=root2->val){
                res=false;
                return;
            }
            find(root1->left,root2->right);
            find(root1->right,root2->left);
        }
        else if(root1==nullptr && root2==nullptr){
            return;
        }
        else{
            res=false;
            return;
        }
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(!root)   return true;
        res=true;
        if(root->left==nullptr && root->right==nullptr) return true;
        find(root->left,root->right);
        return res;
    }
};