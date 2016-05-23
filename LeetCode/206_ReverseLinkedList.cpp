/**
 * Reverse a linked list: do it iteratively and recursively
 */

class Solution{
public:
    ListNode* reverseList(ListNode *head){
        if(head == NULL)
            return NULL;
        ListNode *curr = NULL;
        ListNode *next = head;
        while(next != NULL){
            head = next;
            next = next->next;
            head->next = curr;
            curr = head;
        }
        return head;
    }
    /* reverse list recursively */
    ListNode *reverseListRecursive(ListNode *head){
        if(head == NULL || head->next == NULL)
            return head;

        ListNode *newHead = reverseListRecursive(head->next);
        head->next->next = head;
        head->next = NULL;

        return newHead;
    }
};
