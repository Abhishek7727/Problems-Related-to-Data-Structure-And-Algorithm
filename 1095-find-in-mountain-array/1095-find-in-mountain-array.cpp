/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
   int findPeak(MountainArray &arr)
   {
    int low=0;
    int high=arr.length()-1;
    while(low<high)
    {
        int mid=low+(high-low)/2;
        int curr=arr.get(mid);
        int next=arr.get(mid+1);
        if(curr<next)
        {
            low=mid+1;
        }
        else
        {
            high=mid;
        }
        
    }
    return low;
   }
   int searchLeft(MountainArray &arr,int low,int high,int target)
   {
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(arr.get(mid)==target)
        return mid;
        else if(arr.get(mid)<target)
        {
            low=mid+1;
        }
        else
        high=mid-1;
    }
    return -1;
   }

   int searchRight(MountainArray &arr,int low,int high,int target)
   {
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(arr.get(mid)==target)
        return mid;
        else if(arr.get(mid)>target)
        {
            low=mid+1;
        }
        else
        high=mid-1;
    }
    return -1;
   }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peak=findPeak(mountainArr);
        int leftAns=searchLeft(mountainArr,0,peak,target);
        if(leftAns!=-1)
        return leftAns;

        return searchRight(mountainArr,peak+1,mountainArr.length()-1,target);
    }
};