class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.length();
        map<char,int>m;
        int l=0,res=0,i=0;
        while(i<n){
            m[s[i]]++;
            if(m.size()==3){
                res+=(n-i);
                m[s[l]]--;
                l++;
                if(m[s[l-1]]==0){
                    m.erase(s[l-1]);
                }
                else{
                    while(l<n && m.size()==3){
                        m[s[l]]--;
                        if(m[s[l]]==0) m.erase(s[l]);
                        res+=(n-i);
                        l++;
                    }
                }
            }
            i++;
        }
        return res;
    }
};