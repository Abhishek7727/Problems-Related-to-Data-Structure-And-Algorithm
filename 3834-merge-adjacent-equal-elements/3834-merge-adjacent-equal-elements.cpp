class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        vector<long long>v;
        for(int x:nums)
            {
                long long curr=x;
                while(v.size()>0 && v.back()==curr)
                    {
                        curr=curr+v.back();
                        v.pop_back();
                    }
                v.push_back(curr);
            }
        // for(auto x:v)
        //     {
        //         cout<<x<<" ";
        //     }
        return v;
    }
};