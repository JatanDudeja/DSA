// Not the best approach as we are using a extra data structure

// This approach was build from this comment in Leetcode's discussions: - https://leetcode.com/problems/min-stack/description/comments/2690696
// Discussion in case if it ever gets deleted from Leetcode :- @user3924AS Yup, no PhD thesis necessary here, only push a new min to the internal stack when its less or equal to old min, as you pop from main stack, check if value equal to old min and then pop from internal stack. Corner conditions were the excruciating problem. You do not even need to maintain pair.

class MinStack {
public:
stack<int> st, minSt;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(minSt.empty()){
            minSt.push(val);
        }else{
            if(val <= minSt.top()){
                minSt.push(val);
            }
        }
    }
    
    void pop() {
        int top = st.top();
        if(top == minSt.top()) {
            minSt.pop();
        }

        st.pop();
    }
    
    int top() {
        int top = st.top();
        return top;
    }
    
    int getMin() {
        return minSt.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */



// Best Solution but this will not work on Leetcode due to INT_MAX * 2 calculcation or signed integer overflow error
// Solution from Striver's Video
class MinStack {
public:
    stack<int> st;
    int mini = INT_MAX;
    MinStack() {}

    void push(int val) {
        if(st.empty()){
            mini = val;
        }
        if (val > mini) {
            st.push(val);
        } else {
            st.push(2 * val - mini);
            mini = val;
        }
    }

    void pop() {
        int top = st.top();
        if (top < mini) {
            mini = 2 * mini - top;
        }

        st.pop();
    }

    int top() {
        int top = st.top();
        if (top < mini) {
            top = mini;
        }
        return top;
    }

    int getMin() { return mini; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */