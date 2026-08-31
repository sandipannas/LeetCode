class Solution {
public:
    void mul(int n,string& word){
        string answer="";
        for(int i=1;i<=n;i++){
            answer+=word;
        }
        word=answer;
        //cout<<endl<<"mul_answer-->"<<word;
    }

    void operation(vector<string>& stk){
        string opp="";
        
        while(stk.back()!="["){
            string gg=stk.back(); 
            stk.pop_back();  //cout<<endl<<"pop-->"<<gg;
                    
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

            //cout<<endl<<"-- "<<c<<" --"<<endl;

            if(c=='['){
                if(!word.empty()){ 
                    stk.push_back(word); //cout<<endl<<"pushing-->"<<word;
                }
                stk.push_back(num); //cout<<endl<<"pushing-->"<<num;
                stk.push_back("["); //cout<<endl<<"pushing-->"<<"[";
                
                word=""; num="";
            }

            else if(c==']'){
                if(!word.empty()){
                    stk.push_back(word); //cout<<endl<<"pushing-->"<<word;
                    word="";
                }

                operation(stk); 

                string opp=stk.back(); stk.pop_back();
                int n=stoi(stk.back()); stk.pop_back();

                mul(n,opp);
                stk.push_back(opp);  //cout<<endl<<"pushing-->"<<opp;
            }
            else if(c>='0' && c<='9'){ num+=c; }
            else { word+=c; }
        }
        if(!word.empty()){
            stk.push_back(word); //cout<<endl<<"pushing-->"<<word;
             word="";
        }

        operation(stk);

        return stk.back();
    }
};