//
//  Heap_Impl.hpp
//  Data_Structs
//
//  Created by Christian J Howard on 3/4/16.
//
//  The MIT License (MIT)
//    Copyright © 2016 Christian Howard. All rights reserved.
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in all
//  copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//  SOFTWARE.
//
//

#ifndef Heap_Impl_h
#define Heap_Impl_h

#include "Heap.hpp"


#define TEMPLATE_HEADER template<class K, class D, template<typename> class C>

TEMPLATE_HEADER
K Heap<K,D,C>::getRootKey()
{
    if( heap != 0 ){
        return heap[0].key;
    }
    return K();
}

TEMPLATE_HEADER
D Heap<K,D,C>::getRootData()
{
    if( heap != 0 ){
        return heap[0].data;
    }
    return D();
}



TEMPLATE_HEADER
Heap<K,D,C>::Heap(){
    length_arr = 20;
    heap_count = 0;
    heap = new Node[length_arr];
}

TEMPLATE_HEADER
Heap<K,D,C>::Heap(int N ){
    length_arr = N;
    heap_count = 0;
    heap = new Node[length_arr];
}

TEMPLATE_HEADER
void Heap<K,D,C>::swapDown( int index )
{
    int ir = 2*(index + 1);
    int il = 2*index + 1;
    int ib = 0;
    
    if( ir >= heap_count && il >= heap_count ){
        return;
    }else if( ir >= heap_count ){
        ib = il;
    }else{
        if( compare(heap[il].key, heap[ir].key) ){
            ib = il;
        }else{    ib = ir;    }
    }
    
    if( compare(heap[ib].key, heap[index].key) ){
        Node tmp = heap[ib];
        heap[ib] = heap[index];
        heap[index] = tmp;
        
        swapDown(ib);
    }
    
}


TEMPLATE_HEADER
void Heap<K,D,C>::generateHeap()
{
    int ic = heap_count/2-1;
    Node tmp;
    
    for( ; ic >= 0; ic-- ){
        swapDown(ic);
    }
    
}


TEMPLATE_HEADER
void Heap<K,D,C>::printKeys(){
    
    for( int i = 0; i < heap_count; i++ ){
        std::cout << "( " << heap[i].key <<" )";
    }
    
    std::cout << "\n";
    
}

TEMPLATE_HEADER
Heap<K,D,C>::Heap(K keys[], D data[], int N ){
    int n = N + 4;
    heap = new Node[n];
    length_arr = n;
    heap_count = N;
    
    for( int i = 0; i < N; i++ ){
        heap[i].key  = keys[i];
        heap[i].data = data[i];
    }
    
    generateHeap();
}

TEMPLATE_HEADER
Heap<K,D,C>::Heap(std::vector<K> keys, std::vector<D> data){
    int N = keys.size();
    
    heap = new Node[N];
    length_arr = N;
    heap_count = N;
    
    typename std::vector<K>::iterator ik = keys.begin();
    typename std::vector<D>::iterator id = data.begin();
    
    for( int i = 0 ; ik != keys.end() ; ik++, id++, i++ ){
        heap[i].key  = (*ik);
        heap[i].data = (*id);
    }
    
    generateHeap();
}


TEMPLATE_HEADER
Heap<K,D,C>::~Heap(){
    if( heap != 0 ){
        delete [] heap;
        heap = 0;
    }
    
    length_arr = 0;
    heap_count = 0;
}

TEMPLATE_HEADER
void Heap<K,D,C>::push(K key, D data){
    if( length_arr == heap_count ){
        resize();
    }
    
    Node n = {key, data};
    heap[heap_count] = n;
    heap_count++;
    
    pushHelper(heap_count-1);
}

TEMPLATE_HEADER
D Heap<K,D,C>::pop()
{
    if( heap_count != 0 ){
        D data = heap[0].data;
        heap_count--;
        heap[0] = heap[heap_count];
        swapDown(0);
        
        return data;
    } else {
        return D();
    }
}

TEMPLATE_HEADER
void Heap<K,D,C>::resize(){
    Node* new_heap = new Node[length_arr*2];
    
    for( int i = 0; i < length_arr; i++ ){
        new_heap[i] = heap[i];
    }
    
    length_arr *= 2;
    
    delete [] heap;
    heap = new_heap; 
    new_heap = 0;
}

TEMPLATE_HEADER
void Heap<K,D,C>::pushHelper(int index)
{
    if( index != 0 ){
        int parent;
        if( index % 2 == 0 ){
            parent = (index - 2)/2;
        }else{
            parent = (index - 1)/2;
        }
        
        if( compare(heap[index].key, heap[parent].key)  ){
            Node tmp = heap[parent];
            heap[parent] = heap[index];
            heap[index] = tmp;
            
            pushHelper(parent);
        }
    }
}

#undef TEMPLATE_HEADER

#endif /* Heap_Impl_h */
