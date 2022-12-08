/*
You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.

 

Example 1:
Input: head = [1,2,3,4]
Output: [1,4,2,3]


Example 2:
Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]
 
Constraints:
The number of nodes in the list is in the range [1, 5 * 104].
1 <= Node.val <= 1000
*/



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
    void reorderList(ListNode* head) {
        if(!head)
           return;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = slow->next;   // find the middle of the list
        slow->next = NULL;   // and set the end of the first list as NULL
        slow = fast;         // set "slow" as the head of the second list
        
        ListNode* pre = NULL; // reverse the second list, its head becomes "pre"
        while(slow){
            ListNode* temp = slow->next;
            slow->next = pre;
            pre = slow;
            slow = temp;
        }
        
        ListNode* l1 = head;  //set l1 as the head of the first list
        ListNode* l2 = pre;   //set l2 as the head of the reverse second list and combine them
        while(l1 && l2){
            ListNode* temp1 = l1->next;
            ListNode* temp2 = l2->next;
            l1->next = l2;
            l2->next = temp1;
            l1 = temp1;
            l2 = temp2;
        }
    }
};

