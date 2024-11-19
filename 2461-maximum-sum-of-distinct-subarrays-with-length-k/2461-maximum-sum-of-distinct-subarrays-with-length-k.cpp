class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if (k > n) return 0;
        
        long long sum = 0, res = 0;
        map<int, int> m;
        int l = 0;        
        for (int i = 0; i < n; ++i) {
            if (m.find(nums[i]) != m.end() && m[nums[i]] >= l) {
                while (l <= m[nums[i]]) {
                    sum -= nums[l];
                    l++;
                }
            }
            sum += nums[i];
            m[nums[i]] = i;
            if (i - l + 1 == k) {
                res = max(res, sum);
                sum -= nums[l];
                l++;
            }
        }
        
        return res;
    }
};
