class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        set<char>s1;
        int c=0;
        for(auto it:allowed)
            s1.insert(it);
        for(auto it:words){
            set<char>s2;
            int flag=0;
            for(auto ch:it){
                if(s1.find(ch)==s1.end()){
                    flag=1;
                    break;
                }
            }
            if(!flag)
                c++;
        }
        return c;
    }
};