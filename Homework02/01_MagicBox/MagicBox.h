#pragma once
using namespace std;
template<class T>
class MagicBox {
private:
	T* array;
	int currentSize;
	int maxSize;
	void grow();
public:
	MagicBox();
	MagicBox(const MagicBox<T>& copy);
	MagicBox<T>& operator=(const MagicBox<T>& copy);
	~MagicBox();
	friend ostream& operator<<(ostream& out, const MagicBox<T>& box);
	void insert(const T& element);
	void pop();
	void list();
	bool isFull();
};

template<class T>
inline void MagicBox<T>::grow(){
	T* newArray = new T[maxSize * 2];
	for (int i = 0; i < currentSize; i++) {
		newArray[i] = array[i];
	}
	delete[] array;
	array = newArray;
	maxSize *= 2;
}

template<class T>
inline MagicBox<T>::MagicBox(){
	maxSize = 10;
	currentSize = 0;
	array = new T[maxSize];

}

template<class T>
inline MagicBox<T>::MagicBox(const MagicBox<T>& copy) {
	currentSize = copy.currentSize;
	maxSize = copy.maxSize;
	array = new T[copy.maxSize];
	for (int i = 0; i < copy.currentSize; i++) {
		array[i] = copy.array[i];
	}
}

template<class T>
inline MagicBox<T>& MagicBox<T>::operator=(const MagicBox<T>& copy){
	if (this != &copy) {
		currentSize = copy.currentSize;
		maxSize = copy.maxSize;
		delete[] array;
		array = new T[copy.maxSize];
		for (int i = 0; i < copy.currentSize; i++) {
			array[i] = copy.array[i];
		}
	}
	return *this;
}

template<class T>
inline MagicBox<T>::~MagicBox(){
	delete[] array;
}

template<class T>
 inline ostream& operator<<(ostream & out, const MagicBox<T>& box){
	 for (int i = 0; i < box.currentSize; i++) {
		 out << box.array[i] << " ";
	 }
	 return this;
}

template<class T>
inline void MagicBox<T>::insert(const T& element){
	if (isFull()) {
		grow();
	}
	array[currentSize] = element;
	currentSize++;
}

template<class T>
inline void MagicBox<T>::pop(){
	int random = rand()%currentSize;
	for (int i = random; i < currentSize; i++) {
		array[i] = array[i + 1];
	}
	array[currentSize] = -1;
	currentSize--;
}

template<class T>
inline void MagicBox<T>::list(){
	for (int i = 0; i < currentSize; i++) {
		cout << array[i] << " ";
	}
}

template<class T>
inline bool MagicBox<T>::isFull()
{
	return currentSize>=maxSize;
}
