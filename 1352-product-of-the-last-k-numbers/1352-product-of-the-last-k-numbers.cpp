class ProductOfNumbers {
public:
    vector<unsigned long long> gg;
    vector<int> og;
    long long count=0;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if(num==0){
        count++; num=1;
        if(gg.size()==0){
        gg.push_back(num);
        og.push_back(count);
        }
        
        else{
        gg.push_back(num);
        og.push_back(count);
        }
        return;
        }

        if(gg.size()==0){
        gg.push_back(num);
        og.push_back(count);
        }
        
        else{
        gg.push_back(gg.back()*num);
        og.push_back(count);
        }
    }
    
    int getProduct(int k) {
        
        if(gg.size()==0) { return 0; }

        if(k==gg.size()){
            if(count>0){return 0;}
            return gg.back();
            }

        if(og.back()-og[og.size()-k-1]>0) { return 0; }
        
        return gg.back()/gg[gg.size()-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */