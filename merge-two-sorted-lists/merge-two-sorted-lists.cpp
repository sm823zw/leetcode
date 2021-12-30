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
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        if(!head1 && !head2){
            return NULL;
        }
        if(!head1){
            return head2;
        }
        if(!head2){
            return head1;
        }
        ListNode* head = NULL;
        ListNode* a = head1;
        ListNode* b = head2;
        if(a->val > b->val){
            head = b;
            b = b->next;
        }
        else{
            head = a;
            a = a->next;
        }
        ListNode* x = head;
        while(a && b){
            if(a->val > b->val){
                x->next = b;
                x = x->next;
                b = b->next;
            }
            else{
                x->next = a;
                x = x->next;
                a = a->next;
            }
        }
        while(a){
            x->next = a;
            x = x->next;
            a = a->next;
        }
        while(b){
            x->next = b;
            x = x->next;
            b = b->next;
        }
        return head;
    }
};