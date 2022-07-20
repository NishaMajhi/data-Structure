/*
Given the head of a linked list, rotate the list to the right by k places.

Example 1:

Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]


Example 2:

Input: head = [0,1,2], k = 4
Output: [2,0,1]
 

Constraints:

The number of nodes in the list is in the range [0, 500].
-100 <= Node.val <= 100
0 <= k <= 2 * 109

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL)
            return head;
        
//         ListNode *prev = NULL;
//         ListNode *temp = NULL;
//         int i=1;
        // t.c=(nk)
//         while(i<=k){
//             temp = head;
//             while(temp->next != NULL){
//                 prev = temp;
//                 temp=temp->next;
//             }
//             prev->next = NULL;
//             temp->next = head;
//             head = temp;
//             i++;
//         }
        
//         return head;
        
        
        ListNode *temp = head;
        ListNode *lastNode = NULL;
        int len=0;
        //count length of LL and found last node of LL
        while(temp != NULL){
            len++;
            lastNode = temp;
            temp=temp->next;
        }
        
        //if modules become 0 then no need to rotate the LL  k times
        // after k times rotating LL will be same as current LL
                if(k%len==0) 
            return head;
        //otherwise find number of rotation 
        int j = k%len;
        
        //do the LL as circular LL
        lastNode->next = head;
        
        //newHead will bw new answer
        ListNode *newHead = head;
        //prev will be new tail
        ListNode *prev = head;
        
        //rotate the LL
        for(int i=0;i<len - j;i++){
            prev = newHead;
            newHead = head->next;
            head = head->next;
        }
        
        prev->next=NULL;
        return newHead;
     }
};
