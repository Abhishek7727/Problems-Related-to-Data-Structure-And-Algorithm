class Solution {
public:
    int maxArea(vector<int>& nums) {
        int area=0;
        int left=0;
        int right=nums.size()-1;

        while(left<right)
        {
            int width=right-left;
            int ans=min(nums[left],nums[right])*width;
           area=max(ans,area);
            if(nums[left]>nums[right])
            right--;
            else
            left++;
        }
        return area;
        
    }
};