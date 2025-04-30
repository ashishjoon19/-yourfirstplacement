class Solution {
public:
    bool rotateString(string s, string goal) {
        int m=s.length();
        int n=goal.length();
        int ind=0,i=0;
        if(m!=n) return false;
        for(int i=0;i<n;i++){
            if(goal[i]==s[0]){
                ind=0;
                int j=i;
                while(ind<m && s[ind]==goal[j]){
                    j=(j+1)%n;
                    ind++;
                }
                if(ind==m) return true;
            }
        }
        return false;
    }
};