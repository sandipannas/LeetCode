class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string answer="";
        int up=0;
        int down=0;

        int flag=0;

        while(up<word1.size() && down<word2.size()){
            if(flag==0){
                flag=1;
                answer.push_back(word1[up]);
                up++;
            }
            else{
                flag=0;
                answer.push_back(word2[down]);
                down++;
            }
        }

        while(up<word1.size()){
            answer.push_back(word1[up]);
            up++;
        }

        while(down<word2.size()){
            answer.push_back(word2[down]);
            down++;
        }

        return answer;
    }
};