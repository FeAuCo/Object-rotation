#include <cmath>
#include "quaternion.h"

typedef obj_r::Quaternion quaternion;

quaternion::Quaternion(double a, double b, double c, double d)
    : a(a), b(b), c(c), d(d)
{}

double quaternion::getA(){
    return this->a;
}

double quaternion::getB(){
    return this->b;
}

double quaternion::getC(){
    return this->c;
}

double quaternion::getD(){
    return this->d;
}

void quaternion::setA(double new_a){
    this->a = new_a;
}

void quaternion::setB(double new_b){
    this->b = new_b;
}

void quaternion::setC(double new_c){
    this->c = new_c;
}

void quaternion::setD(double new_d){
this->d = new_d;
}

double quaternion::getAbs(){
    return sqrt((this->a) * (this->a) + (this->b) * (this->b) + (this->c) * (this->c) + (this->d) * (this->d));
}

quaternion quaternion::conjugate(){
    return quaternion(this->a, this->b * (-1), this->c * (-1), this->d * (-1));
};
