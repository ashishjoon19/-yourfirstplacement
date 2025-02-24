class Solution {
private:
    int res;
    map<int,int>m;
    void setbob(vector<vector<int>>& graph,int bob,vector<int>&vis,int step,bool &flag){
        if(flag) return;
        if(bob==0){
            m[0]=step;
            flag=true;
            return;
        }
        m[bob]=step;
        for(auto it:graph[bob]){
            if(!vis[it]){
                vis[it]=1;
                setbob(graph,it,vis,step+1,flag);
                if(!flag) m.erase(it);
                if(flag) return;
                vis[it]=0;
            }
        }
    }
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        res = -INT_MAX;
        int n=edges.size()+1;
        vector<vector<int>>graph(n);
        
        for(auto it:edges){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        vector<int>vis(n,0);
        bool flag=false;
        vis[bob]=1;
        setbob(graph,bob,vis,0,flag);
        
        vector<int>vis2(n,0);
        vis2[0]=1;
        find(graph,0,0,amount,vis2,0);
        return res;
    }

    void find(vector<vector<int>>& graph,int alice,int step,vector<int>& amount,vector<int>&vis,int val){
        if(m.find(alice)==m.end()){
            val+=amount[alice];
        }
        else if(step < m[alice]){
            val+=amount[alice];
        }
        else if(step==m[alice]){
            val+=(amount[alice]/2);
        }
        if(graph[alice].size()==1 && alice !=0 ){
            res=max(res,val);
            return;
        }
        for(auto it:graph[alice]){
            if(!vis[it]){
                vis[it]=1;
                find(graph,it,step+1,amount,vis,val);
                vis[it]=0;
            }
        }
    }
};