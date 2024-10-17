class Solution {
public:
    static bool comp(int a,int b){
        if(a>b)
            return true;
        return false;
    }
    int maximumSwap(int num) {
        vector<int>vec;
        while(num){
            vec.push_back(num%10);
            num/=10;
        }

        reverse(vec.begin(),vec.end());
        vector<int>maxi=vec;
        sort(maxi.begin(),maxi.end(),comp);

        for(int i=0;i<maxi.size();i++){
            if(vec[i]!=maxi[i]){
                int temp=vec[i];
                vec[i]=maxi[i];
                for(int j=maxi.size()-1;j>=0;j--){
                    if(vec[j]==vec[i] && j>i){
                        vec[j]=temp;
                        break;
                    }
                }
                break;
            }
        }
        int res=0;
        for(auto it:vec){
            res=res*10+it;
        }

        return res;
    }
};