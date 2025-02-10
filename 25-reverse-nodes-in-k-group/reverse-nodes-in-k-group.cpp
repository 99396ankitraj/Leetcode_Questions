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
    ListNode* reverseKGroup(ListNode* head, int k) {
         if(!head || !head->next) return head;
         ListNode* temp = head;

         for(int i = 0 ; i < k ; i++){
            if(!temp) return head;
            temp = temp->next;
         }

         ListNode* prev = NULL;
         ListNode* curr = head;
         ListNode* forw = NULL;

         while(curr != temp){
            forw = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forw;
         }

         if(curr) head->next = reverseKGroup(curr,k);

         return prev;

    }
};