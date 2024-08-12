class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n=s.length();
        string temp="";
        for(int i=0;i<n/2;i++){
            temp+=s[i];
            int l=i+1;
            if(n%l==0){
                int c=n/l;
                string tempi="";
                tempi+=temp;
                for(int j=0;j<c-1;j++){
                    tempi += temp;
                }
                if(tempi==s)
                    return true;
            }
        }
        return false;
    }
};