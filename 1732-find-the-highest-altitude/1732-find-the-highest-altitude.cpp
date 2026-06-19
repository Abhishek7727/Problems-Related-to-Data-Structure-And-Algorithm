class Solution {
public:
    int largestAltitude(vector<int>& gains) {
        int res=gains[0];
        int sum=gains[0];
        for(int i=1;i<gains.size();i++)
        {
            sum+=gains[i];
            res=max(res,sum);
        }
        if(res<0)
        return 0;
        return res;
        
    }
};