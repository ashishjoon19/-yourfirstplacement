class Solution {
public:
    static bool comp(pair<char,int>&p1,pair<char,int>&p2){
        return p1.second > p2.second;
    }
    int minimumPushes(string word) {
        map<char,int>freq;
        for(auto it:word)
            freq[it]++;
        
        vector<pair<char,int>>vec;
        for(auto it:freq)
            vec.push_back({it.first,it.second});

        sort(vec.begin(),vec.end(),comp);

        int count=1,flag=1;
        map<char,int>key;

        for(int i=0;i<vec.size();i++){
            char ch=vec[i].first;
            count++;
            if(count<=9)
                key[ch]=flag;
            else{
                flag++;
                count=2;
                key[ch]=flag;
            }
        }

        int sum=0;
        for(auto it:freq){
            sum += it.second*key[it.first];
        }
        return sum;
    }
};