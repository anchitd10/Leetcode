// Problem-92: Reverse Linked List II

// Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.
// Input: head = [1,2,3,4,5], left = 2, right = 4
// Output: [1,4,3,2,5]

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr || left == right) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        //move prev to the node before the left position
        ListNode* prev = dummy;
        for (int i = 1; i < left; ++i) {
            prev = prev->next;
        }

        //reverse the sublist between left and right
        ListNode* current = prev->next;
        ListNode* fast = nullptr;
        ListNode* prevRight = nullptr;

        for (int i = 0; i < (right - left + 1); ++i) {
            fast = current->next;
            current->next = prevRight;
            prevRight = current;
            current = fast;
        }

        //connect the reversed sublist back to the list
        prev->next->next = current;  //connect the end of the reversed part to the remaining part
        prev->next = prevRight;      //connect the node before left to the start of the reversed part

        return dummy->next;  // Return the updated list (dummy's next is the actual head)
    }
};