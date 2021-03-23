class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int last = 0, res = 0;
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] < intervals[last][1]) {
                res++;
                if (intervals[i][1] < intervals[last][1])
                    last = i;
            }else last = i;
        }
        return res;
    }
};