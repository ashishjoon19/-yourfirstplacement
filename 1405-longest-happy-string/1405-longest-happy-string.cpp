class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        char prev;
        map<char,int>m;
        m['a']=a;
        m['b']=b;
        m['c']=c;
        vector<int>max(3,0);

        char max_char='a';
        int freq=a;
        if(freq < b){
            freq=b;
            max_char='b';
        }
        if(freq < c){
            freq=c;
            max_char='c';
        }
        string res="";
        if(freq==0)
            return "";

        while(m[max_char]!=0 && max[max_char-'a'] < 2){
            if(max_char=='a')
                res+='a';
            else if(max_char=='b')
                res+='b';
            else
                res+='c';
            m[max_char]--;
            //max_a,b,c++
            max[max_char-'a']++;
            int temp=0;
            if(temp < m['a'] && max[0] < 2){
                max_char='a';
                temp=m['a'];
            }
            if(temp < m['b'] && max[1] < 2){
                max_char='b';
                temp=m['b'];
            }
            if(temp < m['c'] && max[2] < 2){
                max_char='c';
                temp=m['c'];
            }
            
            for(int it=0;it<3;it++){
                if(max_char-'a' != it)
                    max[it]=0;
            }
        }
        return res;
    }
};