class Solution {
public:
    long long findHour(vector<int>& arr,int speed)
    {
        long long h=0;
        for(int i=0;i<arr.size();i++)
        {
            h=h+arr[i]/speed;
            if(arr[i]%speed!=0)
            {
                h++;
            }
        }
        return h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1,high=*(max_element(piles.begin(),piles.end()));
        int res=-1;
        while(low<=high)
        {
            int mid=(low+high)/2;

            long long x= findHour(piles,mid);
            if(x>h)
            {
                low=mid+1;
            }
            else
            {
                res=mid;
                high=mid-1;
            }
        }
        return res;
        
    }
};