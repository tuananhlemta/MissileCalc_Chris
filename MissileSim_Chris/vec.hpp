//
//  vec.hpp
//
//  Created by Christian J Howard on 11/25/15.
//  Copyright © 2015 Christian Howard. All rights reserved.
//

#ifndef VecND_hpp
#define VecND_hpp

template<int D, typename scalar = double>
class vec {
public:
    
    // specify typedefs
    typedef scalar data_type;
    
    vec();
    
    // specify accessor methods
    data_type & operator[](int idx);
    const data_type & operator[](int idx) const;
    
    // specify norm-like methods
    data_type dot( const vec & v ) const;
    data_type magnitude() const;
    data_type magnitudeSquared() const;
    void normalize();
    vec getNormal() const;
    
    // specify element-wise math operators
    vec operator+( const vec & v ) const;
    vec operator-( const vec & v ) const;
    vec operator*( const vec & v ) const;
    vec operator/( const vec & v ) const;
    vec operator+( const data_type & d ) const;
    vec operator-( const data_type & d ) const;
    vec operator*( const data_type & d ) const;
    vec operator/( const data_type & d ) const;
    void operator=( const data_type & s );
    
    // print method
    void print() const;
    
protected:
    data_type d[D];
};

#include "vec_impl.hpp"

#endif /* VecND_hpp */
