class Solution {
public:
    vector<vector<int>>ans;
    void solve(int ind,int target,vector<int>&curr,vector<int>&nums)
    {
        if(target==0)
        {
            ans.push_back(curr);
            return ;
        }
        if(ind==nums.size() || target<0)
        return;

            curr.push_back(nums[ind]);
            solve(ind+1,target-nums[ind],curr,nums);
        
        curr.pop_back();
        int next=ind+1;
        while(next<nums.size() && nums[ind]==nums[next])
        next++;

        solve(next,target,curr,nums);
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {

        sort(nums.begin(),nums.end());
        vector<int>curr;
        solve(0,target,curr,nums);
        return ans;
        
    }
};