class Solution {
    public int subarraysDivByK(int[] nums, int k) {
        int[] arr = new int[k];
        arr[0]++;
        int s = 0;
        int c = 0;
        for(int i=0;i<nums.length;i++){
            s = ((s + nums[i])%k + k)%k;
            c += arr[s];
            arr[s]++;
        }
        return c;
    }
}
