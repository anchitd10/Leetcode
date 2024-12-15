// Problem-1792: Maximum Average Pass Ratio

// There is a school that has classes of students and each class will be having a final exam. You are given a 2D integer array classes, where classes[i] = [passi, totali]. You know beforehand that in the ith class, there are totali total students, but only passi number of students will pass the exam.
// You are also given an integer extraStudents. There are another extraStudents brilliant students that are guaranteed to pass the exam of any class they are assigned to. You want to assign each of the extraStudents students to a class in a way that maximizes the average pass ratio across all the classes.
// The pass ratio of a class is equal to the number of students of the class that will pass the exam divided by the total number of students of the class. The average pass ratio is the sum of pass ratios of all the classes divided by the number of the classes.
// Return the maximum possible average pass ratio after assigning the extraStudents students. Answers within 10-5 of the actual answer will be accepted.
// Example 1:
// Input: classes = [[1,2],[3,5],[2,2]], extraStudents = 2
// Output: 0.78333
// Explanation: You can assign the two extra students to the first class. The average pass ratio will be equal to (3/4 + 3/5 + 2/2) / 3 = 0.78333.

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        // calculate the improvement in pass ratio
        auto ratioImprovement = [](int pass, int total) -> double {
            return (double)(pass + 1) / (total + 1) - (double)pass / total;
        };

        priority_queue<pair<double, pair<int, int>>> maxHeap;

        // priority queue with all classes
        for (auto& cls : classes) {
            int pass = cls[0];
            int total = cls[1];
            double improvement = ratioImprovement(pass, total);
            maxHeap.push({improvement, {pass, total}});
        }

        while (extraStudents--) {
            // class with the maximum improvement
            auto top = maxHeap.top();
            maxHeap.pop();
            double improvement = top.first;
            int pass = top.second.first;
            int total = top.second.second;

            pass++;
            total++;

            // improvement and push it back into the heap
            maxHeap.push({ratioImprovement(pass, total), {pass, total}});
        }

        // final average pass ratio
        double totalRatio = 0.0;
        while (!maxHeap.empty()) {
            auto top = maxHeap.top();
            maxHeap.pop();
            int pass = top.second.first;
            int total = top.second.second;
            totalRatio += (double)pass / total;
        }

        return totalRatio / classes.size();
    }
};
