class Trie {
public:
    struct trienode{
        bool isend;
        trienode * children[26];
    };
    trienode* getnode(){
        trienode *newnode= new trienode();
        newnode->isend=false;
        for(int i=0;i<26;i++)
            newnode->children[i]=nullptr;
        return newnode;
    }
    trienode *root;
    Trie() {
        root=getnode();
    }
    
    void insert(string word) {
        trienode *crawl=root;
        for(auto it:word){
            if(crawl->children[it-'a']==nullptr)//new node banana h
                crawl->children[it-'a']=getnode();
            crawl=crawl->children[it-'a'];
        }
        crawl->isend=true;
    }
    
    bool search(string word) {
        trienode *crawl=root;
        for(auto it:word){
            if(crawl->children[it-'a']==nullptr)//word nhi paya
                return false;
            crawl=crawl->children[it-'a'];
        }
        if(crawl!=nullptr && crawl->isend==true)
            return true;
        return false;
    }
    
    bool startsWith(string word) {
        trienode *crawl=root;
        for(auto it:word){
            if(crawl->children[it-'a']==nullptr)
                return false;
            crawl=crawl->children[it-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */