class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
           int n = nums.size();
    long long S1 = 0, S2 = 0;
    long long E1 = (long long)n * (n + 1) / 2;
    long long E2 = (long long)n * (n + 1) * (2 * n + 1) / 6;

    for (int x : nums) {
        S1 += x;
        S2 += (long long)x * x;
    }

    long long diff1 = S1 - E1; // dup - miss
    long long diff2 = S2 - E2; // dup^2 - miss^2
    long long sum_dm = diff2 / diff1; // dup + miss

    int duplicate = (diff1 + sum_dm) / 2;
    int missing = duplicate - diff1;

    return {duplicate, missing};
        
    }
};