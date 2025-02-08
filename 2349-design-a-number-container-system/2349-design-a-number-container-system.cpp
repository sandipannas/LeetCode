class NumberContainers {
public:

    unordered_map<int,int> in;
    unordered_map<int,set<int>> num;

    NumberContainers() {
        
    }
    
    void change(int index, int number) {
     
     int pre=-1;
     
     if(in.count(index)){ pre=in[index]; }
     
     in[index]=number;
     num[number].insert(index);

     if(pre!=-1){
        num[pre].erase(index);
     }

    }
    
    int find(int number) {
        if(num.count(number) && num[number].size()!=0){
        return *next(num[number].begin(),0);}
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */