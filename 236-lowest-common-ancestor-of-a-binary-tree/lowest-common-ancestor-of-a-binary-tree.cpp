class Solution {
private:
    map<int,TreeNode*>add;
    void givepaths(TreeNode* root,vector<int>&vec,int &target,bool &flag){
        if(!root || flag) return;
        add[root->val]=root;
        vec.push_back(root->val);
        if(target==root->val){
            flag=true;
            return;
        }
        givepaths(root->left,vec,target,flag);
        if(flag) return;
        givepaths(root->right,vec,target,flag);
        if(flag) return;
        int idx=vec.size()-1;
        vec.erase(vec.begin()+idx);
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool flag=false;
        vector<int>path1;
        vector<int>path2;
        int val1=p->val;
        int val2=q->val;
        givepaths(root,path1,val1,flag);
        flag=false;
        givepaths(root,path2,val2,flag);
        map<int,int>mapi;
        int m=path1.size();
        int n=path2.size();
        cout<<"m="<<m<<",n="<<n<<endl;
        int siz=m<n?m:n;
        if(siz==n){
            for(int i=0;i<n;i++){
                mapi[path2[i]]=i;
                cout<<path2[i]<<"  "<<i<<endl;
            }
            for(int i=m-1;i>=0;i--){
                if(mapi.find(path1[i])!=mapi.end()){
                    return add[path1[i]];
                }
            }
        }
        else{
            for(int i=0;i<m;i++){
                mapi[path1[i]]=i;
            }
            for(int i=n-1;i>=0;i--){
                if(mapi.find(path2[i])!=mapi.end()){
                    return add[path2[i]];
                }
            }
        }
        return root;
    }
};