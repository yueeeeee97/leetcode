class Solution {
public:
    static bool cmp(const vector<int> &a, const vector<int> &b) {
        if(a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }

    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int res = 0, left = 0;
        sort(intervals.begin(), intervals.end(),cmp);
        for(auto interval: intervals) {
            if(interval[1] > left) {
                res++;
                left = interval[1];
            }
        }
        return res;
    }
};