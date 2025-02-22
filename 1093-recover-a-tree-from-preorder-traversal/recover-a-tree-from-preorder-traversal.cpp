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
// class Solution {
// public:
//     TreeNode* recoverFromPreorder(string s) {
//         int i = 0, n = s.length();
//         stack<pair<int, TreeNode*>> st;
        
//         // Read the first number (root value)
//         int num = 0;
//         while (i < n && isdigit(s[i])) {
//             num = num * 10 + (s[i] - '0');
//             i++;
//         }
        
//         TreeNode* root = new TreeNode(num);
//         st.push({0, root});
        
//         while (i < n) {
//             int depth = 0;
            
//             // Count dashes (depth level)
//             while (i < n && s[i] == '-') {
//                 depth++;
//                 i++;
//             }
            
//             // Read the number (node value)
//             int num = 0;
//             while (i < n && isdigit(s[i])) {
//                 num = num * 10 + (s[i] - '0');
//                 i++;
//             }
            
//             // Ensure the correct depth level by popping stack
//             while (!st.empty() && st.top().first >= depth) {
//                 st.pop();
//             }
            
//             // Create a new node
//             TreeNode* newNode = new TreeNode(num);
//             TreeNode* parent = st.top().second;

//             // Attach the node
//             if (!parent->left) {
//                 parent->left = newNode;
//             } else {
//                 parent->right = newNode;
//             }

//             // Push the new node onto the stack
//             st.push({depth, newNode});
//         }
        
//         return root;
//     }
// };
