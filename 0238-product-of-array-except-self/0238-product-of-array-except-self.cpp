class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>suffix(n,1);
        vector<int>prefix(n,1);

        for(int i=1;i<n;i++)
        {
            suffix[i]=suffix[i-1]*nums[i-1];
            prefix[n-1-i]=prefix[n-i]*nums[n-i];
        }
        for(int i=0;i<n;i++)
        {
            suffix[i]=suffix[i]*prefix[i];
        }
        return suffix;
        
        
    }
};