class Solution {
private:
    int n;
    vector<long long>dp;
    long long find(vector<vector<int>>& questions,int idx){
        if(idx>=n) return 0;
        if(dp[idx]!=-1)
            return dp[idx];
        long long res1=0,res2=0;
        
        res1=find(questions,idx+questions[idx][1]+1)+questions[idx][0];
        res2=find(questions,idx+1);

        return dp[idx]=max(res1,res2);
    }
public:
    long long mostPoints(vector<vector<int>>& questions) {
        n=questions.size();
        dp.resize(n+1,-1);
        return find(questions,0);
    }
};