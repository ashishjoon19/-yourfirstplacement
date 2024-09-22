class Solution {
public:
    long long countSteps(int prefix, int n) {
        long long steps = 0;
        long long current = prefix;
        long long next = prefix + 1;
        while (current <= n) {
            steps += min((long long)n + 1, next) - current;
            current *= 10;
            next *= 10;
        }
        return steps;
    }

    int findKthNumber(int n, int k) {
        int current = 1;
        k--;
        
        while (k > 0) {
            long long steps = countSteps(current, n);
            if (steps <= k) {
                k -= steps;
                current++;
            } else {
                current *= 10;
                k--;
            }
        }
        
        return current;
    }
};
