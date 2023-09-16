class Solution {
public:
    double findMedianSortedArrays(vector<int>& num1, vector<int>& num2) {
        int n=num1.size(),m=num2.size();
        vector<int>arr(n+m,0);
        int i=0,j=0;
        int k=0;
        while(i<n&&j<m)
        {
            if(num1[i]<=num2[j])
            arr[k++]=num1[i++];
            else 
            arr[k++]=num2[j++];
        }
        while(i<n)
        {
            arr[k++]=num1[i++];
        }
        while(j<m)
        arr[k++]=num2[j++]; 
        
    int x=n+m;
    if(x%2==0)
    return (arr[x/2]+arr[x/2-1])/2.0;
    return arr[x/2];
    }
};