class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    } 
    int pop() {
        //将栈1的数据放到栈2中
        while(!stack1.empty()){
            stack2.push(stack1.top());
            stack1.pop();
        }
        int res = stack2.top();
        stack2.pop();
        //再将stack2的元素放到stack1中
        while(!stack2.empty()){
            stack1.push(stack2.top());
            stack2.pop();
    }
    return res;
}
private:
    stack<int> stack1;
    stack<int> stack2;
};