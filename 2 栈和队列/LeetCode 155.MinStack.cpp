#include <stdio.h>
#include <stack>

class MinStack {
public:
    MinStack() {
    }
    void push(int x) {
    	_data.push(x);
    	if (_min.empty()){
	    	_min.push(x);
	    }
	    else{
	    	if (x > _min.top()){
	    		x = _min.top();
	    	}
    		_min.push(x);
    	}
    }
    void pop() {
    	_data.pop();
    	_min.pop();
    }
    int top() {
        return _data.top();
    }
    int getMin() {
        return _min.top();
    }
private:
	std::stack<int> _data;
	std::stack<int> _min;
};

int main(){
	MinStack minStack;
	minStack.push(-2);
	printf("top = [%d]\n", minStack.top());
	printf("min = [%d]\n\n", minStack.getMin());	
	minStack.push(0);
	printf("top = [%d]\n", minStack.top());
	printf("min = [%d]\n\n", minStack.getMin());
	minStack.push(-5);
	printf("top = [%d]\n", minStack.top());
	printf("min = [%d]\n\n", minStack.getMin());
	minStack.pop();
	printf("top = [%d]\n", minStack.top());
	printf("min = [%d]\n\n", minStack.getMin());	
	return 0;
}
