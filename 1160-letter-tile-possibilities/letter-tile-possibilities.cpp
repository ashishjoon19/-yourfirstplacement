class Solution {
private:
    set<string>s;
    void find(string tiles,int n,vector<int>vis,string res){
        if(res.length()>=1)
            s.insert(res);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                vis[i]=1;
                find(tiles,n,vis,res+tiles[i]);
                vis[i]=0;
            }
        }
    }
public:
    int numTilePossibilities(string tiles) {
        int n=tiles.length();
        vector<int>vis(n,0);
        string str="";
        find(tiles,n,vis,str);
        for(auto it:s)
            cout<<it<<endl;
        return s.size();
    }
};