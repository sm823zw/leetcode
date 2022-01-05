class Solution {
    public int maxSum(int[] nums1, int[] nums2) {
        int i = 0;
        int j = 0;
        int m = nums1.length;
        int n = nums2.length;
        long ans_1 = 0;
        long ans_2 = 0;
        long mod = (long)1e9 + 7;
        while(i<m || j<n){
            if(i<m && (j==n || nums1[i]<nums2[j])){
                ans_1 += nums1[i];
                i++;
            }
            else if(j<n && (i==m || nums1[i]>nums2[j])){
                ans_2 += nums2[j];
                j++;
            }
            else{
                ans_1 = Math.max(ans_1, ans_2) + nums1[i];
                ans_2 = ans_1;
                i++;
                j++;
            }
        }
        return (int)(Math.max(ans_1, ans_2)%mod);
    }
}