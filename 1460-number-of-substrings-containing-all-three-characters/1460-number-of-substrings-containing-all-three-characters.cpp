class Solution {
public:
    int numberOfSubstrings(string s) {
        // 
           int n = s.size();
        vector<int> freq(3, 0);
        int left = 0, right = 0, countDistinct = 0, ans = 0;

        while (right < n) {
            // expand window
            if (freq[s[right] - 'a'] == 0) countDistinct++;
            freq[s[right] - 'a']++;
            right++;

            // shrink window while condition true
            while (countDistinct == 3) {
                ans += (n - right + 1);
                freq[s[left] - 'a']--;
                if (freq[s[left] - 'a'] == 0) countDistinct--;
                left++;
            }
        }
        return ans;
    }
};