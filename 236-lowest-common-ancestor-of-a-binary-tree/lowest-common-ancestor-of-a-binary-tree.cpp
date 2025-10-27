/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    int flag;
    vector<TreeNode*>p_path;
    vector<TreeNode*>q_path;
    void find(TreeNode* root,vector<TreeNode*>&path,TreeNode* &node){
        if(!root || flag)   return;
        path.push_back(root);
        if(root==node){
            flag=1;
            return ;
        }
        find(root->left,path,node);
        find(root->right,path,node);
        if(!flag)   path.pop_back();
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        flag=0;
        find(root,p_path,p);
        flag=0;
        find(root,q_path,q);
        int i=0;
        while(i<p_path.size() && i<q_path.size()){
            if(p_path[i]==q_path[i]){
                i++;
            }
            else{
                return p_path[i-1];
            }
        }
        return p_path[i-1];
    }
};