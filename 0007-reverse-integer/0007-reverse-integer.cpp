class Solution {
public:
    int reverse(int x) {
        long y=x;
        string s=to_string(y);
        s=string(s.rbegin(),s.rend());
        long ss=stol(s);
        if(ss>INT_MAX || ss<INT_MIN)
        {
            return 0;
        }
        if(x<0){
            ss=ss*(-1);
        }
        return (int)ss;
        
    }
};