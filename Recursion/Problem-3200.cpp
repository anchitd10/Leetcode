// Problem-3200: Maximum Height of a Triangle

// You are given two integers red and blue representing the count of red and blue colored balls. You have to arrange these balls to form a triangle such that the 1st row will have 1 ball, the 2nd row will have 2 balls, the 3rd row will have 3 balls, and so on.
// All the balls in a particular row should be the same color, and adjacent rows should have different colors.
// Return the maximum height of the triangle that can be achieved.
// Example 1:
// Input: red = 2, blue = 4
// Output: 3

// Concept: Greedily build the triangle row by row, alternating colors and ensuring that there are enough balls of the chosen color for each row.


class Solution {
private:
    int buildRed(int remainingRed, int remainingBlue, int level){
        if(remainingRed >= level){
            return buildBlue(remainingRed - level, remainingBlue, level + 1) + 1;  // blue function is used to change color for next row
        }

        return 0;
    }

    int buildBlue(int remainingRed, int remainingBlue, int level){
        if(remainingBlue >= level){
            return buildRed(remainingRed, remainingBlue - level, level + 1) + 1;
        }

        return 0;
    }

public:
    int maxHeightOfTriangle(int red, int blue) {
        int redStart = buildRed(red, blue, 1);
        int blueStart = buildBlue(red, blue, 1);

        return max(redStart, blueStart);
    }
};