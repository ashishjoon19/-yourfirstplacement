class Solution {
public:
    int find(int r,int c,vector<vector<int>>& grid){
        vector<int>vis(9,0);
        //check for distinct
        for(int i=r;i<r+3;i++){
            for(int j=c;j<c+3;j++){
                if(grid[i][j]>9 || grid[i][j] <= 0)
                    return 0;
                if(!vis[grid[i][j]-1]){
                    vis[grid[i][j]-1]=1;
                }
                else
                    return 0;
            }
        }
        int sum=0;
        for(int j=c;j<c+3;j++){
            sum+=grid[r][j];
        }
        int temp=0;
        for(int i=r+1;i<r+3;i++){
            temp=0;
            for(int j=c;j<c+3;j++){
                temp+=grid[i][j];
            }
            if(temp!=sum)
                return 0;
        }
        for(int i=c;i<c+3;i++){
            temp=0;
            for(int j=r;j<r+3;j++){
                temp+=grid[j][i];
            }
            if(temp!=sum)
                return 0;
        }
        if(grid[r][c]+grid[r+1][c+1]+grid[r+2][c+2]!=sum)
            return 0;
        if(grid[r+2][c]+grid[r+1][c+1]+grid[r][c+2]!=sum)
            return 0;
        return 1;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows=grid.size();
        int col=grid[0].size();
        int result=0;
        if(rows<3 || col<3)
            return 0;
        for(int i=0;i<=rows-3;i++){
            for(int j=0;j<=col-3;j++){
                result+= find(i,j,grid);
            }
        }
        return result;
    }
};