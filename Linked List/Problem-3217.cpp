// Problem-3217: Delete Nodes from LinkedList Present in Array

// You are given an array of integers nums and the head of a linked list. Return the head of the modified linked list after removing all nodes from the linked list that have a value that exists in nums.
// Example 1:
// Input: nums = [1,2,3], head = [1,2,3,4,5]
// Output: [4,5]

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
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> num(begin(nums), end(nums));

        while(head != NULL && num.find(head->val) != num.end()){
            ListNode* temp = head;
            head = head->next;
            delete(temp);
        }

        ListNode* curr = head;
        while(curr != NULL && curr->next != NULL){
            if(num.find(curr->next->val) != num.end()){
                ListNode* temp = curr->next;
                curr->next = curr->next->next;
                delete(temp);
            }
            else{
                curr = curr->next;
            }
        }
        return head;  
    }
};