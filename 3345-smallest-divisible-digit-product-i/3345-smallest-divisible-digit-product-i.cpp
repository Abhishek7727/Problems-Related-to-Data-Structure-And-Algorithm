class Solution {
public:
    int smallestNumber(int n, int t) {
        int x=n;
        while(true)
        {
           int num=x;
           int pro=1;
           while(num)
           {
             pro=pro*(num%10);
            num=num/10;
           }
           if(pro%t==0)
           return x;
           x++;
        }
        
    }
};