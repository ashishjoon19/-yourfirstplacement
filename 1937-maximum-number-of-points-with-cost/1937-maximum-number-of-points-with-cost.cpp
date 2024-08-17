class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size();
        int n = points[0].size();

        // DP array to store the maximum points
        vector<vector<long long>> dp(m, vector<long long>(n, 0));

        // Initialize the last row in dp array
        for (int j = 0; j < n; j++) {
            dp[m-1][j] = points[m-1][j];
        }

        // Fill the DP table from the second-last row to the first row
        for (int i = m-2; i >= 0; i--) {
            vector<long long> leftMax(n), rightMax(n);

            // Compute leftMax array
            leftMax[0] = dp[i+1][0];
            for (int j = 1; j < n; j++) {
                leftMax[j] = max(leftMax[j-1], dp[i+1][j] + j);
            }

            // Compute rightMax array
            rightMax[n-1] = dp[i+1][n-1] - (n-1);
            for (int j = n-2; j >= 0; j--) {
                rightMax[j] = max(rightMax[j+1], dp[i+1][j] - j);
            }

            // Update the dp array for the current row
            for (int j = 0; j < n; j++) {
                dp[i][j] = points[i][j] + max(leftMax[j] - j, rightMax[j] + j);
            }
        }

        // The answer is the maximum value in the first row
        long long maxi = INT_MIN;
        for (int j = 0; j < n; j++) {
            maxi = max(maxi, dp[0][j]);
        }

        return maxi;
    }
};
