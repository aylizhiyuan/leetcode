
#include <stdio.h>

#include <queue>
class MyStack {
public:
    MyStack() {        
    }
    void push(int x) {
    	std::queue<int> temp_queue;
    	temp_queue.push(x);
    	while(!_data.empty()){
	    	temp_queue.push(_data.front());
	    	_data.pop();
	    }
	    while(!temp_queue.empty()){
   			_data.push(temp_queue.front());
   			temp_queue.pop();
    	}
    }
    int pop() {
        int x = _data.front();
    	_data.pop();
    	return x;
    }
    int top() {
        return _data.front();
    }
    bool empty() {
        return _data.empty();
    }
private:
	std::queue<int> _data;
};

int main(){
	MyStack S;
	S.push(1);
	S.push(2);
	S.push(3);
	S.push(4);
	printf("%d\n", S.top());
	S.pop();
	printf("%d\n", S.top());
	S.push(5);
	printf("%d\n", S.top());	
	return 0;
}
