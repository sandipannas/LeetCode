class Solution {
public:
    void mul(int n,string& word){
        string answer="";
        for(int i=1;i<=n;i++){
            answer+=word;
        }
        word=answer;
    }

    void operation(vector<string>& stk){
        string opp="";
        
        while(stk.back()!="["){
            string gg=stk.back(); 
            stk.pop_back();
                    
            if(gg[0]>='0' && gg[0]<='9'){
                int n=stoi(gg);
                mul(n,opp);
            }
            else{ opp=gg+opp; }
        }

        stk.pop_back();
        stk.push_back(opp);
    }
    
    string decodeString(string s) {
        vector<string> stk; stk.push_back("[");
        string num="";
        string word="";

        for(char c : s){
            if(c=='['){
                if(!word.empty()){ 
                    stk.push_back(word);
                }
                stk.push_back(num);
                stk.push_back("[");
                
                word=""; num="";
            }
            else if(c==']'){
                if(!word.empty()){
                    stk.push_back(word);
                    word="";
                }
                operation(stk); 
                string opp=stk.back(); stk.pop_back();
                int n=stoi(stk.back()); stk.pop_back();
                mul(n,opp);
                stk.push_back(opp);
            }
            else if(c>='0' && c<='9'){ num+=c; }
            else { word+=c; }
        }
        if(!word.empty()){
            stk.push_back(word);
             word="";
        }
        operation(stk);
        return stk.back();
    }
};