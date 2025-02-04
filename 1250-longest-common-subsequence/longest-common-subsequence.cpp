class Solution {
    int res,m,n;
    int find(int i,int j,string &s1,string &s2,vector<vector<int>>&dp){
        if(i >= m || j >= n)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        if(s1[i] == s2[j])
            dp[i][j]= 1+find(i+1,j+1,s1,s2,dp);
        else
            dp[i][j]= max(find(i+1,j,s1,s2,dp),find(i,j+1,s1,s2,dp));
        return dp[i][j];
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        res=0;
        m=text1.length();
        n=text2.length();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return find(0,0,text1,text2,dp);
    }
};