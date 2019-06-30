#pragma once
#include<iostream>
//Product Smartphone
class Product {
private:
	char* SKU;
	char* brand;
	char* model;
	double price;
	unsigned int count;
	double screenSize;
	char* chargingPotType;
	unsigned short numberOfCameras;
public:
	Product();
	Product(const char* SKU);
	Product(char* SKU, char* brand, char* model, double price, unsigned int count, double screenSize, char* chargingPotType, short NumberOfCameras);
	Product(Product const& copy);
	Product& operator=(Product const& copy);
	~Product();
	void setSKU(char* SKU);
	void setBrand(char* brand);
	void setModel(char* model);
	void setPrice(double price);
	void setCount(unsigned int count);
	void setScreenSize(double screenSize);
	void setChargingPotType(char* chargingPotType);
	void setNumberOfCameras(unsigned short numberOfCameras);
	char* getSKU() const;
	char* getBrand() const;
	char* getModel() const;
	double getPrice() const;
	int getCount() const;
	double getScreenSize() const;
	char* getChargingPotType() const;
	short getNumberOfCameras() const;
	friend std::ostream& operator<<(std::ostream& out, Product const& product);
	void inputFromConsole();
	friend class Store;
};