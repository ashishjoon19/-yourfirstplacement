class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string res="";
        int ind=0,i=0;
        for(auto it : s){
            if(i<spaces.size() && ind==spaces[i]){
                res+=' ';
                i++;
            }
            res+=it;
            ind++;
        }
        return res;
    }
};