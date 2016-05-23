/**
 * implement stacks using queue
 */

class Stack {
private:
    queue<int> inQue;
    queue<int> outQue;
    int flag = 0; // the top in which queue currently
public:
    // Push element x onto stack.
    void push(int x) {
        if(flag == 0){
            inQue.push(x);
            return;
        }
        outQue.push(x);
        flag = 1;

        return;
    }

    // Removes the element on top of the stack.
    void pop(){
        if(flag == 0 && !inQue.empty()){
            while(inQue.size() > 1){
                outQue.push(inQue.front());
                inQue.pop();
                flag = 1;
            }
            inQue.pop();
        }else if(flag == 1 && !outQue.empty()){
            while(outQue.size() > 1){
                inQue.push(outQue.front());
                outQue.pop();
                flag = 0;
            }
            outQue.pop();
        }

        return;
    }

    // Get the top element.
    int top() {
        if(flag == 0 && !inQue.empty()){
            while(inQue.size() > 1){
                outQue.push(inQue.front());
                inQue.pop();
            }
            return inQue.front();
        }else if(flag == 1 && !outQue.empty()){
            while(outQue.size() > 1){
                inQue.push(outQue.front());
                outQue.pop();
            }
            return outQue.front();
        }
    }

    // Return whether the stack is empty.
    bool empty() {
        return inQue.empty() && outQue.empty();
    }
};
