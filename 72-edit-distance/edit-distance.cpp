class Solution {
private:
    int m;
    int n;
    vector<vector<int>>dp;
    int find(int i,int j,string &word1, string &word2){
        if(j==n)
            return m-i;
        else if(i>=m && j<n){
            return n-j;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(word1[i]==word2[j]){
            dp[i][j]= find(i+1,j+1,word1,word2);
        }
        else{
            int res=find(i+1,j,word1,word2);//delete
            if(res!=INT_MAX)
                res+=1;
            int temp=find(i+1,j+1,word1,word2);
            if(temp!=INT_MAX)
                res=min(res,1+temp);//replace
            temp=find(i,j+1,word1,word2);
            if(temp!=INT_MAX)
                res=min(res,1+temp);//insert
            dp[i][j]= res;
        }
        return dp[i][j];
    }
public:
    int minDistance(string word1, string word2) {
        m=word1.length();
        n=word2.length();
        dp.resize(m+1,vector<int>(n+1,-1));
        if(m==0)
            return n;
        if(n==0)
            return m;
        return find(0,0,word1,word2);
    }
};