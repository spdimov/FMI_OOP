#include "Product.h"
#include<cstring>
using namespace std;
Product::Product(){
	SKU=new char[1];
	SKU[0] = '\0';
	brand = new char[1];
	brand[0] = '\0';
	model = new char[1];
	model[0] = '\0';
	price=0;
	count=0;
	screenSize=0;
	chargingPotType= new char[1];
	chargingPotType[0] = '\0';
	numberOfCameras=0;
}

Product::Product(const char * SKU){
	this->SKU = new char[strlen(SKU)+1];
	strcpy(this->SKU, SKU);
	brand = new char[1];
	brand[0] = '\0';
	model = new char[1];
	model[0] = '\0';
	price = 0;
	count = 0;
	screenSize = 0;
	chargingPotType = new char[1];
	chargingPotType[0] = '\0';
	numberOfCameras = 0;
}

Product::Product(char * SKU, char * brand, char * model, double price, unsigned int count, double screenSize, char * chargingPotType, short numberOfCameras){
	this->SKU = new char[strlen(SKU) + 1];
	strcpy(this->SKU, SKU);
	
	this->brand = new char[strlen(brand) + 1];
	strcpy(this->brand,brand);
	this->model = new char[strlen(model) + 1];
	strcpy(this->model,model);
	this->price = price;
	this->count = count;
	this->screenSize = screenSize;
	this->chargingPotType == new char[strlen(chargingPotType) + 1];
	strcpy(this->chargingPotType, chargingPotType);
	this->numberOfCameras = numberOfCameras;
}

Product::Product(Product const & copy){
	SKU = new char[strlen(copy.SKU) + 1];
	strcpy(SKU, copy.SKU);
	brand = new char[strlen(copy.brand)+1];
	strcpy(brand, copy.brand);
	model = new char[strlen(copy.model)+1];
	strcpy(model, copy.model);
	price = copy.price;
	count = copy.count;
	screenSize = copy.screenSize;
	chargingPotType = new char[strlen(copy.chargingPotType)+1];
	strcpy(chargingPotType, copy.chargingPotType);
	numberOfCameras = copy.numberOfCameras;
}

Product & Product::operator=(Product const & copy){
	if (this != &copy) {
		delete[] SKU;
		delete[] brand;
		delete[] model;
		delete[] chargingPotType;
		SKU = new char[strlen(copy.SKU) + 1];
		strcpy(SKU, copy.SKU);
		brand = new char[strlen(copy.brand) + 1];
		strcpy(brand, copy.brand);
		model = new char[strlen(copy.model) + 1];
		strcpy(model, copy.model);
		price = copy.price;
		count = copy.count;
		screenSize = copy.screenSize;
		chargingPotType = new char[strlen(copy.chargingPotType) + 1];
		strcpy(chargingPotType, copy.chargingPotType);
		numberOfCameras = copy.numberOfCameras;
	}
	return *this;
}

Product::~Product(){
	delete[] SKU;
	delete[] brand;
	delete[] model;
	delete[] chargingPotType;
}

void Product::setSKU(char * SKU){
	this->SKU = new char[strlen(SKU) + 1];
	strcpy(this->SKU, SKU);
}

void Product::setBrand(char * brand){
	this->brand = new char[strlen(brand) + 1];
	strcpy(this->brand, brand);
}

void Product::setModel(char * model){
	this->model = new char[strlen(model) + 1];
	strcpy(this->model,model);
}

void Product::setPrice(double price){
	this->price = price;
}

void Product::setCount(unsigned int count){
	this->count = count;
}

void Product::setScreenSize(double screenSize){
	this->screenSize = screenSize;
}

void Product::setChargingPotType(char * chargingPotType){
	this->chargingPotType = new char[strlen(chargingPotType) + 1];
	strcpy(this->chargingPotType, chargingPotType);
}

void Product::setNumberOfCameras(unsigned short numberOfCameras){
	this->numberOfCameras = numberOfCameras;
}

char * Product::getSKU() const{
	return SKU;
}

char * Product::getBrand() const{
	return brand;
}

char * Product::getModel() const{
	return model;
}

double Product::getPrice() const{
	return price;
}

int Product::getCount() const{
	return count;
}

double Product::getScreenSize() const{
	return screenSize;
}

char * Product::getChargingPotType() const{
	return chargingPotType;
}

short Product::getNumberOfCameras() const{
	return numberOfCameras;
}

void Product::inputFromConsole(){
	char* input=new char[1];
	input[0] = '\0';

	cout << "Enter SKU: ";
	cin >>input;
	SKU = new char[strlen(input) + 1];
	strcpy(SKU, input);

	cout << "Enter brand: ";
	cin >> input;
	brand= new char[strlen(input) + 1];
	strcpy(brand, input);

	cout << "Enter model: ";
	cin >> input;
	model = new char[strlen(input) + 1];
	strcpy(model, input);

	cout << "Enter price: ";
	cin >> price;

	cout << "Enter count: ";
	cin >> count;

	cout << "Enter screen size: ";
	cin >> screenSize;

	cout << "Enter charging pot type: ";
	cin >> input;
	chargingPotType = new char[strlen(input) + 1];
	strcpy(chargingPotType, input);

	cout << "Enter number of cameras: ";
	cin >> numberOfCameras;
	

}


std::ostream & operator<<(std::ostream & out, Product const & product)
{
	out << "SKU: " << product.SKU << " Brand: " << product.brand<<" Model: "<<product.model<<" Price: "<<product.price<<" Count: "<<product.count<<" Screen size: "<<product.screenSize<<" Charging pot type: "<<product.chargingPotType<<" Number of cameras: "<<product.numberOfCameras<<std::endl;
	return out;
}
