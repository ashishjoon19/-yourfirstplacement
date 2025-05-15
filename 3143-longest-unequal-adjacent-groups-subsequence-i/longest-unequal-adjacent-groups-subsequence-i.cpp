class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string>result;
        int n=groups.size();
        int val=groups[0];
        result.push_back(words[0]);
        for(int i=1;i<n;i++){
            if(val!=groups[i]){
                val=groups[i];
                result.push_back(words[i]);
            }
        }
        return result;
    }
};