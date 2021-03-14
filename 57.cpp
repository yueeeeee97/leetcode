// Solution 1: sort
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        vector<int> starts{newInterval[0]};
        vector<int> ends{newInterval[1]};
        for (auto interval: intervals) {
            starts.push_back(interval[0]);
            ends.push_back(interval[1]);
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        
        for (int i = 0; i < starts.size(); ++i) {
            int curStart = i;
            while (i < starts.size() - 1 && starts[i+1] <= ends[i]) i++;
            res.push_back({starts[curStart], ends[i]});
        }
        return res;
    }
};

//map timeline
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        map<int, int> m;
        vector<vector<int>> res;
        for (auto interval: intervals) {
            m[interval[0]]++;
            m[interval[1]]--;
        }
        m[newInterval[0]]++;
        m[newInterval[1]]--;
        int curStart = 0, sum = 0;
        for (auto iter: m) {
            if (sum == 0) curStart = iter.first;
            sum += iter.second;
            if (sum == 0) res.push_back({curStart, iter.first});
        }
        return res;
    }
};