/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    vector<int> list;
    int i;
    int total;
    NestedIterator(vector<NestedInteger> &nestedList) {
        list=debunk(nestedList);
        i=0;
        total=list.size();
    }

    const vector<int> debunk(vector<NestedInteger> &nestedList){
        vector<int> answer;
        for(int i=0;i<nestedList.size(); i++){
            if (nestedList[i].isInteger()){
                answer.push_back(nestedList[i].getInteger());
            }
            else{
                vector<int> gg;
                gg=debunk(nestedList[i].getList());
                for(int i:gg){
                    answer.push_back(i);
                }
            }
        }
        return answer;
    }
    
    int next() {
        int tem=list[i]; i++;
        return tem;
    }
    
    bool hasNext() {
        if(i>=total){ return false; }
        return true;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */