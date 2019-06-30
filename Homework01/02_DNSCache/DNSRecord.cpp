#pragma once
#include"DNSRecord.h"
#include<cstring>
#include<iostream>
DNSRecord::DNSRecord(const char* domain, const char* ip) {
	domainName = new char[strlen(domain) + 1];
	ipAddress = new char[strlen(ip) + 1];
		strcpy_s(domainName, strlen(domain) + 1, domain);
		strcpy_s(ipAddress, strlen(ip) + 1, ip);
}
DNSRecord::DNSRecord() {
	domainName = new char[1];
	ipAddress = new char[1];
	domainName[0] ='\0';
	ipAddress[0] = '\0';
}
DNSRecord::~DNSRecord() {
	delete[] this->domainName;
	delete[] this->ipAddress;
}
DNSRecord::DNSRecord(DNSRecord const& copy) {
	domainName = new char[strlen(copy.domainName) + 1];
	ipAddress = new char[strlen(copy.ipAddress) + 1];
	strcpy_s(domainName, strlen(copy.domainName) + 1, copy.domainName);
	strcpy_s(ipAddress, strlen(copy.ipAddress) + 1, copy.ipAddress);
}
DNSRecord& DNSRecord::operator=(DNSRecord const& copy) {
	if (this != &copy) {
		delete[] domainName;
		delete[] ipAddress;
		this->domainName = new char[strlen(copy.domainName) + 1];
		this->ipAddress = new char[strlen(copy.ipAddress) + 1];
		strcpy(domainName, copy.domainName);
		strcpy(ipAddress, copy.ipAddress);
	}
	return *this;
}

std::ostream & operator<<(std::ostream & out, const DNSRecord & record)
{
	out <<"Domain: " << record.domainName <<" | "<<"IP: " << record.ipAddress;
	return out;
}
