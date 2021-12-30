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
        ListNode* curr = head;
        int len = 0;
        while(curr){
            len++;
            curr = curr->next;
        }
        int k = len-n;
        curr = head;
        ListNode* prev = NULL;
        int i = 0;
        while(curr){
            if(i == k){
                if(prev){
                    prev->next=curr->next;
                    curr = prev->next;
                    return head;
                }
                else{
                    return head->next;
                }
            }
            else{
                prev = curr;
                curr = curr->next;
            }
            i++;
        }
        return head;
    }
};