// Problem-83: Remove Duplicates from Sorted List

// Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.
// Example 1:
// Input: head = [1,1,2]
// Output: [1,2]


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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL){
            return head;
        }
        if(head->next==NULL){
            return head;
        }
        ListNode* temp = head;
        while(temp!=NULL){
            if(temp->next!=NULL && temp->val == temp->next->val){
                ListNode*newnode = temp->next;
                temp->next = newnode->next;
                newnode->next = NULL;
                delete newnode;
            }
            else{
                temp = temp->next;
            }
        }
        return head;
    }
};