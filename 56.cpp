class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        vector<int> starts, ends;
        for (auto interval: intervals) {
            starts.push_back(interval[0]);
            ends.push_back(interval[1]);
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        for (int i = 0; i < intervals.size(); ++i) {
            int tmp = i;
            while (i < intervals.size() - 1 && starts[i+1] <= ends[i]) i++;
            res.push_back({starts[tmp], ends[i]});
        }
        return res;
    }
};