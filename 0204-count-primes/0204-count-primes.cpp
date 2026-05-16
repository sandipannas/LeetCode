class Solution {
public:
    int countPrimes(int n) {
        
        if(n<2){ return 0; }

        vector<bool> isPrime(n,true);
        isPrime[0]=false;
        isPrime[1]=false;

        int count=0;

        for(int i=2;i*i<n;i++){
            if(isPrime[i]==false){ continue; }
            else{
                for(int j=i*i;j<n;j+=i){
                    isPrime[j]=false;
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