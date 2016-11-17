//
//  math_operators.hpp
//  Geom3
//
//  Created by Christian J Howard on 9/24/16.
//  Copyright © 2016 Christian Howard. All rights reserved.
//

#ifndef math_operators_h
#define math_operators_h

#include "mat.hpp"
#include "vec.hpp"

template<int R, int C, typename data>
vec<R,data> operator*( const mat<R,C,data> & m, const vec<C,data> & v ){
    vec<R,data> o;
    for(int i = 0; i < R; ++i){
        for( int j = 0; j < C; ++j ){
            o[i] += m(i,j)*v[j];
        }
    }
    return o;
}

template<int R, int C, typename data>
vec<C,data> operator*( const vec<R,data> & v, const mat<R,C,data> & m ){
    vec<C,data> o;
    for(int i = 0; i < C; ++i){
        for( int j = 0; j < R; ++j ){
            o[i] += v[j]*m(j,i);
        }
    }
    return o;
}

template<int R, int I, int C, typename data>
mat<R,C,data> operator*( const mat<R,I,data> & m1, const mat<I,C,data> & m2 ){
    mat<R,C,data> o;
    for(int i = 0; i < R; ++i){
        for( int j = 0; j < C; ++j ){
            for( int k = 0; k < I; ++k){
                o(i,j) += m1(i,k)*m2(k,j);
            }
        }
    }
    return o;
}

#define mat_scalar_op1(OP) template<int R, int C, typename data>\
mat<R,C,data> operator ## OP( const mat<R,C,data> & m, const data & s ){\
mat<R,C,data> o; \
for( int i = 0; i < mat<R,C,data>::N; ++i ){ o[i] = m[i] OP s; } \
return o; \
}
#define mat_scalar_op2(OP) template<int R, int C, typename data>\
mat<R,C,data> operator ## OP( const data & s, const mat<R,C,data> & m ){\
mat<R,C,data> o; \
for( int i = 0; i < mat<R,C,data>::N; ++i ){ o[i] = m[i] OP s; } \
return o; \
}

template<int R, int C, typename data>
mat<R,C,data> operator+( const mat<R,C,data> & m, const data & s ){
    mat<R,C,data> o;
    for( int i = 0; i < mat<R,C,data>::N; ++i ){ o[i] = m[i] + s; }
    return o;
}
template<int R, int C, typename data>
mat<R,C,data> operator-( const mat<R,C,data> & m, const data & s ){
    mat<R,C,data> o;
    for( int i = 0; i < mat<R,C,data>::N; ++i ){ o[i] = m[i] - s; }
    return o;
}
template<int R, int C, typename data>
mat<R,C,data> operator*( const mat<R,C,data> & m, const data & s ){
    mat<R,C,data> o;
    for( int i = 0; i < mat<R,C,data>::N; ++i ){ o[i] = m[i] * s; }
    return o;
}
template<int R, int C, typename data>
mat<R,C,data> operator/( const mat<R,C,data> & m, const data & s ){
    mat<R,C,data> o;
    for( int i = 0; i < mat<R,C,data>::N; ++i ){ o[i] = m[i] / s; }
    return o;
}

template<int R, int C, typename data>
mat<R,C,data> operator+( const data & s, const mat<R,C,data> & m ){
    mat<R,C,data> o;
    for( int i = 0; i < mat<R,C,data>::N; ++i ){ o[i] = m[i] + s; }
    return o;
}
template<int R, int C, typename data>
mat<R,C,data> operator-( const data & s, const mat<R,C,data> & m ){
    mat<R,C,data> o;
    for( int i = 0; i < mat<R,C,data>::N; ++i ){ o[i] = m[i] - s; }
    return o;
}
template<int R, int C, typename data>
mat<R,C,data> operator*( const data & s, const mat<R,C,data> & m ){
    mat<R,C,data> o;
    for( int i = 0; i < mat<R,C,data>::N; ++i ){ o[i] = m[i] * s; }
    return o;
}
template<int R, int C, typename data>
mat<R,C,data> operator/( const data & s, const mat<R,C,data> & m ){
    mat<R,C,data> o;
    for( int i = 0; i < mat<R,C,data>::N; ++i ){ o[i] = m[i] / s; }
    return o;
}

/*mat_scalar_op1(+)
mat_scalar_op1(-)
mat_scalar_op1(*)
mat_scalar_op1(/)

mat_scalar_op2(+)
mat_scalar_op2(-)
mat_scalar_op2(*)
mat_scalar_op2(/)*/

#endif /* math_operators_h */
