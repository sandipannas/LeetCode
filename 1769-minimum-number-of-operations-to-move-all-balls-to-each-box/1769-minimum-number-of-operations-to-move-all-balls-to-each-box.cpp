class Solution {
public:
    vector<int> minOperations(string boxes) {
        int x = boxes.size();
        vector<int> left(x, 0), right(x, 0), res(x, 0);
        int count = (boxes.at(0) == '1' ? 1 : 0);

        for (int i = 1; i < x; i++) {
            left[i] = left[i - 1] + count;
            count += (boxes.at(i) == '1' ? 1 : 0);
        }

        count = (boxes.at(x-1) == '1' ? 1 : 0);

        for (int i = x - 2; i >= 0; i--) {
            right[i] = right[i + 1] + count;
            count += (boxes.at(i) == '1' ? 1 : 0);
        }

        for (int j = 0; j < x; j++) {
            res[j] = left[j] + right[j];
        }

        return res;
    }
};