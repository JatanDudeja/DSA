// GFG

class MyStack {
  private:
    StackNode *top;

  public:
    void push(int x) {
        // code here
        
        StackNode * newNode = new StackNode(x);
        newNode -> next = top;
        top = newNode;
    }

    int pop() {
        // code here
        if(!top) return -1;
        
        int ele = top -> data;
        
        top = top -> next;
        
        return ele;
    }

    MyStack() { top = NULL; }
};