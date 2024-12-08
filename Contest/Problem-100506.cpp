// Maximum Area Rectangle With Point Constraints I

// You are given an array points where points[i] = [xi, yi] represents the coordinates of a point on an infinite plane.
// Your task is to find the maximum area of a rectangle that:
// Can be formed using four of these points as its corners.
// Does not contain any other point inside or on its border.
// Has its edges parallel to the axes.
// Return the maximum area that you can obtain or -1 if no such rectangle is possible.
// Example 1:
// Input: points = [[1,1],[1,3],[3,1],[3,3]]
// Output: 4

// Incorrect

class Solution {
public:
    int maxRectangleArea(vector<vector<int>>& points) {
//         unordered_set<string> pointSet;
//         for (const auto& point : points) {
//             pointSet.insert(to_string(point[0]) + "," + to_string(point[1]));
//         }

//         int maxArea = -1;
//         int n = points.size();

//         for (int i = 0; i < n; ++i) {
//             for (int j = i + 1; j < n; ++j) {
//                 int x1 = points[i][0], y1 = points[i][1];
//                 int x2 = points[j][0], y2 = points[j][1];

//                 // diagonally opposite corners of rectangle
//                 if (x1 != x2 && y1 != y2) {
//                     // other two corners exist in the set
//                     string corner1 = to_string(x1) + "," + to_string(y2);
//                     string corner2 = to_string(x2) + "," + to_string(y1);

//                     if (pointSet.count(corner1) && pointSet.count(corner2)) {
//                         // no points inside the rectangle
//                         bool valid = true;
//                         for (const auto& point : points) {
//                             int px = point[0], py = point[1];
//                             if (px > min(x1, x2) && px < max(x1, x2) &&
//                                 py > min(y1, y2) && py < max(y1, y2)) {
//                                 valid = false;
//                                 break;
//                             }
//                         }
//                         if (valid) {
//                             int area = abs(x2 - x1) * abs(y2 - y1);
//                             if (maxArea == -1 || area < maxArea) {
//                                 maxArea = area;
//                             }
//                         }
//                     }
//                 }
//             }
//         }

//         return maxArea;
        
        set<int> xCoords, yCoords;
        unordered_set<string> pointSet;
        
        for (const auto& point : points) {
            xCoords.insert(point[0]);
            yCoords.insert(point[1]);
            pointSet.insert(to_string(point[0]) + "," + to_string(point[1]));
        }
        
        int maxArea = -1;
        
        for (int x1 : xCoords) {
            for (int x2 : xCoords) {
                for (int y1 : yCoords) {
                    for (int y2 : yCoords) {
                        if (x1 == x2 || y1 == y2) continue;
                        
                        // parallel to axes
                        if (x1 > x2) swap(x1, x2);
                        if (y1 > y2) swap(y1, y2);
                        
                        // Check if all 4 corners exist
                        if (pointSet.count(to_string(x1) + "," + to_string(y1)) &&
                            pointSet.count(to_string(x1) + "," + to_string(y2)) &&
                            pointSet.count(to_string(x2) + "," + to_string(y1)) &&
                            pointSet.count(to_string(x2) + "," + to_string(y2))) {
                            
                            // strictly inside rectangle
                            bool valid = true;
                            for (const auto& point : points) {
                                int px = point[0], py = point[1];
                                
                                // inside rectangle boundaries and not at the corners or edges
                                if (px > x1 && px < x2 && 
                                    py > y1 && py < y2) {
                                    valid = false;
                                    break;
                                }
                            }
                            
                            if (valid) {
                                int area = abs(x2 - x1) * abs(y2 - y1);
                                maxArea = (maxArea == -1) ? area : min(maxArea, area);
                            }
                        }
                    }
                }
            }
        }
        
        return maxArea;
    }
};