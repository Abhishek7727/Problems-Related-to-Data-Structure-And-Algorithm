class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int minn=nums[k];
        int ans=nums[k];
        int left=k,right=k;
        while(left>0 || right<nums.size()-1)
        {
           if (left == 0)
            {
                right++;
                minn = min(minn, nums[right]);
            }
               else if (right == nums.size() - 1)
            {
                left--;
                minn = min(minn, nums[left]);
            }

            else if(nums[left-1]>nums[right+1])
            {
                  left--;
                minn=min(minn,nums[left]);
              
            }
            else
            {
                right++;
                minn=min(minn,nums[right]);
                
            }
            ans=max(ans,minn*(right-left+1));
        }
        return ans;
    }
};