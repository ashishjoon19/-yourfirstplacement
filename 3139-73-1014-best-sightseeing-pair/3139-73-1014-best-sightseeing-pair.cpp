class Solution {
public:
    int dp[50001][3];

      int solve(int idx, int val, vector<int>& values) {
     
        if (idx == values.size()) return dp[idx][val]=(val == 0 ? 0 : INT_MIN);
        if (val == 0) return dp[idx][val]=0;

        if(dp[idx][val] != -1) return dp[idx][val];

        int notPick = solve(idx + 1, val, values);
        int pick = values[idx] + solve(idx + 1, val - 1, values);

        if (val == 2) pick += idx;
        else if (val == 1) pick -= idx; 

    
        return dp[idx][val]=max(pick, notPick);
    }

    int maxScoreSightseeingPair(vector<int>& values) {
        memset(dp,-1,sizeof(dp));
        return solve(0, 2, values);
    }
};