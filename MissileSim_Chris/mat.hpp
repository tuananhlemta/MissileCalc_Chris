//
//  mat.hpp
//  Geom3
//
//  Created by Christian J Howard on 9/24/16.
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

#ifndef mat_h
#define mat_h


template<int R, int C, typename data_type_ = double>
class mat {
public:
    
    static const int N = R*C;
    typedef data_type_ data_type;
    
    mat();
    data_type & operator()(int r, int c);
    const data_type & operator()(int r, int c) const;
    data_type & operator()(int k);
    const data_type & operator()(int k) const;
    data_type & operator[](int k);
    const data_type & operator[](int k) const;
    
    mat operator+(const mat & m) const;
    mat operator-(const mat & m) const;
    void operator=( const data_type & s );
    mat<C,R,data_type> getTranspose();
    
    int rows() const;
    int cols() const;
    
    void print() const;
    
private:
    
    data_type d[N];
};

#include "mat_impl.hpp"

#endif /* mat_h */
