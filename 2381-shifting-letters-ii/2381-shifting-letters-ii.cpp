class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& Q) {
        int n = s.size();
        vector<int> gg(n, 0);
        for (auto& i : Q) {
            int l = i[0];
            int r = i[1];
            int t = i[2];
            if (t == 1) {
                gg[l] += 1;
                if (r + 1 < n) {
                   gg[r + 1] -= 1;
                }
            } else
            
             {
                gg[l] -= 1;
                if (r + 1 < n) {
                    gg[r + 1] += 1;
                }
            }
        }
        for (int i = 1; i < n; ++i) {
            gg[i] += gg[i - 1];
        }
        for (int i = 0; i < n; ++i) {
            int shift = (gg[i] % 26 + 26) % 26; 
            int ch = s[i] - 'a';
            ch = (ch + shift) % 26;
            s[i] = 'a' + ch;
        }
        return s;
    }
};