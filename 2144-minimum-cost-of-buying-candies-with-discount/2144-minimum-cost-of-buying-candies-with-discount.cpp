class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        int n=cost.size();
        int count=0;

        for(int i=n-1;i>=0;i=i-3)
        { 
           
          count+=cost[i];
          if(i-1>=0)
          count+=cost[i-1];
        }
        return count;
    }
};