class CustomStack {
private:
    int max_size;
    int top;
    vector<int>vec;
public:
    CustomStack(int maxSize) {
        top=0;
        max_size=maxSize;
        vec.resize(max_size);
    }
    
    void push(int x) {
        if(top < max_size){
            vec[top]=x;
            top++;
        }
    }
    
    int pop() {
        if(!top)
            return -1;
        int num=vec[top-1];
        top--;
        return num;
    }
    
    void increment(int k, int val) {
        for(int i=0;i<top && i<k;i++){
            vec[i]+=val;
        }
    }
};