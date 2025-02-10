class Solution {
public:
    string clearDigits(string s) {
        vector<int>ind;
        int n=s.length();
        for(int i=n-1;i>=0;i--){
            if(s[i] < 'a' || s[i] > 'z'){
                s.erase(i,1);
                i--;
                int j=i;
                int flag=0;
                while(j>=0){
                    if(s[j] >= 'a' && s[j] <= 'z'){
                        s.erase(j,1);
                        flag=1;
                        break;
                    }
                    j--;
                }
                if(!flag)
                    return s;
            }
        }
        return s;
    }
};