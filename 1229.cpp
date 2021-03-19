class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        for (auto slot : slots2) {
            slots1.push_back(slot);
        }
        sort(slots1.begin(), slots1.end());
        int end = slots1[0][1];
        for (int i = 1; i < slots1.size(); ++i) {
            if (slots1[i][0] < end && end - slots1[i][0] >= duration && slots1[i][1] - slots1[i][0] >= duration) {
                return {slots1[i][0], slots1[i][0] + duration};
            }
            end = max(end, slots1[i][1]);
        }
        return {};
    }
};

// Two pointers
class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        sort(slots1.begin(), slots1.end());
        sort(slots2.begin(), slots2.end());
        int n1 = slots1.size(), n2 = slots2.size();
        int i = 0, j = 0;
        while (i < n1 && j < n2) {
            int start = max(slots1[i][0], slots2[j][0]);
            int end = min(slots1[i][1], slots2[j][1]);
            if (end - start >= duration) return {start, start + duration};
            else if (slots1[i][1] > slots2[j][1]){
                j++;
            }else i++;
        }
        return {};
    }
};

//priority_queue
class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for (auto slot : slots1) {
            if (slot[1] - slot[0] >= duration) pq.push({slot[0], slot[1]});
        }
        for (auto slot : slots2) {
            if (slot[1] - slot[0] >= duration) pq.push({slot[0], slot[1]});
        }
        while(pq.size() > 1) {
            int end = pq.top().second;
            pq.pop();
            int start = pq.top().first;
            if (end - start >= duration) return {start, start + duration};
        }
        return {};
    }
};