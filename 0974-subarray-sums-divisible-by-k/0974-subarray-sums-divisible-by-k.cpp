class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans=0;
        int sum=0,rem;
        unordered_map<int,int>mp;
        mp[0]=1;
        for(int i=0;i<nums.size();i++)
        {
           sum+=nums[i];
           rem =sum%k;
           if(rem<0)
           {
            rem=rem+k;
           }
           if(mp.find(rem)!=mp.end())
           {
            ans+=mp[rem];

           }
           mp[rem]++;
        }
        return ans;
        
    }
};