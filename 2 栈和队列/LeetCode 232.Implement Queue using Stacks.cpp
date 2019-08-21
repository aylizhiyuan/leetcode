
#include <stdio.h>

#include <stack>	
class MyQueue {
public:
    MyQueue() {
    }
    void push(int x) {
        std::stack<int> temp_stack;
        while(!_data.empty()){
        	temp_stack.push(_data.top());
        	_data.pop();
        }
        temp_stack.push(x);
        while(!temp_stack.empty()){
        	_data.push(temp_stack.top());
        	temp_stack.pop();
        }
    }
    int pop() {
    	int x = _data.top();
    	_data.pop();
        return x;
    }
    int peek() {
        return _data.top();
    }
    bool empty() {
        return _data.empty();
    }
private:
	std::stack<int> _data;
};

int main(){
	MyQueue Q;
	Q.push(1);
	Q.push(2);
	Q.push(3);
	Q.push(4);
	printf("%d\n", Q.peek());
	Q.pop();
	printf("%d\n", Q.peek());	
	return 0;
}
