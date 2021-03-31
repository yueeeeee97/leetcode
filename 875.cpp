class Solution {
public:

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int left = 1, right = 0;
        for (int p: piles) right = max(right, p);
        if (h == n) return right;
        while (left < right) {
            int mid = (left + right) / 2, cnt = 0;
            for (int p: piles) cnt += (p % mid == 0) ? p / mid : p / mid + 1;
            if (cnt <= h) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};