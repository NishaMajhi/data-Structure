/*
Given the head of a linked list, remove the nth node from the end of the list and return its head.


Example 1:

Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]


Example 2:

Input: head = [1], n = 1
Output: []


Example 3:

Input: head = [1,2], n = 1
Output: [1]
 

Constraints:

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       
        //approach 1 two time traversal not much optimise
//         int count=1;
//         ListNode *temp = head;
//         //count size of LL
//         while(temp->next != NULL){
//             count++;
//             temp = temp->next;
//         }
        
        
//         int f = count-n;
//         temp = head;
//         while(f>1){
//             temp = temp->next;
//             f--;
//         }
//         temp->next=temp->next->next;
        
//         return head;
        
        
        //approach 2 required only one traversal
        ListNode *newHead = new ListNode();
        newHead-> next = head;
        ListNode *fast = newHead;
        ListNode *slow = newHead;
        
        for(int i=1;i<=n;i++)
            fast = fast->next;
        
        while(fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        
        return newHead-> next;
        
    }
};
