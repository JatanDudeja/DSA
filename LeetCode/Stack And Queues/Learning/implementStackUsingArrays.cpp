// GFG

/*
class MyStack
{
private:
    int arr[1000];
    int top;
public:
    MyStack(){top=-1;}
    int pop();
    void push(int);
};
*/

int i = -1;

void MyStack ::push(int x) {
    // Your Code
    i++;
    arr[i] = x;
    // cout << i << ", " << arr[i] << endl;
}

// Function to remove an item from top of the stack.
int MyStack ::pop() {
    // cout << i << ", " << arr[i] << endl;
    // Your Code
    if(i < 0) {
        i = -1;
        return -1;
    }
    int topEle = arr[i];
    i--;
    
    return topEle;
    
}
