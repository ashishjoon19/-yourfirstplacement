class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        // sort(bills.begin(),bills.end());
        map<int,int>m;
        m[5]=0;
        m[10]=0;
        m[20]=0;
        for(auto i:bills){
            if(i==5)
                m[i]++;
            else{
                int temp=i-5;
                while(temp!=0){
                    if(temp >= 20 && m[20]!=0)
                    {
                        temp-=20;
                        m[20]--;
                    }
                    else if(temp>=10 && m[10]!=0){
                        temp-=10;
                        m[10]--;
                    }
                    else if(temp>=5 && m[5]!=0){
                        temp-=5;
                        m[5]--;
                    }
                    else
                        return false;
                }
                m[i]++;
            }
        }
        return true;
    }
};