class Solution {
public:
    struct trienode{
        trienode* children[10];
    };
    trienode *root;
    trienode *getnode(){
        trienode *newnode=new trienode();
        for(int i=0;i<10;i++)
            newnode->children[i]=nullptr;
        return newnode;
    }
    int maxi;
    void insert(string str){
        trienode *crawl=root;
        for(auto it:str){
            if(crawl->children[it-'0']==nullptr)
                crawl->children[it-'0']=getnode();
            crawl=crawl->children[it-'0'];
        }
    }
    void search(string str){
        int cnt=0;
        trienode *crawl=root;
        for(auto it:str){
            if(crawl->children[it-'0']==nullptr)
                break;
            crawl=crawl->children[it-'0'];
            cnt++;
        }
        maxi=max(maxi,cnt);
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        root=getnode();
        maxi=0;
        for(auto it:arr1){
            string temp=to_string(it);
            insert(temp);
        }
        for(auto it:arr2){
            string temp=to_string(it);
            search(temp);
        }
        return maxi;
    }
};