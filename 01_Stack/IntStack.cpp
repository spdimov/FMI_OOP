#include"IntStack.h"
#include<iostream>
IntStack::IntStack() {
	size = 1;
	top = -1;
	arr = new int[size];
}
IntStack::IntStack(IntStack const &copy) {
	this->size = copy.size;
	this->top = copy.top;
	arr = new int[copy.size];
	for (int i = 0; i < copy.top+1; i++) {
		arr[i] = copy.arr[i];
	}
}
IntStack& IntStack::operator=(IntStack const &copy) {
	if (this != &copy) {
		this->size = copy.size;
		this->top = copy.top;
		delete[] arr;
		arr = new int[copy.size];
		for (int i = 0; i < copy.top+1; i++) {
			arr[i] = copy.arr[i];
		}
	}
	return *this;
}
IntStack::~IntStack() {
	delete[] arr;
}
void IntStack::grow() {
	int *newArr = new int[size * 2];
	for (int i = 0; i < top+1; i++) {
		newArr[i] = arr[i];
	}
	delete[] arr;
	arr = newArr;
	size *= 2;
}
bool IntStack::full() {
	return top == size - 1;
}
void IntStack::push(int a) {
	if (full()) {
		grow();
	}
	arr[++top] = a;
	
}
int IntStack::pop() {
	if (top == -1) {
		std::cout << "Error!";
		return 0;
	}
	return arr[top];
	top--;
}
void IntStack::print() {
	for (int i = top; i >=0; i--) {
		std::cout << arr[i]<<" ";
	}
}