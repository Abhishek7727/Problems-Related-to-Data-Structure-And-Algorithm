class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {

        long long maxTriplet=0,maxElement=0,maxDiff=0;
        for(long long x:nums)
        {
            maxTriplet=max(maxDiff*x,maxTriplet);
            maxDiff=max(maxDiff,maxElement-x);
            maxElement=max(maxElement,x);
        }
        return maxTriplet;
    }
};