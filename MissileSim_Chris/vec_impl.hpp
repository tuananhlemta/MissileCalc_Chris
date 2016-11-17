//
//  vec.cpp
//
//  Created by Christian J Howard on 11/25/15.
//  Copyright © 2015 Christian Howard. All rights reserved.
//

#include "vec.hpp"

#ifndef _vec_impl_hpp
#define _vec_impl_hpp

#include <math.h>
#define HEADER template<int D, typename scalar>
#define VEC vec<D,scalar>

// specify accessor methods
HEADER
typename VEC::data_type & VEC::operator[](int idx) {
    return d[idx];
}
HEADER
const typename VEC::data_type & VEC::operator[](int idx) const {
    return d[idx];
}

HEADER
VEC::vec(){
    data_type zero = data_type();
    for(int i = 0; i < D; ++i){ d[i] = zero; }
}

// specify norm-like methods
HEADER
typename VEC::data_type VEC::dot( const vec & v ) const {
    data_type out = data_type();
    for(int i = 0; i < D; ++i ){ out += d[i]*v.d[i]; }
    return out;
}
HEADER
typename VEC::data_type VEC::magnitude() const {
    return sqrt(magnitudeSquared());
}
HEADER
typename VEC::data_type VEC::magnitudeSquared() const {
    data_type out = data_type();
    for(int i = 0; i < D; ++i ){ out += d[i]*d[i]; }
    return out;
}
HEADER
void VEC::normalize(){
    data_type m = magnitude();
    for(int i = 0; i < D; ++i ){ d[i] /= m; }
}
HEADER
VEC VEC::getNormal() const {
    vec out;
    data_type m = magnitude();
    for(int i = 0; i < D; ++i ){ out.d[i] = d[i]/m; }
    return out;
}

HEADER
void VEC::operator=( const data_type & s ) {
    for(int i =0 ;i < D; ++i){ d[i] = s; }
}

// specify element-wise math operators
HEADER
VEC VEC::operator+( const vec & v ) const{
    vec out;
    for(int i = 0; i < D; ++i ){ out.d[i] = d[i] + v.d[i]; }
    return out;
}
HEADER
VEC VEC::operator-( const vec & v ) const {
    vec out;
    for(int i = 0; i < D; ++i ){ out.d[i] = d[i]-v.d[i]; }
    return out;
}
HEADER
VEC VEC::operator*( const vec & v ) const {
    vec out;
    for(int i = 0; i < D; ++i ){ out.d[i] = d[i]*v.d[i]; }
    return out;
}
HEADER
VEC VEC::operator/( const vec & v ) const{
    vec out;
    for(int i = 0; i < D; ++i ){ out.d[i] = d[i]/v.d[i]; }
    return out;
}
HEADER
VEC VEC::operator+( const data_type & d_ ) const {
    vec out;
    for(int i = 0; i < D; ++i ){ out.d[i] = d[i]+d_; }
    return out;
}
HEADER
VEC VEC::operator-( const data_type & d_ ) const{
    vec out;
    for(int i = 0; i < D; ++i ){ out.d[i] = d[i]-d_; }
    return out;
}
HEADER
VEC VEC::operator*( const data_type & d_ ) const {
    vec out;
    for(int i = 0; i < D; ++i ){ out.d[i] = d[i]*d_; }
    return out;
}
HEADER
VEC VEC::operator/( const data_type & d_ ) const {
    vec out;
    for(int i = 0; i < D; ++i ){ out.d[i] = d[i]/d_; }
    return out;
}

HEADER
void VEC::print() const {
    printf("[ %lf",d[0]);
    for(int i = 1; i < D; ++i){
        printf(", %lf",d[i]);
    }
    printf(" ]\n");
}

#undef HEADER
#undef VEC

#endif




