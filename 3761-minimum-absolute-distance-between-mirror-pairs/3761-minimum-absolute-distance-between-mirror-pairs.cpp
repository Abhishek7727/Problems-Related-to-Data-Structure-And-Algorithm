class Solution {
public:
    int reverse(int x)
    {
        int ans=0;
        while(x>0)
        {
            ans=ans*10+x%10;
            x=x/10;
        }
        return ans;
    }
    int minMirrorPairDistance(vector<int>& nums) {
            unordered_map<int, int> mp; // number -> latest index
        int res = INT_MAX;

        for (int j = 0; j < nums.size(); j++) {
            int rev = reverse(nums[j]);

            // Need previous index i where nums[i] = reverse(nums[j])
            if (mp.find(nums[j]) != mp.end()) {
                res = min(res, j - mp[nums[j]]);
            }

            // store current index
            mp[rev] = j;
        }

        return (res == INT_MAX) ? -1 : res;
       
       
        
        
        return res==INT_MAX?-1:res;
    }
};