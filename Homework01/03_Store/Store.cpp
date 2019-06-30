#include "Store.h"

void Store::grow(){
	Product *newData = new Product[maxSize * 2];
	for (int i = 0; i < size; i++) {
		newData[i] = data[i];
	}
	delete[] data;
	data = newData;
	maxSize *= 2;
}

Store::Store(){
	size = 0;
	maxSize = 10;
	data = new Product[maxSize];
}

Store::Store(Store const & copy){
	size = copy.size;
	maxSize = copy.maxSize;
	data = new Product[copy.maxSize];
	for (int i = 0; i < copy.size; i++) {
		data[i] = copy.data[i];
	}
}

Store & Store::operator=(Store const & copy){
	if (this != &copy) {
		delete[] data;
		size = copy.size;
		maxSize = copy.maxSize;
		data = new Product[copy.maxSize];
		for (int i = 0; i < copy.size; i++) {
			data[i] = copy.data[i];
		}
	}
	
	return *this;
}

Store::~Store(){
	delete[] data;
}

void Store::add(Product const & product){
	if (size == maxSize) {
		grow();
	}
	data[size] = product;
	size++;
}

void Store::removeAt(int position){
	Product* newData = new Product[maxSize];
	for (int i = position; i < size-1; i++){
		data[i] = data[i + 1];
	}
	for (int i = 0; i < size - 1; i++) {
		newData[i] = data[i];
	}
	delete[] data;
	data = newData;
}

void Store::changeProductAt(int position) {
	data[position].inputFromConsole();
}

void Store::printInStock(){
	for (int i = 0; i < maxSize; i++) {
		if (data[i].count > 0) {
			std::cout <<"Product "<<i<<"--"<< data[i]<<std::endl;
		}
	}
}
