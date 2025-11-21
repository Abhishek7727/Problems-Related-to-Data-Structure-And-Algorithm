class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int>ans;
        int j=1;
        while(j<=2){
        for(int i=0;i<nums.size();i++)
        {
            ans.push_back(nums[i]);
        }
        j++;
        }
        return ans;

        
    }
};