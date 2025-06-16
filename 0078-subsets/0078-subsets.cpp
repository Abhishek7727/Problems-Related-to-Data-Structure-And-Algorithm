class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>op;
        solve(0,op,ans,nums);
        return ans;
    }
    void solve(int index, vector<int>op,vector<vector<int>>& ans,vector<int> nums)
    {
        if(nums.size()==index)
        {
            ans.push_back(op);
            return;
        }
        
        solve(index+1,op,ans,nums);

       
       op.push_back(nums[index]);
         solve(index+1,op,ans,nums);
         



    }
};