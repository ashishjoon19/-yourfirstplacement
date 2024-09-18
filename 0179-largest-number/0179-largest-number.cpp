class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // Convert the integers to strings
        vector<string> strs;
        for (int num : nums) {
            strs.push_back(to_string(num));
        }

        // Sort the strings based on the custom rule
        sort(strs.begin(), strs.end(), [](string &a, string &b) {
            return a + b > b + a;
        });

        // Edge case: if the largest number is "0", return "0"
        if (strs[0] == "0") {
            return "0";
        }

        // Join all the sorted strings into one large number
        string ans = "";
        for (string &s : strs) {
            ans += s;
        }

        return ans;
    }
};