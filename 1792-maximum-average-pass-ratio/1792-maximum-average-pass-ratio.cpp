class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int ex) {

        priority_queue<vector<double>> pq;
        int j=0;
        for(auto pair : classes){
            pq.push({double(pair[0]+1)/double(pair[1]+1)-double(pair[0])/double(pair[1]),double(j)});
            j++;
        }

    
        
        int i=0;
        while(i<ex){
            
            auto selected = pq.top();
            pq.pop();

            int index=int(selected[1]);

            classes[index][0]++;
            classes[index][1]++;
            pq.push({double(classes[index][0]+1)/double(classes[index][1]+1)-double(classes[index][0])/double(classes[index][1]),double(index)});

            i++;
        }
        
        double answer;
        for(auto pair : classes){
            answer+= double(pair[0])/double(pair[1]);
        }

        return double(answer)/double(classes.size());


    }
};