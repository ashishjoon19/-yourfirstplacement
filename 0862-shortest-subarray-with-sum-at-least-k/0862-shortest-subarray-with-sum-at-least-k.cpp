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
        deque<pair<long long, int>> dq;
        vector<long long> pref(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            pref[i] = pref[i - 1] + nums[i - 1];
        }
        for (int i = 0; i <= n; i++) {
            while (!dq.empty() && dq.back().first >= pref[i]) {
                dq.pop_back();
            }
            dq.push_back({pref[i], i});

            while (!dq.empty() && pref[i] - dq.front().first >= k) {
                res = min(res, i - dq.front().second);
                dq.pop_front();
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};
