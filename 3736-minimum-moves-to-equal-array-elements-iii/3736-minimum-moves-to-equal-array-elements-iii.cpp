class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ele=*max_element(nums.begin(),nums.end());
        //cout<<<ele;
        int ans=0;
        for(int x:nums)
        {
            ans+=(ele-x);
        }
        return ans;
    }
};