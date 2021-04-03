class Solution {
public:
    bool isValid(vector<int>& sweetness, int mid, int K) {
        int cnt = 0, curSum = 0;
        for (int s: sweetness) {
            curSum += s;
            if (curSum >= mid) {
                cnt++;
                curSum = 0;
                if (cnt >= K) return false;
            }
        }
        return true;
    }
    int maximizeSweetness(vector<int>& sweetness, int K) {
        int left = INT_MAX, sum = 0;
        for (int s: sweetness) {
            left = min(left, s);
            sum += s;
        }
        if (sweetness.size() == K + 1) return left;
        while (left <= sum) {
            int mid = (left + sum) / 2;
            if (isValid(sweetness, mid, K + 1)) sum = mid - 1;
            else left = mid + 1;
        }
        return sum;
    }
};