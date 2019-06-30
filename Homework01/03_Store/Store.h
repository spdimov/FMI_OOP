#pragma once
#include"Product.h"
class Store {
private:
	Product* data;
	int size;
	int maxSize;
	void grow();
public:
	Store();
	Store(Store const& copy);
	Store& operator=(Store const& copy);
	~Store();
	void add(Product const& product);
	void removeAt(int position);
	void changeProductAt(int position);
	void printInStock();
};