// Problem-2326: Spiral Matrix IV

// You are given two integers m and n, which represent the dimensions of a matrix.
// You are also given the head of a linked list of integers.
// Generate an m x n matrix that contains the integers in the linked list presented in spiral order (clockwise), starting from the top-left of the matrix. If there are remaining empty spaces, fill them with -1.
// Return the generated matrix.
// Example:
// Input: m = 3, n = 5, head = [3,0,2,6,8,1,7,9,4,2,5,5,0]
// Output: [[3,0,2,6,8],[5,0,-1,-1,1],[5,2,4,9,7]]
// Explanation: The diagram above shows how the values are printed in the matrix.
// Note that the remaining spaces in the matrix are filled with -1.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// divide matrix ids:
// id=0(left to right)
// id=1(top to down)
// id=2(right to left)
// id=3(down to top)


class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> matrix(m, vector<int>(n,-1));

        int id = 0;  //0,1,2,3
        int top = 0;
        int down = m-1;
        int left = 0;
        int right = n-1;

        while(top <= down && left <= right){
            if(id == 0){ //traverse left to right
                for(int i=left; head != NULL && i<= right; i++){
                    matrix[top][i] = head->val;
                    head = head->next;
                }
                top++;
            }
            if(id == 1){  //traverse top to bottom
                for(int i=top; head != NULL && i<=down; i++){
                    matrix[i][right] = head->val;
                    head = head->next;
                }
                right--;
            }
            if(id == 2){  //traverse right to left
                for(int i=right; head != NULL && i>=left; i-- ){
                    matrix[down][i] = head->val;
                    head = head->next;
                }
                down--;
            }
            if(id == 3){  //traverse bottom to up
                for(int i=down; head != NULL && i>=top; i--){
                    matrix[i][left] = head->val;
                    head = head->next;
                }
                left++;
            }
            id = (id+1)%4;
        }
        return matrix;
    }
};