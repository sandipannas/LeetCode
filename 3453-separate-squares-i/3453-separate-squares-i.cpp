class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double ta=0;
        double hi=0; 
        double low=0; 
        for(auto& a:squares)
            {
                ta+=pow(a[2],2);
                hi=max(hi,(double)a[1]+a[2]);
            }
        double eps=1e-6;
        double ff=-1;
        
        while(hi-low>eps)
        {   double mid=(hi+low)/2;
            long double tem=0;
            
            for(auto& a:squares)
            { if(mid>a[1] && mid>=a[1]+a[2]){ tem+=(double)a[2]*(double)a[2];}
              else if(mid>a[1] && mid<a[1]+a[2]){tem+=(mid-a[1])*a[2];}
            }

            if(ta/2>tem){ low=mid;}
            else{
                hi=mid;
            }
            ff=mid;
        }
        return low;
        
    }
};