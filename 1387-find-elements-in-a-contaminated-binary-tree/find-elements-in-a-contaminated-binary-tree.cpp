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
class FindElements {
private:
    TreeNode *main;
    void recover(TreeNode *root,int x){
        if(!root) return;
        root->val=x;
        if(root->left) recover(root->left,2*x+1);
        if(root->right) recover(root->right,2*x+2);
    }
    void contaminate(TreeNode *root){
        if(!root) return;
        root->val=-1;
        if(root->left) contaminate(root->left);
        if(root->right) contaminate(root->right);
    }
    bool find2(TreeNode *root,int &target){
        if(!root) return false;
        if(root->val==target) return true;
        bool flag=false;
        if(root->left) flag|=find2(root->left,target);
        if(root->right) flag|=find2(root->right,target);
        return flag;
    }
public:
    FindElements(TreeNode* root) {
        main=root;
        contaminate(root);
        recover(root,0);
    }
    
    bool find(int target) {
        return find2(main,target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */