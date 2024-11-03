class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length())
            return false;
        int n=s.length();
        if(s==goal)
            return true;
        while(n--){
            string temp=s.substr(1);
            temp+=s[0];
            s=temp;
            if(s==goal)
                return true;
        }
        return false;
    }
};