//
//  mat_impl.hpp
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

#ifndef mat_impl_h
#define mat_impl_h

#include "mat.hpp"

#define HEADER template<int R, int C, typename data_type>
#define MAT mat<R,C,data_type>
#define MATt mat<C,R,data_type>
#define DT typename MAT::data_type

HEADER
MAT::mat() {
    data_type zero = data_type();
    for(int i = 0; i < N; ++i){ d[i] = zero; }
}

HEADER
DT & MAT::operator()(int r, int c) {
    return d[c + r*C];
}

HEADER
const DT & MAT::operator()(int r, int c) const {
    return d[c + r*C];
}

HEADER
DT & MAT::operator()(int k){
    return d[k];
}

HEADER
const DT & MAT::operator()(int k) const{
    return d[k];
}

HEADER
DT & MAT::operator[](int k){
    return d[k];
}

HEADER
const DT & MAT::operator[](int k) const{
    return d[k];
}

HEADER
MAT MAT::operator+(const mat & m) const {
    mat o;
    for(int i = 0; i < N; ++i){ o[i] = d[i] + m.d[i]; }
    return o;
}

HEADER
MAT MAT::operator-(const mat & m) const {
    mat o;
    for(int i = 0; i < N; ++i){ o[i] = d[i] - m.d[i]; }
    return o;
}

HEADER
void MAT::operator=( const data_type & s ) {
    for(int i =0; i < N; ++i){ d[i] = s; }
}

HEADER
MATt MAT::getTranspose() {
    MATt mt;
    for(int i = 0; i < R; ++i){
        for(int j = 0; j < C; ++i){
            mt(i,j) = this->operator()(j,i);
        }
    }
    return mt;
}

HEADER
int MAT::rows() const {
    return R;
}

HEADER
int MAT::cols() const {
    return C;
}

HEADER
void MAT::print() const {
    for(int i = 0; i < R; ++i){
        printf("%lf",static_cast<double>((*this)(i,0)));
        for(int j = 1; j < C; ++j){
            printf(", %lf",static_cast<double>((*this)(i,j)));
        }
        printf("\n");
    }
}

#undef HEADER
#undef MAT
#undef MATt
#undef DT

#endif /* mat_impl_h */
