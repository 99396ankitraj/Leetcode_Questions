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
private:
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        if(!list2) return list1;

        if(list1->val > list2->val){
            return mergeTwoLists(list2, list1);
        }

        ListNode *small = list1;
        ListNode *curr2 = list2;
        ListNode* temp = small;

        if(!small->next){
             small->next = curr2;
             return small;
        }
        ListNode *curr1 = small->next;

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
};