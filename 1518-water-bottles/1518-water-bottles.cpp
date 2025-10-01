class Solution {
public:
    int numWaterBottles(int b, int e) {
        int answer=b;
        while(b >= e){
          int newB =b/e;
          cout<<"new Bottles we get is "<<newB<<"\n";
          answer+=newB;
          cout<<"total bottles we have are "<<answer<<"\n";
          newB+=b%e;
          cout<<"the left bottles are "<<b%e<<"\n";
          cout<<"now ava bottles are "<<b%e+newB<<"\n";
          b=newB;
        }
        return answer;
    }
};