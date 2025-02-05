class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n=s1.length();
        int flag=0;
        char ch1,ch2;
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]){
                if(flag==0){
                    ch1=s1[i],ch2=s2[i];
                    flag++;
                }
                else if(flag==1){
                    if(s1[i]==ch2 && s2[i]==ch1)
                        flag++;
                    else
                        return false;
                }
                else
                    return false;
            }
        }
        if(flag==0 || flag==2)
            return true;
        return false;
    }
};