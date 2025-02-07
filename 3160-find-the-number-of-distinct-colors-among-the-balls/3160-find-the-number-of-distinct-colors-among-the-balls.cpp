class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int> balltocolor;
        unordered_map<int,int> colorno;
        vector<int> ans;

        for(auto& i:queries)
        {
            int ball=i[0];
            int color=i[1];

            if(!balltocolor.count(ball)) { balltocolor[ball]=color; colorno[color]++;}
            else{
                  //delete the exisiting color count
                  colorno[balltocolor[ball]]--; if(colorno[balltocolor[ball]]==0) {colorno.erase(balltocolor[ball]);}

                  //increase the color count of the new color count
                  colorno[color]++;

                  //change the ball color
                  balltocolor[ball]=color;
                }
                ans.push_back(colorno.size());
        }
        return ans;
    }
};