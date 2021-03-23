// 自己一开始的想法。。有点小复杂
// int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
//     int sum = 0;
//     vector<pair<int, int>> m;
//     for (int i = 0; i < customers.size(); ++i) {
//         if (grumpy[i] == 0) sum += customers[i];
//         else m.push_back(make_pair(i, customers[i]));
//     }
//     int start = 0, curSum = m.empty() ? 0 : m[0].second;
//     int cur = curSum;
//     for (int end = 1; end < m.size(); ++end) {
//         curSum += m[end].second;
//         while (m[end].first - m[start].first >= X) {
//             curSum -= m[start++].second;
//         }
//         cur = max(cur, curSum);
//     }
//     return sum + cur;
// }

//sliding window
int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
    int sum = 0, curSum = 0, maxSum = 0;
    for (int i = 0; i < customers.size(); ++i) {
        sum += grumpy[i] == 0 ? customers[i] : 0;
        curSum += grumpy[i] == 1 ? customers[i] : 0;
        if (i >= X) curSum -= grumpy[i - X] == 0 ? 0 : customers[i - X];
        maxSum = max(maxSum, curSum);
    }
    return sum + maxSum;
}