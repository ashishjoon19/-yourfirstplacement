class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m=str1.size();
        int n=str2.size();
        vector<vector<int>>t(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(str1[i-1]==str2[j-1])
                    t[i][j]=1+t[i-1][j-1];
                else
                    t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        }
        string result="";
        while(m>0 && n>0){
            if(str1[m-1]==str2[n-1]){
                result+=str1[m-1];
                m--;
                n--;
            }
            else if(t[m-1][n] > t[m][n-1]){
                result+=str1[m-1];
                m--;
            }
            else
            {
                result+=str2[n-1];
                n--;
            }
        }
        while(n!=0){
            result+=str2[n-1];
            n--;
        }
        while(m!=0){
            result+=str1[m-1];
            m--;
        }

        string temp="";
        for(int i=result.size()-1;i>=0;i--)
            temp+=result[i];
        return temp;
    }
};