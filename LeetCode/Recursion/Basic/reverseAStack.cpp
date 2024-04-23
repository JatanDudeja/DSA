void pushAtBottom(stack<int> &s, int item){
    if(s.empty()){  // pushes the top element of the stack at the bottom of the stack
        s.push(item);
        return;
    }

    int topItem = s.top(); // if stack is not empty then we store the top element and just pop and recursion is done 

    s.pop();

    pushAtBottom(s, item); 

    s.push(topItem); // when the stack is empty again then we are in if condition and then we just push the top element we got from reverseStack function and them push back all the elements we just popped in this function

}

void reverseStack(stack<int> &s) {
    // Write your code here
    if(s.empty()){
        return;
    }

    int item = s.top();  // helps to get the top element

    s.pop(); // removes the top element

    reverseStack(s);    // empties the stack and helps to keep the top element saved in varaible item

    pushAtBottom(s, item); // when the stack is empty then pushAtBottom reverses the stack by pushing the top element to the end by emptying the stack again if there are some elements

}