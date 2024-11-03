class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";
        int len = 0;
        for(int i = 0;i < s.length();i++){
            int p1 = i,p2 = i;
            while(p1 >= 0 && p2 < s.length() && s[p1] == s[p2]){
                if(p2 - p1 + 1 > len){
                    len = p2 - p1 + 1;
                    ans = s.substr(p1,len);
                }
                p1--;
                p2++;
            }
            p1 = i,p2 = i+1;
            while(p1 >= 0 && p2 < s.length() && s[p1] == s[p2]){
                if(p2 - p1 + 1 > len){
                    len = p2 - p1 + 1;
                    ans = s.substr(p1,len);
                }
                p1--;
                p2++;
            }
        }
        return ans;
    }
};