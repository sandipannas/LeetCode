class Solution {
    public long maxMatrixSum(int[][] matrix) {
        int m=matrix.length;
        int n=matrix[0].length;
        int count=0;
        long sum=0;
        long min=Long.MAX_VALUE;
        int flag=0;
        for(int i=0;i<m;i++)
        {   
        
            for(int j=0;j<n;j++)
            {   if(matrix[i][j]==0)
            {
                flag=1;
                
            }
                if(matrix[i][j]<=0)
                {
                    count++;
                }
                sum+=Math.abs(matrix[i][j]);
                min=Math.min(min,Math.abs(matrix[i][j]));

            }
        }

    if(count%2==0 || flag==1)
    {
      return sum;
    }
    else
    {
        return sum-(min*2);
    }
    }
}