#pragma once
class IntStack {
	
private:
	int *arr;
	int top;
	int size;
	void grow();
public:
	IntStack();
	IntStack(IntStack const &copy);
	IntStack& operator=( IntStack const &copy);
	~IntStack();
	void push(int a);
	int pop();
	bool full();
	friend IntStack sortStack(IntStack const &stack);
	void print();
};