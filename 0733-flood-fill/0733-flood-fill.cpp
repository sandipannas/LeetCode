class Solution {
public:
    void colorr(vector<vector<int>>& image, int sr, int sc, int color, int original){
        if(sr<0 || sr>=image.size() || sc<0 || sc>=image[0].size() || image[sr][sc]!=original || image[sr][sc]==color){ return;}

        image[sr][sc]=color;
        //up
        colorr(image,sr-1,sc,color,original);
        //right
        colorr(image,sr,sc+1,color,original);
        //left
        colorr(image,sr,sc-1,color,original);
        //down
        colorr(image,sr+1,sc,color,original);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int original = image[sr][sc];

        if(color==original){ return image; }
        colorr(image,sr,sc,color,original);

        return image;
    }
};