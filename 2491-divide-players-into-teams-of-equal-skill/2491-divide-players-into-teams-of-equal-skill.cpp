class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        std::vector<int> v(1001, 0);
        int n = skill.size();
        int tsum = 0;
        for (auto it: skill) {
            tsum += it;
            v[it]++;
        }
        n >>= 1;
        if (tsum % n != 0)
            return -1;
        int sum = tsum / n;
        // std::cout << sum << '\n';
        std::int64_t ans = 0;
        for (int i = 0; i <= sum / 2; ++i) {
            if (v[i] == 0)
                continue;
            int c = sum - i;
            // std::cout << i << ' ' << c << '\n';
            if (i != c) {
                if (v[i] != v[c])
                    return -1;
                ans += 1ll * i * c * v[i];
                n -= v[i];
            } else {
                if (v[i] & 1)
                    return -1;
                ans += 1LL * i * i * v[i] / 2;
                n -= v[i] / 2;
            }
        }
        if (n > 0)
            return -1;
        return ans;
    }
};