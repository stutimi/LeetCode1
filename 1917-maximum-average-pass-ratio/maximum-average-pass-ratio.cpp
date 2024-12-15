class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto gain = [](int pass, int total) {
            return (double)(pass + 1) / (total + 1) - (double)pass / total;
        };
        priority_queue<pair<double, pair<int, int>>> maxHeap;
        for (auto& c : classes) {
            maxHeap.push({gain(c[0], c[1]), {c[0], c[1]}});
        }
        while (extraStudents-- > 0) {
            auto [currGain, classData] = maxHeap.top();
            maxHeap.pop();
            int pass = classData.first, total = classData.second;
            pass++;
            total++;
            maxHeap.push({gain(pass, total), {pass, total}});
        }
        double totalRatio = 0.0;
        while (!maxHeap.empty()) {
            auto [_, classData] = maxHeap.top();
            maxHeap.pop();
            int pass = classData.first, total = classData.second;
            totalRatio += (double)pass / total;
        }

        return totalRatio / classes.size();
    }
};
