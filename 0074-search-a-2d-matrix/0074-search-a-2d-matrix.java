class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
       
       int m=matrix.length;
       int n=matrix[0].length;
       if(target>matrix[m-1][n-1] || target<matrix[0][0])
       {
        return false;
       }
       int st=0;
       int ed=m-1;
       while(st<ed)
       {
        int mid=st+(ed-st)/2;
        if( target<=matrix[mid][n-1] && target>=matrix[mid][0])
        {
            st=mid;ed=mid;

        }
        else if(target>matrix[mid][n-1])
        {
            st=mid+1;
        }
        else if(target<matrix[mid][n-1])
        {
            ed=mid-1;
        }
        System.out.println("st= " + st + " ed= " + ed);
       }
       ed=n-1;
       n=st;
       st=0;

       while(st<ed)
       { System.out.println("i started");
        int mid=st+(ed-st)/2;
        if(target==matrix[n][mid])
        {
            return true;
        }
        else if(target>matrix[n][mid])
        {
            st=mid+1;
        }
        else
        {
            ed=mid-1;
        }
       }
       
        if(st==ed && matrix[n][st]==target)
        {
            return true;
        }
        
       
       return false; 
    }
}