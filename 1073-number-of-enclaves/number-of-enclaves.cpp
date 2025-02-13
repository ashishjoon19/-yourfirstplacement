class Solution {
private:
    int m;
    int n;
    void dfs(int i,int j,/*vector<vector<int>>& vis,*/vector<vector<int>>& grid){
        // vis[i][j]=1;
        grid[i][j]=2;
        if(i+1 < m && grid[i+1][j]==1)
            dfs(i+1,j,/*vis,*/grid);
        if(j+1 < n && grid[i][j+1]==1)
            dfs(i,j+1,/*vis,*/grid);
        if(i-1 >=0 && grid[i-1][j]==1)
            dfs(i-1,j,/*vis,*/grid);
        if(j-1 >=0 && grid[i][j-1]==1)
            dfs(i,j-1,/*vis,*/grid);
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        // vector<vector<int>>vis(m,vector<int>(n,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || j==0 || i==m-1 || j==n-1){
                    if(grid[i][j]==1/* && vis[i][j]==0*/){
                        dfs(i,j/*,vis*/,grid);
                    }
                }
            }
        }

        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)
                    cnt++;
            }
        }
        return cnt;
    }
};