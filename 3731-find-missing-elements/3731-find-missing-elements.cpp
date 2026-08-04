class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>ans;
        int x=nums[0];
        int i=0;
        int n=nums.size();
        while(x<=nums[n-1] && i<n)
        {
           if(x!=nums[i])
           {
            ans.push_back(x);
            x++;
           }
           else
           {
            x++;
            i++;
           }
        }
        return ans;
    }
};