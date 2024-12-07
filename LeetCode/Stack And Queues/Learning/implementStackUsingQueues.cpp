class MyStack {
public:
    queue<int> q1, q2;
    MyStack() {
    }
    
    void push(int x) {
        // push the latest element in the q2
        q2.push(x);

        // take the front element from the q1 and push it to q2
        // and then pop from q1 to reverse it
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }

        // now we simply swap the names of the variables
        // this makes q2 always empty and q1 having all the element in the reversed orders or in 
        // the order required for stack that is LIFO
        queue<int> q = q1;
        q1 = q2;
        q2 = q;

    }
    
    int pop() {
        if(q1.empty()){
            return -1;
        }

        int ele = q1.front();
        q1.pop();
        return ele;
    }
    
    int top() {
        if(q1.empty()) return -1;

        return q1.front();
    }
    
    bool empty() {
        if(q1.empty()) return true;
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */