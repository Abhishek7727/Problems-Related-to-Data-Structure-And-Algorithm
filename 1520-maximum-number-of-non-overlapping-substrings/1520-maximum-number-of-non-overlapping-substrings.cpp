class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {

        int n = s.size();

        // 1. First and last occurrence
        vector<int> first(26, -1);
        vector<int> last(26, -1);

        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';

            if (first[c] == -1)
                first[c] = i;

            last[c] = i;
        }

        // 2. Generate valid intervals
        vector<pair<int, int>> intervals;

        for (int c = 0; c < 26; c++) {

            if (first[c] == -1)
                continue;

            int l = first[c];
            int r = last[c];

            bool valid = true;

            // Expand r if required
            for (int i = l; i <= r; i++) {

                int x = s[i] - 'a';

                // This character occurs before l
                if (first[x] < l) {
                    valid = false;
                    break;
                }

                // This character occurs after r
                if (last[x] > r) {
                    r = last[x];
                }
            }

            if (valid) {
                intervals.push_back({l, r});
            }
        }

   
        sort(intervals.begin(), intervals.end(),
            [](const pair<int,int>& a,
               const pair<int,int>& b) {

                return a.second < b.second;
            });

       
        vector<string> ans;

        int prevEnd = -1;

        for (auto &p : intervals) {

            int l = p.first;
            int r = p.second;

            if (l > prevEnd) {

                ans.push_back(s.substr(l, r - l + 1));

                prevEnd = r;
            }
        }

        return ans;
    }
};