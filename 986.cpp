class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> res;
        vector<int> starts, ends;
        for (auto first: firstList) {
            starts.push_back(first[0]);
            ends.push_back(first[1]);
        }
        for (auto second: secondList) {
            starts.push_back(second[0]);
            ends.push_back(second[1]);
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        for(int i = 1; i < starts.size(); ++i) {
            if (starts[i] <= ends[i-1]) {
                res.push_back({starts[i], ends[i-1]});
            }
        }
        return res;
    }
};