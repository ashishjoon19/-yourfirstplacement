class Solution {
public:
    set<string>s;
    vector<int>dp;
    int n;
    int find(string str){
        if(dp[n-str.length()]!=-1)
            return dp[n-str.length()];
        string temp="";
        int mini=str.length();
        if(1<str.length())
            mini=min(mini,1+find(str.substr(1)));
        for(int i=0;i<str.length();i++){
            temp+=str[i];
            if(s.find(temp)!=s.end()){
                if(i==str.length()-1){
                    dp[n-str.length()]=0;
                    return 0;
                }
                mini=min(mini,find(str.substr(i+1)));
            }
        }
        dp[n-str.length()]=mini;
        return mini;
    }
    int minExtraChar(string str, vector<string>& dictionary) {
        n=str.length();
        dp.resize(str.length(),-1);
        for(auto it:dictionary)
            s.insert(it);
        return find(str);
    }
};