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

double quaternion::operator[](const int& index) const{
    return this->components[index];
}

quaternion quaternion::conjugate() const{
    return quaternion(this->components[0], this->components[1] * (-1), this->components[2] * (-1), this->components[3] * (-1));
}

quaternion quaternion::operator*(const quaternion& other) const{
    return quaternion
                                (
                                    obj_r::toZero(this->components[0] * other[0] - this->components[1] * other[1] - this->components[2] * other[2] - this->components[3] * other[3]),
                                    obj_r::toZero(this->components[0] * other[1] + this->components[1] * other[0] + this->components[2] * other[3] - this->components[3] * other[2]),
                                    obj_r::toZero(this->components[0] * other[2] + this->components[2] * other[0] - this->components[1] * other[3] + this->components[3] * other[1]),
                                    obj_r::toZero(this->components[0] * other[3] + this->components[3] * other[0] + this->components[1] * other[2] - this->components[2] * other[1])
                                );
}

quaternion obj_r::getQ(const double& x, const double& y, const double& z, const double& w){
    return quaternion(cos(w/2), sin(w/2) * x, sin(w/2) * y, sin(w/2) * z);
}

quaternion obj_r::getH(const double& x, const double& y, const double& z){
    return quaternion(0 , x, y, z);
}

quaternion obj_r::rotate(const quaternion& q, const quaternion& h){
    return q * h * q.conjugate();
}

double obj_r::toZero(const double& number){
    if (std::abs(number) < 1e-10){
        return 0;
    }

    else{
        return number;
    }
}
