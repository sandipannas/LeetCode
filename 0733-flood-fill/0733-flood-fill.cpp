class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        if(image[sr][sc]==color){ return image; }

        int m=image.size();
        int n=image[0].size();
        queue<pair<int,int>> line;

        int original=image[sr][sc];
        
        image[sr][sc]=color;
        line.push({sr,sc});

        while(line.size()!=0){
            //cout<<line.size()<<endl;
            int i=line.front().first;
            int j=line.front().second;
            line.pop();

            //up
            if(i-1>=0 && image[i-1][j]==original){ 
                //cout<<"pushing "<<i-1<<" "<<j<<endl;
                image[i-1][j]=color; 
                line.push({i-1,j});
            }
            //down
            if(i+1<m && image[i+1][j]==original){ 
                //cout<<"pushing "<<i+1<<" "<<j<<endl;
                image[i+1][j]=color; 
                line.push({i+1,j});
            }
            //left
            if(j-1>=0 && image[i][j-1]==original){ 
                //cout<<"pushing "<<i<<" "<<j-1<<endl;
                image[i][j-1]=color; 
                line.push({i,j-1});
            }
            //right
            if(j+1<n && image[i][j+1]==original){ 
                //cout<<"pushing "<<i<<" "<<j+1<<endl;
                image[i][j+1]=color; 
                line.push({i,j+1});
            }
        }
        return image;

    }
};