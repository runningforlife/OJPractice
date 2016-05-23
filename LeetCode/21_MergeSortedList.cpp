/**
 * Merger two sorted linked list into a new one
 */

class Solution{
public:
    ListNode* mergeTwoLists(ListNode* l1,ListNode *l2){
        if(l1 == NULL && l2 == NULL) return NULL;
        if(l1 != NULL && l2 == NULL) return l1;
        if(l1 == NULL && l2 != NULL) return l2;

        ListNode* newHead;
        if(l1->val > l2->val){
            ListNode* tmp = l2;
            l2 = l2->next;
            tmp->next = l1;
            newHead = tmp;
            l1 = newHead;
        } else newHead = l1;

        ListNode* currL1 = l1;
        while(l2 != NULL){
            if(l1 == NULL){
                currL1->next->next = l2;
                break;
            }
            ListNode* currL2 = l2;
            while(currL1->next != NULL && currL2->val >= currL1->next->val){
                currL1 = currL1->next;
            }
            l2 = l2->next;
            l1 = currL1->next;
            currL1->next = currL2;
            currL2->next = l1;
        }

        return newHead;
    }
};
