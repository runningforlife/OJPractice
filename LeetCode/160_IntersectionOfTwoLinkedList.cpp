/**
 * Write a program to find the node
 * at which the intersection of two singly linked lists begins.
 */

 class Solution{
 private:
    stack<ListNode*> nodeA;
    stack<ListNode*> nodeB;
 public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) return NULL;

        ListNode* ptrA = headA;
        ListNode* ptrB = headB;

        while(ptrA != NULL){
            nodeA.push(ptrA);
            ptrA = ptrA->next;
        }

        while(ptrB != NULL){
            nodeB.push(ptrB);
            ptrB = ptrB->next;
        }

        while(!nodeA.empty() && !nodeB.empty()){
            if(nodeA.top() != nodeB.top()){
                return ptrA;
            }else{
                ptrA = nodeA.pop();
                ptrB = nodeB.pop();
            }
        }
        if(nodeA.empty()){
            return ptrA;
        }
        return ptrB;
    }
 };
