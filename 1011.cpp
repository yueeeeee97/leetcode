class Solution {
public:
    bool isValid(vector<int>& weights, int D, int mid) {
        int cnt = 1, curSum = 0;
        for (int w: weights) {
            curSum += w;
            if (curSum > mid) {
                cnt ++;
                curSum = w;
            }
            if (cnt > D) return false;
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int D) {
        int maxNum = 0, sum = 0;
        for (int w: weights) {
            maxNum = max(maxNum, w);
            sum += w;
        }
        while (maxNum < sum) {
            int mid = (maxNum + sum) / 2;
            if (isValid(weights, D, mid)) sum = mid;
            else maxNum = mid + 1;
        }
        return maxNum;
    }
};