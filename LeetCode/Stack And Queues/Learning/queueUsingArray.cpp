// GFG

/*

The structure of the class is
class MyQueue {
private:
    int arr[100005];
    int front;
    int rear;

public :
    MyQueue(){front=0;rear=0;}
    void push(int);
    int pop();
};
 */

// Function to push an element x in a queue.
void MyQueue ::push(int x) {
    // Your Code
    // cout << "in "<< endl;
    if(rear == 100005) return;
    // cout << "in "<< endl;
    arr[rear++] = x;
}

// Function to pop an element from queue and return that element.
int MyQueue ::pop() {
    // Your Code
    if(front == rear){
        return -1;
    }
    int firstEle = arr[front++];
    return firstEle;
}