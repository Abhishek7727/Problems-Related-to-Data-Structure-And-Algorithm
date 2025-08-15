class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0;
        int cnt = 0;     // kitne odds window me
        int left = 0;    // pehle odd se pehle even count
        int ans = 0;

        while (j < n) {
            if (nums[j] % 2 != 0) { // odd aaya
                cnt++;
                left = 0;
            }

            while (cnt == k) {
                if (nums[i] % 2 != 0) cnt--;
                i++;
                left++;
            }

            ans += left;
            j++;
        }

        return ans;
    }
};