class Solution {
public:
    int totalMoney(int n) {
        int pre=1; int answer=0;
        for(int i=1;i<=n;i++){
            if(i%7==1){ pre=(i/7)+1; }
            answer+=pre;
            pre++;
        }
        return answer;
    }
};