class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.length();
        int res=0;
        int l=0,r=0;
        map<char,int>f;
        while(r<n){
            if(s[r]=='a' || s[r]=='b' || s[r]=='c')
                f[s[r]]++;
            if(f.size()==3){
                res+=1+n-1-r;
                while(s[l]!='a' && s[l]!='b' && s[l]!='c')
                    l++;
                f[s[l]]--;
                if(f[s[l]]==0)
                    f.erase(s[l]);
                l++;
                f[s[r]]--;
            }
            else
                r++;
        }
        return res;
    }
};