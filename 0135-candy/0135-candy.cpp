class Solution {
public:
    int candy(vector<int>& arr) {
      //  int count=arr.size();
        int n=arr.size();

       vector<int>freq(n,1);
       for(int i=1;i<n;i++)
       {
          if(arr[i]>arr[i-1])
          freq[i]=freq[i-1]+1;
       }
       for(int i=n-1;i>0;i--)
       {
        if(arr[i-1]>arr[i])
        {
            freq[i-1]=max(freq[i]+1,freq[i-1]);
        }
       }

       int sum=0;
       for(int x:freq)
       sum+=x;
       return sum;



        
    }
};