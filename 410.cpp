class Solution {
public:
    bool isValid(vector<int>& nums, int mid, int m) {
        int curSum = 0, cnt = 0;
        for (int n: nums) {
            curSum += n;
            if (curSum > mid){
                cnt++;
                curSum = n;
                if (cnt >= m) return false;
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int m) {
        int maxNum = 0, sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            maxNum = max(maxNum, nums[i]);
            sum += nums[i];
        }
        if (m == 1) return sum;
        if (m == nums.size()) return maxNum;
        int left = maxNum, right = sum;
        while (left < right) {
            int mid = (left + right) / 2;
            if (isValid(nums, mid, m)) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};
