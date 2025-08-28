class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
     
     priority_queue<int> maxHeap;
     priority_queue<int , vector<int>,greater<int>> minHeap;

     for(int k=0;k<grid.size();k++){
        int j=0;
        for(int i=k;i<grid.size();i++){
            int element=grid[i][j];
            maxHeap.push(element);
            j++;
        }

        int l=0;
        for(int m=1+k;m<grid.size();m++){

            
            int element=grid[l][m];
            //cout<<element<<"->";
            minHeap.push(element);
            l++;
        }   

        l=0;
        for(int m=1+k;m<grid.size();m++){
            grid[l][m]=minHeap.top();
            minHeap.pop();
            l++;
        }



        j=0;
        for(int i=k;i<grid.size();i++){
            grid[i][j]=maxHeap.top();
            maxHeap.pop();
            j++;
        }
        //cout<<endl;

    
     }
       return grid;
    }
};