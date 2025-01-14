class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> f(A.size() + 1, 0);
        vector<int> ans;
        int c = 0;
        
        for (int i = 0; i < A.size(); i++) {
            if (++f[A[i]] == 2){ c++;}
            if (++f[B[i]] == 2){ c++;}
            ans.push_back(c);
        }
        return ans;
    }
};