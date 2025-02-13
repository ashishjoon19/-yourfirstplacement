class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        q.push({-1,-1});
        int res=0;
        while(!q.empty()){
            pair<int,int>p=q.front();
            q.pop();
            int i=p.first;
            int j=p.second;
            if(i==-1){
                if(q.empty())
                    break;
                res++;
                q.push({-1,-1});
                continue;
            }
            if(i+1 < m && grid[i+1][j]==1 && vis[i+1][j] ==0){
                q.push({i+1,j});
                vis[i+1][j]=1;
            }
            if(i-1 >=0 && grid[i-1][j]==1 && vis[i-1][j] ==0){
                q.push({i-1,j});
                vis[i-1][j]=1;
            }
            if(j+1 < n && grid[i][j+1]==1 && vis[i][j+1] ==0){
                q.push({i,j+1});
                vis[i][j+1]=1;
            }
            if(j-1 >=0  && grid[i][j-1]==1 && vis[i][j-1] ==0){
                q.push({i,j-1});
                vis[i][j-1]=1;
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && vis[i][j]==0)
                    return -1;
            }
        }
        return res;
    }
};