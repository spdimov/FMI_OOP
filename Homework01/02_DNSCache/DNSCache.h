#pragma once
#include"DNSRecord.h"
#include<iostream>
class DNSCache {
private:
		DNSRecord *arr;
		int maxSize;
		int currentSize;
public:
		DNSCache();
		DNSCache(DNSCache const& copy);
		DNSCache& operator=(DNSCache const& copy);
		~DNSCache();
		void flush();
		void grow();
		void add(DNSRecord const& record);
		const char *lookup( const char *domain);
		void print();
};