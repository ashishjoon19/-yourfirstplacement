#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        // Array to store character frequencies (since we have only lowercase English letters)
        vector<int> targetFreq(26, 0);
        vector<int> currFreq(26, 0);
        
        int n = word1.size();
        
        // Initialize the frequency of characters in word2
        for (char c : word2) {
            targetFreq[c - 'a']++;
        }
        
        int i = 0, j = 0;
        long long result = 0;
        int requiredChars = 0;

        // Count how many unique characters in word2 need to be matched
        for (int count : targetFreq) {
            if (count > 0) requiredChars++;
        }
        
        int matchedChars = 0;

        // Sliding window approach
        while (j < n) {
            char endChar = word1[j];
            if (targetFreq[endChar - 'a'] > 0) {
                currFreq[endChar - 'a']++;
                if (currFreq[endChar - 'a'] == targetFreq[endChar - 'a']) {
                    matchedChars++;
                }
            }
            
            // When all characters are matched
            while (matchedChars == requiredChars) {
                // Add the valid substrings from this point onward
                result += (n - j);
                
                char startChar = word1[i];
                if (targetFreq[startChar - 'a'] > 0) {
                    if (currFreq[startChar - 'a'] == targetFreq[startChar - 'a']) {
                        matchedChars--;
                    }
                    currFreq[startChar - 'a']--;
                }
                i++;  // Shrink the window from the left
            }
            
            j++;  // Expand the window from the right
        }
        
        return result;
    }
};
