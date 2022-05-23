#pragma once
#include<vector>
using namespace std; 

template<typename T>
class MaxHeap {
public:
    //                                                             Constructors and Functions to Deal With Memory
    //-----------------------------------------------------------------------------------------------------------------------------------------------------------------

    //Default Constructor
    MaxHeap() {
        size = 0;
    }

    //Copy Constructor
    MaxHeap(const MaxHeap& rhs) {
        size = rhs.size;
        data.clear();
        for (unsigned int ii = 0; ii < rhs.data.size(); ii += 1) {
            data.push_back(rhs.data.at(ii));
        }
    }

    //Overloading Copy Assignement Operator
    MaxHeap<T>& operator=(const MaxHeap<T>& rhs) {
        return *this;
    }

    //Destructor
    ~MaxHeap() {
        data.clear();
        size = 0;
    }
  

    //                                                                      Heap Functions
    //----------------------------------------------------------------------------------------------------------------------------------------------------------------

        void insert(T val) {
                data.push_back(val);
                size += 1;
                HeapifyUp(size - 1);
        }

        T top() {
            return data.at(0);
        }

        T pop() {
            if (size != 0) {
                T temp = data.at(0);
                remove();
                return temp;
            }
        }


        void MaxKElements(int k, vector<T>& elements) {
            if (k == 0) {
                return;
            }
            else {
                while (size != 0) {
                    elements.push_back(pop());
                    MaxKElements(k - 1, elements);
                }
            }
        }

        unsigned int Size() {
            return size; 
        }

private:
    //                                                                       Utility Functions 
  //-----------------------------------------------------------------------------------------------------------------------------------------------------------------

    void swap(int ii, int jj) {
        T temp = data.at(ii);
        data.at(ii) = data.at(jj);
        data.at(jj) = temp;
    }

    void HeapifyUp(int index) {
        int parent = (index - 1) / 2;

        if (data.at(parent) > 0) {
            if (data.at(index) > data.at(parent)) {
                swap(index, parent);
                HeapifyUp(parent);
            }
        }
    }

    void HeapifyDown(int index) {
        int largest = index;
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;

        if (leftChild < size && data.at(leftChild) > data.at(largest)) {
            largest = leftChild;
        }

        if (rightChild < size && data.at(rightChild) > data.at(largest)) {
            largest = rightChild;
        }

        if (largest != index) {
            swap(index, largest);
            HeapifyDown(largest);
        }
    }

    void remove() {
        T lastVal = data.at(size - 1);
        data.at(0) = lastVal;
        HeapifyDown(0);
        size -= 1;
    }
    //Variable Declaration
    vector<T> data; 
    unsigned int size;
};
