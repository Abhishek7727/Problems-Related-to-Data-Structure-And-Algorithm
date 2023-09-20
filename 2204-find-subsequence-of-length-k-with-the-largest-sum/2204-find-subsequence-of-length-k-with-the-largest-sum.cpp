class Solution {
public:

    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minH;
        for(int i=0;i<nums.size();i++)
        {
            minH.push({nums[i],i});
            if(minH.size()>k)
            minH.pop();
        }
        vector<int>ans;
        while(minH.size())
        {
            ans.push_back(minH.top().second);
            minH.pop();
        }
        sort(ans.begin(),ans.end());
        vector<int>res;
        
        for(int i=0;i<ans.size();i++)
        {
           res.push_back(nums[ans[i]]);
        }
        return res;

    }
};