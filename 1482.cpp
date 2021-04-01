class Solution {
public:
    bool isValid(vector<int>& bloomDay, int mid, int m, int k) {
        int cnt = 0, cur = 0;
        for (int num: bloomDay) {
            if (num > mid)
                cur = 0;
            else if (++cur >= k) {
                cnt++;
                cur = 0;
            }
        }
        return cnt >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int left = INT_MAX, right = 0;
        if (bloomDay.size() < m * k) return -1;
        for (int n: bloomDay) {
            left = min(left, n);
            right = max(right, n);
        }
        
        left = left + m * k - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (isValid(bloomDay, mid, m, k)) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};