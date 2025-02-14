class ProductOfNumbers {
private:
    vector<int>nums;
    vector<int>cum;
    int last_zero;
    int size;
    int sum;
public:
    ProductOfNumbers() {
        last_zero = -1;
        size=0;
        sum=1;
    }
    
    void add(int num) {
        nums.push_back(num);
        size++;
        if(num==0){
            last_zero=1;
            sum=1;
        }
        else{
            sum*=num;
            if(last_zero != -1)
                last_zero++;
        }
        cum.push_back(sum);
    }
    
    int getProduct(int k) {
        if(last_zero <= k && last_zero != -1)
            return 0;
        int ind=size-k-1;
        if(ind<0)
            return sum;
        return sum/cum[ind];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */