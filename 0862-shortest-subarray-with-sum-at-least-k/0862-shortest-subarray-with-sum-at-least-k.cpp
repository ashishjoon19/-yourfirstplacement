#include <iostream>
#include <deque>
#include <vector>
#include <climits>

using namespace std;

class Solution {
private:
    int n;
    int res;
public:
    int shortestSubarray(vector<int>& nums, int k) {
        n = nums.size();
        res = INT_MAX;
        deque<pair<long long, int>> dq;  // Use long long for the deque pair to avoid overflow
        vector<long long> pref(n + 1, 0);  // Use long long for the prefix sum

        // Calculate prefix sums
        for (int i = 1; i <= n; i++) {
            pref[i] = pref[i - 1] + nums[i - 1];  // Accumulate sums into the prefix array
        }

        // Iterate over the array to find the shortest subarray
        for (int i = 0; i <= n; i++) {
            // Maintain increasing order of prefix sums in deque
            while (!dq.empty() && dq.back().first >= pref[i]) {
                dq.pop_back();
            }
            dq.push_back({pref[i], i});

            // Compress deque and check for valid subarrays
            while (!dq.empty() && pref[i] - dq.front().first >= k) {
                res = min(res, i - dq.front().second);  // Update result with shortest subarray
                dq.pop_front();
            }
        }

        // If no valid subarray was found, return -1
        return res == INT_MAX ? -1 : res;
    }
};
