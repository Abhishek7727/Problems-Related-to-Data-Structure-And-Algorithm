class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
    unordered_map<int, vector<int>> mp;
    int n = nums.size();
    vector<long long> ans(n);

    // same value ke indices store
    for(int i=0;i<n;i++){
        mp[nums[i]].push_back(i);
    }

    for(auto &it : mp){

        vector<int> pos = it.second;

        long long total = 0;
        for(int x : pos) total += x;

        long long leftSum = 0;
        int m = pos.size();

        for(int i=0;i<m;i++){

            total -= pos[i]; // ab ye right sum hai

            long long left =
                1LL * i * pos[i] - leftSum;

            long long right =
                total - 1LL * (m-i-1) * pos[i];

            ans[pos[i]] = left + right;

            leftSum += pos[i];
        }
    }

    return ans;
}
};