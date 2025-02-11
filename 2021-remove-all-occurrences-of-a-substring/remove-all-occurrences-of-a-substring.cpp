class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n=s.length();
        int m=part.length();
        stack<char>st;
        for(int i=0;i<n;i++){
            st.push(s[i]);
            int j=m-1;
            if(s[i]==part[m-1] && st.size() >= m){
                while(j>=0 && st.top()==part[j]){
                    st.pop();
                    j--;
                }
                if(j>=0){
                    j++;
                    while(j<m){
                        st.push(part[j]);
                        j++;
                    }
                }
            }
        }
        string str="";
        while(!st.empty()){
            str=st.top()+str;
            st.pop();
        }
        return str;
    }
};