class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        //brute force
        int n=strs.size(),res=0,cnt=strs[0].length();
        string result="";
        for(int i=1;i<n;i++){
            int m=strs[i].length();
            int ni=strs[i-1].length();
            int idx=0;
            while(idx < m && idx < ni && idx < cnt){
                if(strs[i][idx]==strs[i-1][idx]){
                    res++;
                }
                else
                    break;
                idx++;
            }
            cnt=min(res,cnt);
            res=0;
        }
        return strs[0].substr(0,cnt);
    }
};