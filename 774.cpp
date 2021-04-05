class Solution {
public:
    bool isValid(vector<int>& nums, int k, double mid) {
        int cnt = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] - nums[i - 1] > mid) {
                cnt += ceil((nums[i] - nums[i - 1]) / mid) - 1;
                if (cnt > k) return false;
            }   
        }
        return true;
    }
    double minmaxGasDist(vector<int>& stations, int k) {
        double left = 0, right = 0;
        int n = stations.size();
        for (int i = 1; i < n; ++i) {
            right = max(right, (double)stations[i] - stations[i - 1]);
        }
        while (left + 1e-6 < right) {
            double mid = (left + right) / 2;
            if (isValid(stations, k, mid)) right = mid;
            else left = mid;
        }
        return left;
    }
};