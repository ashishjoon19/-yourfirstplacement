class Solution {
public:
    TreeNode* recoverFromPreorder(string s) {
        int num=0,i=0;
        stack<pair<int,TreeNode*>>st;
        while(i<s.length() && s[i]!='-'){
            num=num*10+(s[i]-'0');
            i++;
        }
        TreeNode*root=new TreeNode(num);
        TreeNode* main=root;
        st.push({0,root});
        int left=0;
        for(i=i;i<s.length();i++){
            int cnt=0;
            while(s[i]=='-'){
                cnt++;
                i++;
            }
            int num=0;
            while(i<s.length() && s[i]!='-'){
                num=num*10+(s[i]-'0');
                i++;
            }
            i--;
            while((st.top()).first >= cnt){
                st.pop();
            }
            TreeNode* newnode=new TreeNode(num);
            TreeNode* par=st.top().second;
            if(!par->left)
                par->left=newnode;
            else
                par->right=newnode;
            st.push({cnt,newnode});
        }
        return main;
    }
};