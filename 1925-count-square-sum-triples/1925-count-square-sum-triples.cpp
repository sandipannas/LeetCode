class Solution {
public:
    int countTriples(int n) {
      int count=0;
      for(int a=1;a<=n;a++){
        for(int b=1;b<=n;b++){
            float c=pow(a,2)+pow(b,2);
            c=sqrt(c);
            if(c<=(float)n && fmod(c,1.0)==0){ count++; }
            //cout<<a<<" "<<b<<" "<<c<<" "<<fmod(c,1.0)<<endl;
        }
      }
      return count;   
    }
};