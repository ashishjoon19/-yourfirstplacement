class Solution {
public:
    long long minimumSteps(string s) {
        int n=s.length();
        int i=0,j=0;
        long long cnt=0;
        long long res=0;
        while(i<n){
            if(s[i]=='1')
                cnt++;
            else
                res+=cnt;
            i++;
        }
        return res;
    }
};