class Solution {
private:
    int res;
    int r;
    int c;
    vector<vector<int>>dp;
    int find(int i,int j,vector<vector<int>>& grid){
        if(j>=c){
            return 0;
        }
        if(dp[i][j] != -1)
            return dp[i][j];
        int r1=0,r2=0,r3=0;
        if(i+1<r && j+1<c && (grid[i+1][j+1] > grid[i][j]))
            r1=1+find(i+1,j+1,grid);
        if(j+1<c && (grid[i][j+1] > grid[i][j]))
            r2=1+find(i,j+1,grid);
        if(i-1>=0 && j+1<c && (grid[i-1][j+1] > grid[i][j]))
            r3=1+find(i-1,j+1,grid);
        return dp[i][j]=max(r1,max(r2,r3));
    }
public:
    int maxMoves(vector<vector<int>>& grid) {
        res=0;
        r=grid.size();
        c=grid[0].size();
        dp.resize(r,vector<int>(c,-1));
        for(int i=0;i<r;i++){
            res=max(res,find(i,0,grid));
        }
        return res;
    }
};