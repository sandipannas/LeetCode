class Solution {
    public double areadown(int squares[][],double tar){
        double a=0;
        for(int[] sq:squares){
            //double x=sq[0];
            double y=sq[1];
            double h=sq[2];
            
            double y1=y+h;
            if(y1<=tar){
                a=a+(double)(h*h);
            }
            else if(y<tar){
                double h2=tar-y;
                a+=(h2*h);
            }
        }
        return a;
    }
   
    
    
 public double separateSquares(int[][] squares) {
    int max=Integer.MIN_VALUE;
    int min=Integer.MAX_VALUE;
        double tot=0;
        for(int i=0;i<squares.length;i++){
            max=Math.max(max,(squares[i][1]+squares[i][2]));
            min=Math.min(min,(squares[i][1]));
                        
            tot+=(double)(squares[i][2] * squares[i][2]);
        }
       double low=(double)min;
       double high=(double)max;
        double limit=1e-6;
        double ans=0;
        
        while(high-low>limit){
            double mid=(low+high)/2;
            double downarea=areadown(squares,mid);
            double uparea=tot-downarea;
            
            
            
            if(downarea>=uparea){
                high=mid;
            }else{
                low=mid;
            }
            
        }
        return low;
    }
}