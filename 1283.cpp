class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        long sum = 0;
        int right = 0;
        for (int num: nums) {
            sum += num;
            right = max(right, num);
        }
        int left = max((int)sum / threshold, 1);
        while (left < right) {
            int mid = (left + right) / 2, sum = 0;
            for (int num: nums) {
                sum += num % mid == 0 ? num / mid : num / mid + 1;
            }
            if (sum <= threshold) right = mid;
            else left = mid + 1;
        }
        return left;
    }
    // int smallestDivisor(vector<int>& A, int threshold) {
    //     int left = 1, right = 1e6, m, sum;
    //     while (left < right) {
    //         m = (left + right) / 2, sum = 0;
    //         for (int i : A)
    //             sum += (i + m - 1) / m;
    //         if (sum > threshold)
    //             left = m + 1;
    //         else
    //             right = m;
    //     }
    //     return left;
    // }
};