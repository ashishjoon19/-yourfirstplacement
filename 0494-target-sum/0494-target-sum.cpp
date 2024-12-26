class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        map<int, int> m;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        m[sum] = 1;
        for (int i = 0; i < nums.size(); i++) {
            for (auto const& [key, val] : m) {
                m[key - 2 * nums[i]] += val;
            }
        }
        return m[target];
    }
};