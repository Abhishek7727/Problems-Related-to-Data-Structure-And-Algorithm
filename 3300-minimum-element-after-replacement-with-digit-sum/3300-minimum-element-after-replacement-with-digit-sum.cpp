class Solution {
public:
    int sum(int n)
    {
        int ans=0;
        while(n)
        {
            ans+=n%10;
            n=n/10;
        }
        return ans;
    }
    int minElement(vector<int>& nums) {
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            ans=min(ans,sum(nums[i]));
        }
        return ans;
        
    }
};