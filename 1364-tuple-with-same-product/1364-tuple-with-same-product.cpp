class Solution {
public:
int nC2(int n)
{
    return (n*(n-1)/2);
}
    int tupleSameProduct(vector<int>& nums) {

        int n=nums.size();
        unordered_map<int,int>mp;
        int count=0;
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int pro=nums[i]*nums[j];
                mp[pro]++;
            }
        } 

        for(auto x:mp)
        {
            int m=x.second;
            count+=8*nC2(m);
        }

        return count;
        
    }
};