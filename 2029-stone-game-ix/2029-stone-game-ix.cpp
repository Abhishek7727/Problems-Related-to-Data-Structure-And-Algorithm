class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
          int cnt[3] = {0};

        for (int x : stones) {
            cnt[x % 3]++;
        }

        int c0 = cnt[0];
        int c1 = cnt[1];
        int c2 = cnt[2];

        // Alice has only one type among remainder 1/2.
        if (c1 == 0 || c2 == 0) {
            return max(c1, c2) > 2 && c0 % 2 == 1;
        }

        // Both remainder 1 and 2 exist.
        if (c0 % 2 == 0) {
            return true;
        }

        return abs(c1 - c2) > 2;
    }
};