class Solution {
public:
     void solve(int n ,unordered_map<string,int>&mp,string res)
     {
        if(n==0)
        {
            mp[res]=1;
            return ;

        }
        solve(n-1,mp,res+"0");
        solve(n-1,mp,res+"1");

     }
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_map<string,int>mp;
        int n=nums[0].size();
        solve(n,mp,"");
       for(auto s : nums)
        {
            mp.erase(s);
        }
            for(auto it : mp)
        {
            return it.first;
        }

        return "";
        
    }
};