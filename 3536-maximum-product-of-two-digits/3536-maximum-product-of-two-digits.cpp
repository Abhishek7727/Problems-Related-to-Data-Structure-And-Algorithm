class Solution {
public:
    int maxProduct(int n) {
        int maxx=n%10;
        n=n/10;
        if(n==0)
        return maxx;
        

        int prev=n%10;
        n=n/10;
        if(prev>maxx)
        {
            swap(prev,maxx);
        }
        while(n)
        {
          int curr=n%10;
          if(curr>maxx)
          {
            prev=maxx;
            maxx=curr;
          }
          else
          {
            if(prev<curr)
            prev=curr;
          }
          n=n/10;
        }
        return prev*maxx;
        
    }
};