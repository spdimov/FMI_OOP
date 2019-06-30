#pragma once
#include<iostream>
class DNSRecord {
private:
	char *domainName;
	char *ipAddress;
public:
	DNSRecord(const char* domain, const char* ip);
	DNSRecord();
	DNSRecord(DNSRecord const& copy);
	DNSRecord& operator=(DNSRecord const& copy);
	~DNSRecord();
	friend class DNSCache;
	friend std::ostream& operator<<(std::ostream & out, const DNSRecord& record);
};