class Solution {
public:
    static int countBits(int n)
    {
        int count=0;
        while(n>0)
        {
            count++;
            n=n&(n-1);

        }
        return count;
    }
    static bool compare(int a,int b)
    {
        int countA=countBits(a);
        int countB=countBits(b);
        if(countA==countB)
        {
            return a<b;
        }
        return countA<countB;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),compare);
        return arr;
        
    }
};