#pragma once
#include<iostream>
#include"DNSCache.h"
#include"DNSRecord.h"
#include<cstring>
void DNSCache::grow() {
	DNSRecord *newArr = new DNSRecord[maxSize * 2];
	for (int i = 0; i < maxSize; i++) {
		newArr[i] = arr[i];
	}
	delete[] arr;
	arr = new DNSRecord[maxSize * 2];
	arr = newArr;
	maxSize *= 2;
}
DNSCache::DNSCache() {
	maxSize = 10;
	currentSize = 0;
	arr = new DNSRecord[maxSize];
}
DNSCache::DNSCache(DNSCache const& copy) {
	this->maxSize = copy.maxSize;
	this->currentSize = copy.currentSize;
	arr = new DNSRecord[copy.maxSize];
	for (int i = 0; i < copy.currentSize; i++) {
		arr[i] = copy.arr[i];
	}

}

DNSCache& DNSCache::operator=(DNSCache const & copy){
	if (this != &copy) {
		delete[] arr;
		maxSize = copy.maxSize;
		currentSize = copy.currentSize;
		arr = new DNSRecord[copy.currentSize];
		for (int i = 0; i < copy.currentSize; i++) {
			arr[i] = copy.arr[i];
		}
	}
	return *this;
}
DNSCache::~DNSCache() {
	delete[] arr;
}

void DNSCache::flush(){
	delete[] arr;
	 maxSize = 10;
	 currentSize = 0;
	arr = new DNSRecord[maxSize];
}



void DNSCache::add(DNSRecord const& add){
	if (currentSize == maxSize) {
		grow();
	}
	arr[currentSize] = add;
	currentSize++;

}

 const char * DNSCache::lookup(const char* domain) {
	bool check = 0;
	int position = 0;
	const char* returnError = "No such domain found \n";
	for (int i = 0; i < currentSize; i++) {
		if (strcmp(arr[i].domainName, domain) == 0) {
			position = i;
			check = 1;
		}
	}
	if (check == 1) {
		return arr[position].ipAddress;;
	}
	else return returnError;
	
}

 void DNSCache::
	 print()
{
	for (int i = 0; i < currentSize; i++) {
		std::cout << arr[i]<< std::endl;
	}
}



