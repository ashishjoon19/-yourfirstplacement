class Solution {
public:
    struct trienode{
        string val;
        trienode *children[26];
        bool isend;
    };
    int m,n;
    trienode *root;
    trienode* getnode(){
        trienode *newnode=new trienode();
        newnode->isend=false;
        for(int i=0;i<26;i++)
            newnode->children[i]=nullptr;
        return newnode;
    }
    void trie(){
        root=getnode();
    }
    void insert(string str){
        trienode* crawl=root;
        for(auto it:str){
            if(!crawl->children[it-'a'])
                crawl->children[it-'a']=getnode();
            crawl=crawl->children[it-'a'];
        }
        crawl->isend=true;
        crawl->val=str;
    }
    vector<string>res;
    void find(int i,int j,vector<vector<char>>& board,trienode *crawl){
        if(crawl->isend){
            res.push_back(crawl->val);
            crawl->isend=false;
        }
        char ch=board[i][j];
        board[i][j]='$';
        if(i+1 < m  && board[i+1][j]!='$' && crawl->children[board[i+1][j]-'a']){
            find(i+1,j,board,crawl->children[board[i+1][j]-'a']);
        }
         if(i-1 >=0 && board[i-1][j]!='$' && crawl->children[board[i-1][j]-'a']){
            find(i-1,j,board,crawl->children[board[i-1][j]-'a']);
        }
         if(j+1 < n && board[i][j+1]!='$' && crawl->children[board[i][j+1]-'a']){
            find(i,j+1,board,crawl->children[board[i][j+1]-'a']);
        }
         if(j-1 >=0 && board[i][j-1]!='$'  && crawl->children[board[i][j-1]-'a']){
            find(i,j-1,board,crawl->children[board[i][j-1]-'a']);
        }
        board[i][j]=ch;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        trie();
        m=board.size();
        n=board[0].size();
        for(auto it:words)
            insert(it);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(root->children[board[i][j]-'a']){
                    find(i,j,board,root->children[board[i][j]-'a']);
                }
            }
        }
        return res;
    }
};