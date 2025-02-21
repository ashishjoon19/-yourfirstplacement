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