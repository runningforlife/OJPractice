/**
 * Implement the following operations of a queue using stacks.
 */

class Queue {
private:
    stack<int> stkIn;
    stack<int> stkOut;
public:
    // Push element x to the back of queue.
    void push(int x) {
        stkIn.push(x);
        return;
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if(!stkOut.empty()){
            stkOut.pop();
            return;
        }
        while(!stkIn.empty()){
            stkOut.push(stkIn.top());
            stkIn.pop();
        }

        stkOut.pop();

        return;
    }

    // Get the front element.
    int peek(void) {
        if(!stkOut.empty())
            return stkOut.top();
        while(!stkIn.empty()){
            stkOut.push(stkIn.top());
            stkIn.pop();
        }

        return stkOut.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return stkIn.empty() && stkOut.empty();
    }
};
