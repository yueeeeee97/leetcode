class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        long p = 0, q = 0;
        for (int i = 0, j = 0; i < n1 || j < n2;) {
            if (i < n1 && (j == n2 || nums1[i] < nums2[j])) {
                p += nums1[i++];
            }else if (j < n2 && (i == n1 || nums1[i] > nums2[j])) {
                q += nums2[j++];
            }else {
                p = q = max(p, q) + nums1[i];
                i++;j++;
            }
        }
        return max(p, q) % (int)(1e9 + 7);
    }
};