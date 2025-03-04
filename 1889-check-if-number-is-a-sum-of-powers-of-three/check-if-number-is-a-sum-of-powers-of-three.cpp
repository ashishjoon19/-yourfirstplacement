class Solution {
private:
    int lmt;
    bool find(int n,int pwr){
        // if(n==0) return true;
        n-=pow(3,pwr);//12-1=11,11-3=8,8-9=-1
        if(n<0) return false;
        if(n==0) return true;
        bool res=false;
        for(int i=pwr+1;i<lmt;i++){
            res|=find(n,i);//{11,1},{8,2}
            if(res) return true;
        }
        return res;
    }
public:
    bool checkPowersOfThree(int n) {
        // 1+3+3^2+3^3+...
        //91-1=90, 90-9=81, 81-81=0
        lmt=0;
        int temp=n;//temp=12
        while(temp>0){//12>0,11>0,8>0,-1!>0 break;
            temp-=pow(3,lmt);//12-1=11,11-3=8,8-9=-1,
            lmt++;//1,2,3
        }
        bool res=false;
        for(int i=0;i<lmt;i++){//0,
            res|=find(n,i);//{12,0}
            if(res) return true;
        }
        return res;
    }
};