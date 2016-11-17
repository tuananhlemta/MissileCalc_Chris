//
//  Quaternion.hpp
//  NumCH
//
//  Created by Christian J Howard on 11/24/15.
//  Copyright © 2015 Christian Howard. All rights reserved.
//
//  The MIT License (MIT)
//  Copyright © 2016 Christian Howard. All rights reserved.
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

#ifndef Quaternion_hpp
#define Quaternion_hpp


#include "vec3.hpp"

class EulerAngles;

/*!
 *
 * Quaternion Class
 * Assume the form is: q = s + v
 * where s = scalar component
 * and   v = vector component
 *
 */
template<typename data_type = double>
class Quaternion {
public:
    
    typedef vec<3,data_type> vec3;
    
    // Constructor
    Quaternion();
    Quaternion( data_type roll, data_type pitch, data_type yaw ); // Assumes Euler Rotation Order of X -> Y -> Z
    Quaternion( const EulerAngles & angles ); // Assumes Euler Rotation Order of X -> Y -> Z
    Quaternion( data_type angleRadians, const vec3 & axis );
    
    // Method to rotate vector based on quaternion
    vec3 rotate( const vec3 & vec) const;
    
    // Method to normalize quaternion
    void        normalize();
    
    // get quaternion inverse
    Quaternion  getInverse() const;
    
    // get quaternion conjugate
    Quaternion  getConjugate() const;
    
    // get axis quaternion is based on
    vec3       getAxis() const;
    
    // get the angle the quaternion rotates
    // about the axis
    data_type      getAmountRotated() const;
    
    EulerAngles getEulerAngles() const;
    
    
    
    // get/set scalar/vector parts of quaternion
    data_type           getScalarPart() const;
    const vec3 &        getVectorPart() const;
    void        setScalarPart( data_type scalar );
    void        setVectorPart( const vec3 & vec );
    
    // get quaternion derivative based on
    // input angular rate
    Quaternion  getDerivative( const vec3 & omega ) const;
    
    // Get Quaternion Magnitude
    data_type      getMagnitude() const;
    
    // Math operators for Quaternion
    Quaternion  operator*( const Quaternion & q ) const;
    Quaternion  operator+( const Quaternion & q ) const;
    Quaternion  operator-( const Quaternion & q ) const;
    Quaternion operator*( data_type c ) const; // scalar
    Quaternion operator/( data_type c ) const; // scalar
    
    // Method to access components of quaternion
    data_type      operator[](int index) const;
    data_type &    operator[](int index);
    
    // print quaternion value
    void print() const;
    
private:
    
    // quaternion defined by:
    // q = s + v
    // where s is scalar part
    // and v is vector part
    data_type s;
    vec3 v;
    
    
};

#include "Quaternion_Impl.hpp"

#endif /* Quaternion_hpp */
