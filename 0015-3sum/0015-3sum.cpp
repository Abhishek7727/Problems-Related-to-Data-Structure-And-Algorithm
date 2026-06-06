class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        int left=0,right=n-1;
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++)
        {
               if(i>0 && nums[i] == nums[i-1]){
                continue;
            }
            left=i+1;
            right=n-1;
            while(left<right)
            {
                
                if(nums[left]+nums[right]==-nums[i])
                {
                    ans.push_back({nums[i],nums[left],nums[right]});
                    left++;
                    right--;
                    while((left<right )&& nums[left]==nums[left-1])
                    left++;
                   while((left <right) && nums[right]==nums[right+1])
                   right--;
                  
                }
                else if(nums[left]+nums[right]>-nums[i])
                right--;
                else
                left++;



            }
        }
        return ans;
    }
};