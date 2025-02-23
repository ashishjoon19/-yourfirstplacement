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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n=preorder.size();
        stack<pair<int,TreeNode*>>st;
        TreeNode *root=new TreeNode(preorder[0]);
        st.push({preorder[0],root});
        set<int>vis;
        vis.insert(preorder[0]);
        int i=1;
        while(i<n && preorder[i]!=postorder[0]){
            TreeNode* newnode=new TreeNode(preorder[i]);
            (st.top().second)->left=newnode;
            st.push({preorder[i],newnode});
            vis.insert(preorder[i]);
            i++;
        }
        int j=0;
        while(i<n && j<n){
            if(preorder[i]==postorder[j]){
                TreeNode* newnode=new TreeNode(preorder[i]);
                TreeNode* crawl=st.top().second;
                if(crawl->left == nullptr) 
                    crawl->left=newnode;
                else
                    crawl->right=newnode;
                i++,j++;
            }
            else if(vis.find(postorder[j])!=vis.end()){
                st.pop();
                j++;
            }
            else{
                TreeNode* newnode=new TreeNode(preorder[i]);
                TreeNode* crawl=st.top().second;
                if(crawl->left == nullptr) 
                    crawl->left=newnode;
                else 
                    crawl->right=newnode;
                st.push({preorder[i],newnode});
                vis.insert(preorder[i]);
                i++;
            }
        }
        return root;
    }
};