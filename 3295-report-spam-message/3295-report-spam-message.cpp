class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        set<string>s;
        for(auto it:bannedWords)
            s.insert(it);
        int cnt=0;
        for(auto it:message){
            if(s.find(it)!=s.end()){
                cnt++;
                if(cnt==2)
                    return true;
            }
        }
        return false;
    }
};