class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            int t=-nums[i]; 
            int l=i+1;
            int h=n-1;
            while(l<h)
            {
                if(nums[l]+nums[h]==t)
                {
                    while(l<h&&nums[l]==nums[l+1])
                    l++;
                    while(l<h&&nums[h]==nums[h-1])
                    h--;
                    ans.push_back({nums[i],nums[l],nums[h]});
                    l++;
                    h--;
                }
                else if(nums[l]+nums[h]>t)
                h--;
                else
                l++;
            }
            while(i+1<n&&nums[i]==nums[i+1])
            i++;
        }
        return ans;
    }
};