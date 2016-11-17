//
//  Q.cpp
//  NumCH
//
//  Created by Christian J Howard on 11/24/15.
//  Copyright © 2015 Christian Howard. All rights reserved.
//

#include "Quaternion.hpp"
#include "EulerAngles.hpp"

#ifndef _quat_impl_hpp
#define _quat_impl_hpp

#define HEADER template<typename data_type>
#define Q Quaternion<data_type>

HEADER
Q::Quaternion():s(),v(){
}

HEADER
Q::Quaternion( data_type roll, data_type pitch, data_type yaw ){
    Quaternion q1( roll, vec3(1.0, 0.0, 0.0));
    Quaternion q2( pitch, vec3(0.0, 1.0, 0.0));
    Quaternion q3( yaw, vec3(0.0, 0.0, 1.0));
    *this = q3*q2*q1;
}

HEADER
Q::Quaternion( const EulerAngles & angles ){
    Quaternion q1( angles[0], vec3(1.0, 0.0, 0.0));
    Quaternion q2( angles[1], vec3(0.0, 1.0, 0.0));
    Quaternion q3( angles[2], vec3(0.0, 0.0, 1.0));
    *this = q3*q2*q1;
}

HEADER
EulerAngles Q::getEulerAngles() const{
    EulerAngles angles;
    angles[0] = atan2( 2.0*(s*v[0]+v[1]*v[2]), 1.0 - 2.0*(v[0]*v[0]+v[1]*v[1] ) );
    angles[1] = asin( 2.0*(s*v[1]-v[0]*v[2] ) );
    angles[2] = atan2( 2.0*(s*v[2]+v[1]*v[0]), 1.0 - 2.0*(v[2]*v[2]+v[1]*v[1] ) );
    return angles;
}

HEADER
Q::Quaternion( data_type angle, const vec3 & axis ){
    s = cos(angle*0.5);
    data_type t = sin(angle*0.5);
    data_type r = (t/axis.magnitude());
    v[0] = axis[0]*r;
    v[1] = axis[1]*r;
    v[2] = axis[2]*r;
}

HEADER
typename Q::vec3 Q::rotate( const vec3 & v_) const{
    Quaternion P;
    P.v = v_;
    Quaternion q = (*this) * P * (*this).getInverse();
    return q.getVectorPart();
}

HEADER
Q  Q::getInverse() const{
    return getConjugate();
}

HEADER
Q  Q::getConjugate() const{
    Quaternion q;
    q.s = s;
    data_type t = static_cast<data_type>(-1);
    q.v[0] = v[0]*t;
    q.v[1] = v[1]*t;
    q.v[2] = v[2]*t;
    return q;
}

HEADER
Q  Q::getDerivative( const vec3 & omega ) const{
    Quaternion w;
    w.v = omega/2.0;
    return (*this)*w;
}

HEADER
typename Q::vec3       Q::getAxis() const{
    data_type t = sqrt(1.0 - s*s);
    return v / t;
}

HEADER
data_type      Q::getAmountRotated() const{ return 2.0*acos(s); }

HEADER
data_type      Q::getScalarPart() const{ return s; }

HEADER
const typename Q::vec3  &     Q::getVectorPart() const{ return v; }

HEADER
void        Q::setScalarPart( data_type scalar ){ s = scalar; }

HEADER
void        Q::setVectorPart( const vec3 & vec ){ v = vec; }

HEADER
data_type      Q::getMagnitude() const{
    return sqrt(s*s + v.magnitudeSquared());
}

HEADER
void        Q::normalize(){
    data_type mag = getMagnitude();
    s /= mag;
    v[0] /= mag;
    v[1] /= mag;
    v[2] /= mag;
}

HEADER
Q  Q::operator*( const Quaternion & q ) const{
    data_type s2    = q.getScalarPart();
    const vec3 & v2 = q.getVectorPart();
    data_type sn = s*s2 - v.dot(v2);
    vec3 cv = v.cross(v2);
    Quaternion out;
    out.s = sn;
    out.v[0] = v2[0]*s + v[0]*s2 + cv[0];
    out.v[1] = v2[1]*s + v[1]*s2 + cv[1];
    out.v[2] = v2[2]*s + v[2]*s2 + cv[2];
    return out;
}

HEADER
Q  Q::operator+( const Quaternion & q ) const{
    Quaternion qn;
    qn.s = s + q.getScalarPart();
    const vec3 & tmp = q.getVectorPart();
    qn.v[0] = v[0] + tmp[0];
    qn.v[1] = v[1] + tmp[1];
    qn.v[2] = v[2] + tmp[2];
    qn.normalize();
    return qn;
}

HEADER
Q  Q::operator-( const Quaternion & q ) const{
    Quaternion qn;
    qn.s = s - q.getScalarPart();
    const vec3 & tmp = q.getVectorPart();
    qn.v[0] = v[0] - tmp[0];
    qn.v[1] = v[1] - tmp[1];
    qn.v[2] = v[2] - tmp[2];
    qn.normalize();
    return qn;
}

HEADER
Q Q::operator*( data_type c ) const{
    Quaternion out;
    out.s = s*c;
    out.v[0] = v[0]*c;
    out.v[1] = v[1]*c;
    out.v[2] = v[2]*c;
    return out;
}

HEADER
Q Q::operator/( data_type c ) const{
    Quaternion out;
    out.s = s/c;
    out.v[0] = v[0]/c;
    out.v[1] = v[1]/c;
    out.v[2] = v[2]/c;
    return out;
}

HEADER
data_type      Q::operator[](int index) const{
    if( index != 0 ){
        return v[index-1];;
    }else{
        return s;
    }
}

HEADER
data_type &    Q::operator[](int index){
    if( index != 0 ){
        return v[index-1];
    }else{
        return s;
    }
}
HEADER
void Q::print() const{
    printf("%lf + %lfi + %lfj + %lfk\n",s,v[0],v[1],v[2]);
}

#undef HEADER
#undef Q

#endif
