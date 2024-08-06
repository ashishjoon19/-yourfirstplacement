class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int>m;
        int sz=0,res=0,l=0;
        int n=s.length();
        int i=0;
        for(i=0;i<n;i++){
            if(m.find(s[i])!=m.end()){
                res=max(i-l,res);
                int temp=l;
                l=m[s[i]]+1;
                for(int k=temp;k<l;k++){
                    m.erase(s[k]);
                }
                m[s[i]]=i;
            }
            else{
                m[s[i]]=i;
            }
        }
        res=max(i-l,res);
        return res;
    }
};