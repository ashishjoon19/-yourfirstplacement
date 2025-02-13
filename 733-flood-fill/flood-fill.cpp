class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int,int>>q;
        int m=image.size();
        int n=image[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        q.push({sr,sc});
        int clr=image[sr][sc];
        while(!q.empty()){
            pair<int,int>p=q.front();
            q.pop();
            int i=p.first;
            int j=p.second;
            image[i][j]=color;
            if(i+1 < m && image[i+1][j]==clr && vis[i+1][j]==0){
                q.push({i+1,j});
                vis[i+1][j]=1;
            }
            if(i-1 >=0 && image[i-1][j]==clr && vis[i-1][j]==0){
                q.push({i-1,j});
                vis[i-1][j]=1;
            }
            if(j+1 < n && image[i][j+1]==clr && vis[i][j+1]==0){
                q.push({i,j+1});
                vis[i][j+1]=1;
            }
            if(j-1 >= 0 && image[i][j-1]==clr && vis[i][j-1]==0){
                q.push({i,j-1});
                vis[i][j-1]=1;
            }
        }
        return image;
    }
};