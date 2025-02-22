class Solution {
private:
    int m,n;
    struct trie{
        string str;
        bool isend;
        trie *children[26];
    };
    trie *root;
    trie *getnode(){
        trie *newnode=new trie();
        newnode->isend=false;
        for(int i=0;i<26;i++)
            newnode->children[i]=nullptr;
        return newnode;
    }
    void insert(string &word){
        trie *crawl=root;
        for(auto it:word){
            if(!crawl->children[it-'a'])
                crawl->children[it-'a']=getnode();
            crawl=crawl->children[it-'a'];
        }
        crawl->isend=true;
        crawl->str=word;
    }
    vector<string>result;
    void find(int i,int j,vector<vector<char>>& board,vector<vector<int>>&vis,trie *crawl){
        if(i >= m || j>= n || i<0 || j<0) return;

        vis[i][j]=1;
        if(crawl->isend) {
            result.push_back(crawl->str);
            crawl->isend=false;
        }
        if(i+1 < m && vis[i+1][j]==0 && crawl->children[board[i+1][j]-'a']!=nullptr){
            find(i+1,j,board,vis,crawl->children[board[i+1][j]-'a']);
        }
        if(i-1 >= 0 && vis[i-1][j]==0 && crawl->children[board[i-1][j]-'a']!=nullptr){
            find(i-1,j,board,vis,crawl->children[board[i-1][j]-'a']);
        }
        if(j+1 < n && vis[i][j+1]==0 && crawl->children[board[i][j+1]-'a']!=nullptr){
            find(i,j+1,board,vis,crawl->children[board[i][j+1]-'a']);
        }
        if(j-1 >= 0 && vis[i][j-1]==0 && crawl->children[board[i][j-1]-'a']!=nullptr){
            find(i,j-1,board,vis,crawl->children[board[i][j-1]-'a']);
        }
        vis[i][j]=0;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root=getnode();
        for(auto it:words)
            insert(it);
        m=board.size(),n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(root->children[board[i][j]-'a']!=nullptr){
                    vector<vector<int>>vis(m,vector<int>(n,0));
                    find(i,j,board,vis,root->children[board[i][j]-'a']);
                }
            }
        }
        // vector<string>res;
        // for(auto it:result)
        //     res.push_back(it);
        return result;
    }
};