/**
 * remove all duplicates such that each element appear only once
 */
class Solution{
public:
    ListNode *deleteDuplicates(ListNode *head){
        if(head == NULL || head->next == NULL) return head;

        ListNode *curr = head;
        ListNode *next = head->next;
        while(next != NULL){
            if(curr->val == next->val){
                ListNode *tmp = next;
                next = next->next;
                curr->next = next;
                delete tmp;
            }else{
                curr = next;
                next = next->next;
            }
        }

        return head;
    }
};

