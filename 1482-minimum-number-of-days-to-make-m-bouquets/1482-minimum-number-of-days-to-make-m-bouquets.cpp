class Solution {
public: 
    bool isPossible(vector<int>&nums,int mid,int m,int k)
    {
        int bouqet=0;
        int cont=0;
        for(int x:nums)
        {
            if(x<=mid){
            cont++;
            if(cont==k){
            bouqet++;
            if(bouqet>=m)
            return true;
            cont=0;
            }
            
            }
            else
            cont=0;
        }
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long need=1LL*m*k;
        if(need>bloomDay.size())
        return -1;

        int low=*min_element(bloomDay.begin(),bloomDay.end());
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;

            if(isPossible(bloomDay,mid,m,k))
            {
                ans=mid;
                high=mid-1;

            }
            else
            low=mid+1;
        }
        return ans;
    }
};