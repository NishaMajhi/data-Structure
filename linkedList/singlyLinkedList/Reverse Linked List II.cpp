/*
Given the head of a singly linked list and two integers left and right where left <= right, 
reverse the nodes of the list from position left to position right, and return the reversed list.


Example 1:
Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]


Example 2:
Input: head = [5], left = 1, right = 1
Output: [5]
 
Constraints:
The number of nodes in the list is n.
1 <= n <= 500
-500 <= Node.val <= 500
1 <= left <= right <= n
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
    
    ListNode *reverse(ListNode *left,ListNode *right){
        
        if(left == NULL || left->next == NULL)
            return left;
        
        ListNode *curr = left;
        ListNode *prev =  NULL,*next = NULL;
        while(curr != right){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if(left==right)
            return head;
        
        if(head == NULL || head->next == NULL)
            return head;
        
        int count = 1;
        
        ListNode* prev = NULL;
        ListNode* leftNode = head;
        while(count!=left && leftNode->next !=NULL){
            prev = leftNode;
            leftNode = leftNode->next;
            count++;
        }
        
        ListNode* rightNode = leftNode;
        while(count!=right && rightNode->next!=NULL){
            rightNode =rightNode->next;
            count++;
        }
       
        ListNode* rightnext = rightNode->next;
        ListNode* newhead = reverse(leftNode , rightnext);
        if(prev!=NULL){
        prev->next =newhead;
        leftNode->next = rightnext;
            return head;
        }
        leftNode->next = rightnext;
        return newhead;
        
    }
};

