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
    void ankit(ListNode* &head,ListNode* &curr,ListNode* &prev){
            if(curr==NULL){
              head=prev;
                return;
            }
            ListNode* forw = curr->next;
            curr->next = prev;
            prev = curr;
            ankit(head , forw , prev);


    }
    ListNode* reverseList(ListNode* head) {
           ListNode* current=head;
           ListNode* prev=NULL;
            ankit(head,current,prev);
             return head;
    }
};