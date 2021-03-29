class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int left = k, right = k, n = nums.size() - 1;
        int curMin = nums[k], res = nums[k];
        while (left > 0 || right < n) {
            if (left == 0 || nums[left - 1] < nums[right + 1]) {
                right++;
            }else if (right == n || nums[left - 1] >= nums[right + 1]) {
                left--;
            }
            curMin = min(curMin, min(nums[left], nums[right]));
            res = max(res, curMin * (right - left + 1));
        }
        return res;
    }
};