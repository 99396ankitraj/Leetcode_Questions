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
    int nodecount(ListNode* head){
        ListNode* temp=head;
        int count=0;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        return count;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
              int k=nodecount(head)-n;
              if(k==0){
                  return head->next;
              }
              else{
                  ListNode* prev=NULL;
                  ListNode* current=head;
                  while(k){
                    prev=current;
                    current=current->next;
                    k--;
              }
                   prev->next=current->next;
                   current->next=NULL;
                   delete current;
              }
              return head;

    }
};