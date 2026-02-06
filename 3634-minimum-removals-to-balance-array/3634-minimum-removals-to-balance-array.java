class Solution {
    public int minRemoval(int[] nums, int k) {
        int n = nums.length;
        Arrays.sort(nums);
        int j = 0;
        int res = Integer.MIN_VALUE;

        for(int i = 0; i < n; i++)
        {
            while((long) nums[i] > (long) nums[j] * k)
            {
                j++;
            }
            res = Math.max(res, i - j + 1);
        }
        return n - res;
    }
}