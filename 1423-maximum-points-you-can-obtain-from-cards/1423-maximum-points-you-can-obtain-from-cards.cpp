class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int sum=0,ans=0;
        int n=arr.size();

        for(int i=0;i<k;i++)
        sum+=arr[i];
        ans=sum;
        for(int i=0;i<k;i++)
        {
              sum-=arr[k-i-1];
              sum+=arr[n-1-i];
              ans=max(ans,sum);
        }
        return ans;
        
    }
};