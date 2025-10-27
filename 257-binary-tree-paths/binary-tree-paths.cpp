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
    string add;
    vector<string>res;
    void find(TreeNode* root,string s){
        if(!root){
            return;
        }
        if(root->left==nullptr && root->right==nullptr){
            s+=add+to_string(root->val);
            res.push_back(s);
            return;
        }
        if(s.length()>0)
            s+=add;
        s+=to_string(root->val);
        if(root->left)
            find(root->left,s);
        if(root->right)
            find(root->right,s);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        add="->";
        if(!root)   return res;
        if(root->left==nullptr && root->right==nullptr){
            string s=to_string(root->val);
            res.push_back(s);
            return res;
        }
        find(root,"");
        return res;
    }
};