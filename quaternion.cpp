#include "quaternion.h"

typedef obj_r::Quaternion quaternion;

quaternion::Quaternion(const double& a, const double& b, const double&  c, const double& d){
    this->components[0] = a;
    this->components[1] = b;
    this->components[2] = c;
    this->components[3] = d;
}

void quaternion::setA(const double& new_a){
    this->components[0] = new_a;
}

void quaternion::setB(const double& new_b){
    this->components[1] = new_b;
}

void quaternion::setC(const double& new_c){
    this->components[2] = new_c;
}

void quaternion::setD(const double& new_d){
    this->components[3] = new_d;
}

double quaternion::getAbs(){
    return sqrt((this->components[0]) * (this->components[0]) + (this->components[1]) * (this->components[1]) + (this->components[2]) * (this->components[2]) + (this->components[3]) * (this->components[3]));
}

double quaternion::operator[](const int& index){
    return this->components[index];
}

quaternion quaternion::conjugate(){
    return quaternion(this->components[0], this->components[1] * (-1), this->components[2] * (-1), this->components[3] * (-1));
}

quaternion quaternion::operator*(quaternion& other){
    return quaternion
                                (
                                    this->components[0] * other[0] - this->components[1] * other[1] - this->components[2] * other[2] - this->components[3] * other[3],
                                    this->components[0] * other[1] + this->components[1] * other[0] + this->components[2] * other[3] - this->components[3] * other[2],
                                    this->components[0] * other[2] + this->components[2] * other[0] - this->components[1] * other[3] + this->components[3] * other[1],
                                    this->components[0] * other[3] + this->components[3] * other[0] + this->components[1] * other[2] - this->components[2] * other[1]
                                );
}

quaternion getQ(const double& x, const double& y, const double& z, const double& w){
    return quaternion(cos(w/2), sin(w/2) * x, sin(w/2) * y, sin(w/2) * z);
}

quaternion getH(const double& x, const double& y, const double& z){
    return quaternion(0 , x, y, z);
}

//-------
// quaternion rotate(quaternion& q, quaternion& h){
//     return q * h * q.conjugate();
// }
//-------
