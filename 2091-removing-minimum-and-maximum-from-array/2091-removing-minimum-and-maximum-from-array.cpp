class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mx=0,mn=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[mx]<nums[i])
            mx=i;
            if(nums[mn]>nums[i])
            mn=i;
        }
        int ans=0;
        
            int front=max(mx,mn)+1;
        

            int back=max(n-mx,n-mn);
        
        int middle= min(
            mn + 1 + (n - mx),
            mx + 1 + (n - mn));

        return min({front,back,middle});
    }
};