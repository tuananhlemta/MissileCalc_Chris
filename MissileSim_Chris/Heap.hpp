#ifndef _heap_h_
#define _heap_h_

#include <vector>
#include <iostream>


template<   class K,
            class D,
            template <typename> class Comparison >
class Heap {
public:
    
    // Note to store Heap data
    typedef struct Node{
        K key;
        D data;
    }Node;
    
    // Heap Constructors
	Heap();
	Heap(int N);
	Heap(K keys[], D data[], int N = 20);
    Heap(std::vector<K> keys, std::vector<D> data);
    
    // Heap Destructors
	~Heap();

    // Methods for getting data at some index
	D & operator[](int index){ return heap[index].data; }
    D & getDataAt(int i){ return (heap[i].data); }
    K & getKeyAt(int i){ return (heap[i].key); }
    
    // Method for modifying the key at some point
    void setKeyAt(int i, K key){ heap[i].key = key; }
    
    // Methods to get root key and data
	K getRootKey();
	D getRootData();
    
    // Methods to add and remove data
	void push(K key, D data);
	D pop();
    
    // Method to print keys
	void printKeys();
    
    
    // Get size of heap
	int getHeapCount(){ return heap_count; }
    int size(){ return heap_count; }
    
    // get size of memory allocated to heap
	int getArrayLength(){ return length_arr; }

    // method to build the heap with a
    // structure based on the Comparison
    // template input
    void generateHeap();

private:

    Comparison<K> compare;
	Node* heap;
	int length_arr;
	int heap_count;
	void resize();
	void pushHelper(int index);
	void swapDown( int index );

};



#include "Heap_Impl.hpp"

// Define a less than and Greater than
// comparison operators
template<class K>
class LessThan {
public:
    bool operator()(K k1, K k2){
        return (k1 < k2);
    }
};

template<class K>
class GreaterThan {
public:
    bool operator()(K k1, K k2){
        return (k1 > k2);
    }
};



// Define a Min and Max Heap based on
// the LessThan and GreaterThan Comparison Operators
template <class K, class D>
class MinHeap : public Heap<K, D, LessThan>{
public:
    MinHeap():Heap<K, D, LessThan>(){}
    MinHeap(int n):Heap<K, D, LessThan>(n){}
    MinHeap(K keys[], D data[], int N = 20):Heap<K, D, LessThan>(keys,data,N){}
    MinHeap(std::vector<K> keys, std::vector<D> data):Heap<K, D, LessThan>(keys,data){}
};

template <class K, class D>
class MaxHeap : public Heap<K, D, GreaterThan>{
public:
    MaxHeap():Heap<K, D, GreaterThan>(){}
    MaxHeap(int n):Heap<K, D, GreaterThan>(n){}
    MaxHeap(K keys[], D data[], int N = 20):Heap<K, D, GreaterThan>(keys,data,N){}
    MaxHeap(std::vector<K> keys, std::vector<D> data):Heap<K, D, GreaterThan>(keys,data){}
};





#endif