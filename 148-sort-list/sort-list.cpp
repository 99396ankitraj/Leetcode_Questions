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
    ListNode* middle(ListNode* head){
        ListNode *slow = head;
        ListNode *fast = head;

        while(fast && fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* head1 , ListNode* head2){
        if(!head1) return head2;
        if(!head2) return head1;

        if(head1->val > head2->val) return merge(head2 , head1);

        if(!head1->next){
            head1->next = head2;
            return head1;
        } 

        ListNode *small = head1;
        ListNode *temp = small;
        ListNode *curr1 = small->next;
        ListNode *curr2 = head2;

        while(curr1 && curr2){
            if(curr1->val > curr2->val){
                small->next = curr2;
                curr2 = curr2->next;
            }else{
                small->next = curr1;
                curr1 = curr1->next;
            }
            small = small->next;
        }

        if(curr1) small->next = curr1;
        if(curr2) small->next = curr2;

        return temp;
    }
    ListNode* mergesort(ListNode *low , ListNode *high){
        if(low == high) return low;
        ListNode* mid = middle(low);
        ListNode* midNext = mid->next;
        mid->next = NULL;
        ListNode* left = mergesort(low , mid);
        ListNode* right = mergesort(midNext , high);
        return merge(left , right);
    }
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* low = head;
        ListNode* high = head;
        while(high->next){
            high = high->next;
        }
        return mergesort(low , high);
    }
};