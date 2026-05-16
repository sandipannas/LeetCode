class Solution {
public:
    int countPrimes(int n) {
        
        if(n==0 || n==1){ return 0; }

        vector<bool> isPrime(n,true);
        isPrime[0]=false;
        isPrime[1]=false;

        int count=0;

        for(int i=2;i<=sqrt(n);i++){
            if(isPrime[i]==false){ continue; }
            else{
                int ele=2*i;
                while(ele<n){
                    isPrime[ele]=false;
                    ele+=i;
                }
            }
        }
        for(bool b:isPrime){
            if(b==true){
                count++;
            }
        }
        return count;
        
    }
};