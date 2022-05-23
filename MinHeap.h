#pragma once
#include<vector>
using namespace std;

template<typename T>
class MinHeap {
public:
	MinHeap();
	MinHeap(int capacity);
	MinHeap(const MinHeap& rhs);
	MinHeap<T>& operator=(const MinHeap<T>& rhs);
	~MinHeap();
	void resizeUp();
	void resizeDown();
	void swap(int ii, int jj);
	void HeapifyUp(int index);
	void HeapifyDown(int index);
	void insert(T val);
	T top();
	T pop();
	void MinKElements(int k, vector<T>& elements);
	void remove();
    unsigned int Size(); 
private:
	T* data;
	unsigned int capacity;
	unsigned int size;
};


//                                                             Constructors and Functions to Deal With Memory
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------

//Default Constructor
template<typename T>
MinHeap<T>::MinHeap() {
    capacity = 1;
    size = 0;
    data = new T[capacity];
}

//Constructor
template<typename T>
MinHeap<T>::MinHeap(int capacity) {
    this->capacity = capacity;
    size = 0;
    data = new T[capacity];
}

//Copy Constructor
template<typename T>
MinHeap<T>::MinHeap(const MinHeap& rhs) {
    capacity = rhs.capacity;
    size = rhs.size;
    data = new T[capacity];
    for (unsigned int ii = 0; ii < capacity; ii += 1) {
        data[ii] = rhs.data[ii];
    }
}

//Overloading Copy Assignement Operator
template<typename T>
MinHeap<T>& MinHeap<T>::MinHeap::operator=(const MinHeap<T>& rhs) {
    return *this;
}

//Destructor
template<typename T>
MinHeap<T>::~MinHeap() {
    delete[] data;
    capacity = 1;
    size = 0;
}
//                                                                       Utility Functions 
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------

template<typename T>
void MinHeap<T>::resizeUp() {
    capacity = capacity * 2;
    T* tempArray = new T[capacity];
    for (unsigned int ii = 0; ii < size; ii += 1) {
        tempArray[ii] = data[ii];
    }
    delete[] data;
    data = tempArray;
}

template<typename T>
void MinHeap<T>::resizeDown() {
    bool resize = false;
    if (capacity % 2 == 0) {
        if (size == capacity / 2) {
            resize = true;
        }
    }
    else {
        if (size - 1 == capacity / 2) {
            resize = true;
        }
    }
    if (resize) {
        capacity = capacity / 2;
        T* tempArray = new T[capacity];
        for (unsigned int ii = 0; ii < size - 2; ii += 1) {
            tempArray[ii] = data[ii];
        }
        delete[] data;
        data = tempArray;
        size -= 1;
    }
    else {
        T* tempArray = new T[capacity];
        for (unsigned int ii = 0; ii < size - 1; ii += 1) {
            tempArray[ii] = data[ii];
        }
        delete[] data;
        data = tempArray;
        size -= 1;
    }
}

template<typename T>
void MinHeap<T>::swap(int ii, int jj) {
    T temp = data[ii];
    data[ii] = data[jj];
    data[jj] = temp;
}

template<typename T>
void MinHeap<T>::HeapifyUp(int index) {
    int parent = (index - 1) / 2;

    if (data[parent] > 0) {
        if (data[index] < data[parent]) {
            swap(index, parent);
            HeapifyUp(parent);
        }
    }
}

template<typename T>
void MinHeap<T>::HeapifyDown(int index) {
    int smallest = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    if (leftChild < size && data[leftChild] < data[smallest]) {
        smallest = leftChild;
    }

    if (rightChild < size && data[rightChild] < data[smallest]) {
        smallest = rightChild;
    }

    if (smallest != index) {
        swap(index, smallest);
        HeapifyDown(smallest);
    }
}

//                                                                      Heap Functions
//----------------------------------------------------------------------------------------------------------------------------------------------------------------

template<typename T>
void MinHeap<T>::insert(T val) {
    if (size == capacity) {
        resizeUp();
        data[size] = val;
        size += 1;
        HeapifyUp(size - 1);
    }
    else {
        data[size] = val;
        size += 1;
        HeapifyUp(size - 1);
    }
}

template<typename T>
T MinHeap<T>::top() {
    return data[0];
}

template<typename T>
T MinHeap<T>::pop() {
    T temp = data[0];
    remove();
    return temp;
}

template<typename T>
void MinHeap<T>::MinKElements(int k, vector<T>& elements) {
    if (k == 0) {
        return;
    }
    else {
        elements.push_back(pop());
        MinKElements(k - 1, elements);
    }
}

template<typename T>
void MinHeap<T>::remove() {
    T lastVal = data[size - 1];
    data[0] = lastVal;
    resizeDown();
    HeapifyDown(0);
}

template<typename T>
unsigned int MinHeap<T>::Size(){
    return size; 
}

