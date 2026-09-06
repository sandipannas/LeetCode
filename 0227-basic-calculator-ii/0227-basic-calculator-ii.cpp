class Solution {
public:
    int calculate(string s) {
        vector<int> nums;
        vector<char> sym;
        
        string num="";
        for(char c:s){
            if(c=='*' || c=='+' || c=='/' || c=='-'){
                nums.push_back(stoi(num));
                num="";
                sym.push_back(c);
            }
            else if(c==' '){ continue; }
            else{
                num+=c;
            }
        }
        if(!num.empty()) nums.push_back(stoi(num));

        for(int i=0;i<sym.size();i++){
            if(sym[i]=='-'){
                sym[i]='+';
                nums[i+1]*=-1;
            }
        }
        
        vector<int> tem_nums;
        vector<char> tem_sym;
        
        tem_nums.push_back(nums[0]);

        for(int i=0;i<sym.size();i++){
            if(sym[i]=='/'){ 
                tem_nums.back()/=nums[i+1]; 
            }
            else if(sym[i]=='*'){ 
                tem_nums.back()*=nums[i+1]; 
            }
            else{
                tem_nums.push_back(nums[i+1]);
                tem_sym.push_back(sym[i]);
            }
        }

        nums=tem_nums; tem_nums={};
        sym=tem_sym; tem_nums={};

        tem_nums.push_back(nums[0]);
        for(int i=0;i<sym.size();i++){
            tem_nums.back()+=nums[i+1]; 
        }

        return tem_nums.back();
    }
};