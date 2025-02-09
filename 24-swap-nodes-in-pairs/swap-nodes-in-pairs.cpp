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
    ListNode* swapPairs(ListNode* &head) {
        //if list has single node or one node
        if(head == NULL || head->next == NULL)
              return head;
        //if list has more than one node
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* forw=NULL;
        int k=2;

        //step 1: reverse first k element
        while(k){
            forw=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forw;
            k--;
        }
        //step 2: recursion dekh lega aage ka
        if(curr !=NULL)
           head->next=swapPairs(curr);
        //srep 3:return head of prev node
            return  prev;


    }
};


// //if list has more then one node
//         ListNode* dummy=new ListNode(0);
//         ListNode* temp=NULL;
//         temp=dummy;
//         ListNode* slow=head;
//         ListNode* fast=head->next;

//         while(slow && fast){
//             temp->next=fast;
//             temp=temp->next;
//             temp->next=slow;
//             temp=temp->next;
//             slow=slow->next->next;
//             fast=fast->next->next;
//         }
//         if(fast==NULL && slow!=NULL)
//             temp->next=slow->next->next;

//          return dummy->next;
