class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int res=0;
        int n=matrix[0].size();
        for(auto currow:matrix){
            vector<int>invert(n);
            for(int i=0;i<n;i++){
                invert[i]=(currow[i]==0?1:0);
            }
            int cnt=0;
            for(auto it:matrix){
                if(it==currow || it==invert){
                    cnt++;
                }
            }
            res=max(res,cnt);
        }
        return res;
    }
};